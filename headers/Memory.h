#ifndef MEMORY_H
#define MEMORY_H

class Memory {

  int *mem;
  int size;

public:
  Memory(int size, int valueToInitialize = 0);
  ~Memory();
  int read(int address);
  bool write(int address, int value);
};

#endif