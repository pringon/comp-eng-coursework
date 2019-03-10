#include "../headers/ALU.h";

ALU::add(int operand1, int operand2) {
  return operand1 + operand2;
}

ALU::sub(int* target, int operand1, int operand2) {
  return operand1 - operand2;
}