#include "../headers/CPU.hpp"
#include "../headers/ALU.hpp"

CPU::CPU(std::string instructionsFile, std::string mode/* = normal */) {

  taskRunner = new InstructionRegister();
  mainMem = new Memory(100000);
  registers = new Memory(31);

  registers->lockMem(0);
  taskRunner->loadInstructions(instructionsFile);
  this->mode = mode;

  std::cout<<"Started emulation in "<<mode<<" mode"<<std::endl;
}

void CPU::logInstruction(Instruction* instruction) {
  
      std::cout<<"Performing "<<instruction->opcode<<".\n";
     
      std::vector<int>::iterator argsIt = instruction->arguments.begin();

      std::cout<<"Arguments: ";
      while (argsIt != instruction->arguments.end()) {

        std::cout<<*(argsIt++)<<' ';
      }
      std::cout<<std::endl;
}

void CPU::run() {

  while(taskRunner->programRunning()) {

    Instruction *currentInstruction = taskRunner->nextInstruction();
    std::string opcode = currentInstruction->opcode;
    std::vector<int> arguments = currentInstruction->arguments;

    if (mode == "debug") {
      logInstruction(currentInstruction);
    }

    if (!opcode.compare("ADD")) {
      registers->write(
              arguments[0],
              ALU::add(
                      registers->read(arguments[1]),
                      registers->read(arguments[2])
              )
      );
    } else if (!opcode.compare("ADDI")) {
      registers->write(
              arguments[0],
              ALU::add(
                      registers->read(arguments[1]),
                      arguments[2]
              )
      );
    } else if (!opcode.compare("SUB")) {
      registers->write(
              arguments[0],
              ALU::sub(
                      registers->read(arguments[1]),
                      registers->read(arguments[2])
              )
      );
    } else if (!opcode.compare("SUBI")) {
      registers->write(
              arguments[0],
              ALU::sub(
                      registers->read(arguments[1]),
                      arguments[2]
              )
      );
    } else if (!opcode.compare("MUL")) {
      registers->write(
              arguments[0],
              ALU::multiplty(
                      registers->read(arguments[1]),
                      registers->read(arguments[2])
              )
      );
    } else if(!opcode.compare("DIV")) {
      registers->write(
              arguments[0],
              ALU::divide(
                      registers->read(arguments[1]),
                      registers->read(arguments[2])
              )
      );
    } else if (!opcode.compare("LOAD")) {
      registers->write(
              arguments[0],
              mainMem->read(registers->read(arguments[1]))
      );
    } else if (!opcode.compare("STORE")) {
      mainMem->write(
              registers->read(arguments[1]),
              arguments[0]
      );
    } else if (!opcode.compare("BNE")) {
      if (registers->read(arguments[0]) != 0) {
        taskRunner->branch(arguments[1]);
      }
    } else if (!opcode.compare("BEZ")) {
      if (registers->read(arguments[0]) == 0) {
        taskRunner->branch(arguments[1]);
      }
    } else if (!opcode.compare("BGE")) {
      if (registers->read(arguments[0]) >= registers->read(arguments[1])) {
        taskRunner->branch(arguments[2]);
      }
    } else if (!opcode.compare("BLE")) {
      if (registers->read(arguments[0]) <= registers->read(arguments[1])) {
        taskRunner->branch(arguments[2]);
      }
    } else if(!opcode.compare("PRINT")) {

      std::cout<<"Value in register "<<arguments[0];
      std::cout<<": "<<registers->read(arguments[0])<<".\n";
    } else if(!opcode.compare("DUMP")) {
      registers->logAll();
    } else {
      std::cout<<"Error: Instruction not implemented";
    }
  }
}