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

/** Uma árvore enraizada que contém um iterador pelos nós que pode conter
 variadas quantidades de filhos por nó.
@details
  A Classe contém um um ponteiro para um nó raiz e um ponteiro iterador para o
nó em que este se presencia. Inicinalmente o ponteiro par a raiz da árvore e
o ponteiro do iterador apontam para o null e assim que se insere uma raiz para
a árvore, o iterador se move para o nó raiz e o ponteiro da raiz da árvore
aponta para a raiz. O iterador pode se mover pela árvore livremente o que é
importante para que o usuário possa exercer funções como acessar os itens da
árvore.
@tparam Item
  Tipo do item que será manipulado pelos nós das árvores.
*/
template <class Item>
class Tree {
public:
  /** Configura a raiz e o iterador apontados para null e zera o tamanho da
    árvore.
  @post
    Variável criada possui raiz e iterador apontados para null e possui tamanho
  iual a 0.
  */
  Tree();

  /** Criar uma árvore a partir de outra árvore já existente, fazendo uma cópia
    de todos os nós e itens, além da posição do iterador.
  @param other
    Árvore a ser clonada.
  @pre
    \var other deve ser uma árvore existente com memória alocada corretamente.
  @post
    A variável que utilizar esse método será terá memória corretamente alocada,
  sendo uma cópia da árvore \var other.
  @post
    O iterador da nova árvore estará na mesma posição relativa comparado ao
  iterador da árvore \var other.
  */
  Tree(const Tree& other);

  /** Libera a memória da de todos os nós presentes na Tree.
  @pre
    A árvore deve estar alocada na memória.
  @post
    A memória da árvore se torna desalocada.
  */
  ~Tree();

  /** Retorna o valor do tamanho da árvore.
  @return
    Número de itens armazenados na árvore.
  */
  int size() const;

  /** Recuperar referência para o item do nó em que o iterador se encontra.
  @return
    Referência para o item do nó apontado pelo iterador.
  @pre
  A memória da árvore deve estar alocada,
  @pre
  O iterador deve estar numa posição válida de um nó.
  @post
  A árvore não é modificada nessa função.
  */
  Item& itemNode();

  /** Recuperar referência para o item do nó em que o iterador se encontra.
  @return
    Referência constante para o item do nó apontado pelo iterador.
  @pre
  A memória da árvore deve estar alocada,
  @pre
  O iterador deve estar numa posição válida de um nó.
  @post
  A árvore não é modificada nessa função.
  */
  const Item& itemNode() const;

  /** Descobre se o iterador está no nó que é raiz.
  @return
    true, caso o nó apontado pelo iterador seja raiz. false, caso o nó apontado
  pelo itrador não seja raiz.
  @pre
    A árvore deve estar alocada na memória.
  @pre
    O nó apontado pelo iterador existe e pertence a árvore.
  */
  bool isRootNode() const;

  /** Recupera o número de filhos do nó em que o iterador se posiciona.
  @return
    O número de nós filhos que o iterador da árvore se encontra. Ou, caso o
  iterador aponte para null no caso de uma árvore vazia, retorna-se o valor -1.
  @pre
    A memoria da árvore deve estar corretamente alocada.
  */
  int numSonsNode() const;

  /** Mover o iterador de um nó para seu pai na árvore.
  @return
    true caso foi possível mover o iterador de sua posição atual para o
  seu pai. false, caso o iterador esteja posicionado em uma raiz ou esteja
  apontado para null, sendo assim, não se encontra em um nó que contém pais.
  @pre
  A memória da árvore deve estar alocada corretamente.
  @post
  O iterador foi movido para o nó pai, caso este exista.
 */
  bool gotoDadNode() const;

  /** Move o iterador do nó em que se encontra para o filho escolhido do nó.
  @param num_son
    Um natural indicando a qual dos nós filhos deseja-se mover o iterador da
  árvore.
  @return
    true caso foi possível mover o iterador do nó atual para o filho \var
  num_son. false caso o nó em que se encontra o iterador não possua o filho
  desejado ou o iterador está apontado para null.
 @pre
    A memória da árvore precisa estar alocada corretamente.
  @post
    A estrura da árvore se mantém, mudando-se apenas a posição do iterador para
  o filho desejado caso seja possível movê-lo.
  */
  bool gotoSonNode(int num_son) const;

  /** Retornar o iterador da árvore para a raiz caso essa exista.
  @return
     true, se a árvore possui uma raiz.
     false, se a árvore está vazia.
  @pre
    A memória da árvore deve estar alocada corretamente.
  @post
    O iterador da árvore estará na posição da raiz caso esta exista.
  */
  bool gotoRootNode() const;

