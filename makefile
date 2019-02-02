CPP = g++ -std=c++11
CPPFLAGS = -g -Wall -Werror -pedantic -ansi #-DMAP
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
	$(ECHO) "Build debug version of <$(EXE)>"
	@ $(CPP) $(CPPFLAGS) -o $(EXE) $(REAL)

release:
	@ mkdir -p bin
	$(ECHO) "Build release version of <$(EXE)>"
	@ $(CPP) $(OPTIMIZATION) -o $(EXE) $(REAL)

tests:
	@ cd Tests/ && ./mktest.sh

clean:
	@ rm -r $(BIN)/*
	$(ECHO) "Bin directory is now clean"
