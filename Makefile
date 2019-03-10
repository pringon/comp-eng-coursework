CC = g++
CFLAGS = -g -Wall -I .
TARGET = cpu

FILES = $(TARGET).cpp sources/InstructionRegister.cpp \
				sources/Memory.cpp sources/ALU.cpp


all: $(TARGET)

$(TARGET): 	$(FILES)
	$(CC) $(CFLAGS) $(FILES) -o $(TARGET)

clean:
	$(RM) $(TARGET)