#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "tree.hpp"

TEST_CASE("Construtor") {
  chess::Tree<int> tree;
  SECTION("Função size") {
    CHECK(tree.size() == 0);
  }
}

TEST_CASE("Inserir raiz") {
  chess::Tree<int> tree;
  tree.insertRoot(0);
  SECTION("Função size") {
    CHECK(tree.size() == 1);
  }
}
