FAMILY  = colognechip
PART    = CCGM1A1
#xc7a100tcsg324-2
#xc7a200tffg1156
BOARD   = GateMateA1-EVB
PROJECT = TestMesh

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

TestMesh:
	mkdir -p ../../chipdb &> /dev/null
	scala-cli $(SCALA_SOURCES) TestMesh.scala $< -- $(PROJECT) $(PART) $(PRJXRAY_DB_DIR)/$(FAMILY)/$(PART) 3 4 4 64 500
	
	#/$(CCGM1A1) 

include ../config.mk