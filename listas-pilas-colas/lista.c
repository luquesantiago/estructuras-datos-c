#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"
#include "lista.h"

struct Lista{

    NodoPtr primero;

};




ListaPtr crearLista(){

    ListaPtr lista = malloc(sizeof(struct Lista));

    lista->primero = NULL;

    return lista;
};


void insertarPrimero(ListaPtr lista, DatoPtr dato){

    NodoPtr nuevoNodo = crearNodo(dato, lista->primero);

    lista->primero = nuevoNodo;


};
void insertarUltimo(ListaPtr lista, DatoPtr dato){

    NodoPtr nuevoNodo = crearNodo(dato, NULL);

    NodoPtr actual = lista->primero;
    if(actual == NULL){
        lista->primero = nuevoNodo;
    }else{
        while(getSiguiente(actual)!=NULL){

            actual = getSiguiente(actual);
        }

       setSiguiente(actual, nuevoNodo);
        }

}; //tarea
void insertarPosicion(ListaPtr lista, DatoPtr dato, int posicion) {
    NodoPtr nuevoNodo = crearNodo(dato, NULL);

    if (posicion <= 0 || lista->primero == NULL) {
        setSiguiente(nuevoNodo, lista->primero);
        lista->primero = nuevoNodo;
        return;
    }

    NodoPtr actual = lista->primero;
    int cont = 1;

    while (getSiguiente(actual) != NULL && cont < posicion - 1) {
        actual = getSiguiente(actual);
        cont++;
    }

    setSiguiente(nuevoNodo, getSiguiente(actual));
    setSiguiente(actual, nuevoNodo);
}

DatoPtr obtenerPrimero(ListaPtr lista) {
    return getDato(lista->primero);
}
DatoPtr obtenerUltimo(ListaPtr lista) {
    NodoPtr actual = lista->primero;
    while (getSiguiente(actual) != NULL) {
        actual = getSiguiente(actual);
    }
    return getDato(actual);
}
DatoPtr obtenerPosicion(ListaPtr lista, int pos) {
    NodoPtr actual = lista->primero;
    for (int i = 1; i <= pos; i++) {
        if (i == pos) {
            return getDato(actual);
        }
        actual = getSiguiente(actual);
    }
    return 0;
}

int eliminarPrimero(ListaPtr lista) {
    if (lista->primero == NULL) return 0;
    NodoPtr actual = lista->primero;
    lista->primero = getSiguiente(actual);
    liberarNodo(actual);
    return 1;
}
int eliminarUltimo(ListaPtr lista) {
    if (lista->primero == NULL) return 0;

    NodoPtr actual = lista->primero;
    NodoPtr anterior = NULL;

    while (getSiguiente(actual) != NULL) {
        anterior = actual;
        actual = getSiguiente(actual);
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
        lista->primero = getSiguiente(actual);
        liberarNodo(actual);
        return 1;
    }

    while (getSiguiente(actual) != NULL) {
        if (cont == posicion) {
            setSiguiente(anterior, getSiguiente(actual));
            liberarNodo(actual);
            return 1;
        }
        anterior = actual;
        actual = getSiguiente(actual);
        cont++;
    }

    return 0;
}

int obtenerTamanio(ListaPtr lista){

    int tam = 0 ;
    NodoPtr actual = lista->primero;
    while (actual != NULL){

            tam = tam + 1;
            actual = getSiguiente(actual);

    }

    return tam;
}; //tarea

