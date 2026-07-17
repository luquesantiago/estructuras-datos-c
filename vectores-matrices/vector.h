#ifndef VECTOR_H
#define VECTOR_H

// Generación y carga
int* generarVec(int tam);
void cargarVector(int *vec, int tam, int manual);
void generarNumeros(int *vec, int tam, int permitir_repetidos);

// Mostrar
void mostrarVec(int *vec, int tam);
void mostrarVecInvertido(int *vec, int tam);

// Análisis
int contarPares(int *vec, int tam);
int moduloVector(int *vec, int tam);
int buscarMaximo(int *vec, int tam,int *pos);
int buscarMinimo(int *vec, int tam, int *pos);


// Ordenamientos
void ordenarBurbuja(int *vec, int tam);
void ordenarSeleccion(int *vec, int tam);
void ordenarInsercion(int *vec, int tam);

// Operaciones entre vectores
int* sumarVectores(int *vec1, int *vec2, int tam);
int multiplicacionEscalar(int *vec1, int *vec2, int tam);

// Búsquedas
int buscarSecuencial(int *vec, int tam, int clave);
int buscarBinaria(int *vec, int tam, int clave);

// Liberar memoria
void liberarVec(int *vec);

#endif
