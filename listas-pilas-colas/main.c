#include <stdio.h>
#include <stdlib.h>
#include "persona.h"
#include "lista.h"
#include "pila.h"
#include "cola.h"

int main()
{

//    ListaPtr lista = crearLista();
//    ListaPtr lista2 = crearLista();
//    ListaPtr lista3 = crearLista();
//
//
//    int n1 = 40,n2 = 11,n3 = 19,n4 = 21,n5=12;
//
//
//    insertarPrimero(lista, &n1);
//    insertarPrimero(lista, &n2);
//    insertarUltimo(lista, &n3);
//    insertarPrimero(lista, &n4);
//
//
//
//    ordenarLista(lista,&compararint);
//
//    insertarEnOrden(lista,&n5,&compararint);
//
//    mostrarListaGenerica(lista,&mostrarNodo);
//    printf("el dato buscado esta en la pos : %d\n",(buscarElemento(lista,&n2)));
//
/////////////////////////////////////////////////////////////
//
//    char nom1[] = "nico",  nom2[] = "brenda", nom3[] = "walter" ,nom4[] = "flor" , nom5[] = "aston";
//
//
//    insertarPrimero(lista2, nom1);
//    insertarPrimero(lista2, nom2);
//    insertarUltimo(lista2, nom3);
//    insertarPrimero(lista2, nom4);
//
//    ordenarLista(lista2,&compararchar);
//
//    insertarEnOrden(lista2,nom5,&compararchar);
//
//    mostrarListaGenerica(lista2,&mostrarChar);
//    printf("el dato buscado esta en la pos : %d\n",(buscarElemento(lista2,&nom2)));
//
/////////////////////////////////////////////////////////
//
//
//    float nf1 = 400.12,nf2 = 11.43,nf3 = 109.009,nf4 = 21.14,  nf5=12.55;
//
//
//    insertarPrimero(lista3, &nf1);
//    insertarPrimero(lista3, &nf2);
//    insertarUltimo(lista3, &nf3);
//    insertarPrimero(lista3, &nf4);
//
//    ordenarLista(lista3,&compararint);
//
//    insertarEnOrden(lista3,&nf5,&compararint);
//
//    mostrarListaGenerica(lista3,&mostrarFloat);
//    printf("el dato buscado esta en la pos : %d\n",(buscarElemento(lista3,&nf5)));
//
//////////////////////////////////////////////////////
//
//    PersonaPtr p1 = crearPersona(1, "Nico");
//    PersonaPtr p2 = crearPersona(33, "Walter");
//    PersonaPtr p3 = crearPersona(12, "Brenda");
//    PersonaPtr p5 = crearPersona(13, "Brenda2");
//    PersonaPtr p4 = crearPersona(22, "bruno");
//    ListaPtr lista4 = crearLista();
//
//    insertarPrimero(lista4, &p1);
//    insertarPrimero(lista4, &p2);
//    insertarPrimero(lista4, &p3);
//    insertarPrimero(lista4,&p5);
//
//    ordenarLista(lista4, &compararPersonasDatoPtr);
//
//    insertarEnOrden(lista4,&p4,&compararPersonasDatoPtr);
//
//    mostrarListaGenerica(lista4, &mostrarPersonaDatoPtr);
//    printf("el dato buscado esta en la pos : %d\n",(buscarElemento(lista4,&p2)));
//    printf("el dato buscado esta en la pos : %d\n",(buscarElementoBinaria(lista4,&p2,&compararPersonasDatoPtr)));
//
///////////////////////////////////////////////////////////////

    ColaPtr cola = crearCola();

    char nom1[] = "nico",  nom2[] = "brenda", nom3[] = "walter" ,nom4[] = "flor" , nom5[] = "aston";

    encolar(cola,&nom1);
    encolar(cola,&nom2);
    encolar(cola,&nom3);
    encolar(cola,&nom4);
    encolar(cola,&nom5);

    desencolar(cola);

    ColaPtr cola2= duplicarCola(cola);

    printf("el siguiente es %s ,",(char*)desencolar(cola2));

////////////////////////////////////////////////////////////////

    PilaPtr pila = crearPila();

    char lib1[] = "nico",  lib2[] = "brenda", lib3[] = "walter" ,lib4[] = "flor" , lib5[] = "aston";

    pushPila(pila,&lib1);
    pushPila(pila,&lib2);
    pushPila(pila,&lib3);
    pushPila(pila,&lib4);
    pushPila(pila,&lib5);

    popPila(pila);

    PilaPtr pila2= duplicarPila(pila);

    printf("tu libro es %s",(char *)popPila(pila2));

    return 0;
}
