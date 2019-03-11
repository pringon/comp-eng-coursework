#include <iostream>
#include <cstring>

#include "InstructionRegister.hpp"
#include "Memory.hpp"

class CPU {

private:
  InstructionRegister* taskRunner;
  Memory* mainMem;
  Memory* registers;
  std::string mode;
  void logInstruction(Instruction* instruction);

public:
  CPU(std::string instructionsFile, std::string mode = "normal");
  void run();
};