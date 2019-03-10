#include "../headers/Memory.h"

#include "../libs/catch.hpp"

SCENARIO("Memory created without initial value", "[Memory]") {

  Memory mock(10);

  WHEN("value is written") {
    mock.write(2, 15); 

    THEN("should be able to read it") {

      REQUIRE( mock.read(2) == 15);
    }

    WHEN("Value is locked") {
      mock.lockMem(2); 

      THEN("should not be able to reassign") {

        REQUIRE( mock.write(2, 22) == false);
        REQUIRE( mock.read(2) == 15);
      }
    }
  }
}

SCENARIO("Memory created with initial value", "[Memory]") {

  Memory mock(10, 42);

  THEN("should be correctly initialised") {
    REQUIRE( mock.read(1) == 42 );
  }
}
