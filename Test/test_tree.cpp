#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "tree.hpp"

TEST_CASE("Construtor") {
  SECTION("Test part of the function") {
    CHECK("Check something");
    CHECK_THROWS("Check trows of something");
  } // SECTION
} // TEST_CASE