  /** Insere-se um nó guardando um item na raiz da árvore.
  @details
    Se a estrutura Tree não ṕossui raiz, então aloca-se memória para um nó raiz.
  Já se a árvore já possuir uma raiz, retira-se todos os itens da árvore para
  inserir uma nova raiz com um novo item.
  @param item
    Item a ser guardado pela raiz da árvore.
  @pre
    A memória da árvore deve estar corretamente alocada.
  @post
    A árvore possuirá apenas uma raiz que conterá uma cópia de \var item. O
  iterador da árvore se encontrará na raiz.
  */
  void insertRoot(const Item& item);

  /** A partir do nó em que se encontra o iterador, insere-se um novo filho
    armazenando uma cópia de um item.
  @details
    Caso o iterador esteja posicionado em um nó da árvore, cria-se um novo nó
  contendo uma cópia de \var item e posiciona-se este nó como sendo o último
  filho do nó em que se encontra o iterador. Nos casos em que a árvore é vazia e
  o iterador aponta para null, cria-se uma raiz com esse memso item.
  @param item
    Item que deverá ter uma cópia armazenada pelo novo nó.
  @pre
    A memoria da árvore deve estar corretamente alocada.
  @post
    Caso a árvore não possua nós, cria-se uma raiz para ela contendo a cópia do
  \var item, senão, cria-se um nó filho na última posição do nó em que se
  encontra o iterador que contenha uma cópia de \var item.
  */
  void insertSonNode(const Item& item);

  /** Retira-se todos os nós contidos na sub-árvore que tem como raiz o nó em que
    se encontra o iterador e move-se o iterador para o antigo pai do nó.
  @details
    Sendo o nó do iterador uma raiz de uma sub-árvore, retira-se todos os nós
  contidos nesta e move-se o iterador para o pai da raiz da sub-árvore excluída.
  Se a raiz da sub-árvore for também raiz da árvore, exclui-se toda a árvore e o
  iterador apontará para null.
  @pre
    A memória da árvore deve esta corretamente alocada.
  @pre
    O iterador deve estar em algum nó existente da árvore. Sendo assim, a árvore
  não pode estar vazia.
  @post
    A árvore terá a sub-árvore dada como raiz o nó em que se situa o iterador
  excluída e o pai da sub-árvore excluida terá um filho a menos e os filhos que
  estavam numa posição posterior em relação a sub-árvore excluída, terão suas
  posições decrescidas de um termo. Exemplo: o filho 2 que teve o irmão 0
  excluído, agora será o filho 1. Caso o nó em que se situava o iterador fosse
  a raiz da árvore, a árvore fica vazia e tem seu iterador apontado para null.
  */
  void removeNode();

  /** Copia o conteúdo de uma árvore para outra.
  @details
    Copia os itens contidos em uma outra árvore em suas respectivas posições
  para a árvore além de copiar a posição do iterador na árvore. Os itens
  antigos da árvore que chama o método são excluídos.
  @param other
    Árvore a ser copiada.
  @pre
    Tanto a árvore a ser copiada quanto a árvore que chama o método, devem ter
  memória corretamente alocada.
  @post
    A árvore que chama o método é uma cópia de \var other.
  */
  Tree& operator=(const Tree& other);

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
    Node* node_;  /// Ponteiro para posição do iterador na árvore.
    std::stack<Edge> path_;  /// Caminho percorrido pelo iterador desde a raiz
                             /// até a posição do iterador na árvore.
  }; // struct Iterator
private:

  /** Deletar todos os nós a partir do \var src e diminuir tamanho da árvore.
  @param src   Nó que será ponto de origen da limpeza da função.
  */
  void deleteNode(Node* src);

  /** Copiar nó com todos seus descendentes, acrescentando valor ao tamanho da
  árvore.
  @param src Raiz da subárvore a ser copirada.
  @return Ponteiro para a raiz da sub-árvore criada.
  */
  Node* copyNode(Node* src);

private:
  Node* root_;  /// Raiz da árvore.
  int size_;   /// Número de itens da árvore.
  mutable Iterator iterator_;  /// Iterador que se move pela árvore.
};


template <class Item>
Tree<Item>::Tree() :
  root_(nullptr), size_(0) {
  iterator_.node_ = nullptr;
} // Tree::Tree()

