#ifndef PAINTBOARD_H
#define PAINTBOARD_H

#include <QObject>
#include <QWidget>
#include <QMouseEvent>
#include <QDebug>
#include "figura.h"
#include "lista_figura.h"
#include <math.h>

class PaintBoard : public QWidget
{
   Q_OBJECT

public:
    PaintBoard(QWidget *parent = 0);

    void setListaFiguras ( lista_figura *l);
    int getCurrentFigura() { return this->currentFigura;}
    void guardar(QString f){pix->save(f);}

signals:
    void currentFiguraChanged(int cualFigura);

private:
     float distancia(int x, int y, int x1, int y1);
     lista_figura *lista;
     int currentFigura; // Marca la posicion de la figura actual
     QImage image;
     QPixmap * pix;
protected:
     // Incluir figura.h, rectangulo.h, QPainter
    void paintEvent(QPaintEvent *event);
    void mouseDoubleClickEvent ( QMouseEvent * event );

};

#endif // PAINTBOARD_H
