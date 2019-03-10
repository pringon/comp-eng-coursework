#include <iostream>
#include <cstring>

#include "headers/InstructionRegister.h"
#include "headers/Memory.h"
#include "headers/ALU.h"

void logInstruction(Instruction* instruction) {

      std::cout<<"Performing an "<<instruction->opcode<<".\n";
     
      std::vector<int>::iterator argsIt = instruction->arguments.begin();

      std::cout<<"Arguments: ";
      while (argsIt != instruction->arguments.end()) {

        std::cout<<*(argsIt++)<<' ';
      }
      std::cout<<std::endl;
}

int main(int argc, char* argv[]) {

  InstructionRegister taskRunner;
  // Main memory of the processor.
  Memory mainMem(100000);
  // Registers that operations will be performed on.
  // First register always has a value of 0.
  Memory registers(31);

  taskRunner.loadInstructions(argv[1]);
  bool debugMode = false;
  if(!strcmp(argv[2], "-debug")) {
    std::cout<<"Start emulation in debug mode."<<std::endl;
    debugMode = true;
  }

  while(taskRunner.programRunning()) {

    Instruction* currentInstruction = taskRunner.nextInstruction();
    std::string opcode = currentInstruction->opcode;
    std::vector<int> arguments = currentInstruction->arguments;

    if (debugMode) {
      logInstruction(currentInstruction);
    }

    if (!opcode.compare("ADD")) {
      registers.write(
        arguments[0],
        ALU::add(
          registers.read(arguments[1]),
          registers.read(arguments[2])
        )
      );
    } else if(!opcode.compare("ADDI")) {
      registers.write(
        arguments[0],
        ALU::add(
          registers.read(arguments[1]),
          arguments[2]
        )
      );
    } else if(!opcode.compare("SUB")) {
      registers.write(
        arguments[0],
        ALU::sub(
          registers.read(arguments[1]),
          registers.read(arguments[2])
        )
      );
    } else if(!opcode.compare("SUBI")) {
      registers.write(
        arguments[0],
        ALU::sub(
          registers.read(arguments[1]),
          arguments[2]
        )
      );
    } else if(!opcode.compare("LOAD")) {
      registers.write(
        arguments[0],
        registers.read(arguments[1])
      );
    } else if(!opcode.compare("STORE")) {
      registers.write(
        registers.read(arguments[1]),
        arguments[0]
      );
    } else if(!opcode.compare("BNE")) {
      if (registers.read(arguments[0]) != 0) {
        taskRunner.branch(arguments[1]-1);
      }
    } else if(!opcode.compare("BEZ")) {
      if (registers.read(arguments[0]) == 0) {
        taskRunner.branch(arguments[1]-1);
      }
    } else {
      std::cout<<"Error: Instruction not implemented";
    }
  }

  return 0;
}
