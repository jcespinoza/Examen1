#ifndef RECTANGULOSOMBREADO_H
#define RECTANGULOSOMBREADO_H
#include "rectangulo.h"

class RectanguloSombreado : public Rectangulo
{
public:
    RectanguloSombreado();
    RectanguloSombreado (int x, int y, int w, int h,
                QColor color,
                QColor fondo,int grosor);
    virtual void Dibujar (QPainter *AreaPintado);
    virtual char tipoFigura() ;
    void setGrosorSombra(int grosor);
    int getGrosor() const;

private:
    int grosor_sombra;
};

#endif // RECTANGULOSOMBREADO_H
