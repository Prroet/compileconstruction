# Makefile

FILES	= Lexer.c Parser.c Expression.c main.c
CC	= g++
CFLAGS	= -g -ansi

BisonParser:		$(FILES)
		$(CC) $(CFLAGS) $(FILES) -o BisonParser

Lexer.c:	Lexer.l 
		flex Lexer.l

Parser.c:	Parser.y Lexer.c
		bison Parser.y

TreeTest: AbstractNode.cpp TestNode.cpp
		$(CC) $(CFLAGS) nodetest.cpp AbstractNode.cpp TestNode.cpp -o TreeTest

clean:
		rm -f *.o *~ Lexer.c Lexer.h Parser.c Parser.h BisonParser TreeTest
