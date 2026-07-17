#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

int main()
{

    ListaPtr lista = crearLista(); //Para int
    ListaPtr lista2 = crearLista(); //para char
    ListaPtr lista3 = crearLista();//Para float

    mostrarLista(lista);
    int n1 = 4,n2 = 11,n3 = 19,n4 = 21;


    insertarPrimero(lista, &n1);
    insertarPrimero(lista, &n2);
    insertarUltimo(lista, &n3);
    insertarPrimero(lista, &n4);

    eliminarPrimero(lista);


    mostrarLista(lista);


    //---------------------------------//
    mostrarListaChar(lista2);
    char nom1[] = "nico",  nom2[] = "brenda", nom3[] = "walter" ,nom4[] = "flor";


    insertarPrimero(lista2, nom1);
    insertarPrimero(lista2, nom2);
    insertarUltimo(lista2, nom3);
    insertarPrimero(lista2, nom4);

    mostrarListaChar(lista2);
    printf("%d",buscarElemento(lista2,nom1));

    //-----------//

    mostrarListaFloat(lista3);
    float nf1 = 4.12,nf2 = 11.43,nf3 = 109.009,nf4 = 21.14;


    insertarPrimero(lista3, &nf1);
    insertarPrimero(lista3, &nf2);
    insertarUltimo(lista3, &nf3);
    insertarPrimero(lista3, &nf4);

    eliminarPrimero(lista3);

    mostrarListaFloat(lista3);




    return 0;
}
