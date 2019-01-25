CPP = g++ -std=c++11
CPPFLAGS = -g -Wall -Werror -pedantic -ansi #-DMAP
EXE = bin/analog
INT = $(wildcard src/*.h) src/Analog.cpp
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

release:
	@ mkdir -p bin
	$(ECHO) "Build release version of <$(EXE)>"
	@ $(CPP) -o $(EXE) $(REAL)

clean:
	rm -f $(EXE)
