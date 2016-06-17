# Makefile

FILES = AbstractNode.cpp NonTerminalNode.cpp TerminalNode.cpp Lexer.c Parser.c Expression.c main.c
CC	= g++
CFLAGS = `llvm-config --ldflags --cxxflags` -std=c++11 -g 
BisonParser:		$(FILES)
		$(CC) $(CFLAGS) $(FILES) -o BisonParser

Lexer.c:	Lexer.l 
		flex Lexer.l

Parser.c:	Parser.y Lexer.c
		bison Parser.y
## make TreeTest 
TreeTest: AbstractNode.cpp TestNode.cpp
		$(CC) $(CFLAGS) AbstractNode.cpp TestNode.cpp nodetest.cpp -o TreeTest

clean:
		rm -f *.o *~ Lexer.c Lexer.h Parser.c Parser.h BisonParser TreeTest
