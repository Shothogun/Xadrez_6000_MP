#include "chessboard.h"
#include <QApplication>
<<<<<<< Updated upstream
#include <QGraphicsRectItem>
#include <QGraphicsView>

ChessBoard *game;
=======
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene *chess = new QGraphci
>>>>>>> Stashed changes

int main(int argc, char *argv[]){
    QApplication app (argc, argv);

    game = new ChessBoard();
    game->show();

    return app.exec();
}
