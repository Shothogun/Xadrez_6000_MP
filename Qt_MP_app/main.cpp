 #include "chessboard.h"
#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication app (argc, argv);

    ChessBoard *game = new ChessBoard();
    game->show();

    return app.exec();
}
