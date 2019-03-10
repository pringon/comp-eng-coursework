#ifndef MEMORY_H
#define MEMORY_H

class Memory {

private:
  int *mem;
  bool *locked;
  int size;

public:
  Memory(int size, int valueToInitialize = 0);
  ~Memory();
  int read(int address);
  bool write(int address, int value);
  bool lockMem(int address);
  void logAll();
};

#endif
