#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "nodo.h"


struct Lista;
typedef struct Lista * ListaPtr;

ListaPtr crearLista();

void insertarPrimero(ListaPtr lista, DatoPtr dato);
void insertarUltimo(ListaPtr lista, DatoPtr dato); //tarea
void insertarPosicion(ListaPtr lista, DatoPtr dato, int posicion); //tarea


DatoPtr obtenerPrimero(ListaPtr lista);
DatoPtr obtenerUltimo(ListaPtr lista); //tarea
DatoPtr obtenerPosicion(ListaPtr lista, int pos); //tarea

int eliminarPrimero(ListaPtr lista);
int eliminarUltimo(ListaPtr lista); //tarea
int eliminarposicion(ListaPtr lista,int posicion); //tarea

int obtenerTamanio(ListaPtr lista); //tarea

void ordenarLista(ListaPtr lista);//tarea
ListaPtr ordenarListaCopia(ListaPtr lista);//tarea
ListaPtr duplicarLista(ListaPtr lista);//tarea

int buscarElemento(ListaPtr lista, DatoPtr dato);//tarea

void insertarEnOrden(ListaPtr lista, DatoPtr dato);//tarea, si la lista está ordenada cada vez que
//se inserta se inserta en la posición que corresponda


void mostrarLista(ListaPtr lista);

void liberarLista(ListaPtr lista);


#endif // LISTA_H_INCLUDED
