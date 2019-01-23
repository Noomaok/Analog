CPP = g++ -std=c++11
CPPFLAGS = -g -Wall -Werror -pedantic -ansi #-DMAP
EXE = bin/analog
INT = $(wildcard src/*.h)
REAL = $(INT:.h=.cpp)
ECHO = @echo

all:
	$(ECHO) "- all     : Display this message"
	$(ECHO) "- debug   : Build debug version of <Analog>"
	$(ECHO) "- release : Build release version of <Analog>"
	$(ECHO) "- clean   : Delete all generated files"

debug:
	@ mkdir -p bin
	$(ECHO) "Build debug version of <$(EXE)>"
	@ $(CPP) $(CPPFLAGS) -o $(EXE) $(REAL)
	$(ECHO) "Running <$(EXE)>"
	@ ./$(EXE) -g tmp/graphTest.dot tmp/court.log

release:
	@ mkdir -p bin
	$(ECHO) "Build release version of <$(EXE)>"
	@ $(CPP) -o $(EXE) $(REAL)
	$(ECHO) "Running <$(EXE)>"
	@ ./$(EXE) tmp/court.log

clean:
	rm -f $(EXE)
