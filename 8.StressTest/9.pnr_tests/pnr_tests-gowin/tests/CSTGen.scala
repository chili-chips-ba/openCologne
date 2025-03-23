package PnrTests

import chisel3._
import chisel3.reflect.DataMirror
import java.io.{BufferedWriter, FileWriter, File}
import scala.io.Source
import scala.collection.mutable.ListBuffer
import scala.util.Random
import scala.annotation.unused

class CSTGen[T <: Module](moduleFactory: () => T, outdir: String, project: String, @unused part: String, txtPath: String) extends Module {

  val test = Module(moduleFactory())

  val pins = ListBuffer[(String, String)]() // (pinNumber, pinName)
  val clock_pins = ListBuffer[(String, String)]() // (pinNumber, gclkName)
  
  // Keep track of pin counts
  var initialRegularPins = 0
  var initialClockPins = 0
  var usedRegularPins = 0
  var usedClockPins = 0
  
  // Read the Gowin pin list text file
  val sourceTxt = Source.fromFile(txtPath)
  
  // Skip header line
  val lines = sourceTxt.getLines().toList
  val dataLines = lines.drop(1)
  
  for (line <- dataLines) {
    // Format: Pin Name,Function,DQS,BANK,Configuration Function,Differential Pair,LVDS,QN88[1]
    val columns = line.split(",", -1)
    
    if (columns.length >= 8) { // Make sure we have enough columns
      val fullPinName = columns(0).trim
      val function = columns(1).trim
      val pinNumber = columns(7).trim // The last column is the pin number
      
      // Only add I/O pins
      if (function == "I/O") {
        // Check if this is a clock pin (has /GCLK in the name)
        if (fullPinName.contains("/GCLK")) {
          val parts = fullPinName.split("/")
          val baseName = parts(0)
          val gclkName = parts(1)
          
          // Add to clock pins with the GCLK name
          clock_pins += ((pinNumber, gclkName))
        } else {
          // For regular pins, just use the pin name as is
          // If it has a slash but not GCLK, take the part before the slash
          val baseName = if (fullPinName.contains("/")) fullPinName.split("/")(0) else fullPinName
          pins += ((pinNumber, baseName))
        }
      }
    }
  }
  sourceTxt.close()
  
  initialRegularPins = pins.size
  initialClockPins = clock_pins.size
  
  val random = new Random()
  
  // Safe random index generator - ensures we never generate zero or negative numbers
  def safeRandomIndex(size: Int): Int = {
    require(size > 0, "Cannot generate a random index for an empty collection")
    if (size == 1) {
      0  // Only one element, so return index 0
    } else {
      // Ensure we get a positive number in the range [0, size-1]
      Math.abs(random.nextInt()) % size
    }
  }
  
  val fileCST = new File(s"$outdir/$project.cst")
  fileCST.createNewFile()
  val writerCST = new BufferedWriter(new FileWriter(fileCST))
  
  // Write header information to the CST file
  writerCST.write("//Gowin GW2AR-18CQN88 constraints file\n")
  writerCST.write(s"//Project: $project\n")
  writerCST.write("//Generated automatically by CCFGen\n\n")
  
  // Custom exception for pin availability
  class NotEnoughPinsException(message: String) extends Exception(message)
  
  try {
    // First process all clock signals to use dedicated clock pins when possible
    val clockPorts = DataMirror.modulePorts(test).filter { case (name, _) => 
      name == "clock" || name == "clk"
    }
    
    // Assign clock pins to clock signals first
    for ((name, port) <- clockPorts) {
      port := DontCare
      
      if (clock_pins.nonEmpty) {
        val randomIndex = safeRandomIndex(clock_pins.length)
        val (pinNumber, gclkName) = clock_pins(randomIndex)
        
        // Clock pin with special properties - use the GCLK name
        writerCST.write(s"""IO_LOC "$name" $pinNumber;\n""")
        writerCST.write(s"""IO_PORT "$name" IO_TYPE=LVCMOS33 PULL_MODE=UP;\n""")
        
        clock_pins.remove(randomIndex)
        usedClockPins += 1
      } else if (pins.nonEmpty) {
        // If no clock pins are available, fall back to regular pins
        val randomIndex = safeRandomIndex(pins.length)
        val (pinNumber, pinName) = pins(randomIndex)
        
        writerCST.write(s"""IO_LOC "$name" $pinNumber;\n""")
        writerCST.write(s"""IO_PORT "$name" IO_TYPE=LVCMOS33 PULL_MODE=UP;\n""")
        
        pins.remove(randomIndex)
        usedRegularPins += 1
      } else {
        throw new NotEnoughPinsException("Not enough pins available in device for clock signal")
      }
    }
    
    // Now move any remaining clock pins to regular pins
    if (clock_pins.nonEmpty) {
      // Convert clock pins to regular I/O pins - use the base name (before the /)
      for ((pinNumber, gclkName) <- clock_pins) {
        // Just use the pinNumber as the name since we already extracted the relevant part
        val baseName = pinNumber
        pins += ((pinNumber, baseName))
      }
      clock_pins.clear()
    }
    
    // Process the remaining non-clock ports
    val nonClockPorts = DataMirror.modulePorts(test).filter { case (name, _) => 
      name != "clock" && name != "clk"
    }
    
    for ((name, port) <- nonClockPorts) {
      port := DontCare
      
      if (port.getWidth > 1) {
        // Handle multi-bit ports
        for (i <- 0 until port.getWidth) {
          if (pins.isEmpty) {
            throw new NotEnoughPinsException(s"Not enough pins available in device for multi-bit port ${name}[$i]")
          }
          
          val randomIndex = safeRandomIndex(pins.length)
          val (pinNumber, pinName) = pins(randomIndex)
          
          // Format for Gowin CST file
          writerCST.write(s"""IO_LOC "${name}[$i]" $pinNumber;\n""")
          writerCST.write(s"""IO_PORT "${name}[$i]" IO_TYPE=LVCMOS33;\n""")
          
          pins.remove(randomIndex)
          usedRegularPins += 1
        }
      } else {
        // Handle single-bit non-clock ports
        if (pins.isEmpty) {
          throw new NotEnoughPinsException(s"Not enough pins available in device for port: $name")
        }
        
        val randomIndex = safeRandomIndex(pins.length)
        val (pinNumber, pinName) = pins(randomIndex)
        
        // For regular pins, use standard format
        writerCST.write(s"""IO_LOC "$name" $pinNumber;\n""")
        writerCST.write(s"""IO_PORT "$name" IO_TYPE=LVCMOS33;\n""")
        
        pins.remove(randomIndex)
        usedRegularPins += 1
      }
    }
  } catch {
    case e: NotEnoughPinsException => 
      // Close the file before exiting with error
      writerCST.close()
      
      // Print diagnostic information specifically for "Not enough pins" error
      println(e.getMessage)
      println(s"Pin statistics:")
      println(s"  - Initial pins: $initialRegularPins regular pins, $initialClockPins clock pins")
      println(s"  - Used pins: $usedRegularPins regular pins, $usedClockPins clock pins")
      println(s"  - Remaining pins: ${pins.size} regular pins, ${clock_pins.size} clock pins")
      
      throw e
    case e: Throwable =>
      // For any other exception, just close the file and rethrow
      writerCST.close()
      throw e
  }
  
  writerCST.close()
}
