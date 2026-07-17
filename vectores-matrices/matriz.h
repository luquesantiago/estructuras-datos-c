#ifndef MATRIZ_H
#define MATRIZ_H

int** generarMatriz(int filas, int columnas);
void cargarMatriz(int** mat, int filas, int columnas, int manual);
void mostrarMatriz(int** mat, int filas, int columnas);


int buscarMaximoMatriz(int** mat, int filas, int columnas,int* filaMax, int* colMax);
int buscarMinimoMatriz(int** mat, int filas, int columnas,int* filaMin, int* colMin);



double promedioFila(int* fila, int columnas);
void promediosFilas(int** mat, int filas, int columnas);
void promediosColumnas(int** mat, int filas, int columnas);
double promedioGeneral(int** mat, int filas, int columnas);

// Sumas
void sumaFilas(int** mat, int filas, int columnas);
void sumaColumnas(int** mat, int filas, int columnas);

// Operaciones con matrices
int** sumarMatrices(int** mat1, int** mat2, int filas, int columnas);
int** multiplicarMatrices(int** mat1, int f1, int c1, int** mat2, int f2, int c2);

void liberarMatriz(int** mat, int filas);
#endif
