# Makefile

FILES = AbstractNode.cpp PackageIdentifierNode.cpp DeclarationNode.cpp NonTerminalNode.cpp TerminalNode.cpp FuncIdentifierNode.cpp  NumberNode.cpp VariableNode.cpp BinaryNode.cpp Lexer.c Parser.c Expression.c main.c
CC	= clang++
CFLAGS = `llvm-config --cxxflags --ldflags --system-libs --libs all` -std=c++11 -g -fexceptions
BisonParser: $(FILES)
		$(CC) $(FILES) $(CFLAGS) -o BisonParser

Lexer.c: Lexer.l 
	flex Lexer.l

Parser.c: Parser.y Lexer.c
	bison Parser.y
clean:
	rm -f *.o *~ Lexer.c Lexer.h Parser.c Parser.h BisonParser TreeTest
