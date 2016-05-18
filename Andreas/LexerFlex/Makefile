

CC=clang++
CFLAGS= -o
LEX=flex
YACC=bison
YFLAGS=-v -d
TARGET=lexer


all: $(TARGET).cc
	$(CC) $(CFLAGS) $(TARGET) $(TARGET).cc

$(TARGET).cc: $(TARGET).ll
	$(LEX) -o $(TARGET).cc $(TARGET).ll

clean:
	$(RM) $(TARGET).cc $(TARGET)
