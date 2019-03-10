#include "../headers/ALU.h"
#include "../libs/catch.hpp"

SCENARIO("ALU perfoms operations correctly", "[ALU]") {

  WHEN("adding") {

    REQUIRE( ALU::add(2, 3) == 5 );
    REQUIRE( ALU::add(3, -12) == -9 );
    REQUIRE( ALU::add(-3, 12) == 9 );
    REQUIRE( ALU::add(-16, -23) == -39);
  }

  WHEN("subtracting") {


    REQUIRE( ALU::sub(3, 2) == 1 );
    REQUIRE( ALU::sub(2, 3) == -1 );
    REQUIRE( ALU::sub(3, -12) == 15 );
    REQUIRE( ALU::sub(3, 12) == -9 );
    REQUIRE( ALU::sub(-3, 12) == -15 );
    REQUIRE( ALU::sub(-16, -23) == 7);
  }
}