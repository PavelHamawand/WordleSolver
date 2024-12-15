# Compiler and flags
CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror
INCLUDE = -I src

# Directories
SRC_DIR = src
TEST_DIR = test

# Targets
TARGET = wordle_solver
TEST_TARGET = test_main
UTILS_TEST_TARGET = test_utils

# Source files
SRC_FILES = $(SRC_DIR)/wordle.cc $(SRC_DIR)/utils.cc
MAIN_SRC = $(SRC_DIR)/main.cc
TEST_SRC = $(TEST_DIR)/test_main.cc
UTILS_TEST_SRC = $(TEST_DIR)/test_utils.cc

# Build the main program
all: $(TARGET)

$(TARGET): $(MAIN_SRC) $(SRC_FILES)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $(TARGET) $(MAIN_SRC) $(SRC_FILES)

# Build the test program for do_filter
test: $(TEST_SRC) $(SRC_FILES)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $(TEST_TARGET) $(TEST_SRC) $(SRC_FILES)

# Build the test program for utils
test_utils: $(UTILS_TEST_SRC) $(SRC_FILES)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $(UTILS_TEST_TARGET) $(UTILS_TEST_SRC) $(SRC_FILES)

# Clean up build artifacts
clean:
	rm -f $(TARGET) $(TEST_TARGET) $(UTILS_TEST_TARGET)