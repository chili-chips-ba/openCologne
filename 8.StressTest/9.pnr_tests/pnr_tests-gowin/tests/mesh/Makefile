FAMILY  = GW2AR
PART    = 18CLQFP176
#xc7a200tffg1156
BOARD   = Tang Nano 20K
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
../CSTGen.scala

TestMesh:
	mkdir -p ../../chipdb &> /dev/null
	scala-cli $(SCALA_SOURCES) TestMesh.scala $< -- $(PROJECT) $(PART) $(PRJXRAY_DB_DIR)/$(FAMILY)/$(PART) 3 4 4 64 500

include ../config.mk
