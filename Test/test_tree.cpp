#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "tree.hpp"

TEST_CASE ("Construtor") {
  chess::Tree<int> tree;
  SECTION ( "Função size") {
    CHECK (tree.size() == 0);
  }
}

TEST_CASE ("Inserir raiz") {
  chess::Tree<int> tree;
  tree.insertRoot(0);
  SECTION ("Arvore apenas contém o item 0 em sua raiz") {
    CHECK (tree.size() == 1);
    CHECK (tree.item() == 0);
  }
  tree.insertRoot(1);
  SECTION ("Sobreposição de inserção de raízes deve resultar em uma nova árvore") {
    CHECK (tree.size() == 1);
    CHECK (tree.item() == 1);
  }
}

TEST_CASE ("Inserir filho na raiz") {
  chess::Tree<int> tree;
  tree.insertSon(0);
  SECTION("Deve haver apenas um item '0' na raiz") {
    CHECK (tree.size() == 1);
    CHECK (tree.item() == 0);
  }
  tree.insertSon(10);
  SECTION ("Tamnho da árvore deve ser 2 e o item do primeiro filho deve ser 10") {
    CHECK (tree.size() == 2 );
  }
}
