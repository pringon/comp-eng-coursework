#ifndef MEMORY_H
#define MEMORY_H

class Memory {

  int *mem;
  int size;

public:
  Memory(int size);
  ~Memory();
  bool read(int address, int* target);
  bool write(int address, int value);
};

#endif