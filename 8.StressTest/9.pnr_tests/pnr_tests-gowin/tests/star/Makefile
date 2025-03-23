AMILY  = GW2AR
PART    = 18CLQFP176
#xc7a200tffg1156
BOARD   = Tang Nano 20K
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
../CSTGen.scala

TestStar:
	mkdir -p ../../chipdb
	scala-cli $(SCALA_SOURCES) TestStar.scala $< -- $(PROJECT) $(PART) $(PRJXRAY_DB_DIR)/$(FAMILY)/$(PART) 1 250 1 30 500

include ../config.mk
