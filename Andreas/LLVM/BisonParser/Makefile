# Makefile
FLEXFILES = Lexer.l
BISONFILES = Parser.y
CPPFILES = $(FLEXFILES:.l=.cpp)
CPPFILES :=	$(BISONFILES:.y=.cpp) $(CPPFILES)
CPPFILES := $(CPPFILES) $(wildcard *.cpp)
OBJFILES = $(CPPFILES:.cpp=.o)
CC= clang++
CFLAGS = `llvm-config --cxxflags --ldflags --system-libs --libs all` -std=c++11 -g -fexceptions

BisonParser: $(OBJFILES)
		$(CC) $^ $(CFLAGS) -o BisonParser

%.o: %.cpp
		$(CC) -std=c++11 -g -c $^ 

Lexer.cpp Parser.cpp: Lexer.l Parser.y
	flex Lexer.l;
	bison Parser.y;

#Parser.cpp: Parser.y Lexer.cpp
#	bison Parser.y

clean:
	rm -f *.o *~ Lexer.cpp Lexer.h Parser.cpp Parser.h BisonParser
