#ifndef INSTRUCTION_REGISTER_H
#define INSTRUCTION_REGISTER_H

#include <string>
#include <vector>

typedef struct Instruction {
  std::string opcode;
  std::vector<std::string> arguments;
} Instruction;

class InstructionRegister {

private:
  std::vector<Instruction> instructions;
  bool debug;

  Instruction parseInstruction(std::vector<std::string> rawInstruction);

public:
  InstructionRegister();
  void enableDebug();
  bool loadInstructions(std::string fileName);
  bool executeInstructions();
};

#endif