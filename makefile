CPP = g++ -std=c++11
CPPFLAGS = -g -Wall -Werror -pedantic -ansi #-DMAP
EXE = bin/analog
INT = $(wildcard src/*.h) src/Analog.cpp
REAL = $(INT:.h=.cpp)
ECHO = @echo
.PHONY: clean tests

help:
	$(ECHO) "- help     : Display this message"
	$(ECHO) "- test     : Run mktest"
	$(ECHO) "- debug   : Build debug version of <Analog>"
	$(ECHO) "- release : Build release version of <Analog>"
	$(ECHO) "- clean   : Delete all generated files"

debug:
	@ mkdir -p bin
	$(ECHO) "Build debug version of <$(EXE)>"
	@ $(CPP) $(CPPFLAGS) -o $(EXE) $(REAL)

release:
	@ mkdir -p bin
	$(ECHO) "Build release version of <$(EXE)>"
	@ $(CPP) -o $(EXE) $(REAL)

tests:
	cd Tests/ && ./mktest.sh

clean:
	rm -f $(EXE)
