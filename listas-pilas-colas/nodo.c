#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"
#include"persona.h"
#include<string.h>

struct Nodo {

    DatoPtr dato;
    struct Nodo * siguiente;

};


DatoPtr getDato(NodoPtr nodo){

    return nodo->dato;
};

NodoPtr getSiguiente(NodoPtr nodo){

    return nodo->siguiente;
};

void setDato(NodoPtr nodo, DatoPtr nuevoDato){

    nodo->dato = nuevoDato;
};

void setSiguiente(NodoPtr nodo, NodoPtr nuevoSiguiente){

    nodo->siguiente = nuevoSiguiente;

};

NodoPtr crearNodo(DatoPtr dato, NodoPtr siguiente){


    NodoPtr nodo = (NodoPtr) malloc(sizeof(struct Nodo));

    nodo->dato = dato;
    nodo->siguiente = siguiente;

    return nodo;

};


int compararint(void *d1,void * d2)
{
    return (*(float*)d1 > *(float*)d2);
};
int compararchar(void *d1, void *d2) {
    return strcmp((char *)d1, (char *)d2) > 0;
}


void mostrarNodo(void * dato){

printf("{ %d }", *(int*)(dato));

};

void mostrarChar(void* dato){

    printf("{ %s }", (char*)(dato));

};

void mostrarFloat(void* dato){

    printf("{ %.2f }", *(float*)(dato));

};



void liberarNodo(NodoPtr nodo){

    free(nodo);


};
