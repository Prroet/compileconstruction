CC := g++
CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))
LD_FLAGS :=
CC_FLAGS := -std=c++11
 
# rename main to program name for right output program name

bullshitCompiler: $(OBJ_FILES)
	$(CC) $(LD_FLAGS) -o bin/$@ $^

obj/%.o: src/%.cpp
	$(CC) $(CC_FLAGS) -c -o $@ $<

clean:
	rm -f bin/* obj/*
