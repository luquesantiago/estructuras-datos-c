#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "nodo.h"


struct Lista;

typedef struct Lista * ListaPtr;


NodoPtr getPrimero(ListaPtr lista);
void setPrimero(ListaPtr lista, NodoPtr nuevoPrimero);

ListaPtr crearLista();

void insertarPrimero(ListaPtr lista, DatoPtr dato);
void insertarUltimo(ListaPtr lista, DatoPtr dato);
void insertarPosicion(ListaPtr lista, DatoPtr dato, int posicion); //tarea


DatoPtr obtenerPrimero(ListaPtr lista);
DatoPtr obtenerUltimo(ListaPtr lista); //tarea
DatoPtr obtenerPosicion(ListaPtr lista, int posicion); //tarea

int eliminarPrimero(ListaPtr lista);
int eliminarUltimo(ListaPtr lista); //tarea
int eliminarPosicion(ListaPtr lista, int posicion); //tarea

int obtenerTamanio(ListaPtr lista); //tarea


ListaPtr ordenarListaCopia(ListaPtr lista,int(*resultadoComparacion)(DatoPtr, DatoPtr));
ListaPtr duplicarLista(ListaPtr lista);//tarea

int buscarElemento(ListaPtr lista, DatoPtr datoBuscado);//tarea

void insertarEnOrden(ListaPtr lista, DatoPtr dato,int(*resultadoComparacion)(DatoPtr,DatoPtr));//tarea, si la lista está ordenada cada vez que
//se inserta se inserta en la posición que corresponda

void mostrarListaGenerica(ListaPtr lista, void(*mostrar)(DatoPtr));

void liberarLista(ListaPtr lista);

void ordenarLista(ListaPtr lista, int(*resultadoComparacion)(DatoPtr, DatoPtr));
void ordenarListaInsercion(ListaPtr lista, int (*resultadoComparacion)(DatoPtr, DatoPtr));
void ordenarListaSeleccion(ListaPtr lista, int (*resultadoComparacion)(DatoPtr, DatoPtr));


#endif // LISTA_H_INCLUDED
