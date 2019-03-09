CC = g++
CFLAGS = -g -Wall -I .
TARGET = cpu

FILES = $(TARGET).cpp sources/ProgramCounter.cpp \
				sources/Register.cpp sources/Memory.cpp


all: $(TARGET)

$(TARGET): 	$(FILES)
	$(CC) $(CFLAGS) $(FILES) -o $(TARGET)

clean:
	$(RM) $(TARGET)