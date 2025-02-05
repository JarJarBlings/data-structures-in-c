# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g -Iincludes -Iincludes/unity

# Directories
SRC_DIR = src/linked-list
BIN_DIR = bin/test-executables

# Source files
SRC_FILES = $(SRC_DIR)/linked_list.c $(SRC_DIR)/test_linked_list.c src/unity.c

# Output executable
TEST_EXEC = $(BIN_DIR)/test.exe

# Default target
all: $(TEST_EXEC)

# Ensure the binary directory exists
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Link all sources to create the executable
$(TEST_EXEC): $(SRC_FILES) | $(BIN_DIR)
	$(CC) $(CFLAGS) $(SRC_FILES) -o $(TEST_EXEC)

# Clean up object files and the executables
clean:
	rm -rf $(BIN_DIR)
	find . -name "*.o" -type f -delete

.PHONY: all clean
