CPP = g++
CPPFLAGS = -g -Wall -Werror -pedantic -ansi -std=c++11
EXE = TP4
INT = 
REAL = $(INT:.h=.cpp)
OBJ = $(REAL:.cpp=.o)


