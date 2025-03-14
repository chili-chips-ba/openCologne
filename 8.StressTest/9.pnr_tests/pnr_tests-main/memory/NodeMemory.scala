package PnrTests

import chisel3._
import chisel3.util._

import chisel3.experimental.ChiselAnnotation
import chisel3.experimental.annotate

class NodeMemory(memType: Int, inCtrl: Int, inWidth: Int, outCtrl: Int, outWidth: Int, complexity: Int) extends Module {

  val in = IO(Flipped(Decoupled(UInt(inWidth.W))))
  val out = IO(Decoupled(UInt(outWidth.W)))

  in.ready := true.B
  out.valid := true.B
  out.bits := Cat(in.bits,in.bits)

  if (memType%3 == 0) {
    val ports = 4
    val abits = (inCtrl-ports)/ports
    val depth = 2<<abits max (8<<complexity)
    val width = (inWidth-inCtrl)/ports
    val mem = SyncReadMem(depth, UInt(width.W))
    val data = (
      for (i <- 0 until ports) yield {
        val data_beg = inCtrl+(i+0)*width
        val data_end = inCtrl+(i+1)*width
        when (in.valid && in.bits(i)) {
          mem.write(in.bits(ports+abits*(i+1)-1,ports+abits*i), in.bits(data_end-1,data_beg))
        }
        val read = mem.read(in.bits(ports+abits*(i+1)-1,ports+abits*i)+1.U, true.B)
        Mux(in.bits(i), read, in.bits(data_end-1,data_beg))
      }
    ).toVector
    out.bits := Cat(Cat(data).asUInt,in.bits(inCtrl-1,0))
  }

  if (memType%3 == 1) {
    val abits = (inCtrl-1)/1
    val mem = SyncReadMem(2048<<complexity/*depth*/, UInt(((inWidth/32+1)*32).W))
    val data = (
      for (i <- 0 until 1) yield {
        val data_beg = inCtrl+(i+0)*(inWidth-inCtrl)/1
        val data_end = inCtrl+(i+1)*(inWidth-inCtrl)/1
        when (in.valid && in.bits(i)) {
          mem.write(in.bits(1+abits*(i+1)-1,1+abits*i), in.bits(data_end-1,data_beg))
        }
        val read = mem.read(in.bits(1+abits*(i+1)-1,1+abits*i)+1.U, true.B)
        Mux(in.bits(i), read, in.bits(data_end-1,data_beg))
      }
    ).toVector
    out.bits := Cat(Cat(data).asUInt,in.bits(inCtrl-1,0))
  }

  if (memType%3 == 2) {
    val abits = (inCtrl-1)/1
    val mem = SyncReadMem(2048<<complexity/*depth*/, UInt(((inWidth/64+1)*64).W))
    val data = (
      for (i <- 0 until 1) yield {
        val data_beg = inCtrl+(i+0)*(inWidth-inCtrl)/1
        val data_end = inCtrl+(i+1)*(inWidth-inCtrl)/1
        when (in.valid && in.bits(i)) {
          mem.write(in.bits(1+abits*(i+1)-1,1+abits*i), in.bits(data_end-1,data_beg))
        }
        val read = mem.read(in.bits(1+abits*(i+1)-1,1+abits*i)+1.U, true.B)
        Mux(in.bits(i), read, in.bits(data_end-1,data_beg))
      }
    ).toVector
    out.bits := Cat(Cat(data).asUInt,in.bits(inCtrl-1,0))
  }
}
