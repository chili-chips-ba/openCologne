package PnrTests

import chisel3._
import chisel3.util._

class NodeQueue(memType: Int, inCtrl: Int, inWidth: Int, outCtrl: Int, outWidth: Int, complexity: Int) extends Module {

  val in = IO(Flipped(Decoupled(UInt(inWidth.W))))
  val out = IO(Decoupled(UInt(outWidth.W)))

  val numQueues = memType+1
  val queues = Array.fill(numQueues)(Module(new Queue(UInt(inWidth.W), 2<<complexity)))

  queues(0).io.enq <> in
  queues(0).io.enq.valid := in.valid && in.bits(0)
  for (i <- 0 until queues.length-1) {
    queues(i+1).io.enq <> queues(i).io.deq
  }
  out <> queues(numQueues-1).io.deq
}
