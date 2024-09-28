# Makefile to compile bootchoice.c into bootchoice.exe

# Compiler
CC = gcc

# Output executable name. Add to system32 so it's in path
TARGET = C:/windows/system32/bootchoice.exe

# Source file
SRC = bootchoice.c

# Default rule to build the target
all: $(TARGET)

# Compile the source file to create the executable
$(TARGET): $(SRC)
	$(CC) -o $(TARGET) $(SRC)

# Clean up generated files
clean:
	rm -f $(TARGET)
