CXX := g++
CPPFLAGS := --std=c++20 -Wpedantic

BUILD_DIR := build

all: main.cpp | $(BUILD_DIR)
	$(CXX) $(CPPFLAGS) main.cpp -o $(BUILD_DIR)/zeroes

clean:
	rm -rf $(BUILD_DIR)/*

$(BUILD_DIR):
	mkdir -p $@