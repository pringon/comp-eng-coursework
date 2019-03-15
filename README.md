# Simple processor emulator for Computer Engineering Coursework.

## Build

- To run the build command present in the Makefile use the command:  
`$ make`

##  Usage

`$ ./cpu CODE [-debug] [-v]`

### Description
- ./cpu - path to executable
- CODE - file containing the code you want to run
- -debug - enables debug mode
- -v - enables verbose output in debug mode

### Features
- All the opcodes you will need to write some cool assembly programs (refer to opcodes section).
- Allows writting comments in your assembly code.

### Opcodes

- ADD
- ADDI
- SUB
- SUBI
- MUL
- MULI
- DIV
- DIVI
- LOAD
- STORE
- BNE
- BEZ
- BGE
- BLE
- PRINT

## Test

- Command to build test suite is also present in the Makefile.
- All you have to do is:  
`$ make test`  
`$ ./test-suite`