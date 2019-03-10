#include "../headers/Memory.h"

#include "../libs/catch.hpp"

SCENARIO("Memory created without initial value", "[Memory]") {

  Memory mock(10);

  WHEN("value is written") {
    mock.write(2, 15); 

    THEN("should see the new value") {
      
      REQUIRE( mock.read(2) == 15 );
    }

    WHEN("address is locked") {
      mock.lockMem(2); 

      THEN("should not be able to reassign") {

        REQUIRE( mock.write(2, 22) == false);
        REQUIRE( mock.read(2) == 15);
      }

      WHEN("address is unlocked and value is changed") {
       
        mock.unlockMem(2);
        mock.write(2, 12);

        THEN("the change should take effect") {

          REQUIRE( mock.read(2) == 12);
        }
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
