#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "tree.hpp"

TEST_CASE("Programação orientada a teste") {
  chess::Tree<int> tree;
  SECTION("Árvore vazia") {
    CHECK(tree.size() == 0);
  } // SECTION
} // TEST_CASE
