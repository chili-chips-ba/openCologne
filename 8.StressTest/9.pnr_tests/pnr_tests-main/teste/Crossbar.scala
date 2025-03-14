package PnrTests

import chisel3._
import chisel3.util._

class Crossbar(maxWidth: Int, minWidth: Int) extends Module {

  val in = IO(Flipped(Decoupled(UInt(maxWidth.W))))
  val in1 = IO(Flipped(Decoupled(UInt(maxWidth.W))))
  val out = IO(Decoupled(UInt(maxWidth.W)))
  val out1 = IO(Decoupled(UInt(maxWidth.W)))

  val out_buf = Reg(Valid(UInt(maxWidth.W)))
  val out1_buf = Reg(Valid(UInt(maxWidth.W)))

  in.ready := false.B
  in1.ready := false.B
  out_buf.valid := false.B
  out1_buf.valid := false.B
  out_buf.bits := in.bits
  out1_buf.bits := in1.bits

  when (in.valid && in.bits(minWidth-1,0).xorR) {
    in.ready := out.ready
    out_buf.bits := in.bits
    out_buf.valid := true.B
  }
  when (in.valid && !in.bits(minWidth-1,0).xorR) {
    in.ready := out1.ready
    out1_buf.bits := in.bits
    out1_buf.valid := true.B
  }
  when (in1.valid && in1.bits(minWidth-1,0).xorR) {
    in1.ready := out.ready
    out_buf.bits := in1.bits
    out_buf.valid := true.B
  }
  when (in1.valid && !in1.bits(minWidth-1,0).xorR) {
    in1.ready := out1.ready
    out1_buf.bits := in1.bits
    out1_buf.valid := true.B
  }
  out.bits := out_buf.bits
  out.valid := out_buf.valid
  out1.bits := out1_buf.bits
  out1.valid := out1_buf.valid
}
