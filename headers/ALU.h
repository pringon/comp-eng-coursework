#ifndef ALU_H
#define ALU_H

class ALU {

private:
  ALU() {}  

public:
  static bool add(int operand1, int operand2);
  static bool sub(int operand1, int operand2);
};

#endif