#include "rectangulo.h"

Rectangulo::Rectangulo():Figura() // Se corre el constructor de Figura primero
{
  this->alto = 10;
  this->ancho = 10;
}
Rectangulo::Rectangulo(int x,int y,int w,int h,
                       QColor color,
                       QColor fondo)
:Figura(x,y,color,fondo) // Correr el constructor padre de Figura
{
   this->alto = h;
   this->ancho =w;

}
// Implementar la funcion VIRTUAL PURA DIBUJAR
void Rectangulo::Dibujar(QPainter *AreaPintado)
{
    QPen pen(this->getColor(), 2,
             Qt::SolidLine,
             Qt::RoundCap,
             Qt::RoundJoin);
    AreaPintado->setPen( pen);
    AreaPintado->setBrush(this->getFondo());
    AreaPintado->drawRect(this->getX(),this->getY(),
                          this->getAlto(),
                          this->getAncho());

 }
 char Rectangulo::tipoFigura()
 {
     return 'R';
 }
 // MEtodo Virtual NO puro, reimplementado para mejorar la funcionalidad
 void Rectangulo::setX(int newx)
 {
     if (newx<0)
         //  this->setX(0); Esto seria recursivo y no es lo que queremos
         Figura::setX(0);  // Queremos llamar a la version PADRE
         // Tenemos que hacerlo asi porque X es privado y no tenemos acceso directo
         // desde Rectangulo
     else
         Figura::setX(newx);
 }
// MEtodo Virtual NO puro, reimplementado para mejorar la funcionalidad
 void Rectangulo::setY(int newy)
 {
     if (newy<0)
         //  this->setX(0); Esto seria recursivo y no es lo que queremos
         Figura::setY(0);  // Queremos llamar a la version PADRE
         // Tenemos que hacerlo asi porque X es privado y no tenemos acceso directo
         // desde Rectangulo
     else
         Figura::setY(newy);
 }

void Rectangulo::setColoryFondo(QColor color, QColor fondo)
{
    Figura::setColor(color);
    this->setColor(color);    // Set color no esta implementado en rectangulo
    Figura::setFondo(fondo);
    this->setFondo(fondo);

}
int Rectangulo::getAncho() const
{
    return this->ancho;
}
int Rectangulo::getAlto() const
{
    return this->alto;
}

void Rectangulo::setAncho(int ancho)
{
    this->ancho = ancho;

}

void Rectangulo::setAlto(int alto)
{
    this->alto = alto;
}

double Rectangulo::area(){
    return alto * ancho;
}
