# Makefile for building the examples distributed 
# with libsetila.

# List of source files
SOURCES += mcp9808_example.cpp

#List of object files
OBJECTS += $(SOURCES:.cpp=.o)

#Compile all of the source files
%.o: %.cpp
	@echo Compiling file: $<
	g++ -std=c++0x -O0 -Wall -c -fmessage-length=0 "$^" -o "$@"
	@echo

#Building the binary
mcp9808_example: mcp9808_example.o
	@echo Building target file: $@.
	g++ -o $@ $^ -Wl,-Bdynamic -lsetila -lm
	@echo

.PHONY: clean

clean:
	rm -f *.o mcp9808_example

