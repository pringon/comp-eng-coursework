#ifndef INSTRUCTION_REGISTER_H
#define INSTRUCTION_REGISTER_H

#include <string>
#include <vector>

typedef struct Instruction {
  std::string opcode;
  std::vector<std::string> arguments;
} Instruction;

class InstructionRegister {

public:
  InstructionRegister();
};

#endif