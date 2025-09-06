# Application target.
TARGET := app

# Source files.
SOURCE_FILES := source/lin_reg.cpp \
                source/main.cpp \

# Include directory.
INCLUDE_DIR := include

# Compiler flags.
COMPILER_FLAGS := -Wall -Werror -std=c++17

# Build and run the application as default.
default: build run

# Build the application.
build:
	@g++ $(SOURCE_FILES) -o $(TARGET) -I$(INCLUDE_DIR) $(COMPILER_FLAGS)

# Run the application.
run:
	@./$(TARGET)

# Clean the application.
clean:
	@rm -f $(TARGET)
