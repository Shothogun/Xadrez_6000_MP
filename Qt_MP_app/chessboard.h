#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include "../peca.h"
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QBrush>



class ChessBoard : public QGraphicsView
{
public:
    ChessBoard();

    QGraphicsScene * board;

};


#endif // CHESSBOARD_H
