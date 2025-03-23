FAMILY  = GW2AR
PART    = 18CLQFP176
#xc7a200tffg1156
BOARD   = Tang Nano 20K
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
../Crossbar.scala \
../CSTGen.scala

TestPipeline:
	mkdir -p ../../chipdb
	scala-cli $(SCALA_SOURCES) TestPipeline.scala $< -- $(PROJECT) $(PART) $(PRJXRAY_DB_DIR)/$(FAMILY)/$(PART) 5 8 128 500

include ../config.mk
