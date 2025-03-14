package PnrTests

import chisel3._
import chisel3.util._
import scala.util.Random

class NodeMap(mapType: Int, inCtrl: Int, inWidth: Int, outCtrl: Int, outWidth: Int, complexity: Int) extends Module {

  val in = IO(Flipped(Decoupled(UInt(inWidth.W))))
  val out = IO(Decoupled(UInt(outWidth.W)))

  val random = new Random()
  in.ready := true.B
  out.valid := true.B
  out.bits := Cat(MuxCase(in.bits,
    (for (i <- 0 until (1+mapType)*(2+complexity)) yield {
       val rnd = BigInt(random.nextInt((math.pow(2, inWidth-inCtrl).toInt)))
       (in.bits < rnd.U) -> ((in.bits>>inCtrl) | random.nextInt(math.pow(2, inWidth-inCtrl).toInt).U)
    }).toSeq
  ),in.bits(outCtrl-1,0))

  val cnt = 2*complexity
  if (cnt > 1 && (inWidth-inCtrl)/cnt > 5) {
    val data = (for (i <- 0 until cnt) yield {
      val region_beg = inCtrl+i*(inWidth-inCtrl)/cnt
      val region_end = inCtrl+(i+1)*(inWidth-inCtrl)/cnt
      MuxCase(in.bits(inCtrl-1,0),
        (for (i <- 0 until cnt) yield {
          (in.bits(region_end-1,region_beg) === random.nextInt(math.pow(2, region_end-region_beg).toInt).U) -> random.nextInt(math.pow(2, region_end-region_beg).toInt).U
        }).toSeq
      )
    }).toVector
    out.bits := Cat(Cat(data).asUInt,in.bits(outCtrl-1,0))
  }

}
