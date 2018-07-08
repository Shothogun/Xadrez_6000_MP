#include "../chesspiece.h"
#include <QPixmap>


Piece::Piece(PieceColor c, PieceType p, int weight)
{
    this->color = c;
    this->type = p;
    this->weight = weight;
    this->CentersRegions();
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
        sound->setMedia(QUrl("qrc:/sound_test/BIO02.WAV"));
        sound->play();
    }
}

void Piece::mouseMoveEvent(QGraphicsSceneMouseEvent* mouseEvent)
{
    // Corrects mouse position while move
    QPointF p(20,20);

    if(mouseEvent->buttons() & Qt::LeftButton)
      {
        this->setOffset(mouseEvent->pos() - p);
    }

}

void Piece::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    QMediaPlayer* sound = new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/sound_test/BIO03.WAV"));
    sound->play();

    //Set inside the chessboard
    if(mouseEvent->pos().x() < 400 && mouseEvent->pos().y() < 400)
    {
      int idx = this->FoundCenterRegion(mouseEvent->pos());

      this->setOffset(this->centers[idx]);
    }

    // Outside doesn't set in any square
    else
    {
       this->setOffset(mouseEvent->pos());
    }

    this->promotion(mouseEvent->pos());

}

void Piece::CentersRegions()
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            this->centers.insert(this->centers.end() ,QPointF(25+50*i, 30+50*j));
        }
    }
}

int Piece::FoundCenterRegion(QPointF point)
{
    int idxCenter;
    float distance, smaller = 1000;
    for(int i = 0; i < 64; i++)
    {
        QPointF pointCenter = this->centers[i];
        distance = std::sqrt( std::pow(point.x() - pointCenter.x(), 2) + std::pow(point.y() - pointCenter.y(), 2));
        if(distance < smaller)
        {
            smaller = distance;
            idxCenter = i;
        }
    }
    return idxCenter;
}

void Piece::promotion(QPointF point)
{
    QPixmap image;

    if(this->color == PieceColor::White && point.y() < 50)
    {
        this->type = PieceType::queen;
        this->weight = 9;
        image = QPixmap(":/chessboard/chess_icons/WQ.png");
        image = image.scaled( QSize(40,40),  Qt::IgnoreAspectRatio, Qt::FastTransformation);
        setPixmap(QPixmap(image));
    }

    if(this->color == PieceColor::Black && point.y() > 380)
    {
        this->type = PieceType::queen;
        this->weight = 9;
        image = QPixmap(":/chessboard/chess_icons/BQ.png");
        image = image.scaled( QSize(40,40),  Qt::IgnoreAspectRatio, Qt::FastTransformation);
        setPixmap(QPixmap(image));
    }
}
