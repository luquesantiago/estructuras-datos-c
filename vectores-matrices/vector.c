#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "vector.h"

int* generarVec(int tam) {
    int *vec = (int*)malloc(sizeof(int) * tam);
    if (!vec) {
        printf("Error al asignar memoria.\n");
        exit(1);
    }
    return vec;
}

void cargarVector(int *vec, int tam, int manual) {
    if (manual) {
        printf("Ingrese %d numeros enteros:\n", tam);
        for (int i = 0; i < tam; i++) {
            scanf("%d", &vec[i]);
        }
    } else {
        generarNumeros(vec, tam, 0);
    }
}

void generarNumeros(int *vec, int tam, int permitir_repetidos) {

    int i, j, num;
    for (i = 0; i < tam; i++) {
        do {
            num = rand() % 100;
            for (j = 0; j < i; j++) {
                if (!permitir_repetidos && vec[j] == num)
                    break;
            }
        } while (j < i);
        vec[i] = num;
    }
}

void mostrarVec(int *vec, int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%02d ", vec[i]);
    }
    printf("\n");
}

void mostrarVecInvertido(int *vec, int tam) {
    printf("Invertido: ");
    for (int i = tam - 1; i >= 0; i--) {
        printf("%02d ", vec[i]);
    }
    printf("\n");
}

int contarPares(int *vec, int tam) {
    int cont = 0;
    for (int i = 0; i < tam; i++) {
        if (vec[i] % 2 == 0)
            cont++;
    }
    return cont;
}

int moduloVector(int *vec, int tam) {
    int suma = 0;
    for (int i = 0; i < tam; i++) {
        suma += vec[i] * vec[i];
    }
    return (int)sqrt((double)suma);
}

int buscarMaximo(int *vec, int tam, int *pos) {
    int max = vec[0];
    *pos = 0;
    for (int i = 1; i < tam; i++) {
        if (vec[i] > max) {
            max = vec[i];
            *pos = i;
        }
    }
    return max;
}

int buscarMinimo(int *vec, int tam, int *pos) {
    int min = vec[0];
    *pos = 0;
    for (int i = 1; i < tam; i++) {
        if (vec[i] < min) {
            min = vec[i];
            *pos = i;
        }
    }
    return min;
}

int sumaVector(int* vec, int tam) {
    int suma = 0;
    for (int i = 0; i < tam; i++)
        suma += vec[i];
    return suma;
}

void ordenarBurbuja(int *vec, int tam) {
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - i - 1; j++) {
            if (vec[j] > vec[j + 1]) {
                int temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
            }
        }
    }
}

void ordenarSeleccion(int *vec, int tam) {
    for (int i = 0; i < tam - 1; i++) {
        int min = i;
        for (int j = i + 1; j < tam; j++) {
            if (vec[j] < vec[min])
                min = j;
        }
        int temp = vec[i];
        vec[i] = vec[min];
        vec[min] = temp;
    }
}

void ordenarInsercion(int *vec, int tam) {
    for (int i = 1; i < tam; i++) {
        int clave = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > clave) {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = clave;
    }
}

int* sumarVectores(int *vec1, int *vec2, int tam) {
    int *res = generarVec(tam);
    for (int i = 0; i < tam; i++) {
        res[i] = vec1[i] + vec2[i];
    }
    return res;
}

int multiplicacionEscalar(int *vec1, int *vec2, int tam) {
    int resultado = 0;
    for (int i = 0; i < tam; i++) {
        resultado += vec1[i] * vec2[i];
    }
    return resultado;
}

int buscarSecuencial(int *vec, int tam, int clave) {
    for (int i = 0; i < tam; i++) {
        if (vec[i] == clave)
            return i;
    }
    return -1;
}

int buscarBinaria(int *vec, int tam, int clave) {
    int inicio = 0, fin = tam - 1;
    while (inicio <= fin) {
        int medio = (inicio + fin) / 2;
        if (vec[medio] == clave)
            return medio;
        else if (vec[medio] < clave)
            inicio = medio + 1;
        else
            fin = medio - 1;
    }
    return -1;
}

void liberarVec(int *vec) {
    free(vec);
}
