#ifndef CIRCULO_H
#define CIRCULO_H
#include "figura.h"

class Circulo : public Figura
{
    static const double pi;
public:
  Circulo();
  Circulo(int x, int y, float r,
    QColor color, QColor fondo);

    virtual void Dibujar(QPainter *AreaPintado);
    virtual char tipoFigura() ;
    virtual double area();

    //No vamos a re-implementar setx ni sety

    float getRadio() const;
    void setRadio(float r);

private:
    float radio;

};

#endif // CIRCULO_H
