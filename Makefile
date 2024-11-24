# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++17 -g

# Directories (adjusting for your project location)
SRC_DIR = /Users/justinsmith/Documents/GitHub/blockchain/src
BUILD_DIR = /Users/justinsmith/Documents/GitHub/blockchain/build
EXEC = blockchain

# OpenSSL includes and libraries (adjust paths if needed)
OPENSSL_INCLUDE = /opt/homebrew/opt/openssl/include
OPENSSL_LIB = /opt/homebrew/opt/openssl/lib

# Source files and object files
SRC_FILES = $(wildcard $(SRC_DIR)/**/*.cpp) $(SRC_DIR)/main.cpp
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Default target to build the executable
all: $(BUILD_DIR)/$(EXEC)

# Rule to link object files into the executable
$(BUILD_DIR)/$(EXEC): $(OBJ_FILES)
	@mkdir -p $(BUILD_DIR)  # Ensure build directory exists
	$(CXX) $(CXXFLAGS) -o $@ $^ -L$(OPENSSL_LIB) -lssl -lcrypto

# Rule to compile source files into object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)  # Ensure the object file directory exists
	$(CXX) $(CXXFLAGS) -I$(OPENSSL_INCLUDE) -c $< -o $@

# Clean up build files
clean:
	rm -rf $(BUILD_DIR)

# Run the program
run: $(BUILD_DIR)/$(EXEC)
	$(BUILD_DIR)/$(EXEC)

.PHONY: all clean run
