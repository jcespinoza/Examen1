#include "circulo.h"

const double Circulo::pi = 3.141592654;
Circulo::Circulo() :Figura()
{
    this->radio=10;
}
Circulo::Circulo(int x, int y, float r, QColor color, QColor fondo)
:Figura(x,y,color,fondo)
{
    this->radio =r;
}
void Circulo::setRadio(float r)
{
    this->radio=r;
}
float Circulo::getRadio() const
{
    return this->radio;
}

void Circulo::Dibujar(QPainter *AreaPintado)
{
    QPen pen(this->getColor(), 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    AreaPintado->setPen( pen);
    AreaPintado->setBrush(this->getFondo());
    QPointF punto(this->getX(),this->getY());
    AreaPintado->drawEllipse(punto,(qreal)this->radio,
                             (qreal)this->radio);

 }


 char Circulo::tipoFigura()
 {
     return 'C';
 }

 double Circulo::area(){
     return pi * radio * radio;
 }
