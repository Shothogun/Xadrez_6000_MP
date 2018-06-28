/** @file tree.hpp
 @author
   * Luigi Minardi Ferreira Maia
   * Danilo Raposo Freire Caldas
 @date 06/26/2018
 @brief Arquivo de contendo a implementação de uma árvore com implementação em
 meta-programação (template).
 @copyright GNU Public License.
*/

#ifndef TREE_HPP_
#define TREE_HPP_

#include <stack>
#include <vector>

namespace chess {

/** @brief
 *
 @tparam Item  Tipo do item que será manipulado pelos nós das árvores.
*/
template <class Item>
class Tree {
public:
  Tree();
  ~Tree();
  int size() const;
  const Item& item() const;
  Item& item();
  void insertRoot(const Item& item);
private:
  /** Strutura que guarda os itens contidos na árvore e serve de conector entre
  os nós da árvore.
  */
  struct Node {
    Item item_;  /// Item holded by the node.
    Node* dad_;  /// Dad of the node.
    std::vector<Node*> sons_;  /// Array of poiters to the sons of the node.
  }; // struct Node
  /** Estrutura que pode se mover pelos nós da árvore.
  */
  struct Iterator {
    Node* current_;  /// Poiter to the current node.
    std::stack<int> path_;  /// Path from the root node to the current node.
  }; // struct Iterator
private:
  /** Deletar todos os nós a partir do \var src e diminuir tamanho da árvore.
  @param src   Nó que será ponto de origen da limpeza da função.
  */
  void clearNodes(Node* src);
private:
  Node* root_;  /// Raiz da árvore.
  int size_;   /// Número de itens da árvore.
  Iterator iterator_;  /// Iterador que se move pela árvore.
};


template <class Item>
Tree<Item>::Tree() :
  root_(nullptr), size_(0) {
} // Tree::Tree()

template <class Item>
Tree<Item>::~Tree() {
  if (root_ != nullptr)
    clearNodes(root_);
}

template <class Item>
int Tree<Item>::size() const {
  return size_;
}  // size()

template <class Item>
const Item& Tree<Item>::item() const {
  return iterator_.current_->item_;
} // Tree::item()

template <class Item>
Item& Tree<Item>::item() {
  return iterator_.current_->item_;
} // Tree::item()

template <class Item>
void Tree<Item>::insertRoot(const Item& item) {
  if (root_ != nullptr)
    clearNodes(root_);
  root_ = new Tree<Item>::Node;
  root_->item_ = item;
  root_->dad_ = nullptr;
  ++size_;
  iterator_.current_ = root_;
  iterator_.path_ = std::stack<int>();
} // insertRoot()

template <class Item>
void Tree<Item>::clearNodes(Tree<Item>::Node* src) {
  for (int son = 0; son < src->sons_.size(); ++son)
    clearNodes(src->sons_[son]);
  delete src;
  --size_;
} // Tree::clearNodes()

} // namespace chess
#endif // TREE_HPP_
