

CC=clang++
CFLAGS=--std=c++11
LEX=flex
YACC=bison
YFLAGS=-v -d
# lexer Name
LEXER=lexer
# Parser Name
PARSER=Parser

all: $(LEXER).cpp $(PARSER).cpp
	$(CC) $(CFLAGS) -o $(PARSER) $(PARSER).cpp $(LEXER).cpp 

$(LEXER).cpp:
	$(LEX) -o $(LEXER).cpp $(LEXER).ll

$(PARSER).cpp :
	$(YACC) $(PARSER).yy

ParseTree: ParseTree.h ParseTree.cpp 
	$(CC) -o ParseTree ParseTree.cpp
clean:
	$(RM) $(LEXER).cpp $(LEXER) $(PARSER) $(PARSER).cpp $(PARSER).h ParseTree
