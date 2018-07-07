#include "../peca.h"
#include <QPixmap>


Piece::Piece(PieceColor c, PieceType p, int weight, QGraphicsItem* parent)
{
	this->color = c;
	this->type = p;
	this->weight = weight;
    this->setImage(c,p);
}

void Piece::setImage(PieceColor c, PieceType type)
{
    //-------------------- White pieces --------------------//

    if(c == PieceColor::White && type == PieceType::pawn)
    {
        QPixmap image = QPixmap(":/chessboard/chess_icons/WP.png");
        image = image.scaled( QSize(40,40),  Qt::IgnoreAspectRatio, Qt::FastTransformation);
        setPixmap(QPixmap(image));
    }

    else if(c == PieceColor::White && type == PieceType::rook)
    {
        QPixmap image = QPixmap(":/chessboard/chess_icons/WR.png");
        image = image.scaled( QSize(40,40),  Qt::IgnoreAspectRatio, Qt::FastTransformation);
        setPixmap(QPixmap(image));
    }

    else if(c == PieceColor::White && type == PieceType::bishop)
    {
        QPixmap image = QPixmap(":/chessboard/chess_icons/WB.png");
        image = image.scaled( QSize(40,40),  Qt::IgnoreAspectRatio, Qt::FastTransformation);
        setPixmap(QPixmap(image));
    }

    else if(c == PieceColor::White && type == PieceType::knight)
    {
        QPixmap image = QPixmap(":/chessboard/chess_icons/WH.png");
        image = image.scaled( QSize(40,40),  Qt::IgnoreAspectRatio, Qt::FastTransformation);
        setPixmap(QPixmap(image));
    }


    else if(c == PieceColor::White && type == PieceType::queen)
    {
        QPixmap image = QPixmap(":/chessboard/chess_icons/WQ.png");
        image = image.scaled( QSize(40,40),  Qt::IgnoreAspectRatio, Qt::FastTransformation);
        setPixmap(QPixmap(image));
    }

    else if(c == PieceColor::White && type == PieceType::king)
    {
        QPixmap image = QPixmap(":/chessboard/chess_icons/WK.png");
        image = image.scaled( QSize(40,40),  Qt::IgnoreAspectRatio, Qt::FastTransformation);
        setPixmap(QPixmap(image));
    }

    //-------------------- Black pieces --------------------//

    if(c == PieceColor::Black && type == PieceType::pawn)
    {
        QPixmap image = QPixmap(":/chessboard/chess_icons/BP.png");
        image = image.scaled( QSize(40,40),  Qt::IgnoreAspectRatio, Qt::FastTransformation);
        setPixmap(QPixmap(image));
    }

    else if(c == PieceColor::Black && type == PieceType::rook)
    {
        QPixmap image = QPixmap(":/chessboard/chess_icons/BR.png");
        image = image.scaled( QSize(40,40),  Qt::IgnoreAspectRatio, Qt::FastTransformation);
        setPixmap(QPixmap(image));
    }

    else if(c == PieceColor::Black && type == PieceType::bishop)
    {
        QPixmap image = QPixmap(":/chessboard/chess_icons/BB.png");
        image = image.scaled( QSize(40,40),  Qt::IgnoreAspectRatio, Qt::FastTransformation);
        setPixmap(QPixmap(image));
    }

    else if(c == PieceColor::Black && type == PieceType::knight)
    {
        QPixmap image = QPixmap(":/chessboard/chess_icons/BH.png");
        image = image.scaled( QSize(40,40),  Qt::IgnoreAspectRatio, Qt::FastTransformation);
        setPixmap(QPixmap(image));
    }

    else if(c == PieceColor::Black && type == PieceType::king)
    {
        QPixmap image = QPixmap(":/chessboard/chess_icons/BK.png");
        image = image.scaled( QSize(40,40),  Qt::IgnoreAspectRatio, Qt::FastTransformation);
        setPixmap(QPixmap(image));
    }

    else if(c == PieceColor::Black && type == PieceType::queen)
    {
        QPixmap image = QPixmap(":/chessboard/chess_icons/BQ.png");
        image = image.scaled( QSize(40,40),  Qt::IgnoreAspectRatio, Qt::FastTransformation);
        setPixmap(QPixmap(image));
    }

  }

void Piece::mousePressEvent(QGraphicsSceneMouseEvent* mouseEvent)
{
    if(mouseEvent->button() == Qt::LeftButton)
    {
        QMediaPlayer* sound = new QMediaPlayer();
        sound->setMedia(QUrl("qrc:/sound_test/BIO04.WAV"));
        sound->play();

        offset_position = mouseEvent->pos();
    }
}

void Piece::mouseMoveEvent(QGraphicsSceneMouseEvent* mouseEvent)
{
    if(mouseEvent->buttons() & Qt::LeftButton)
      {
        this->move(mapToParent(mouseEvent->pos() - offset_position));
      }
}

