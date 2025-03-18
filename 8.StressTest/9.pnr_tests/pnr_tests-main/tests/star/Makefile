FAMILY  = colognechip
PART    = CCGM1A1
#xc7a100tcsg324-2
#xc7a200tffg1156
BOARD   = GateMateA1-EVB
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
../CCFGen.scala

TestStar:
	mkdir -p ../../chipdb &> /dev/null
	scala-cli $(SCALA_SOURCES) TestStar.scala $< -- $(PROJECT) $(PART) $(PRJXRAY_DB_DIR)/$(FAMILY)/$(PART) 1 250 1 30 500

include ../config.mk