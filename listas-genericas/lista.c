#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "nodo.h"

struct Lista {
    NodoPtr primero;
};

ListaPtr crearLista() {
    ListaPtr lista = malloc(sizeof(struct Lista));
    lista->primero = NULL;
    return lista;
}

void insertarPrimero(ListaPtr lista, DatoPtr dato) {
    NodoPtr nuevoNodo = crearNodo(dato, lista->primero);
    lista->primero = nuevoNodo;
}

void insertarUltimo(ListaPtr lista, DatoPtr dato) {
    NodoPtr nuevoNodo = crearNodo(dato, NULL);

    if (lista->primero == NULL) {
        lista->primero = nuevoNodo;
    } else {
        NodoPtr actual = lista->primero;
        while (obtenerSiguiente(actual) != NULL) {
            actual = obtenerSiguiente(actual);
        }
        setSiguiente(actual, nuevoNodo);
    }
}

void insertarPosicion(ListaPtr lista, DatoPtr dato, int posicion) {
    NodoPtr nuevoNodo = crearNodo(dato, NULL);

    if (posicion <= 0 || lista->primero == NULL) {
        setSiguiente(nuevoNodo, lista->primero);
        lista->primero = nuevoNodo;
        return;
    }

    NodoPtr actual = lista->primero;
    int cont = 1;

    while (obtenerSiguiente(actual) != NULL && cont < posicion - 1) {
        actual = obtenerSiguiente(actual);
        cont++;
    }

    setSiguiente(nuevoNodo, obtenerSiguiente(actual));
    setSiguiente(actual, nuevoNodo);
}

DatoPtr obtenerPrimero(ListaPtr lista) {
    return obtenerDato(lista->primero);
}

DatoPtr obtenerUltimo(ListaPtr lista) {
    NodoPtr actual = lista->primero;
    while (obtenerSiguiente(actual) != NULL) {
        actual = obtenerSiguiente(actual);
    }
    return obtenerDato(actual);
}

DatoPtr obtenerPosicion(ListaPtr lista, int pos) {
    NodoPtr actual = lista->primero;
    for (int i = 1; i <= pos; i++) {
        if (i == pos) {
            return obtenerDato(actual);
        }
        actual = obtenerSiguiente(actual);
    }
    return -1;
}

int eliminarPrimero(ListaPtr lista) {
    if (lista->primero == NULL) return 0;
    NodoPtr actual = lista->primero;
    lista->primero = obtenerSiguiente(actual);
    liberarNodo(actual);
    return 1;
}

int eliminarUltimo(ListaPtr lista) {
    if (lista->primero == NULL) return 0;

    NodoPtr actual = lista->primero;
    NodoPtr anterior = NULL;

    while (obtenerSiguiente(actual) != NULL) {
        anterior = actual;
        actual = obtenerSiguiente(actual);
    }

    if (anterior == NULL) {
        lista->primero = NULL;
    } else {
        setSiguiente(anterior, NULL);
    }

    liberarNodo(actual);
    return 1;
}

int eliminarposicion(ListaPtr lista, int posicion) {
    if (lista->primero == NULL) return -1;

    NodoPtr actual = lista->primero;
    NodoPtr anterior = NULL;
    int cont = 1;

    if (posicion == 1) {
        lista->primero = obtenerSiguiente(actual);
        liberarNodo(actual);
        return 1;
    }

    while (obtenerSiguiente(actual) != NULL) {
        if (cont == posicion) {
            setSiguiente(anterior, obtenerSiguiente(actual));
            liberarNodo(actual);
            return 1;
        }
        anterior = actual;
        actual = obtenerSiguiente(actual);
        cont++;
    }

    return 0;
}

int obtenerTamanio(ListaPtr lista) {
    int cont = 0;
    NodoPtr actual = lista->primero;
    while (actual != NULL) {
        cont++;
        actual = obtenerSiguiente(actual);
    }
    return cont;
}

void ordenarLista(ListaPtr lista) {
    if (lista->primero == NULL || obtenerSiguiente(lista->primero) == NULL) return;

    int intercambio;
    NodoPtr actual;
    NodoPtr limite = NULL;

    do {
        intercambio = 0;
        actual = lista->primero;

        while (obtenerSiguiente(actual) != limite) {
            NodoPtr sig = obtenerSiguiente(actual);
            if (obtenerDato(actual) > obtenerDato(sig)) {
                int temp = obtenerDato(actual);
                setDato(actual, obtenerDato(sig));
                setDato(sig, temp);
                intercambio = 1;
            }
            actual = sig;
        }
        limite = actual;
    } while (intercambio);
}

ListaPtr ordenarListaCopia(ListaPtr lista) {
    ListaPtr nueva = duplicarLista(lista);
    ordenarLista(nueva);
    return nueva;
}

ListaPtr duplicarLista(ListaPtr lista) {
    ListaPtr nueva = crearLista();
    NodoPtr actual = lista->primero;
    while (actual != NULL) {
        insertarUltimo(nueva, obtenerDato(actual));
        actual = obtenerSiguiente(actual);
    }
    return nueva;
}

int buscarElemento(ListaPtr lista, DatoPtr dato) {
    int posicion = 1;
    NodoPtr actual = lista->primero;
    while (actual != NULL) {
        if (obtenerDato(actual) == dato) {
            return posicion;
        }
        actual = obtenerSiguiente(actual);
        posicion++;
    }
    return -1;
}

void insertarEnOrden(ListaPtr lista, DatoPtr dato) {
    NodoPtr nuevo = crearNodo(dato, NULL);

    if (lista->primero == NULL || dato < obtenerDato(lista->primero)) {
        setSiguiente(nuevo, lista->primero);
        lista->primero = nuevo;
        return;
    }

    NodoPtr actual = lista->primero;
    while (obtenerSiguiente(actual) != NULL && obtenerDato(obtenerSiguiente(actual)) < dato) {
        actual = obtenerSiguiente(actual);
    }

    setSiguiente(nuevo, obtenerSiguiente(actual));
    setSiguiente(actual, nuevo);
}

void mostrarLista(ListaPtr lista){

    printf("\n<LISTA> TAM:%d \n", obtenerTamanio(lista));
    NodoPtr actual = lista->primero;

    while (actual!=NULL){

        mostrarNodo(actual);
        actual = obtenerSiguiente(actual);
    }
    printf("\n\n");



};

void mostrarListaChar(ListaPtr lista){

    printf("\n<LISTA> TAM:%d \n", obtenerTamanio(lista));
    NodoPtr actual = lista->primero;

    while (actual!=NULL){

        mostrarNodoChar(actual);
        actual = obtenerSiguiente(actual);
    }
    printf("\n\n");



};


void mostrarListaFloat(ListaPtr lista){

    printf("\n<LISTA> TAM:%d \n", obtenerTamanio(lista));
    NodoPtr actual = lista->primero;

    while (actual!=NULL){

        mostrarNodoFloat(actual);
        actual = obtenerSiguiente(actual);
    }
    printf("\n\n");



};


void liberarLista(ListaPtr lista) {
    NodoPtr actual = lista->primero;
    while (actual != NULL) {
        NodoPtr siguiente = obtenerSiguiente(actual);
        liberarNodo(actual);
        actual = siguiente;
    }
}
