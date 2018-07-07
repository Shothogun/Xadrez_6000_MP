#include "square.h"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>

extern Piece *piece;

ChessSquare::ChessSquare(QGraphicsItem *parent):QGraphicsRectItem(parent)
{
    //making the Square Chess
    setRect(0,0,40,40);
    this->currentPiece = NULL;
}

ChessSquare::~ChessSquare()
{
    delete this;
}

/*void ChessSquare::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(currentPiece != NULL){
        currentPiece == NULL;
        return;
    }

    if(currentPiece == NULL){
        currentPiece == piece;
        return;
    }
}*/
