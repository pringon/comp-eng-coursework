#include "headers/CPU.hpp"

int main(int argc, char* argv[]) {

  std::string instructionsFile;
  std::string mode;

  if (argv[1]) {
    instructionsFile = argv[1];
  } else {
    std::cout<<"Fatal error: no instructions provided.";
    exit(1);
  }

  if (argv[2]) {
    mode = argv[2];
    mode.erase(0, 1);
  } else {
    mode = "normal";
  }

  CPU cpu(instructionsFile, mode);
  cpu.run();

  return 0;
}
