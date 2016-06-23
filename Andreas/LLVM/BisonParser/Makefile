# Makefile
CPPFILES = $(wildcard *.cpp)
OBJFILES=$(wildcard *.o)
CC= g++
CFLAGS = `llvm-config --cxxflags --ldflags --system-libs --libs all` -std=c++11 -g -fexceptions


BisonParser: $(OBJFILES)
		$(CC) $(OBJFILES) -o BisonParser

$(OBJFILES): $(CPPFILES)
		$(CC) -c $(CFLAGS) $(CPPFILES)

Lexer.cpp: Lexer.l 
	flex Lexer.l

Parser.cpp: Parser.y Lexer.cpp
	bison Parser.y
clean:
	rm -f *.o *~ Lexer.cpp Lexer.h Parser.cpp Parser.h BisonParser
