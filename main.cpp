#include "headers/CPU.hpp"

int main(int argc, char* argv[]) {

  std::string instructionsFile;
  std::string mode;
  bool verbose = false;

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

  if (argv[3] && !strcmp(argv[3], "-v")) {
    verbose = true;
  }

  CPU cpu(instructionsFile, mode, verbose);
  cpu.run();

  return 0;
}
