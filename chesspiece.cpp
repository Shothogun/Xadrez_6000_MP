#include "../chesspiece.h"
#include <QPixmap>

/** \brief Construtor da Peça
        A função inicializa a cor, o tipo e o peso das peças. 
        O vetor com os centros das regiões também é criado.
        As o objeto com sua imagem é colocada no tabuleiro.
        \param Cor, tipo e peso da peça, cenário para peça (parent)
*/
Piece::Piece(PieceColor c, PieceType p, int weight, QGraphicsItem* parent)
{
    this->color = c;
    this->type = p;
    this->weight = weight;
    this->CentersRegions();
    this->setImage(c,p);
}

/** \brief Coloca a imagem da peça no tabuleiro.
        A Função colcoa as peças no cenário do tabuleiro
        juntamente com sua imagem.
*/
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

/** \brief Emite som ao jogador clicar no mouse
        ao clicar a peça com o mouse, emite som.
    \param click do mouse
*/
void Piece::mousePressEvent(QGraphicsSceneMouseEvent* mouseEvent)
{
    if(mouseEvent->button() == Qt::LeftButton)
    {
        QMediaPlayer* sound = new QMediaPlayer();
        sound->setMedia(QUrl("qrc:/sound_test/BIO02.WAV"));
        sound->play();
    }
}

/** \brief Realiza movimento da peça ao movimentar com ela 
        pelo mouse.
        O objeto peça se moviemento junto com o movimento do mouse.
    \param Movimento do mouse
*/
void Piece::mouseMoveEvent(QGraphicsSceneMouseEvent* mouseEvent)
{
    // Corrects mouse position while move
    QPointF p(20,20);

    if(mouseEvent->buttons() & Qt::LeftButton)
      {
        this->setOffset(mouseEvent->pos() - p);
    }
}

/** \brief Realiza movimento da peça ao centro da região escolhida pelo jogador.
        Ao soltar o mouse, a função verifica a posição atual, calcula
        qual centro de região mais próxima e colcoa a peça nessa região.
        Caso a região seja o topo do tabuleiro, a peça é promovida.
    \param Ação de soltar o mouse
*/
void Piece::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    QMediaPlayer* sound = new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/sound_test/BIO03.WAV"));
    sound->play();
    int idx = this->FoundCenterRegion(mouseEvent->pos());
    this->setOffset(this->centers[idx]);
    this->promotion(mouseEvent->pos());
}

/** \brief Cria vetor com os centros das regiões.
        Calcula o centro de cada quadrado do tabuleiro e guarda
        seu centro num vetor.
*/
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

/** \brief Encontra o centro mais proximo da posição dada.
        A função calcula a distancia euclidiana do ponto dado
        com cada centro do tabuleiro e devolve o indice da posição
        do centro mais proximo à esse ponto no vetor.
    \param Posição da peça ao soltar o mouse
*/
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

/** \brief Promoção da Peça.
        A função verifica se o ponto dado (posição atual da peça no tabuleiro)
        é o fim do tabuleiro e entao verifica qual sua cor para
        então fazer a promoção para rainha.
    \param Posição atual da peça.
*/
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