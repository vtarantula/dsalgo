# Compiler and compiler options
CC = g++
CC_FLAGS = -std=c++17 -g -Wall -pedantic -I include

# File names
CURRENT_DIR := $(shell basename $(CURDIR))

EXEC = $(CURRENT_DIR)
SOURCES = $(wildcard src/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

# Main target
$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC)

# To obtain object files
%.o: %.cpp
	$(CC) -c $(CC_FLAGS) $< -o $@

# To remove generated files
clean:
	rm -f $(EXEC) $(OBJECTS)

