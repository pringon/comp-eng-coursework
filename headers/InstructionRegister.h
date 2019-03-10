#ifndef INSTRUCTION_REGISTER_H
#define INSTRUCTION_REGISTER_H

#include <string>
#include <vector>

typedef struct Instruction {
  std::string opcode;
  std::vector<int> arguments;
} Instruction;

class InstructionRegister {

private:
  std::vector<Instruction> instructions;
  bool debug;
  int programCounter;

  bool instrutionsLoaded();
  Instruction parseInstruction(std::vector<std::string> rawInstruction);

public:
  InstructionRegister();
  void enableDebug();
  bool loadInstructions(std::string fileName);
  void startExecution();
  bool programRunning();
  Instruction nextInstruction();
  bool branch(int newLocation);
};

#endif