void ordenarLista(ListaPtr lista, int(*resultadoComparacion)(DatoPtr, DatoPtr)){

    int permutacion;
    NodoPtr nodo;
    NodoPtr ultimo = NULL;

    if(obtenerTamanio(lista)< 2){

    } else {

        do{
            permutacion = 0 ;
            nodo = lista->primero;

            while (getSiguiente(nodo) != ultimo){

                if( resultadoComparacion(getDato(nodo),getDato(getSiguiente(nodo)))){


                    DatoPtr aux = getDato(nodo);
                    setDato(nodo, getDato(getSiguiente(nodo)));
                    setDato(getSiguiente(nodo), aux);
                    permutacion = 1;

                }
                nodo = getSiguiente(nodo);

            }
            ultimo = nodo;

        }while (permutacion!=0);


    }
}
void ordenarListaInsercion(ListaPtr lista, int (*resultadoComparacion)(DatoPtr, DatoPtr)) {
    if (obtenerTamanio(lista) < 2) return;

    NodoPtr actual = getSiguiente(lista->primero);

    while (actual != NULL) {
        NodoPtr comparador = lista->primero;
        while (comparador != actual) {
            if (resultadoComparacion(getDato(actual), getDato(comparador))) {
                DatoPtr aux = getDato(comparador);
                setDato(comparador, getDato(actual));
                setDato(actual, aux);
            }
            comparador = getSiguiente(comparador);
        }
        actual = getSiguiente(actual);
    }
}
void ordenarListaSeleccion(ListaPtr lista, int (*resultadoComparacion)(DatoPtr, DatoPtr)) {
    if (obtenerTamanio(lista) < 2) return;

    NodoPtr i = lista->primero;

    while (i != NULL) {
        NodoPtr minNodo = i;
        NodoPtr j = getSiguiente(i);

        while (j != NULL) {
            if (resultadoComparacion(getDato(minNodo), getDato(j))) {
                minNodo = j;
            }
            j = getSiguiente(j);
        }

        if (minNodo != i) {
            DatoPtr aux = getDato(i);
            setDato(i, getDato(minNodo));
            setDato(minNodo, aux);
        }

        i = getSiguiente(i);
    }
}

ListaPtr ordenarListaCopia(ListaPtr lista,int(*resultadoComparacion)(DatoPtr, DatoPtr)) {
    ListaPtr nueva = duplicarLista(lista);
    ordenarLista(nueva,resultadoComparacion);
    return nueva;
}

ListaPtr duplicarLista(ListaPtr lista) {
    ListaPtr nueva = crearLista();
    NodoPtr actual = lista->primero;
    while (actual != NULL) {
        insertarUltimo(nueva, getDato(actual));
        actual = getSiguiente(actual);
    }
    return nueva;
}

int buscarElemento(ListaPtr lista, DatoPtr dato) {
    int posicion = 1;
    NodoPtr actual = lista->primero;
    while (actual != NULL) {
        if (getDato(actual) == dato) {
            return posicion;
        }
        actual = getSiguiente(actual);
        posicion++;
    }
    return -1;
}
int buscarElementoBinaria(ListaPtr lista, DatoPtr dato,int(*resultadoComparacion)(DatoPtr, DatoPtr)) {
    int inicio = 1;
    int fin = obtenerTamanio(lista);

    while (inicio <= fin) {
        int medio = (inicio + fin) / 2;
        DatoPtr datoMedio = obtenerPosicion(lista, medio);

        if (datoMedio == dato) {
            return medio;
        } else if (resultadoComparacion(dato,datoMedio)) {
            inicio = medio + 1;
        } else {
            fin = medio - 1;
        }
    }

    return -1;
}




void insertarEnOrden(ListaPtr lista, DatoPtr dato,int(*resultadoComparacion)(DatoPtr,DatoPtr)) {
    NodoPtr nuevo = crearNodo(dato, NULL);

    if (lista->primero == NULL || resultadoComparacion(getDato(lista->primero),dato)) {
        setSiguiente(nuevo, lista->primero);
        lista->primero = nuevo;
        return;
    }

    NodoPtr actual = lista->primero;
    while (getSiguiente(actual) != NULL && resultadoComparacion(dato,getDato(getSiguiente(actual)))) {
        actual = getSiguiente(actual);
    }

    setSiguiente(nuevo, getSiguiente(actual));
    setSiguiente(actual, nuevo);
}


void mostrarListaGenerica(ListaPtr lista, void(*mostrar)(DatoPtr)){

    printf("\n<LISTA> TAM:%d \n", obtenerTamanio(lista));
    NodoPtr actual = lista->primero;

    while (actual!=NULL){

        mostrar(getDato(actual));
        actual = getSiguiente(actual);
    }
    printf("\n\n");



};

void liberarLista(ListaPtr lista) {

    NodoPtr actual = lista->primero;
    NodoPtr aux;

    while (actual!=NULL){
        aux = actual;
        actual = getSiguiente(actual);
        liberarNodo(aux);
    }
    free(lista);
}
