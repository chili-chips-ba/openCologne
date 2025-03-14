FAMILY  = artix7
PART    = xc7a100tcsg324-2
#xc7a200tffg1156
BOARD   = arty
PROJECT = TestPipeline

SCALA_SOURCES= \
../../queue/NodeQueue.scala \
../../mux/NodeMux.scala \
../../mux/NodeDemux.scala \
../../math/NodeMul.scala \
../../math/NodeDiv.scala \
../../decode/NodeMap.scala \
../../memory/NodeMemory.scala \
../../common/AttributeAnnotation.scala \
../NodeFabric.scala \
../XDCGen.scala

TestPipeline:
	mkdir -p ../../chipdb
	scala-cli $(SCALA_SOURCES) TestPipeline.scala $< -- $(PROJECT) $(PART) $(PRJXRAY_DB_DIR)/$(FAMILY)/$(PART)/$(xc7a100tcsg324-2) 5 8 128 500

include ../openXC7.mk
