#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "nodo.h"

struct Pila{
    NodoPtr ultimo;
};

NodoPtr getUltimoP(PilaPtr pila)
{
    return pila->ultimo;

}
void setUltimoP(PilaPtr pila, NodoPtr nuevoUltimo)
{
    pila->ultimo = nuevoUltimo;
}
PilaPtr crearPila()
{
    PilaPtr pila = malloc(sizeof(struct Pila));
    pila->ultimo = NULL;
    return pila;
}
void pushPila(PilaPtr pila, DatoPtr dato)
{
    pila->ultimo = crearNodo(dato, pila->ultimo);
}
DatoPtr popPila(PilaPtr pila){
    if(pila->ultimo==NULL)return NULL;
    NodoPtr nodo = pila->ultimo;
    DatoPtr dato = getDato(nodo);
    pila->ultimo=getSiguiente(nodo);
    liberarNodo(nodo);
    return dato;

}
PilaPtr duplicarPila(PilaPtr pila)
{
    PilaPtr tmp = crearPila();
    PilaPtr copia = crearPila();
    NodoPtr actual=pila->ultimo;
    DatoPtr dato;
    while(actual){
        pushPila(tmp,getDato(actual));
        actual=getSiguiente(actual);
    }
    while((dato=popPila(tmp))!=NULL){
        pushPila(copia,dato);
    }
    free(tmp);
    return copia;
}

void liberarPila(PilaPtr pila)
{
    NodoPtr nodo=pila->ultimo;
    while (pila->ultimo!=NULL){
        pila->ultimo=getSiguiente(nodo);
        liberarNodo(nodo);
        nodo=pila->ultimo;
    }
     free(pila);
};


