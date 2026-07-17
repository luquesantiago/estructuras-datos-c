
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "persona.h"


struct PersonaE{ //.nombre

    int dni;
    char nombre[15];


};

int getDNI(PersonaPtr p){
    return p->dni;

};
char* getNombre(PersonaPtr p){

    return p->nombre;
};



void setDNI(PersonaPtr p, int nuevoDNI){

    p->dni = nuevoDNI;
};

void setNombre(PersonaPtr p, char nuevoNombre[15]){

    strcpy(p->nombre, nuevoNombre);
};


PersonaPtr crearPersona(int d, char n[15]){

    PersonaPtr p = (PersonaPtr) malloc(sizeof(struct PersonaE)); //void *

    p->dni = d;
    strcpy(p->nombre, n);



    return p;


};



;


//Destructor
void destruirPersona(PersonaPtr p){

    free(p);


};

//Mostrar
void mostrarPersona(PersonaPtr p){


    printf("\n---------- PERSONA -----------\n");
    printf("DNI: %d\n", p->dni);
    printf("NOMBRE: %s\n", p->nombre);


};

void mostrarPersonaDatoPtr (void * p){

    PersonaPtr persona = *(PersonaPtr *)p;

    mostrarPersona(persona);


}

int compararPersonasDatoPtr(void * p1, void * p2){

    PersonaPtr persona1 = *(PersonaPtr *)p1;
    PersonaPtr persona2 = *(PersonaPtr *)p2;

    return (persona1->dni > persona2->dni);


}
