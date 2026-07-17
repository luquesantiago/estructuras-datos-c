#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED
/// movi la estructura nodo al .h por que
/// me saltaba un error de referencia como si no conociera la estructura ,probe y funciono
struct Nodo;

typedef void * DatoPtr;

typedef struct Nodo * NodoPtr;



DatoPtr getDato(NodoPtr nodo);
NodoPtr getSiguiente(NodoPtr nodo);

void setDato(NodoPtr nodo, DatoPtr nuevoDato);
void setSiguiente(NodoPtr nodo, NodoPtr nuevoSiguiente);

NodoPtr crearNodo(DatoPtr dato, NodoPtr siguiente);

int compararint(void *d1,void * d2);
int compararchar(void *d1,void * d2);

void mostrarNodo(void* nodo);
void mostrarChar(void* nodo);
void mostrarFloat(void* nodo);

void liberarNodo(NodoPtr nodo);





#endif // NODO_H_INCLUDED
