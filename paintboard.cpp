#include "paintboard.h"

PaintBoard::PaintBoard(QWidget *parent): QWidget(parent)
{
   this->lista =0;
   this->currentFigura = 0; // Valida es de 0 en adelante

    pix = new QPixmap(geometry().width() -1, geometry().height() - 1);
}

float PaintBoard::distancia(int x, int y, int x1, int y1){
    return (sqrt((float) (x1-x)*(x1-x) + (y1-y)*(y1-y) ));
}
void PaintBoard::mouseDoubleClickEvent ( QMouseEvent * event )
{
    qDebug() << event->x() << ":" << event->y();
    //Averiguar la figura seleccionada
    if(lista!=0) // Si el apuntador de lista es diferente de nulo
    {
        // Recorrer la lista y dibujar
        lista->ir_a_inicio();
        for (int i=1; i <= lista->getCuantos(); i++)
        {
          Figura *temp = lista->recuperar();
          // Sacar la distancia entre los dos puntos y ver que tan cerca
          float dist = this->distancia(temp->getX(),temp->getY(),
                                       event->x(),event->y());

          //qDebug() << "Distancia : " << dist;
          if (dist<3) // Hardcoded
          {
               this->currentFigura = i;
               qDebug() << "Figura" << this->currentFigura;
               this->update();
               emit this->currentFiguraChanged(this->currentFigura);
               return;
          }

          lista->siguiente();

        }
        this->currentFigura=0;
        this->update();
        emit currentFiguraChanged(this->currentFigura);
    }
    else
        this->currentFigura=0;
}

void PaintBoard::paintEvent( QPaintEvent * event ){
    //QPainter painter( this ); // Inicializar el Painter
    // Dibujar el tablero primero SIEMPRE
   /*painter.setBrush(Qt::white);
   painter.drawRect(0,0,this->geometry().width()-1,this->geometry().height()-1);*/

    pix->fill(Qt::white);
    QPainter painter2(pix);
   if(lista!=0){ // Si el apuntador de lista es diferente de nulo
       // Recorrer la lista y dibujar
       lista->ir_a_inicio();
       for (int i=0; i < lista->getCuantos(); i++){
         Figura *temp = lista->recuperar();

         temp->Dibujar(&painter2);
         lista->siguiente();
       }

       QPainter painter(this);
       painter.drawPixmap(0,0, *pix);
       /*qDebug()<<"CurrentFigura " << this->currentFigura << "cuantos :"
                << this->lista->getCuantos();

       if (this->currentFigura > 0
               && this->currentFigura <= this->lista->getCuantos()){
           // Dibujar el indicadord
           //qDebug()<<"Entro";
           QPen pen(Qt::gray, 3, Qt::DotLine, Qt::RoundCap, Qt::RoundJoin);
           painter.setPen( pen);
           painter.setBrush(Qt::green);
           Figura *temp = lista->recuperar(this->currentFigura);
           painter.drawEllipse(0,0,5,5);
           painter.drawLine(0,0,temp->getX(),temp->getY());
       }*/
   }
}

void PaintBoard::setListaFiguras(lista_figura *l)
{
    this->lista = l;
}
