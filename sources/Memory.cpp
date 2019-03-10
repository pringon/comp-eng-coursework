#include "../headers/Memory.h"

#include <iostream>

Memory::Memory(int size, int valueToInitialize/* = 0 */) {
  
  mem = new int[size];
  this->size = size;

  for(int i = 0; i < size; i++) {
    mem[i] = 0;
  }
}

Memory::~Memory() {

  delete [] mem;
}

int Memory::read(int address) {

  if (address >= size) {
    std::cout<<"Index error: address out of bounds";
    return -1;
  }

  return mem[address];
}

bool Memory::write(int address, int value) {

  if (address >= size) {
    std::cout<<"Index error: address out of bounds";
    return false;
  }

  mem[address] = value;

  return true;
}

void Memory::logAll() {

  std::cout<<"Logging all words from memory.\n";
  for(int i = 0; i < size; i++) {
    std::cout<<i<<": "<<mem[i]<<'\n';
  }
}