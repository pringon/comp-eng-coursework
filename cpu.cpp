#include <iostream>

#include "headers/InstructionRegister.h"
#include "headers/Memory.h"
#include "headers/ALU.h"

int main(int argc, char* argv[]) {

  InstructionRegister taskRunner;
  // Main memory of the processor.
  Memory mainMem(100000);
  // Registers that operations will be performed on.
  // First register always has a value of 0.
  Memory registers(31);

  taskRunner.loadInstructions(argv[1]);

  while(taskRunner.programRunning()) {

    Instruction currentInstruction = taskRunner.nextInstruction();
    std::vector<int> arguments = currentInstruction.arguments;

    switch(currentInstruction.opcode) {
      case "ADD":
        ALU.add(
          registers.write(
            arguments[0],
            ALU.add(
              registers.read(arguments[1]),
              registers.read(arguments[2])
            )
          );
        break;
      case "ADDI":
        ALU.add(
          registers.write(
            arguments[0],
            ALU.add(
              registers.read(arguments[1]),
              arguments[2]
            )
          );
        break;
      case "SUB":
        ALU.add(
          registers.write(
            arguments[0],
            ALU.sub(
              registers.read(arguments[1]),
              registers.read(arguments[2])
            )
          );
        break;
      case "SUBI":
        ALU.add(
          registers.write(
            arguments[0],
            ALU.sub(
              registers.read(arguments[1]),
              arguments[2]
            )
          );
        break;
      case "LOAD":
        registers.write(
          arguments[0],
          registers.read(arguments[1])
        );
        break;
      case "STORE":
        registers.write(
          registers.read(arguments[1]),
          arguments[0]
        );
        break;
      case "BNE":
        if (registers.read(arguments[0]) != 0) {
          taskRunner.branch(arguments[1]-1);
        }
        break;
      case "BEZ":
        if (registers.read(arguments[0]) == 0) {
          taskRunner.branch(arguments[1]-1);
        }
        break;
      case "DUMP":
        break;
    }
  }

  return 0;
}
