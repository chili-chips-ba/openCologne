//> using scala "2.13.12"
//> using dep "org.chipsalliance::chisel:6.7.0"
//> using plugin "org.chipsalliance:::chisel-plugin:6.7.0"
//> using options "-unchecked" "-deprecation" "-language:reflectiveCalls" "-feature" "-Xcheckinit" "-Ywarn-dead-code" "-Ywarn-unused" "-Ymacro-annotations"

import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage
import java.nio.file.{Files, Paths}
import java.io.{BufferedWriter, FileWriter, PrintWriter, File}
import scala.sys.process._
import scala.io.Source
import scala.collection.mutable.Queue

import PnrTests.NodeFabric
import PnrTests.XDCGen
import PnrTests.CCFGen

class Config {
  val startWidth = 32
  val minWidth = 10
}

class TestMeshIO(startWidth: Int) extends Module {
  val in_valid = IO(Input(Bool()))
  val in_ready = IO(Output(Bool()))
  val in_bits = IO(Input(UInt(startWidth.W)))
  val out_valid = IO(Output(Bool()))
  val out_ready = IO(Input(Bool()))
  val out_bits = IO(Output(UInt(startWidth.W)))

  in_ready := DontCare
  out_valid := DontCare
  out_bits := DontCare
}

class TestMesh(cfg: Config, complexity: Int, x: Int, y: Int, maxWidth: Int, num: Int) extends TestMeshIO(cfg.startWidth) {

  val in = Wire(Flipped(Decoupled(UInt(cfg.startWidth.W))))
  in.valid := in_valid
  in_ready := in.ready
  in.bits := in_bits

  val out = Wire(Decoupled(UInt(cfg.startWidth.W)))
  out_valid := out.valid
  out.ready := out_ready
  out_bits := out.bits

  val fabric = new NodeFabric(cfg.startWidth)
  val links = Seq.fill(y+1) {
    Wire(Vec(x, DecoupledIO(UInt(maxWidth.W))))
  }
  for (i <- 0 until y) {
    val modules: Seq[Module] = (0 until x*2).map { i => if (i%2==0) fabric.GenModule(maxWidth, cfg.minWidth, complexity) else fabric.GenCrossbar(maxWidth, cfg.minWidth, complexity) }
    fabric.ChainModules(modules, in, out, maxWidth)
    fabric.MeshModules(modules, links(i), links(i+1), maxWidth)
  }
  links(0) := DontCare
  links(y) := DontCare
}

object Main extends App {
  val project = args(0)
  val part = args(1)
  val partpath = args(2)
  val k = args(3).toInt
  val x = args(4).toInt
  val y = args(5).toInt
  val m = args(6).toInt
  val n = args(7).toInt

  for (i <- 0 until n) {
    val outdir = s"gen_${k}_${x}_${y}_${m}_${i}"
    val path = Paths.get(outdir)
    if (!Files.exists(path)) {
      Files.createDirectories(path)
    }

    val fileMakefile = new File(s"$outdir/Makefile")
    fileMakefile.createNewFile()
    val writerMakefile = new BufferedWriter(new FileWriter(fileMakefile))

    writerMakefile.write(s"""
FAMILY  = colognechip
PART    = $part
BOARD   = GateMateA1-EVB
PROJECT = $project
CHIPDB  = ../../GateMateA1-EVB.ccf
TOP_VERILOG=$$(PROJECT).sv
#SYNTH_OPTS = -nodsp
include ../../config.mk
""")
    writerMakefile.close()

    val cfg: Config = new Config;

//    ChiselStage.emitFIRRTLDialect(new TestMesh(k, l, m, i))
    ChiselStage.emitSystemVerilog(new CCFGen(() => new TestMeshIO(64), outdir, project, part, partpath))
    ChiselStage.emitSystemVerilogFile(new TestMesh(cfg, k, x, y, m, i), Array("--target-dir", outdir), firtoolOpts=Array("--lowering-options=disallowLocalVariables,disallowPackedArrays"))

    val stdoutFile = new File(s"$outdir/stdout.log")
    val stdoutWriter = new PrintWriter(new FileWriter(stdoutFile))
    val stderrFile = new File(s"$outdir/stderr.log")
    val stderrWriter = new PrintWriter(new FileWriter(stderrFile))

    print(s"Running $outdir... ")
    val process = Process("make", new java.io.File(outdir))
    val logger = ProcessLogger(
      line => {stdoutWriter.println(line); stdoutWriter.flush()},
      line => {stderrWriter.println(line); stderrWriter.flush()}
    )
    val exitCode = process ! logger
    stdoutWriter.close()
    stderrWriter.close()

    val source = Source.fromFile(s"$outdir/stderr.log")
    var info = ""
    for (line <- source.getLines()) {
      if (line.contains("SLICE_LUTX:")) {
        val pattern = """.*(SLICE_LUTX:\s+\d+/\d+).*""".r
        info = line match {
          case pattern(extracted) => extracted
          case _ => ""
        }
      }
    }
    source.close()
    print(info)

    if (exitCode != 0) {
      val source = Source.fromFile(s"$outdir/stderr.log")
      val queue = new Queue[String]()
      for (line <- source.getLines()) {
        if (queue.size >= 3) queue.dequeue()
        queue.enqueue(line)
      }
      source.close()
      val errstr = queue.toList
      print("ERROR: ")
      println(errstr)
    }
    else {
      println(s": OK")
    }
  }
}
