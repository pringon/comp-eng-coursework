#include <iostream>

#include "headers/InstructionRegister.h"
#include "headers/Register.h"
#include "headers/Memory.h"

int main(int argc, char* argv[]) {

  InstructionRegister reg;
  reg.loadInstructions(argv[1]);

  return 0;
}
