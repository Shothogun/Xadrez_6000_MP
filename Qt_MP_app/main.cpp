#include "chessboard.h"
#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsView>

ChessBoard *game;

int main(int argc, char *argv[]){
    QApplication app (argc, argv);

    game = new ChessBoard();
    game->show();

    return app.exec();
}
