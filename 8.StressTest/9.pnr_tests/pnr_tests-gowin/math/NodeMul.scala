package PnrTests

import chisel3._
import chisel3.util._

import chisel3.experimental.ChiselAnnotation
import chisel3.experimental.annotate

class NodeMul(mulType: Int, inCtrl: Int, inWidth: Int, outCtrl: Int, outWidth: Int, complexity: Int) extends Module {

  val in = IO(Flipped(Decoupled(UInt(inWidth.W))))
  val out = IO(Decoupled(UInt(outWidth.W)))

  val in_reg = Reg(UInt(inWidth.W))
  val out_reg = Reg(UInt(outWidth.W))

  var complexity1 = complexity
  if (mulType%2 == 0) {
    annotate(new ChiselAnnotation {
        def toFirrtl = firrtl.AttributeAnnotation(in_reg.toTarget, "use_dsp = \"no\"")
      })
    annotate(new ChiselAnnotation {
        def toFirrtl = firrtl.AttributeAnnotation(out_reg.toTarget, "use_dsp = \"no\"")
      })
  }
  else {
    complexity1 += 5
  }

  out.bits := out_reg  // using regs to avoid long math chains
  in_reg := in.bits

  in.ready := true.B
  out.valid := true.B
  out_reg := Cat((in_reg>>inCtrl)*(in_reg((complexity-3) max 1,0)), in_reg(outCtrl-1,0))  // types 0 and 1

  if (mulType >= 2) {
    val data = (
    for (i <- 0 until 4) yield {
      val region_beg = inCtrl+i*(inWidth-inCtrl)/4
      val region_end = inCtrl+(i+1)*(inWidth-inCtrl)/4
      in_reg(region_end-1,region_beg)*in_reg(complexity,0)
    }).toVector
    out_reg := Cat(Cat(data).asUInt,in.bits(outCtrl-1,0))
  }

  if (mulType >= 4) {
    val width = 2<<complexity1
    val data = (
    for (i <- 0 until 1+(inWidth-inCtrl)/width) yield {
      val size = width min (inWidth-inCtrl)
      (in_reg>>(inCtrl+i*size))*(in_reg>>(inCtrl+i*size))
    }).toVector
    out_reg := Cat(Cat(data).asUInt,in.bits(outCtrl-1,0))
  }

  out.bits := out_reg  // using regs to avoid long math chains

}
