#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED


struct NodoE ;


typedef struct NodoE * Nodo;


Nodo nuevoNodo(int dato) ;

void insertar( Nodo nodo, int dato) ;

void preorden( Nodo nodo) ;

void inorden( Nodo nodo) ;

void postorden( Nodo nodo) ;

Nodo buscar(Nodo nodo, int dato);



#endif // ARBOL_H_INCLUDED
