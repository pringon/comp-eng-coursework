CC = g++
CFLAGS = -g -Wall -I .
TARGET = cpu

MODULES = sources/InstructionRegister.cpp \
	  sources/Memory.cpp sources/ALU.cpp

TEST_FILES = tests/$(TARGET).cpp tests/ALU.cpp \
	     tests/Memory.cpp

all: $(TARGET)

$(TARGET): 	$(TARGET).cpp $(MODULES)
	$(CC) $(CFLAGS) $(TARGET).cpp $(MODULES) -o $(TARGET)

test: $(MODULES) $(TEST_FILES)
	$(CC) $(CFLAGS) $(MODULES) $(TEST_FILES) -o test-suite

clean:
	$(RM) $(TARGET)
	$(RM) test-suite
