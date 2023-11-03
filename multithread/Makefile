SHELL=/bin/bash

CXX := g++
CXXFLAGS := -std=c++20 -Wpedantic -g

BUILD_FOLDER := ./build

SOURCES := $(shell find . -name '*.cpp')

# find headers
HEADERS := $(shell find . -name '*.h')

OUTPUT_DIR := ./build
OUTPUT := multi

all: $(OUTPUT)

$(OUTPUT): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(OUTPUT_DIR)/$(OUTPUT)

clean:
	rm -rf $(OUTPUT_DIR)/$(OUTPUT)