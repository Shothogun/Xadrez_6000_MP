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
  tree.insertSonNode(0);
  tree.insertSonNode(10);
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

TEST_CASE ("Limpando nós") {
  chess::Tree<int> tree;
  SECTION ("Remover árvore sem nós") {
    tree.removeNode();
    CHECK (tree.isRootNode() == false);
    CHECK (tree.numSonsNode() == -1);
    CHECK (tree.gotoSonNode(0) == false);
    CHECK (tree.gotoDadNode() == false);
    CHECK (tree.gotoRootNode() == false);
  }
  tree.insertRoot(0);
  SECTION ("Remover raiz") {
    tree.removeNode();
    CHECK (tree.size() == 0);
    CHECK (tree.isRootNode() == false);
    CHECK (tree.numSonsNode() == -1);
    CHECK (tree.gotoSonNode(0) == false);
    CHECK (tree.gotoDadNode() == false);
    CHECK (tree.gotoRootNode() == false);
  }
  tree.insertSonNode(10);
  tree.gotoSonNode(0);
  SECTION ("Remover primeiro filho do nó raiz (nó nutella)") {
    tree.removeNode();
    CHECK (tree.size() == 1);
    CHECK (tree.itemNode() == 0);
    CHECK (tree.isRootNode() == true);
    CHECK (tree.numSonsNode() == 0);
    CHECK (tree.gotoDadNode() == false);
  }
}

TEST_CASE ("Copiando árvores") {
  chess::Tree<int> a;
  chess::Tree<int> b(a);
  SECTION ("Árvore 'b' tem de ser vazia assim como o 'a'") {
    CHECK (b.size() == 0);
    CHECK (b.isRootNode() == false);
    CHECK (b.numSonsNode() == -1);
    CHECK (b.gotoSonNode(0) == false);
    CHECK (b.gotoDadNode() == false);
    CHECK (b.gotoRootNode() == false);
  }
  a.insertRoot(0);
  a.insertSonNode(10);
  a.gotoSonNode(0);
  SECTION ("Árvore 'b' tem de ser independente da 'a'") {
    CHECK (b.size() == 0);
    CHECK (b.isRootNode() == false);
    CHECK (b.numSonsNode() == -1);
    CHECK (b.gotoSonNode(0) == false);
    CHECK (b.gotoDadNode() == false);
    CHECK (b.gotoRootNode() == false);
  }
  chess::Tree<int> c(a);
  SECTION ("A árvore 'c' deve ser identica ao 'a'") {
    CHECK (c.size() == 2);
    CHECK (c.isRootNode() == false);
    CHECK (c.numSonsNode() == 0);
    CHECK (c.gotoSonNode(0) == false);
    CHECK (c.itemNode() == 10);
    CHECK (c.gotoDadNode() == true);
    CHECK (c.itemNode() == 0);
  }
  chess::Tree<int> d;
  d = a;
  SECTION ("A árvore 'd' deve ser identica ao 'a'") {
    CHECK (d.size() == 2);
    CHECK (d.isRootNode() == false);
    CHECK (d.numSonsNode() == 0);
    CHECK (d.gotoSonNode(0) == false);
    CHECK (d.itemNode() == 10);
    CHECK (d.gotoDadNode() == true);
    CHECK (d.itemNode() == 0);
  }
  d = b;
  SECTION ("Árvore 'd' tem de ser vazia assim como o 'b'") {
    CHECK (d.size() == 0);
    CHECK (d.isRootNode() == false);
    CHECK (d.numSonsNode() == -1);
    CHECK (d.gotoSonNode(0) == false);
    CHECK (d.gotoDadNode() == false);
    CHECK (d.gotoRootNode() == false);
  }
}
