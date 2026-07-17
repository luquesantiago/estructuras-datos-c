#include <stdio.h>
#include <stdlib.h>
#include "cola.h"
#include "nodo.h"

struct Cola{
NodoPtr primero;
NodoPtr ultimo;

};


void setPrimeroC(ColaPtr cola, NodoPtr nuevoPrimero)
{
    cola->primero=nuevoPrimero;
}
NodoPtr getPrimeroC(ColaPtr cola)
{
return cola->primero;
}


void setUltimoC(ColaPtr cola, NodoPtr nuevoUltimo)
{
    cola->ultimo=nuevoUltimo;
}
NodoPtr getUltimoC(ColaPtr cola)
{
    return cola->ultimo;
}


ColaPtr crearCola()
{
    ColaPtr cola = malloc(sizeof(struct Cola));
    cola->primero=NULL;
    cola->ultimo=NULL;
    return cola;
}

void encolar(ColaPtr cola, DatoPtr dato)
{
    NodoPtr nuevo = crearNodo(dato,NULL);
       if (cola->primero == NULL) {
        cola->primero = nuevo;
        cola->ultimo  = nuevo;
        return;
    }
    setSiguiente(cola->ultimo,nuevo);
    cola ->ultimo= nuevo;
} ///ENCOLAR - ENQUEUE
DatoPtr desencolar(ColaPtr cola)
{
    if(cola->primero == NULL)return NULL;
    NodoPtr nodo = cola->primero;
    DatoPtr dato = getDato(nodo);
    cola->primero = getSiguiente(nodo);
    liberarNodo(nodo);
    return dato;
} ///DESENCOLAR - DEQUEUE
ColaPtr duplicarCola(ColaPtr cola)
{
     ColaPtr nueva = crearCola();
    NodoPtr actual = cola->primero;
    while (actual != NULL) {
        encolar(nueva, getDato(actual));
        actual = getSiguiente(actual);
    }
    return nueva;
}//tarea
void liberarCola(ColaPtr cola)
{

    NodoPtr actual = cola->primero;
    NodoPtr aux;

    while (actual!=NULL){
        aux = actual;
        actual = getSiguiente(actual);
        liberarNodo(aux);
    };
    free(cola);
}



