 #ifndef COLA_H_INCLUDED
 #define COLA_H_INCLUDED

#include "nodo.h"

struct Cola;

typedef struct Cola* ColaPtr;


void setPrimeroC(ColaPtr cola, NodoPtr nuevoPrimero);
NodoPtr getPrimeroC(ColaPtr cola);
void setUltimoC(ColaPtr cola, NodoPtr nuevoUltimo);
NodoPtr getUltimoC(ColaPtr cola);


ColaPtr crearCola();
void encolar(ColaPtr Cola, DatoPtr dato); ///ENCOLAR - ENQUEUE
DatoPtr desencolar(ColaPtr Cola); ///DESENCOLAR - DEQUEUE
ColaPtr duplicarCola(ColaPtr Cola);//tarea
void liberarCola(ColaPtr Cola);




 #endif // COLA_H_INCLUDED
