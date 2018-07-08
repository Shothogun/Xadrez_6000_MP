#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include "../chesspiece.h"
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QBrush>
#include <QGraphicsSceneMouseEvent>
#include <math.h>


class ChessBoard : public QGraphicsView
{
public:
    ChessBoard();
    QGraphicsScene * board;

    void start();
    void drawPanel(int x, int y, int width, int height, QColor color, double opacity);
    void gameOver();
    void displayGameOverWindow(QString textToDisplay);
};


#endif // CHESSBOARD_H
