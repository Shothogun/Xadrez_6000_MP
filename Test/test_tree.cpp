#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "tree.hpp"

TEST_CASE ("Construtor") {
  chess::Tree<int> tree;
  SECTION ( "Árvore vazia sem nenhum nó") {
    CHECK (tree.size() == 0);
    CHECK (tree.isRootNode() == false);
    CHECK (tree.numSonsNode() == -1);
    CHECK (tree.gotoSonNode(0) == false);
    CHECK (tree.gotoDadNode() == false);
    CHECK (tree.gotoRootNode() == false);
  }
}

TEST_CASE ("Inserir raiz") {
  chess::Tree<int> tree;
  tree.insertRoot(0);
  SECTION ("Arvore apenas contém o item 0 em sua raiz") {
    CHECK (tree.size() == 1);
    CHECK (tree.itemNode() == 0);
    CHECK (tree.isRootNode() == true);
    CHECK (tree.numSonsNode() == 0);
    CHECK (tree.gotoDadNode() == false);
  }
  tree.insertRoot(1);
  SECTION ("Sobreposição de inserção de raízes deve resultar em uma nova árvore") {
    CHECK (tree.size() == 1);
    CHECK (tree.itemNode() == 1);
    CHECK (tree.isRootNode() == true);
    CHECK (tree.numSonsNode() == 0);
  }
}

TEST_CASE ("Inserir filho na raiz") {
  chess::Tree<int> tree;
  tree.insertSon(0);
  tree.insertSon(10);
  SECTION ("Tamanho da árvore deve ser 2 e o item do primeiro filho deve ser 10") {
    CHECK (tree.size() == 2);
    CHECK (tree.gotoSonNode(-1) == false);
    CHECK (tree.gotoSonNode(0) == true);
    CHECK (tree.isRootNode() == false);
    CHECK (tree.itemNode() == 10);
    CHECK (tree.gotoDadNode() == true);
    CHECK (tree.itemNode() == 0);
    CHECK (tree.gotoRootNode() == true);
    CHECK (tree.itemNode() == 0);
  }
}

// falta testar is root quando estiver num nó que não for root.
