#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"

int main()
{
    printf("----- Ejemplo arbol binario ----\n");

    Nodo raiz = nuevoNodo(28);
    insertar(raiz, 11);
    insertar(raiz, 96);
    insertar(raiz, 21);
    insertar(raiz, 6);
    insertar(raiz, 97);
    insertar(raiz, 1);
    insertar(raiz, 30);
    insertar(raiz, 10);
    insertar(raiz, 2);
    insertar(raiz, 25);
/*
                    28
              11           96
           6      21     30      97
        1     10
           2






 28 11 6 1 2 10 21 30 97 96
*/
    printf("\nImprimiendo preorden\n");
    preorden(raiz);
    printf("\nImprimiendo inorden\n");
    inorden(raiz);
    printf("\nImprimiendo postorden\n");
    postorden(raiz);

    printf("\nBuscando el 11\n");
    Nodo buscado = buscar(raiz, 11);

    if(buscado == NULL){
        printf("No encontrado!!!!!");
    }

    else{

        printf("Encontrado");
    }



    return 0;
}
