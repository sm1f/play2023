################################################################################
# Makefile for building calibrate.
################################################################################

# Include the predefined MRCAS make environment
include $(RIOS_ROOT)/MakeIncludeDefs

# Local Definitions
LOCAL_LIBS   =  -lTestUtils -lTaskManagement -lLogger -lRIOSException
LOCAL_CFLAGS =
BIN          = testApp
SOURCES      = $(wildcard *.cpp)

# Local rules
all: default-bin-all test
clean: test-clean

test: default-bin-all

test-clean:
	$(shell find . -name \*.o -exec rm {} \;)
	$(shell find . -name \*~ -exec rm {} \;)
	$(shell find . -name \*.gcda -exec rm {} \;)
	$(shell find . -name \*.gcno -exec rm {} \;)
	rm ./${BIN} || true

run-tests: test
	./${BIN}

shared-test: default-bin-all

# Include the default-* rules
include $(RIOS_ROOT)/MakeDefaultRules
