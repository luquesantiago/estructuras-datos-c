# Estructuras de datos en C

Implementaciones de estructuras de datos clásicas en C, de la cursada de Algoritmos y Estructuras de Datos. En todos los casos se separa interfaz (`.h`) de implementación (`.c`) usando TDA con tipos opacos.

## Contenido

### `arbol-binario/`
Árbol binario de búsqueda: inserción y recorridos **preorden**, **inorden** y **postorden**.

### `listas-pilas-colas/`
Lista enlazada, **pila** y **cola** sobre un TDA nodo común, con un TDA `persona` como dato de ejemplo.

### `listas-genericas/`
Lista enlazada **genérica con `void*`**: la lista no conoce el tipo de dato que almacena.

### `vectores-matrices/`
Vectores y matrices con **memoria dinámica** (`malloc`/`realloc`).

## Compilar

Cada carpeta es independiente. Por ejemplo:

```bash
cd arbol-binario
gcc *.c -o programa
./programa
```

## Herramientas

C (GCC), Code::Blocks como IDE de cursada.

## Compilar

Cada carpeta tiene su `Makefile`:

```bash
cd arbol-binario   # o cualquier otra carpeta
make
./main
```

## Salida de ejemplo (arbol-binario)

```text
----- Ejemplo arbol binario ----

Imprimiendo preorden
28,11,6,1,2,10,21,25,96,30,97,
Imprimiendo inorden
1,2,6,10,11,21,25,28,30,96,97,
Imprimiendo postorden
2,1,10,6,25,21,11,30,97,96,28,
Buscando el 11
No esta el 11 != 28 --> IZQUIERDA
Encontrado
```
