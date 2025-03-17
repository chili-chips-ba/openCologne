FAMILY  = colognechip
PART    = CCGM1A1
#xc7a100tcsg324-2
#xc7a200tffg1156
BOARD   = GateMateA1-EVB
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
../Crossbar.scala \
../NodeFabric.scala \
../CCFGen.scala

TestPipeline:
	mkdir -p ../../chipdb &> /dev/null
	scala-cli $(SCALA_SOURCES) TestPipeline.scala $< -- $(PROJECT) $(PART) $(PRJXRAY_DB_DIR)/$(FAMILY)/$(PART) 5 8 128 500

include ../config.mk