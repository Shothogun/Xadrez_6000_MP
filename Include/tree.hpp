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
  Item& item();
  const Item& item() const;
  bool isRoot() const;
  int numSons() const;
  bool gotoDad() const;
  bool gotoSon(int num_son) const;
  bool gotoRoot();
  void insertRoot(const Item& item);
  void insertSon(const Item& item);
private:
  /** Estrutura que guarda os itens contidos na árvore e serve de conector entre
  os nós da árvore.
  */
  struct Node {
    Item item_;  /// Item holded by the node.
    std::vector<Node*> sons_;  /// Array of poiters to the sons of the node.
  }; // struct Node
  /** Estrutura que guarda informação sobre uma aresta percorrida pelo
  iterator.
  */
  struct Edge {
    Node* dad_; /// Nó pai da aresta.
    int num_son_;  /// Número do filho para o qual o itearador foi.
  }; // struct Edge
  /** Estrutura que pode se mover pelos nós da árvore.
  */
  struct Iterator {
    Node* current_;  /// Poiter to the current node.
    std::stack<Edge> path_;  /// Path from the root node to the current node.
  }; // struct Iterator
private:
  /** Deletar todos os nós a partir do \var src e diminuir tamanho da árvore.
  @param src   Nó que será ponto de origen da limpeza da função.
  */
  void deleteNode(Node* src);
private:
  Node* root_;  /// Raiz da árvore.
  int size_;   /// Número de itens da árvore.
  mutable Iterator iterator_;  /// Iterador que se move pela árvore.
};


template <class Item>
Tree<Item>::Tree() :
  root_(nullptr), size_(0) {
  iterator_.current_ = nullptr;
} // Tree::Tree()

template <class Item>
Tree<Item>::~Tree() {
  if (root_ != nullptr)
    deleteNode(root_);
}

template <class Item>
int Tree<Item>::size() const {
  return size_;
}  // size()

template <class Item>
Item& Tree<Item>::item() {
  return iterator_.current_->item_;
} // Tree::item()

template <class Item>
const Item& Tree<Item>::item() const {
  return iterator_.current_->item_;
} // Tree::item()

template <class Item>
bool Tree<Item>::isRoot() const {
  if (iterator_.current_ != nullptr && iterator_.path_.size() == 0)
    return true;
  else
    return false;
} // isRoot()

template <class Item>
int Tree<Item>::numSons() const {
  if (iterator_.current_ == nullptr)
    return -1;
  else
    return iterator_.current_->sons_.size();
}

template <class Item>
bool Tree<Item>::gotoDad() const {
  if (iterator_.path_.size() == 0)
    return false;
  iterator_.current_ = iterator_.path_.top().dad_;
  iterator_.path_.pop();
  return true;
}
template <class Item>
bool Tree<Item>::gotoSon(int num_son) const {
  if (iterator_.current_ == nullptr)
    return false;
  if (num_son < 0 || num_son >= iterator_.current_->sons_.size())
    return false;
  Edge edge = {iterator_.current_, num_son};
  iterator_.current_ = iterator_.current_->sons_[num_son];
  iterator_.path_.push(edge);
  return true;
}

template <class Item>
void Tree<Item>::insertRoot(const Item& item) {
  if (root_ != nullptr)
    deleteNode(root_);
  root_ = new   Node;
  root_->item_ = item;
  ++size_;
  iterator_.current_ = root_;
} // insertRoot()

template <class Item>
void Tree<Item>::insertSon(const Item& item) {
  if (iterator_.current_ == nullptr) {
    insertRoot(item);
    return;
  } // if (iterator_.current_ == nullptr)
  Node* son_node = new Node;
  son_node->item_ = item;
  iterator_.current_->sons_.push_back(son_node);
  ++size_;
} // Tree::insertSon()

// private methods /////////////////////////////////////////////////////////////

template <class Item>
void Tree<Item>::deleteNode(Node* src) {
  for (int son = 0; son < src->sons_.size(); ++son)
    deleteNode(src->sons_[son]);
  delete src;
  --size_;
} // Tree::deleteNode()

} // namespace chess
#endif // TREE_HPP_
