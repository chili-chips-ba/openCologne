package PnrTests

import chisel3._
import chisel3.util._

class NodeMux(muxType: Int, inCtrl: Int, inWidth: Int, outCtrl: Int, outWidth: Int, complexity: Int) extends Module {

  val in = IO(Flipped(Decoupled(UInt(inWidth.W))))
  val out = IO(Decoupled(UInt(outWidth.W)))

  in.ready := true.B
  out.valid := true.B
  out.bits := Cat(in.bits >> inCtrl >> in.bits(inCtrl-1,0), in.bits(outCtrl-1,0))

  if (muxType%3 == 1 && (inWidth-inCtrl)/(outWidth-outCtrl) > 0) {
    for (i <- 0 until (inWidth-inCtrl)/(outWidth-outCtrl)) {
      val region_beg = inCtrl+i*(outWidth-outCtrl)
      val region_end = inCtrl+(i+1)*(outWidth-outCtrl)
      when (in.bits(inCtrl-1,0) === (i&((1<<inCtrl)-1)).U) {
        out.bits := Cat(in.bits(region_end-1,region_beg), in.bits(outCtrl-1,0))
      }
    }
  }

  if (muxType%3 == 2 && (inWidth)/(outWidth) > 0) {
    out.bits := 0.U
    for (i <- 0 until (inWidth)/(outWidth)) {
      val region_beg = i*(outWidth)
      val region_end = (i+1)*(outWidth)
      when (in.bits(region_beg) === 1.U) {
        out.bits := /*out.bits |*/ in.bits(region_end-1,region_beg+1)
      }
    }
  }

}
