

CC=clang++
CFLAGS= -o
LEX=flex
YACC=bison
YFLAGS=-v -d
# lexer Name
LEXER=lexer
# Parser Name
PARSER=Parser

all: $(LEXER).cpp $(PARSER).cpp
	$(CC) $(CFLAGS) $(PARSER) $(PARSER).cpp $(LEXER).cpp 

$(LEXER).cpp:
	$(LEX) -o $(LEXER).cpp $(LEXER).ll

$(PARSER).cpp :
	$(YACC) $(PARSER).yy

clean:
	$(RM) $(LEXER).cpp $(LEXER) $(PARSER) $(PARSER).cpp $(PARSER).h
