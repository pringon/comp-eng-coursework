#include <iostream>

#include "headers/InstructionRegister.h"
#include "headers/Register.h"
#include "headers/Memory.h"

int main(int argc, char* argv[]) {

  InstructionRegister taskRunner;
  taskRunner.loadInstructions(argv[1]);

  while(taskRunner.programRunning()) {

    switch(instructions[programCounter].opcode) {
      case "ADD":
        break;
      case "ADDI":
        break;
      case "SUB":
        break;
      case "SUBI":
        break;
      case "LOAD":
        break;
      case "STORE":
        break;
      case "BNE":
        break;
      case "BEZ":
        break;
    }
  }

  return 0;
}
