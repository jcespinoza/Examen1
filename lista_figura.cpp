#include "lista_figura.h"
#include <QDebug>

lista_figura::lista_figura()
{
    inicio=final=actual=0;
    cuantos=0;
}

void lista_figura::ir_a_inicio()
{ this->actual = this->inicio; }
void lista_figura::ir_a_final()
{ this->actual = this->final; }
void lista_figura::siguiente()
{ this->actual = this->actual->siguiente; }
void lista_figura::anterior()
{ this->actual = this->actual->anterior; }

Figura* lista_figura::recuperar()
{
    if(actual!=0)
         return actual->Fig;
    else
        return 0;
}

Figura* lista_figura::recuperar(int pos)
{
    if(cuantos==0 || pos>cuantos || pos <=0)
        return 0;
    else
    {
        this->ir_a_inicio();
        for(int i=1; i<pos;i++)
        {
            this->siguiente();
        }
        return this->actual->Fig;



    }
}

int lista_figura::getCuantos()
{
    return cuantos;
}
void lista_figura::agregar(Figura *F)
{
    nodo_figura *nuevo;
    nuevo = new nodo_figura(F);
    if(this->cuantos==0)
    {
        inicio=final=nuevo;
        actual=nuevo;
    }
    else
    {
        final->siguiente=nuevo;
        nuevo->anterior = final;
        final = nuevo;

    }
    this->cuantos++;

}

lista_figura::~lista_figura(){
   this->limpiar();
}
void lista_figura::limpiar(){
   //this->limpiar_recursivamente(this->inicio);
   this->actual = this->inicio;
   while(this->actual!=0)
   {
       this->inicio=this->inicio->siguiente;
       delete actual;
       actual = this->inicio;
   }
   this->inicio =0;
   this->final = 0;
   this->actual =0;
   this->cuantos =0;
}

void lista_figura::limpiar_recursivamente(nodo_figura *n)
{
    if (n==0)  return;
    else
    {
        this->limpiar_recursivamente(n->siguiente);
        delete n;
    }
}

//lista_figura es 1-based
Figura * lista_figura::remover(int pos){
    Figura * fig = 0;
    ir_a_inicio();
    for(int i = 1; i < pos; i++)
        siguiente();
    if(pos != 1 && pos != cuantos){
        actual->anterior->siguiente = actual->siguiente;
        actual->siguiente->anterior = actual->anterior;
    }else if(pos==1){
        inicio = actual->siguiente;
        if(actual->siguiente != 0)
            actual->siguiente->anterior = 0;
    }else if(pos == cuantos){
        final = actual->anterior;
        actual->anterior->siguiente = 0;
    }else{
        //pos es outOfBounds;
    }
    if(pos >0 && pos <= cuantos){
        cuantos--;
        fig = actual->Fig;
        delete actual;
    }
    return fig;
}

bool lista_figura::vacia(){
    return inicio == 0;
}

void lista_figura::irA(int p){
    if(p <= 1){
        ir_a_inicio(); return;
    }
    if(p == cuantos - 1){
        ir_a_final(); return;
    }
    for(int i = 1; i <= p; i++){
        ir_a_inicio();
        if(actual->siguiente != 0)
            siguiente();
        qDebug() << i;
    }
}
