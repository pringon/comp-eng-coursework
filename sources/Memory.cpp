#include "../headers/Memory.h"

#include <iostream>

Memory::Memory(int size, int valueToInitialize = 0) {
  
  mem = new int[size];
  mem = {0};
  this->size = size;
}

Memory::~Memory() {

  delete [] mem;
}

bool Memory::read(int address, int* target) {

  if (address >= size) {
    std::cout<<"Index error: address out of bounds";
    return false;
  }

  return mem[address];
}

bool Memory:write(int address, int value) {

  if (address >= size) {
    std::cout<<"Index error: address out of bounds";
    return false;
  }

  mem[address] = value;

  return true;
}