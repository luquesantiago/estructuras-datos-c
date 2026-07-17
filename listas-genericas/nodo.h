#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

struct Nodo;

typedef struct Nodo * NodoPtr;

typedef void * DatoPtr;

DatoPtr obtenerDato(NodoPtr nodo);
NodoPtr obtenerSiguiente(NodoPtr nodo);

void setDato(NodoPtr nodo, int dato);
void setSiguiente(NodoPtr nodo, NodoPtr sig);

NodoPtr crearNodo(DatoPtr dato, NodoPtr siguiente);

void mostrarNodo(NodoPtr nodo);

void liberarNodo(NodoPtr nodo);





#endif // NODO_H_INCLUDED