template <class Item>
Tree<Item>::Tree(const Tree& other) :
  root_(nullptr), size_(0) {
  if (other.root_ == nullptr) {
    iterator_.node_ = nullptr;
    return;
  } // if (other.root_ == nullptr)
  root_ = copyNode(other.root_);
  iterator_.node_ = root_;
  // Copy iterator position;
  iterator_.path_ = other.iterator_.path_;
  std::vector<int> inverse_path;
  while (iterator_.path_.size() > 0) {
    inverse_path.push_back(iterator_.path_.top().num_son_);
    iterator_.path_.pop();
  }
  for (int deep = inverse_path.size() - 1; deep >= 0 ; --deep)
    this->gotoSonNode(inverse_path[deep]);
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
Item& Tree<Item>::itemNode() {
  return iterator_.node_->item_;
} // Tree::itemNode()

template <class Item>
const Item& Tree<Item>::itemNode() const {
  return iterator_.node_->item_;
} // Tree::itemNode()

template <class Item>
bool Tree<Item>::isRootNode() const {
  if (iterator_.node_ != nullptr && iterator_.path_.size() == 0)
    return true;
  else
    return false;
} // isRootNode()

template <class Item>
int Tree<Item>::numSonsNode() const {
  if (iterator_.node_ == nullptr)
    return -1;
  else
    return iterator_.node_->sons_.size();
}

template <class Item>
bool Tree<Item>::gotoRootNode() const {
  if (root_ == nullptr)
    return false;
  iterator_.node_ = root_;
  iterator_.path_ = std::stack<Edge>();
  return true;
}

template <class Item>
bool Tree<Item>::gotoDadNode() const {
  if (iterator_.path_.size() == 0)
    return false;
  iterator_.node_ = iterator_.path_.top().dad_;
  iterator_.path_.pop();
  return true;
}
template <class Item>
bool Tree<Item>::gotoSonNode(int num_son) const {
  if (iterator_.node_ == nullptr)
    return false;
  if (num_son < 0 || num_son >= iterator_.node_->sons_.size())
    return false;
  Edge edge = {iterator_.node_, num_son};
  iterator_.node_ = iterator_.node_->sons_[num_son];
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
  iterator_.node_ = root_;
} // insertRoot()

template <class Item>
void Tree<Item>::insertSonNode(const Item& item) {
  if (iterator_.node_ == nullptr) {
    insertRoot(item);
    return;
  } // if (iterator_.node_ == nullptr)
  Node* son_node = new Node;
  son_node->item_ = item;
  iterator_.node_->sons_.push_back(son_node);
  ++size_;
} // Tree::insertSonNode()

template <class Item>
void Tree<Item>::removeNode() {
  if (iterator_.node_ == nullptr)
    return;
  if (iterator_.node_ == root_) {
    deleteNode(iterator_.node_);
    root_ = nullptr;
    iterator_.node_ = nullptr;
  } else {
    deleteNode(iterator_.node_);
    iterator_.node_ = iterator_.path_.top().dad_;
    iterator_.node_->sons_.erase(iterator_.node_->sons_.begin()
                                 + iterator_.path_.top().num_son_);
    iterator_.path_.pop();
  } // if (iterator_.node_)
}

template <class Item>
Tree<Item>& Tree<Item>::operator=(const Tree& other) {
  if (this->root_ != nullptr) {
    deleteNode(root_);
    root_ = nullptr;
    iterator_.node_ = nullptr;
    while (iterator_.path_.size() > 0) iterator_.path_.pop();
  } // if (this->root != nullptr)
  if (other.root_ == nullptr)
    return *this;
  root_ = copyNode(other.root_);
  iterator_.node_ = root_;
  // Copy iterator position;
  iterator_.path_ = other.iterator_.path_;
  std::vector<int> inverse_path;
  while (iterator_.path_.size() > 0) {
    inverse_path.push_back(iterator_.path_.top().num_son_);
    iterator_.path_.pop();
  }
  for (int deep = inverse_path.size() - 1; deep >= 0 ; --deep)
    this->gotoSonNode(inverse_path[deep]);
  return *this;
} // Tree::=(other)

// private methods /////////////////////////////////////////////////////////////

template <class Item>
typename Tree<Item>::Node* Tree<Item>::copyNode(Node* src) {
  Node* copy = new Node;
  copy->item_ = src->item_;
  for (int son = 0; son < src->sons_.size(); ++son  )
    copy->sons_.push_back(copyNode(src->sons_[son]));
  size_++;
  return copy;
} // Tree::copyNode()

template <class Item>
void Tree<Item>::deleteNode(Node* src) {
  for (int son = 0; son < src->sons_.size(); ++son)
    deleteNode(src->sons_[son]);
  delete src;
  --size_;
} // Tree::deleteNode()

} // namespace chess
#endif // TREE_HPP_
