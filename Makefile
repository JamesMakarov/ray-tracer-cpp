CXX ?= g++
CXXFLAGS ?= -std=c++17 -O2 -Wall -Wextra -pedantic
TARGET := ray-tracer
SOURCE := src/main.cpp

.PHONY: all test render clean

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) -Iinclude $(SOURCE) -o $(TARGET)

test:
	$(CXX) $(CXXFLAGS) -Iinclude tests/test_math.cpp -o test-math
	./test-math
	rm -f test-math

render: $(TARGET)
	mkdir -p output
	printf '%s\n' -1 | ./$(TARGET) > output/imagem.ppm

clean:
	rm -f $(TARGET) ray-tracer.exe test-math
