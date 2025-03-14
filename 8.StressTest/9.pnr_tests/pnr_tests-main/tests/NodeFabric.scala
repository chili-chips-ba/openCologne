package PnrTests

import chisel3._
import chisel3.util._
import scala.util.Random
import scala.annotation.unused

class NullModule extends Module {}

class NodeFabric(startWidth: Int) {

  val random = new Random()

  var currWidth = startWidth
  def GenModule(maxWidth: Int, minWidth: Int, complexity: Int): Module = {

    var nodeType = random.nextInt(7)
    val nodeSubtype = random.nextInt(6)
    if (currWidth < 16) {
      nodeType = 2;
    }
    if (nodeType == 0) {
      val inWidth = currWidth
      val inCtrlWidth = minWidth max random.nextInt(inWidth/2)
      val outWidth = currWidth
      val outCtrlWidth = inCtrlWidth
      currWidth = outWidth
      print(s"[Q${nodeSubtype}.${currWidth}] ");
      Module(new NodeQueue(nodeSubtype, inCtrlWidth, inWidth, outCtrlWidth, outWidth, complexity))
    } else
    if (nodeType == 1) {
      val inWidth = currWidth
      val inCtrlWidth = minWidth max random.nextInt(inWidth/2)
      val outWidth = minWidth*2 max random.nextInt(currWidth)
      val outCtrlWidth = minWidth max (outWidth/2 min random.nextInt(inCtrlWidth*2))
      currWidth = outWidth
      print(s"[M${nodeSubtype}.${currWidth}-${outCtrlWidth}] ");
      Module(new NodeMux(nodeSubtype, inCtrlWidth, inWidth, outCtrlWidth, outWidth, complexity))
    } else
    if (nodeType == 2) {
      val inWidth = currWidth
      val inCtrlWidth = minWidth max random.nextInt(inWidth/2)
      val outWidth = minWidth*2 max (maxWidth min random.nextInt(currWidth*8))
      val outCtrlWidth = minWidth max (outWidth/2 min random.nextInt(inCtrlWidth*2))
      currWidth = outWidth
      print(s"[D${nodeSubtype}.${currWidth}-${outCtrlWidth}] ");
      Module(new NodeDemux(nodeSubtype, inCtrlWidth, inWidth, outCtrlWidth, outWidth, complexity))
    } else
    if (nodeType == 3) {
      val inWidth = currWidth
      val inCtrlWidth = minWidth max random.nextInt(inWidth/2)
      val outWidth = currWidth
      val outCtrlWidth = minWidth max (outWidth/2 min random.nextInt(inCtrlWidth*2))
      currWidth = outWidth
      print(s"[MUL${nodeSubtype}.${currWidth}-${outCtrlWidth}] ");
      Module(new NodeMul(nodeSubtype, inCtrlWidth, inWidth, outCtrlWidth, outWidth, complexity))
    } else
    if (nodeType == 4) {
      val inWidth = currWidth
      val inCtrlWidth = minWidth max random.nextInt(inWidth/2)
      val outWidth = currWidth
      val outCtrlWidth = minWidth max (outWidth/2 min random.nextInt(inCtrlWidth*2))
      currWidth = outWidth
      print(s"[DIV${nodeSubtype}.${currWidth}-${outCtrlWidth}] ");
      Module(new NodeDiv(nodeSubtype, inCtrlWidth, inWidth, outCtrlWidth, outWidth, complexity))
    } else
    if (nodeType == 5) {
      val inWidth = currWidth
      val inCtrlWidth = minWidth max random.nextInt(inWidth/2)
      val outWidth = currWidth
      val outCtrlWidth = minWidth max (outWidth/2 min random.nextInt(inCtrlWidth*2))
      currWidth = outWidth
      print(s"[MAP${nodeSubtype}.${currWidth}-${outCtrlWidth}] ");
      Module(new NodeMap(nodeSubtype, inCtrlWidth, inWidth, outCtrlWidth, outWidth, complexity))
    } else
    if (nodeType == 6) {
      val inWidth = currWidth
      val inCtrlWidth = minWidth max random.nextInt(inWidth/2)
      val outWidth = currWidth
      val outCtrlWidth = minWidth max (outWidth/2 min random.nextInt(inCtrlWidth*2))
      currWidth = outWidth
      print(s"[MEM${nodeSubtype}.${currWidth}-${outCtrlWidth}] ");
      Module(new NodeMemory(0/*nodeSubtype*/, inCtrlWidth, inWidth, outCtrlWidth, outWidth, complexity))
    }
    else {
      Module(new NullModule)
    }
  }

  def ChainModule(mod: Module, in: DecoupledIO[UInt], out: DecoupledIO[UInt]) {

    mod match {
      case m: NodeQueue =>
        in <> m.in
        m.out <> out
      case m: NodeMux =>
        in <> m.in
        m.out <> out
      case m: NodeDemux =>
        in <> m.in
        m.out <> out
      case m: NodeMul =>
        in <> m.in
        m.out <> out
      case m: NodeDiv =>
        in <> m.in
        m.out <> out
      case m: NodeMap =>
        in <> m.in
        m.out <> out
      case m: NodeMemory =>
        in <> m.in
        m.out <> out
      case m: Crossbar =>
        in <> m.in
        m.out <> out
    }
  }

  def GenCrossbar(maxWidth: Int, minWidth: Int, complexity: Int): Module = {
    print(s"[C] ");
    Module(new Crossbar(maxWidth, minWidth))
  }

  def ChainModules(modules: Seq[Module], in: DecoupledIO[UInt], out: DecoupledIO[UInt], maxWidth: Int): Unit = {

    var ins = Wire(Vec(modules.length, DecoupledIO(UInt(maxWidth.W))))
    var outs = Wire(Vec(modules.length-1, DecoupledIO(UInt(maxWidth.W))))

    ChainModule(modules(0), in, ins(0))

    for (i <- 0 until modules.length-1) {
      ChainModule(modules(i+1), ins(i), outs(i))
      ins(i+1) <> outs(i)
    }
    out <> ins(modules.length-1)
  }

  def StarModules(modules: Seq[Module], in: DecoupledIO[UInt], out: DecoupledIO[UInt], maxWidth: Int): Unit = {

    var ins = Wire(Vec(modules.length, DecoupledIO(UInt(maxWidth.W))))
    var outs = Wire(Vec(modules.length-1, DecoupledIO(UInt(maxWidth.W))))

    ChainModule(modules(0), in, ins(0))

    val regs_ctrl = Reg(UInt(10.W))
    regs_ctrl := ins(modules.length/2).bits(9,0)
    for (i <- 0 until modules.length-1) {
      val star_in = Wire(DecoupledIO(UInt(maxWidth.W)))
      star_in.valid := ins(i).valid
      star_in.bits := Cat(ins(i).bits(maxWidth-1,10),regs_ctrl^ins(i).bits(9,0))
      ins(i).ready := star_in.ready
      ChainModule(modules(i+1), star_in, outs(i))
      ins(i+1) <> outs(i)
    }
    out <> ins(modules.length-1)
  }

  def MeshModules(modules: Seq[Module], in: Vec[DecoupledIO[UInt]], out: Vec[DecoupledIO[UInt]], maxWidth: Int): Unit = {

    for (i <- 0 until modules.length) {
      if (i%2 == 1) {
        modules(i) match {
          case m: Crossbar =>
            m.in1 <> in(i/2)
            out(i/2) <> m.out1
        }
      }
    }
  }

}