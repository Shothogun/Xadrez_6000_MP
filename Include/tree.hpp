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

namespace chess {

/** @brief
 *
 @tparam Item  Tipo do item que será manipulado pelos nós das árvores.
*/
template <class Item>
class Tree {
public:
  Tree();
  int size();
  void insertRoot(Item item);
protected:
  /** Classe que guarda os itens contidos na árvore e serve de conector entre
  os nós da árvore.
  */
  class Node {
    friend class Tree;
  public:
    Node(Item item);
  private:
    Item item_;
    std::vector<Node> sons_;
  }; // class Node
private:
  Node* root_;  /// Raiz da árvore.
  int size_;   /// Número de itens da árvore.
  Node* iterator_;  /// Iterador que se move pela árvore.
};

////////////////////////////////////////////////////////////////////////////////

template <class Item>
Tree<Item>::Tree() :
  root_(nullptr), size_(0), iterator_(nullptr) {}

template <class Item>
int Tree<Item>::size() {
  return size_;
}  // size()

template <class Item>
void Tree<Item>::insertRoot(Item item) {
  Tree<Item>::Node* node;
  if (root_ != nullptr) {
    root_->~Node();
  }
}

} // namespace chess
#endif // TREE_HPP_
