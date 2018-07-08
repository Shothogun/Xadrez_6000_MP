#include "chessboard.h"
#include <QBrush>
#include <QImage>
#include <QVector>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include <QList>

ChessBoard::ChessBoard()
{
    // Create scene
    this->board = new QGraphicsScene(this);
    board->setSceneRect(0,0,902,445);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    this->start();

    if(this->CheckMate == true)
    {
      gameOver();
    }

    setFixedSize(902, 445);
}

void ChessBoard::start()
{

    QImage image(":chessboard/chess_icons/board.jpg");
    image = image.scaled( QSize(902,445),  Qt::IgnoreAspectRatio, Qt::FastTransformation);
    setBackgroundBrush(QBrush(image));

    setScene(board);

    // Adds pawns
    for(int i = 0; i < 8; i++)
    {
        Piece* white_pawn = new Piece(PieceColor::White, PieceType::pawn, 1);

        board->addItem(white_pawn);
        white_pawn->setAcceptedMouseButtons(Qt::LeftButton);
        white_pawn->setOffset(25 + i*50 , 330);

        Piece* black_pawn = new Piece(PieceColor::Black, PieceType::pawn, 1);

        board->addItem(black_pawn);
        black_pawn->setAcceptedMouseButtons(Qt::LeftButton);
        black_pawn->setOffset(25 + i*50 , 80);
    }

     // Adds bishop
     for(int i = 0; i < 2; i++)
     {
         Piece* white_bishop = new Piece(PieceColor::White, PieceType::bishop, 3);

         board->addItem(white_bishop);
         white_bishop->setAcceptedMouseButtons(Qt::LeftButton);
         white_bishop->setOffset(125 + i*150 ,380);

         Piece* black_bishop = new Piece(PieceColor::Black, PieceType::bishop, 3);

         board->addItem(black_bishop);
         black_bishop->setAcceptedMouseButtons(Qt::LeftButton);
         black_bishop->setOffset(125 + i*150 , 30);
     }


    // Adds knight
    for(int i = 0; i < 2; i++)
    {
        Piece* white_knight = new Piece(PieceColor::White, PieceType::knight, 3);

        board->addItem(white_knight);
        white_knight->setAcceptedMouseButtons(Qt::LeftButton);
        white_knight->setOffset(75 + i*250 ,380);

        Piece* black_knight = new Piece(PieceColor::Black, PieceType::knight, 3);

        board->addItem(black_knight);
        black_knight->setAcceptedMouseButtons(Qt::LeftButton);
        black_knight->setOffset(75 + i*250 , 30);
    }


    // Adds rook
    for(int i = 0; i < 2; i++)
    {
        Piece* white_rook = new Piece(PieceColor::White, PieceType::rook, 5);

        board->addItem(white_rook);
        white_rook->setAcceptedMouseButtons(Qt::LeftButton);
        white_rook->setOffset(25 + i*350 ,380);

        Piece* black_rook = new Piece(PieceColor::Black, PieceType::rook, 5);

        board->addItem(black_rook);
        black_rook->setAcceptedMouseButtons(Qt::LeftButton);
        black_rook->setOffset(25 + i*350 , 30);
    }

    // Adds queen
    for(int i = 0; i < 1; i++)
    {
        Piece* white_queen = new Piece(PieceColor::White, PieceType::queen, 9);

        board->addItem(white_queen);
        white_queen->setAcceptedMouseButtons(Qt::LeftButton);
        white_queen->setOffset(175 ,380);

        Piece* black_queen = new Piece(PieceColor::Black, PieceType::queen, 9);

        board->addItem(black_queen);
        black_queen->setAcceptedMouseButtons(Qt::LeftButton);
        black_queen->setOffset(225, 30);
    }

    // Adds King
    for(int i = 0; i < 1; i++)
    {
        Piece* white_king = new Piece(PieceColor::White, PieceType::king, 200);

        board->addItem(white_king);
        white_king->setAcceptedMouseButtons(Qt::LeftButton);
        white_king->setOffset(225 ,380);

        Piece* black_king = new Piece(PieceColor::Black, PieceType::king, 200);

        board->addItem(black_king);
        black_king->setAcceptedMouseButtons(Qt::LeftButton);
        black_king->setOffset(175, 30);

    }

}



void ChessBoard::drawPanel(int x, int y, int width, int height, QColor color, double opacity)
{
    // draws a panel at the specified location with the specified properties
    QGraphicsRectItem* panel = new QGraphicsRectItem(x,y,width,height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    panel->setBrush(brush);
    panel->setOpacity(opacity);
    board->addItem(panel);
}

void ChessBoard::gameOver()
{
    QString message;

    board->clear();

    message = "Checkmate!\nGame Over";

    displayGameOverWindow(message);
}

void ChessBoard::displayGameOverWindow(QString textToDisplay)
{
    // pop up semi transparent panel
    drawPanel(0,0,902,445,Qt::black,0.65);

    // draw panel
    drawPanel(312,100,400,300,Qt::lightGray,0.75);

    // create text annoucning winner
    QGraphicsTextItem* overText = new QGraphicsTextItem(textToDisplay);
    overText->setPos(460,225);
    board->addItem(overText);
}

