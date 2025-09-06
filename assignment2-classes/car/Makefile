# Compiler and flags
CXX      := g++
CXXFLAGS := -Wall -Werror -std=c++17 -Iinc

# Project structure
SRC  := src/main.cpp src/car.cpp
OBJ  := $(SRC:.cpp=.o)
OUT  := car_program

# Default target
all: build run

# Build only
build: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(OUT) $(OBJ)

# Pattern rule for objects
src/%.o: src/%.cpp inc/car.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run only
run:
	./$(OUT)

# Clean build artifacts
clean:
	rm -f $(OBJ) $(OUT)
