#include "../headers/Memory.h"

#include <iostream>

Memory::Memory(int size) {
  
  mem = new int[size];
  this->size = size;
}

Memory::~Memory() {

  delete [] mem;
}

bool Memory::read(int address, int* target) {

  if (address >= size) {
    std::cout<<"Index error: address out of bounts";
    return false;
  }

  *target = mem[address];

  return true;
}

bool Memory:write(int address, int value) {

  if (address >= size) {
    std::cout<<"Index error: address out of bounds";
    return false;
  }

  mem[address] = value;

  return true;
}