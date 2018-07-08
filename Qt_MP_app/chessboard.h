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
    QPointF position;
    QGraphicsScene * board;
    bool CheckMate = false;
    std::vector<QPointF> centers;


    // Starts a new game
    /**
     * start()
     *
     * Descrição:
     *
     * Preenche o tabuleiro com as peças do jogo
     */

    void start();

    /**
     * @brief drawPanel
     * @param x
     * @param y
     * @param width
     * @param height
     * @param color
     * @param opacity
     *
     * Descrição:
     *
     * Cria um painel na janela do jogo
     */

    void drawPanel(int x, int y, int width, int height, QColor color, double opacity);

    /**
     * gameOver()
     *
     * Descrição:
     *
     * Chama  a função displayGameOverWindow e define a mensagem de fim de jogo
     *
     */
    void gameOver();

    /**
     * @brief displayGameOverWindow
     * @param textToDisplay
     *
     * Descrição:
     *
     * Chama a função drawPanel e cria a mensagem de fim de jogo
     */
    void displayGameOverWindow(QString textToDisplay);

};


#endif // CHESSBOARD_H
