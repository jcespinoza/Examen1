#ifndef RECTANGULO_H
#define RECTANGULO_H
#include "figura.h"

class Rectangulo : public Figura // Herencia publica , Why?
{
public:
    Rectangulo();
    Rectangulo (int x, int y, int w, int h,
                QColor color,
                QColor fondo);

    // Virtuales para que se puedan re-implementar si es necesario
    virtual void Dibujar (QPainter *AreaPintado);
    virtual double area();
    virtual char tipoFigura() ;

    // Estas dos ya existen en Figura pero las re-implementaremos
    void setX(int newx);  // Para que validen negativos
    void setY(int newy);  // Ya que las versiones de Figura no lo hacen

    // Un metodo que se combina que no existe en la clase padre
    void setColoryFondo(QColor color, QColor fondo);

    int getAncho() const;
    int getAlto() const;
    void setAncho(int ancho);
    void setAlto(int alto);

private:
    int ancho;
    int alto;

};

#endif // RECTANGULO_H
