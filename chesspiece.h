    #ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include "chessboard.h"
#include <QDebug>
#include <iostream>
#include <list>
#include <utility>
#include <QPointF>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QMediaPlayer>
#include <QObject>

enum class PieceColor { White, Black };
enum class PieceType { pawn, knight, bishop, rook, queen, king };

class Piece: public QGraphicsPixmapItem
{
public:

    PieceColor color;
    PieceType type;
    int weight;
    std::list<std::string> lost_Pieces;
    std::vector<QPointF> centers;

    Piece(PieceColor c, PieceType p, int weight);

    /**
     * @brief setImage
     * @param c
     * @param type
     *
     * Descrição:
     *
     * Insere a image da peça de acordo com os parâmetros de entrada
     */
    void setImage(PieceColor c, PieceType type);

    /**
     * @brief promotion
     * @param point
     *
     * Descrição:
     *
     * Promove o peão quando alcança a casa oposta do tabuleiro
     */
    void promotion(QPointF point);

    /**
     * @brief CentersRegions
     *
     * Descrição:
     *
     * Determina os centros das casas, valores atribuídos ao vetor centers,
     * usado na função FoundCenterRegion()
     */
    void CentersRegions();

    /**
     * @brief FoundCenterRegion
     * @param point
     * @return
     *
     * Descrição:
     *
     * Identifica a casa mais proxima ao local da peça colocada pelo usuário e
     * o posiciona nela.
     */
    int FoundCenterRegion(QPointF point);

    void mousePressEvent(QGraphicsSceneMouseEvent* mouseEvent);
    void mouseMoveEvent(QGraphicsSceneMouseEvent* mouseEvent);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
};


#endif // CHESSPIECE_H
