#include "../headers/InstructionRegister.h"

#include <iostream>
#include <fstream>

#include <sstream>
#include <iterator>

InstructionRegister::InstructionRegister() {
  
  debug = false;
}

void InstructionRegister::enableDebug() {

  debug = true;
}

// Adapted from https://www.fluentcpp.com/2017/04/21/how-to-split-a-string-in-c/
Instruction InstructionRegister::parseInstruction(std::vector<std::string> rawInstruction) {

  Instruction instruction;
  std::vector<std::string>::iterator instructionIt = rawInstruction.begin();

  if(debug) {
    std::cout<<"Loading instruction: ";
    std::cout<<*instructionIt<<'\n';
  }
  instruction.opcode = *(instructionIt++);

  if(debug) {

    std::cout<<"Argumets: ";
  }
  while (instructionIt != rawInstruction.end()) {
    if(debug) {
      std::cout<<*instructionIt<<' ';
    }
    instruction.arguments.push_back(*(instructionIt++));
  }
  if(debug) {
    std::cout<<'\n';
  }

  return instruction;
}

bool InstructionRegister::loadInstructions(std::string fileName) {

  if(instructions.size() > 0) {
    instructions.clear();
  }

  std::ifstream codeFile;

  codeFile.open(fileName);

  std::string line;
  std::getline(codeFile, line);
  if (!line.compare("")) {
    std::cout<<"Fatal error: no code in file.";
    return false;
  }
  // Loop until end of file.
  do {
    std::istringstream iss(line);
    std::vector<std::string> rawInstruction(
      (std::istream_iterator<std::string>(iss)),
      std::istream_iterator<std::string>()
    );

    instructions.push_back(parseInstruction(rawInstruction));

    std::getline(codeFile, line);
  } while (line.compare(""));

  return true;
}

bool InstructionRegister::executeInstructions() {

  programSize = instructions.size();
  if (programSize <= 0) {
    std::cout<<"Error: you must first load instructions";
    return false;
  }

  int programCounter = 0;

  while(programCounter < programSize) {

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

  return true;
}