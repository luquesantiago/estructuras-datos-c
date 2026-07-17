# Estructuras de datos en C

Implementaciones de estructuras de datos clásicas en C, de la cursada de Algoritmos y Estructuras de Datos.

## Árbol binario de búsqueda (`arbol-binario/`)

TDA de árbol binario de búsqueda con tipo opaco (`struct NodoE` definido en el `.c`, el usuario solo maneja el puntero `Nodo`), separando interfaz (`arbol.h`) de implementación (`arbol.c`).

Operaciones: creación de nodos, inserción, y recorridos **preorden**, **inorden** y **postorden**.

```bash
cd arbol-binario
gcc main.c arbol.c -o arbol
./arbol
```

## Próximamente

Listas enlazadas (int, genéricas y con `void*`), pilas y colas.
