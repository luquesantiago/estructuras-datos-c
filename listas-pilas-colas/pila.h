#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include "nodo.h"


struct Pila;

typedef struct Pila * PilaPtr;



NodoPtr getUltimoP(PilaPtr pila);
void setUltimoP(PilaPtr pila, NodoPtr nuevoUltimo);


PilaPtr crearPila();
void pushPila(PilaPtr pila, DatoPtr dato); ///APILAR - PUSH
DatoPtr popPila(PilaPtr pila); ///DESAPILAR - POP
PilaPtr duplicarPila(PilaPtr pila);//tarea
void liberarPila(PilaPtr pila);




#endif // PILA_H_INCLUDED
