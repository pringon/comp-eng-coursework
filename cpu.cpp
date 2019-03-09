#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iterator>
#include <cstring>

#include "headers/InstructionRegister.h"
#include "headers/Register.h"
#include "headers/Memory.h"

Instruction parseInstruction(std::vector<std::string> rawInstruction) {

  Instruction instruction;
  std::vector<std::string>::iterator instructionIt = rawInstruction.begin();

  instruction.opcode = *(instructionIt++);

  while (instructionIt != rawInstruction.end()) {
    instruction.arguments.push_back(*(instructionIt++));
  }

  return instruction;
}

// Adapted from https://www.fluentcpp.com/2017/04/21/how-to-split-a-string-in-c/
std::vector<Instruction> parseCode(std::string fileName) {
  std::ifstream codeFile;

  codeFile.open(fileName);

  std::vector<Instruction> readInstructions;

  std::string line;
  std::getline(codeFile, line);
  if (!line.compare("")) {
    std::cout<<"Fatal error: no code in file.";
  }
  // Loop until end of file.
  do {
    std::istringstream iss(line);
    std::vector<std::string> rawInstruction(
      (std::istream_iterator<std::string>(iss)),
      std::istream_iterator<std::string>()
    );

    readInstructions.push_back(parseInstruction(rawInstruction));

    std::getline(codeFile, line);
  } while (line.compare(""));

  return readInstructions;
}

int main(int argc, char* argv[]) {

  parseCode(argv[1]);

  return 0;
}
