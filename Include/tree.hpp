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
/**
*Metodo Tree()
*
*Descrição:
* Cria uma estrutura de dados chamada Tree que tem como parametros um ponteiro para a raiz da árvore, um
*inteiro que indica a quantidade de nós presentes na árvore e um iterador que se move pela árvore conforme a 
*necessidade.
* Apos a criação, colocamos o ponteiro para a raiz apontando para NULL, atribuimos o valor 0 para a variavel size 
*e o iterador está apontado para NULL.
*
*Parametros:
* O metodo Tree não possui parametros de entradas.
*
*Valor de retorno:
* O metodo Tree retorna uma estrutura de dados do tipo Tree com o parametro root e It apontando para NUUL e o inteiro 
*size com o valor 0,
*
*Assertiva de entrada:
*
*Assertiva de saida:
* A estrutura de dados chamada Tree vai ser alocada.
* A raiz tem valor NULL.
* O tamanho da árvore é 0.
* O iterador aponta para NULL.
*
*Interfaces explicitas:
*
*Interfaces implicitas:
*/
  Tree();
/**
* Método Tree( const Tree& other)
*
* Descrição:
*   Esse metodo cria uma árvore a partir de outra árvore já existente, fazendo uma copia de todos os nós e todo
* o conteudo da outra árvore
*
* Parametros:
*   Esse método recebe como parametro a árvore que será clonada na outra árvore
*
* Valor retornado:
*   Esse método não retorna nenhum valor
* Assertiva de entrada:
*   A árvore que será feita uma cópia dela deve existir
*
* Assertiva de saída:
*   Uma árvore terá sido criada e ela será uma cópia da outra árvore
*
* Interfaces explicitas:
*   const Tree& other
* Interfaces implicitas:
*/
  Tree(const Tree& other);
/**
* Método ~Tree()
*
* Descrição:
*   O metodo libera a memória da de todos os nós presentes na Tree
* 
* Parametros:
*   O metodo não possui parametros
* 
* Valor retornado:
*   O metodo retorna void
*
* Assertiva de entrada:
*   A árvore deve estar alocada na memória
* 
* Assertiva de saída:
*   Todos os nós da árvore serão desalocados
* 
* Interfaces explicitas:
*   A arvore Tree
* Interfaces implicitas:
*/
  ~Tree();
/**
*Método size()
*
*Descrição:
* Metodo que retorna o valor do tamanho da árvore.
*
*Parametros:
* O metodo size() não possui parametros.
*
*Valor Retornado:
* A função retorna o tamanho da árvore.
*
*Assertivas de entrada:
* 
*Assertivas de saída:
*
*Interfaces explicitas:
* Tree
*
*Interfaces inplicitas: 
*/
  int size() const;
/**
* Metodo ItemNode
*
* Descrição:
*   O método retorna referência para o item do nó cujo iterador da árvore está apontando
*
* Parametros:
*   O método não possui parâmetros
*
* Valor retornado:
*   Referência para o item do nó cujo iterador da árvore está apontando
*
* Assertiva de entrada:
*
* Assertiva de saída:
*
* Interfaces explicitas:
*
* Interfaces implicitas:
*/
  Item& itemNode();

/**
* Metodo ItemNode
*
* Descrição:
*   O método retorna referência para o item do nó cujo iterador da árvore está apontando
*
* Parametros:
*   O método não possui parâmetros
*
* Valor retornado:
*  Uma referência constante para o item do nó cujo iterador da árvore está apontando
*
* Assertiva de entrada:
*
* Assertiva de saída:
*
* Interfaces explicitas:
*
* Interfaces implicitas:
*/
  const Item& itemNode() const;
/**
* Metodo isRootNode()
*
* Descrição:
*   O método retorna um valor indicando se o nó cujo método foi aplicado é um nó raiz ou não
*
* Parametros:
*   O método acima não possui parametros
* 
* Valor retornado:
*   Esse método retorna True caso o nó cujo método foi aplicado seja uma raiz e retorna False caso contrário
*
* Assertiva de entrada:
*   O nó cujo método foi aplicado precisa estar alocado na memória
*
* Assertiva de saída:
*   Se o nó for raiz da arvore o método retornará True e caso contrário retornará False
*
* Interfaces explicitas:
*   Arvore Tree
*   Node
*
* Interfaces implicitas:
*/
  bool isRootNode() const;
/**
* Método numSonsNode()
*
* Descrição:
*   O método irá retornar o número de filhos do nó cujo o iterador está
 apontando. Caso o iterador não esteja apontando para nenhum nó, em caso de árvore vazia, retorna-se -1.
*
* Parametros:
* Valor retornado:
*
* Assertiva de entrada:
*
* Assertiva de saída:
*
* Interfaces explicitas:
*
* Interfaces implicitas:
*/
  int numSonsNode() const;
