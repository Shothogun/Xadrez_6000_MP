#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "tree.hpp"

TEST_CASE ("Construtor") {
  chess::Tree<int> tree;
  SECTION ( "Função size") {
    CHECK (tree.size() == 0);
  }
}

TEST_CASE("Inserir raiz") {
  chess::Tree<int> tree;
  tree.insertRoot(0);
  SECTION ("Ver se o tamanho da árvore é 1 e contém o item certo") {
    CHECK (tree.size() == 1);
    CHECK (tree.item() == 0);
  }
  tree.insertRoot(1);
  SECTION ("Sobreposição de inserção de raízes deve resultar em uma nova árvore") {
    CHECK (tree.size() == 1);
    CHECK (tree.item() == 1);
  }
}
