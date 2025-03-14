package PnrTests

import chisel3._

import chisel3.reflect.DataMirror
import java.io.{BufferedWriter, FileWriter, File}
import scala.io.Source
import scala.collection.mutable.ListBuffer
import scala.util.Random
import scala.annotation.unused

class XDCGen[T <: Module](moduleFactory: () => T, outdir: String, project: String, @unused part: String, xrayPath: String) extends Module {

  val test = Module(moduleFactory())

  val pins = ListBuffer[String]()
  val clock_pins = ListBuffer[String]()
  val sourceCSV = Source.fromFile(s"/home/nikola/ChiliChips/openCologne/pnr_tests-novi/colognechip/CCGM1A1/package_pins.csv")
  sourceCSV.getLines().next()
  for (line <- sourceCSV.getLines()) {
    val columns = line.split(",")
    if (columns.length >= 4
        && !columns(3).contains("GTP")
        && !columns(3).contains("MONITOR")
        && !columns(4).contains("SRCC")
        && !columns(4).contains("MRCC")) {
      pins += columns(0)
    }
    if ((columns(4).contains("SRCC")
        || columns(4).contains("MRCC"))
        && !columns(4).contains("N_T")) {
      clock_pins += columns(0)
    }
  }
  val random = new Random()
  val fileXDC = new File(s"$outdir/$project.ccf")
  fileXDC.createNewFile()
  val writerXDC = new BufferedWriter(new FileWriter(fileXDC))
  DataMirror.modulePorts(test).foreach { case (name, port) => {
    port := DontCare
    if (port.getWidth > 1) {
      for (i <- 0 until port.getWidth) {
        assert(pins.length > 0, "no so many pins in device")
        val randomIndex = random.nextInt(pins.length)
        writerXDC.write(s"set_property IOSTANDARD LVCMOS33 [get_ports $name[$i]]\n")
        writerXDC.write(s"set_property PACKAGE_PIN ${pins(randomIndex)} [get_ports $name[$i]]\n")
        pins.remove(randomIndex)
      }
    } else {
      if (name == "clock") {
        val randomIndex = random.nextInt(clock_pins.length)
        writerXDC.write(s"set_property IOSTANDARD LVCMOS33 [get_ports $name]\n")
        writerXDC.write(s"set_property PACKAGE_PIN ${clock_pins(randomIndex)} [get_ports $name]\n")
        clock_pins.remove(randomIndex)
        // if we know all clocks we can give rest clock_pins for generic use
      } else {
        val randomIndex = random.nextInt(pins.length)
        writerXDC.write(s"set_property IOSTANDARD LVCMOS33 [get_ports $name]\n")
        writerXDC.write(s"set_property PACKAGE_PIN ${pins(randomIndex)} [get_ports $name]\n")
        pins.remove(randomIndex)
      }
    }
  }}
  writerXDC.close()
}