/**
*Metodo gotoDadNode()
*
*Descrição:
* A partir do iterador da Tree que estará apontado para um nó da árvore esse método irá fazer com que o iterador da árvore vá 
*para o pai do nó apontado por ele
*
*Parametros:
* Esse método não possui parametros
*
*Valor retornado:
* Esse método retorna True caso tenha conseguido mover o iterador e False caso não tenha conseguido
*
*Assertiva de entrada:
*
*Assertiva de saída:
* O iterador da Tree está apontando para o nó desejado
*
*Interfaces explicitas:
* Tree
*
*Interfaces implicitas:
*/
  bool gotoDadNode() const;
  /**
*Metodo gotoSonNode()
*
*Descrição:
* A partir do iterador da Tree que estará apontando para um nó da árvore esse método irá fazer com que o iterador da árvore va
*para o N-esimo filho do nó que estava sendo apontado pelo iterador.
* Se o nó apontado pelo iterador tiver menos que N filhos, então o método irá retornar false
*
*Parametros:
* Son - Numero da posição do filho no vetor de filhos
*
*Valor retornado:
* Retorna True caso o iterador tenha conseguido ir para o N-esimo filho pedido e retorna False caso não tenha conseguido
*
*Assertivas de entrada:
* Para o iterador se mover para o N-esimo filho do nó é necessário que esse nó tenha no mínimo N filhos
*
*Assertivas de saida:
* O iterador da Tree está apontando para o nó desejado
*
*Interfaces explicitas:
* long int Son
* Tree
*
*Interfaces implicitas:
*/
  bool gotoSonNode(int num_son) const;
/**
* Metodo gotoRootNode()
*
* Descrição:
*   O método faz com que o iterador da Tree vá para a raiz dessa árvore, retornando um valor de acordo com o resultado do método
*
* Parâmetros:
*   O método não possui parâmetros
*
* Valor retornado:
*   O método retorna True caso tenha conseguido mover o iterador para a raiz da árvore e retorna False caso contrário
*
* Assertiva de entrada:
*   A árvore cujo método foi aplicado deve possuir raiz
*
* Assertiva de saída:
*   Ao final do método o iterador da árvore estará apontando para a raiz da mesma
*
* Interfaces explicitas:
*   Tree
*   Iterador
*
* Interfaces implicitas:
*/
  bool gotoRootNode() const;
/**
*Método insertRoot()
*
*Descrição:
* Se a estrutura Tree em que o método foi aplicado não ṕossui raiz, então alocamos memória para uma raiz, configuramos o item dela 
*para ser o item passado como parametro, o pai dela como sendo NULL e inicializamos o vetor dos filhos sem elementos
* Se a estrutura Tree em que o método foi aplicado possui raiz, então a árvore com essa raiz é apagada e aplicamos o metodo novamente
*a essa árvore que agora tem a raiz igual a NULL
*
*Parametros:
* Item - Uma estrutura do tipo Item que representa o item guardado no nó
*
*Valor Retornado:
* O Método não retorna nenhum valor
*
*Assertivas de entrada:
*
*Assertivas de saída:
* A raiz da Tree cujo método fo aplicado foi criada
* raiz.item_ = Item
* raiz.dad = NULL
* raiz.sons está vazio
*
*Interfaces explicitas
* Item Item_
* Tree
*
*Interfaces implicitas
*/
  void insertRoot(const Item& item);
/**
*Metodo insertSonNode()
*
*Descrição:
* A partir do iterador da Tree que estará apontando para um nó dela iremos criar um nó novo e adicionaremos ele na lista dos filhos
*do nó apontado pelo iterador.
* Ao criarmos esse novo nó, iremos fazer com que o item desse nó seja o item passado como parametro, o pai desse nó seja o nó
* apontado pelo iterador e o vetor de filhos desse nó seja inicializado mas esteja vazio
* Caso a árvore esteja vazia e o iterador aponta para NULL, criamos uma raiz.
*
*Parametros:
* Item - Uma estrutura do tipo Item que representa o item guardado no nó
*
*Valor Retornado:
* O Método não retorna nenhum valor
*
*Assertivas de entrada:
*
*Assertivas de saída:
* O nó da Tree cujo método fo aplicado foi criado
* node.item_ = Item
* node.dad = Iterator
* node.sons está vazio
*
*Interfaces explicitas
* Tree
* Item Item_
*
*Interfaces implicitas
*/
  void insertSonNode(const Item& item);
/**
*Metodo removeNode()
*
*Descrição:
* A partir do iterador da Tree que estará apontando para um nó na árvore esse método irá desalocar a memória de toda a subárvore que
*possui como raiz o nó passado pelo iterador e irá fazer com que esse iterador aponte para o pai da raiz da subárvore apagada
*
*Parametros:
* Esse método não possui parametros
*
*Valor retornado:
* Esse método não retorna nenhum valor
*
*Assertivas de entrada:
* O iterador da árvore deve está apontando para um nó da árvore
*
*Assertivas de saida:
* Toda a subárvore que possuia o nó apontado pelo iterador foi desalocada da memória
*
*Interfaces explicitas:
* Tree
*
*Interfaces implicitas:
*/
  void removeNode();
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
    Node* node_;  /// Poiter to the current node.
    std::stack<Edge> path_;  /// Path from the root node to the current node.
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
