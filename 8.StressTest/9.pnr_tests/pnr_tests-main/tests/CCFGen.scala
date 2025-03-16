package PnrTests

import chisel3._
import chisel3.reflect.DataMirror
import java.io.{BufferedWriter, FileWriter, File}
import scala.io.Source
import scala.collection.mutable.ListBuffer
import scala.util.Random
import scala.annotation.unused

class CCFGen[T <: Module](moduleFactory: () => T, outdir: String, project: String, @unused part: String, csvPath: String) extends Module {

  val test = Module(moduleFactory())

  val pins = ListBuffer[String]()
  val clock_pins = ListBuffer[String]()
  
  // Read the CSV file with GateMateFPGA pin information
  val sourceCSV = Source.fromFile(csvPath)
  
  // Skip header lines (there are multiple header lines in the provided format)
  // Skip first 5 lines which are comments and column headers
  val lines = sourceCSV.getLines().toList
  val dataLines = lines.drop(5)
  
  for (line <- dataLines) {
    // Format: Pin;Name;2nd function;Signal group;GPIO bank;"I/O mode";...
    val columns = line.split(";", -1)
    
    if (columns.length >= 5) {
      val pinName = columns(0)
      val ioName = columns(1)  // This is the IO_XX_XX format name we need
      val signalGroup = columns(3)
      val gpioBank = columns(4)
      
      // Only add I/O pins, filter out power, ground, etc.
      if (signalGroup.trim == "GPIO" && !ioName.trim.isEmpty) {
        // Check for valid I/O pins
        if (!signalGroup.contains("Power") && !signalGroup.contains("Ground")) {
          pins += ioName
        }
        
        // Add dedicated clock pins - assume pins with certain banks might be better suited for clocks
        // In a real implementation, this would need to be adjusted based on actual GateMateFPGA documentation
        // For now, using pins from specific banks (NA, NB) as possible clock sources
        if (gpioBank.contains("NA") || gpioBank.contains("NB")) {
          if (ioName.contains("B0") || ioName.contains("A0")) {
            clock_pins += ioName
          }
        }
      }
    }
  }
  sourceCSV.close()
  
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
  
  val fileCCF = new File(s"$outdir/$project.ccf")
  fileCCF.createNewFile()
  val writerCCF = new BufferedWriter(new FileWriter(fileCCF))
  
  // Write header information to the CCF file
  writerCCF.write("## GateMateFPGA constraints file\n")
  writerCCF.write(s"## Project: $project\n")
  writerCCF.write("## Generated automatically by CCFGen\n\n")
  
  DataMirror.modulePorts(test).foreach { case (name, port) => {
    port := DontCare
    if (port.getWidth > 1) {
      // Handle multi-bit ports
      for (i <- 0 until port.getWidth) {
        assert(pins.nonEmpty, "Not enough pins available in device")
        val randomIndex = safeRandomIndex(pins.length)
        
        // New format for pin assignment
        writerCCF.write(s"""Net "$name[$i]" Loc = "${pins(randomIndex)}"; # Auto-assigned\n""")
        
        pins.remove(randomIndex)
      }
    } else {
      // Handle single-bit ports
      if (name == "clock" || name == "clk") {
        // Special handling for clock pins
        if (clock_pins.nonEmpty) {
          val randomIndex = safeRandomIndex(clock_pins.length)
          // Clock pin with Schmitt trigger
          writerCCF.write(s"""Net "$name" Loc = "${clock_pins(randomIndex)}" | SCHMITT_TRIGGER=true; # CLK\n""")
          clock_pins.remove(randomIndex)
        } else {
          // If no clock pins are available, fall back to regular pins
          assert(pins.nonEmpty, "Not enough pins available in device")
          val randomIndex = safeRandomIndex(pins.length)
          // Clock pin with Schmitt trigger
          writerCCF.write(s"""Net "$name" Loc = "${pins(randomIndex)}" | SCHMITT_TRIGGER=true; # CLK (fallback)\n""")
          pins.remove(randomIndex)
        }
      } else {
        assert(pins.nonEmpty, "Not enough pins available in device")
        val randomIndex = safeRandomIndex(pins.length)
        
        // For regular pins, use simple format
        writerCCF.write(s"""Net "$name" Loc = "${pins(randomIndex)}"; # Auto-assigned\n""")
        
        pins.remove(randomIndex)
      }
    }
  }}
  
  writerCCF.close()
}
