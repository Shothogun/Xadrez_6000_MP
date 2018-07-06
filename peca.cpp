#include "peca.h"

Piece::Piece(Color c, Type p, int weight)
{
	this->color = c;
	this->type = p;
	this->weight = weight;
}



/*void Piece::mouseMoveEvent(QMouseEvent* event){
  this->x = event->x;
  this->y = event->y;
  emit Mouse_Pos();
}

void Piece::mousePressEvent(QMouseEvent* event){
  emit Mouse_Pressed();
}

void Piece::PutFigures(){
  
}
*/
