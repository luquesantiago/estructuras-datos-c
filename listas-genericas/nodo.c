#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"

struct Nodo {

    DatoPtr dato;
    struct Nodo * siguiente;

};

DatoPtr obtenerDato(NodoPtr nodo) {
    return nodo->dato;
}

NodoPtr obtenerSiguiente(NodoPtr nodo) {
    return nodo->siguiente;
}

void setDato(NodoPtr nodo, int dato) {
    nodo->dato = dato;
}

void setSiguiente(NodoPtr nodo, NodoPtr sig) {
    nodo->siguiente = sig;
}



NodoPtr crearNodo(DatoPtr dato, NodoPtr siguiente){


    NodoPtr nodo = (NodoPtr) malloc(sizeof(struct Nodo));

    nodo->dato = dato;
    nodo->siguiente = siguiente;

    return nodo;

};

void mostrarNodo(NodoPtr nodo){

    printf("{ %d }", *(int*)(nodo->dato));

};

void mostrarNodoChar(NodoPtr nodo){

    printf("{ %s }", (char*)(nodo->dato));

};

void mostrarNodoFloat(NodoPtr nodo){

    printf("{ %.2f }", *(float*)(nodo->dato));

};


void liberarNodo(NodoPtr nodo){

    free(nodo);


};
