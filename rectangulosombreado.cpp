#include "rectangulosombreado.h"

RectanguloSombreado::RectanguloSombreado():Rectangulo()
{
    this->grosor_sombra=5;
}

RectanguloSombreado::RectanguloSombreado(int x, int y, int w, int h,
                                         QColor color,
                                         QColor fondo,int grosor):
Rectangulo(x,y,w,h,color,fondo)

{
  this->grosor_sombra = grosor;
}

void RectanguloSombreado::setGrosorSombra(int grosor)
{
    this->grosor_sombra=grosor;
}

void RectanguloSombreado::Dibujar(QPainter *AreaPintado)
{
    //Primero dibujar la sombre
    QPen pen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    AreaPintado->setPen( pen);
    AreaPintado->setBrush(Qt::gray);
    AreaPintado->drawRect(this->getX()+this->grosor_sombra,
                          this->getY()+this->grosor_sombra,
                          this->getAlto(),this->getAncho());
    Rectangulo::Dibujar(AreaPintado);

}
char RectanguloSombreado::tipoFigura()
{
    return 'S';
}
