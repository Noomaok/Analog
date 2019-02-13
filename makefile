CPP = g++
CPPFLAGS = -g -Wall -Werror -pedantic -ansi -DSPEEDTEST #-DMAP std=c++11 has to be put in last
OPTIMIZATION = -O3
BIN = bin
EXE = $(BIN)/analog
INT = $(wildcard src/*.h)
REAL = $(INT:.h=.cpp) src/Analog.cpp
ECHO = @echo
.PHONY: clean tests

help:
	$(ECHO) "- help    : Display this message"
	$(ECHO) "- debug   : Build debug version of <Analog>"
	$(ECHO) "- release : Build release version of <Analog>"
	$(ECHO) "- tests   : Run all tests"
	$(ECHO) "- clean   : Delete binary files"

debug:
	@ mkdir -p bin
	$(ECHO) "Building debug version of <$(EXE)> ..."
	@ $(CPP) $(CPPFLAGS) -std=c++11 -o $(EXE) $(REAL)

release:
	@ mkdir -p bin
	$(ECHO) "Building release version of <$(EXE)> ..."
	@ $(CPP) $(OPTIMIZATION) -std=c++11 -o $(EXE) $(REAL)

tests:
	$(ECHO) "Running tests ..."
	@ cd Tests/ && ./mktest.sh

clean:
	@ rm -r $(BIN)/*
	$(ECHO) "Bin directory is now clean"
