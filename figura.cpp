#include "figura.h"

Figura::Figura()
{
    x=y=0;
    color=Qt::black;
    fondo=Qt::white;
}
Figura::Figura(int x, int y, QColor color, QColor fondo)
{
    this->x =x;
    this->y = y;
    this->color = color;
    this->fondo = fondo;
}
void Figura::Mover(int newx, int newy)
{
  this->setX(newx);
  this->setY(newy);
}
void Figura::setX(int newx)
{
    this->x=newx;
}
void Figura::setY(int newy)
{
    this->y=newy;
}
int Figura::getX() const
{
    return x;
}
int Figura::getY() const
{
    return y;
}
void Figura::setColor(QColor color)
{
    this->color = color;
}
void Figura::setFondo(QColor fondo)
{
    this->fondo = fondo;
}
QColor Figura::getColor() const
{
  return this->color;
}
QColor Figura::getFondo() const
{
  return this->fondo;
}


