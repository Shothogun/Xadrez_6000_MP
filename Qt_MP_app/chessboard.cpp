#include "chessboard.h"
#include <QBrush>
#include <QImage>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>

ChessBoard::ChessBoard(QWidget *parent)
{
    // Create scene
    chess = new QGraphicsScene();
    chess->setSceneRect(0,0,714,714);
    QImage image(":chessboard/chess_icons/board.jpg");
    image = image.scaled( QSize(714,714),  Qt::IgnoreAspectRatio, Qt::FastTransformation);
    setBackgroundBrush(QBrush(image));

    setScene(chess);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(714, 714);

    show();

}
