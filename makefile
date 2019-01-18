CPP = g++ -std=c++11
CPPFLAGS = -g -Wall -Werror -pedantic -ansi
EXE = bin/analog
INT = 
REAL = $(INT:.h=.cpp)

all:
	$(ECHO) "- all     : Display this message"
	$(ECHO) "- debug   : Build debug version of <$(EXE)>"
	$(ECHO) "- release : Build release version of <$(EXE)>"
	$(ECHO) "- clean   : Delete all generated files"

debug:
	$(ECHO) "Build debug version of <$(EXE)>"
	$(CPP) $(CPPFLAGS) -o $(EXE) $(INT) $(REAL)

release:
	$(ECHO) "Build release version of <$(EXE)>"
	$(CPP) -o $(EXE) $(INT) $(REAL)

clean:
	rm -f $(EXE)