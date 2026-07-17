#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "matriz.h"

int** generarMatriz(int filas, int columnas) {
    int** mat = (int**)malloc(filas * sizeof(int*));
    if (!mat) {
        printf("Error al asignar memoria.\n");
        exit(1);
    }
    for (int i = 0; i < filas; i++) {
        mat[i] = generarVec(columnas);
    }
    return mat;
}

void cargarMatriz(int** mat, int filas, int columnas, int manual) {
    for (int i = 0; i < filas; i++) {
        cargarVector(mat[i], columnas, manual);
    }
}

void mostrarMatriz(int** mat, int filas, int columnas) {
    printf("Matriz:\n");
    for (int i = 0; i < filas; i++) {
        mostrarVec(mat[i], columnas);
    }
}

int buscarMaximoMatriz(int** mat, int filas, int columnas, int* filaMax, int* colMax) {
    int pos;
    int max = buscarMaximo(mat[0], columnas, &pos);
    *filaMax = 0;
    *colMax = pos;

    for (int i = 1; i < filas; i++) {
        int maxFila = buscarMaximo(mat[i], columnas, &pos);
        if (maxFila > max) {
            max = maxFila;
            *filaMax = i;
            *colMax = pos;
        }
    }
    return max;
}

int buscarMinimoMatriz(int** mat, int filas, int columnas, int* filaMin, int* colMin) {
    int pos;
    int min = buscarMinimo(mat[0], columnas, &pos);
    *filaMin = 0;
    *colMin = pos;

    for (int i = 1; i < filas; i++) {
        int minFila = buscarMinimo(mat[i], columnas, &pos);
        if (minFila < min) {
            min = minFila;
            *filaMin = i;
            *colMin = pos;
        }
    }
    return min;
}

double promedioFila(int* fila, int columnas) {
    return (double)sumaVector(fila, columnas) / columnas;
}

void promediosFilas(int** mat, int filas, int columnas) {
    printf("Promedios por fila:\n");
    for (int i = 0; i < filas; i++) {
        printf("Fila %d: %.2f\n", i, promedioFila(mat[i], columnas));
    }
}

void promediosColumnas(int** mat, int filas, int columnas) {
    printf("Promedios por columna:\n");
    for (int j = 0; j < columnas; j++) {
        int suma = 0;
        for (int i = 0; i < filas; i++)
            suma += mat[i][j];
        printf("Columna %d: %.2f\n", j, (double)suma / filas);
    }
}

double promedioGeneral(int** mat, int filas, int columnas) {
    double sumaTotal = 0;
    for (int i = 0; i < filas; i++) {
        sumaTotal += promedioFila(mat[i], columnas);
    }
    return sumaTotal / filas;
}

void sumaFilas(int** mat, int filas, int columnas) {
    printf("Suma por fila:\n");
    for (int i = 0; i < filas; i++) {
        printf("Fila %d: %d\n", i, sumaVector(mat[i], columnas));
    }
}

void sumaColumnas(int** mat, int filas, int columnas) {
    printf("Suma por columna:\n");
    for (int j = 0; j < columnas; j++) {
        int suma = 0;
        for (int i = 0; i < filas; i++)
            suma += mat[i][j];
        printf("Columna %d: %d\n", j, suma);
    }
}

int** sumarMatrices(int** mat1, int** mat2, int filas, int columnas) {
    int** res = generarMatriz(filas, columnas);
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            res[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    return res;
}

int** multiplicarMatrices(int** mat1, int f1, int c1, int** mat2, int f2, int c2) {
    if (c1 != f2) {
        printf("No se pueden multiplicar: dimensiones incompatibles.\n");
        return NULL;
    }
    int** res = generarMatriz(f1, c2);
    for (int i = 0; i < f1; i++) {

        for (int j = 0; j < c2; j++) {

            res[i][j] = 0;

            for (int k = 0; k < c1; k++) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return res;
}

void liberarMatriz(int** mat, int filas) {
    for (int i = 0; i < filas; i++) {
        liberarVec(mat[i]);
    }
    free(mat);
}
