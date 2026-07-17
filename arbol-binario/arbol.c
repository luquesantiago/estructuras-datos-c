#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"


struct NodoE {
    int dato;

    Nodo izquierda;
    Nodo derecha;
};




 Nodo nuevoNodo(int dato) {
    // Solicitar memoria
     Nodo nodo = (Nodo) malloc(sizeof(struct NodoE));

    // Asignar el dato e iniciar hojas
    nodo->dato = dato;
    nodo->izquierda =NULL;
    nodo->derecha = NULL;

    return nodo;
}

void insertar( Nodo nodo, int dato) {


    if (dato > nodo->dato) {
        // Tienes espacio a la derecha?
        if (nodo->derecha == NULL) {
            nodo->derecha = nuevoNodo(dato);
        } else {
            // Si la derecha ya está ocupada, recursividad ;)
            insertar(nodo->derecha, dato);
        }
    } else { //dato == nodo->dato
        // Si no, a la izquierda
        if (nodo->izquierda == NULL) {
            nodo->izquierda = nuevoNodo(dato);
        } else {
            // Si la izquierda ya está ocupada, recursividad ;)
            insertar(nodo->izquierda, dato);
        }
    }
}


void preorden( Nodo nodo) {
    if (nodo != NULL) {
        printf("%d,", nodo->dato);
        preorden(nodo->izquierda);
        preorden(nodo->derecha);
    }
}

void inorden(Nodo nodo) {
    if (nodo != NULL) {
        inorden(nodo->izquierda);
        printf("%d,", nodo->dato);
        inorden(nodo->derecha);
    }
}

void postorden( Nodo nodo) {
    if (nodo != NULL) {
        postorden(nodo->izquierda);
        postorden(nodo->derecha);
        printf("%d,", nodo->dato);
    }
}


Nodo buscar(Nodo nodo, int dato)
{
    if (nodo == NULL)
    {
        return NULL;
    }


    if (nodo->dato == dato)
    {
        return nodo;
    }

    else if (dato > nodo->dato)
    {
        printf("No esta el %d != %d --> DERECHA\n", dato, nodo->dato);
        return buscar(nodo->derecha, dato);
    }
    else
    {   printf("No esta el %d != %d --> IZQUIERDA\n", dato, nodo->dato);
        return buscar(nodo->izquierda, dato);
    }
}
