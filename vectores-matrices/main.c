#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "matriz.h"

int main() {
     srand(time(NULL));
/////////////////////////////////////////////////// declaracion vector////////////////////////////7
    int tam = 10;
    int *posmax,*posmin;

    int *vec = generarVec(tam);
    cargarVector(vec, tam, 0);
    int *vec2 = generarVec(tam);
    cargarVector(vec2, tam, 0);

    int max =buscarMaximo(vec, tam,&posmax);
    int min=buscarMinimo(vec, tam,&posmin);

/////////////////////////////////////////////////declaracion matriz//////////////////////////////

    int filas = 3;
    int columnas = 3;
    int*filaMax,*colMax,*filaMin,* colMin;

    int **mat = generarMatriz(filas, columnas);
    cargarMatriz(mat, filas, columnas, 0);

    int maxMat = buscarMaximoMatriz(mat, filas, columnas,&filaMax,&colMax);
    int minMat = buscarMinimoMatriz(mat, filas, columnas,&filaMin,&colMin);
    double promedioGen = promedioGeneral(mat, filas, columnas);

    int **mat2 = generarMatriz(filas, columnas);
    cargarMatriz(mat2, filas, columnas, 0);
    int **sumaMat = sumarMatrices(mat, mat2, filas, columnas);

///////////////////////////////////////////////////pruebas vec//////////////////////////////////////////////////////

    printf("==== Pruebas con Vectores ====\n");
    printf("Vector: ");
    mostrarVec(vec, tam);


    ordenarBurbuja(vec, tam);
    printf("Vector: ");
    mostrarVec(vec, tam);
    printf("\n");

    printf("Cantidad de pares: %d\n", contarPares(vec, tam));
    printf("Modulo (Pitagoras) del vector: %d\n",  moduloVector(vec, tam));
    printf("Maximo del vector: %d ,en la posicion %d \n", max , posmax+1);
    printf("Minimo del vector: %d ,en la posicion %d \n",min, posmin+1);
    printf("\n");
    printf("\n");

    printf("Vector1: ");
    mostrarVec(vec,tam);
    printf("Vector2: ");
    mostrarVec(vec2,tam);
    printf("Suma de vectores:\n");
    mostrarVec(sumarVectores(vec, vec2, tam), tam);

    printf("\nMultiplicacion escalar de vectores: %d\n", multiplicacionEscalar(vec, vec2, tam));

    liberarVec(vec);
    liberarVec(vec2);

////////////////////////////////////////////////////pruebas mat/////////////////////////////////////////////////////

    printf("\n==== Pruebas con Matrices ====\n");
    mostrarMatriz(mat, filas, columnas);
    printf("\n");

    printf("Maximo de la matriz: %d en [%d],[%d]  \n", maxMat,filaMax,colMax);
    printf("Minimo de la matriz: %d en [%d],[%d]  \n", minMat,filaMin,colMin);
    printf("\n");

    promediosFilas(mat, filas, columnas);
    printf("\n");
    promediosColumnas(mat, filas, columnas);
    printf("\n");
    printf("Promedio general de la matriz: %.2f\n", promedioGen);
    printf("\n");
    sumaFilas(mat, filas, columnas);
    printf("\n");
    sumaColumnas(mat, filas, columnas);
    printf("\n");
    mostrarMatriz(mat,filas,columnas);
    printf("\n");
    mostrarMatriz(mat2,filas,columnas);
    printf("\n");
    printf("Suma de matrices:\n");
    mostrarMatriz(sumaMat, filas, columnas);
    printf("\n");
    int **prodMat = multiplicarMatrices(mat, filas, columnas, mat2, filas, columnas);
    if (prodMat) {
        printf("Producto de matrices:\n");
        mostrarMatriz(prodMat, filas, columnas);
    }


    liberarMatriz(mat, filas);
    liberarMatriz(mat2, filas);
    liberarMatriz(sumaMat, filas);
    liberarMatriz(prodMat, filas);

    return 0;
}
