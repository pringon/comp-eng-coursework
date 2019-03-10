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
    instruction.arguments.push_back(std::stoi(*(instructionIt++)));
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
    std::cout<<"Fatal error: no code in file: "<<fileName<<".\n";
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

  startExecution();

  return true;
}

bool InstructionRegister::instructionsLoaded() {
  if (instructions.size() <= 0) {

    std::cout<<"Error: you must first load instructions";
    return false;
  }
  return true;
}

void InstructionRegister::startExecution() {

  if(!instructionsLoaded()) {
    return;
  }

  programCounter = 0;
}

bool InstructionRegister::programRunning() {

  if (!instructionsLoaded()) {
    std::cout<<"Execution hasn't started"<<std::endl;
    return false;
  }

  if (programCounter < (int)(instructions.size())) {
    return true;
  }
  return false;
}

Instruction* InstructionRegister::nextInstruction() {

  if (!instructionsLoaded()) {
    return NULL;
  }

  return &instructions[programCounter++];
}

bool InstructionRegister::branch(int newLocation) {

  if (!instructionsLoaded()) {
    return false;
  }

  programCounter = newLocation;
  return true;
}