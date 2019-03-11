#include "../headers/InstructionRegister.hpp"

#include "../libs/catch.hpp"

SCENARIO("Basic instruction register functioning", "[InstructionRegister]") {

  InstructionRegister taskRunner;

  WHEN("file provided doesn't exist") {

    REQUIRE( taskRunner.loadInstructions("./not-here.txt") == false );

    THEN("execution will not start") {

      taskRunner.startExecution();
      REQUIRE( taskRunner.programRunning() == false );
      REQUIRE( taskRunner.nextInstruction() == NULL );
    }
  }

  WHEN("file provided exists") {

    REQUIRE( taskRunner.loadInstructions("./testFile.txt") == true );

    THEN("execution can start") {

      taskRunner.startExecution();
      REQUIRE( taskRunner.programRunning() == true );
      REQUIRE( taskRunner.nextInstruction() != NULL );
    }
  }
}