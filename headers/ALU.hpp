#ifndef ALU_H
#define ALU_H

class ALU {

private:
  ALU() {}  

public:
  static int add(int operand1, int operand2);
  static int sub(int operand1, int operand2);
  static int multiplty(int operand1, int operand2);
  static int divide(int operand1, int operand2);
};

#endif