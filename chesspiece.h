#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <QDebug>
#include <iostream>
#include <list>
#include <utility>
#include <QPointF>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QMediaPlayer>
#include <QObject>

/*! Classe enumerada com as possíveis cores das peças */
enum class PieceColor { White, Black };
/*! Classe enumerada com os possíveis tipos das peças */
enum class PieceType { pawn, knight, bishop, rook, queen, king };

/*! Classe da Peça */
class Piece: public QGraphicsPixmapItem
{
public:

  PieceColor color; //!< Cor da peça
  PieceType type; //!< tipo da peça
	int weight; //!< Peso da peça
	QPointF position; //!< Posição atual da peça
  std::vector<QPointF> centers; //!< Vetor que guarda os centros das regiões
  bool first; // Variável para o peão, representa se é a primeira jogada ou não
  bool diagonal //!< Variável para o peão, representa se pode se movimentar à diagonal
	
  Piece(PieceColor c, PieceType p, int weight, QGraphicsItem* parent = 0); //!< Construtor da peça

  void setImage(PieceColor c, PieceType type); //!< Coloca a imagem da peça no tabuleiro
  void mousePressEvent(QGraphicsSceneMouseEvent* mouseEvent); //!< Cuida das ações ao clicar um objeto com o mouse
  void mouseMoveEvent(QGraphicsSceneMouseEvent* mouseEvent); //!< Cuida das ações movimentar um objeto com o mouse
  void mouseReleaseEvent(QGraphicsSceneMouseEvent* event); //!< Cuida das ações soltar um objeto com o mouse
  void promotion(QPointF point); //!< Promoção da peça
  void CentersRegions(); //!< Cria vetor com os centros das regiões
  int FoundCenterRegion(QPointF point); //!< Encontra região mais próxima da posição dada
  bool checkPawnMove(int fromr, int fromc, int tor, int toc); //!< checa o movimento do peão
  bool checkRookMove(int fromr, int fromc, int tor, int toc); //!< checa o movimento da torre
  bool checkKnightMove(int fromr, int fromc, int tor, int toc); //!< checa o movimento do cavalo
  bool checkBishopMove(int fromr, int fromc, int tor, int toc); //!< checa o movimento do bispo
  bool checkKingMove(int fromr, int fromc, int tor, int toc); //!< checa o movimento do rei
  bool checkMove(int fromr, int fromc, int tor, int toc); //!< checa o movimento das peças
};


#endif // CHESSPIECE_H
