#ifndef LISTA_FIGURA_H
#define LISTA_FIGURA_H
#include "figura.h"
#include <QDebug>
class nodo_figura
{
  public:
    nodo_figura(){ anterior=siguiente=0; Fig=0;}
    nodo_figura(Figura *F) {anterior=siguiente=0; Fig=F;}
    nodo_figura *anterior;
    nodo_figura *siguiente;
    Figura *Fig;
    ~nodo_figura(){
        anterior=siguiente=0;
        Fig=0;
    }
};
class lista_figura
{
public:
    lista_figura();
    void ir_a_inicio();
    void ir_a_final();
    void siguiente();
    void anterior();
    Figura *recuperar();
    Figura *recuperar(int pos);
    int getCuantos();
    void agregar(Figura *F);
    void limpiar();
    bool vacia();
    void irA(int);
    void insertar(int, Figura *);
    ~lista_figura();
    Figura* remover(int pos);
    void printList(){
        irA(0);
        int i = 1;
        while(actual!=0){
            qDebug() << i << ": " << actual;
            actual = actual->siguiente;
            i++;
        }
    }

private:
     nodo_figura *inicio;
     nodo_figura *final;
     nodo_figura *actual;
     int cuantos;
     void limpiar_recursivamente(nodo_figura *n);
};

#endif // LISTA_FIGURA_H










