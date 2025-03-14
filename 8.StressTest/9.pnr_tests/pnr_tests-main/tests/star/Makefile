FAMILY  = artix7
PART    = xc7a100tcsg324-2
#xc7a200tffg1156
BOARD   = arty
PROJECT = TestStar

SCALA_SOURCES= \
../../queue/NodeQueue.scala \
../../mux/NodeMux.scala \
../../mux/NodeDemux.scala \
../../math/NodeMul.scala \
../../math/NodeDiv.scala \
../../decode/NodeMap.scala \
../../memory/NodeMemory.scala \
../../common/AttributeAnnotation.scala \
../Crossbar.scala \
../NodeFabric.scala \
../XDCGen.scala

TestStar:
	mkdir -p ../../chipdb
	scala-cli $(SCALA_SOURCES) TestStar.scala $< -- $(PROJECT) $(PART) $(PRJXRAY_DB_DIR)/$(FAMILY)/$(PART)/$(xc7a100tcsg324-2) 1 250 1 30 500

include ../openXC7.mk
