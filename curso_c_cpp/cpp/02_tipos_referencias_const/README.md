# Lección 02 — Tipos, referencias y `const`

C++ mejora el manejo de datos respecto a C con tres herramientas que usarás constantemente:
**referencias**, el tipo **`std::string`** y un uso más rico de **`const`** y **`auto`**.

## `std::string`: cadenas de verdad

En C una cadena era un incómodo arreglo de `char` con `'\0'`, y había que usar `strcpy`,
`strcmp`, etc. En C++, **`std::string`** (de `<string>`) es un **tipo de texto** que se comporta
como esperas:

```cpp
#include <string>
#include <iostream>
using namespace std;

string nombre = "Ana";
string apellido = "Perez";
string completo = nombre + " " + apellido;   // se concatena con +
cout << completo << " tiene " << completo.length() << " caracteres" << endl;
```

Ventajas frente a las cadenas de C:
- Se **copian** con `=` y se **comparan** con `==`, `<`, `>` (orden alfabético).
- Se **concatenan** con `+`.
- **Crecen** solas (no hay que reservar tamaño ni preocuparse por desbordar).
- Métodos útiles: `.length()`/`.size()`, `.substr(i, n)`, `.find("x")`, `.empty()`, `s[i]`.

### Leer strings

```cpp
string palabra;
cin >> palabra;              // una palabra (se detiene en el espacio)

string linea;
getline(cin, linea);         // una linea completa (con espacios)
```

## Referencias: un "alias" de una variable

Una **referencia** es un **nombre alternativo** para una variable existente. Se declara con `&`:

```cpp
int x = 10;
int &ref = x;      // ref es OTRO NOMBRE para x
ref = 20;          // modifica x
cout << x << endl; // 20
```

`ref` y `x` son **la misma** casilla de memoria. A diferencia de un puntero, una referencia:
- **Debe** inicializarse al declararse.
- **No** puede cambiar a qué se refiere después.
- Se usa como una variable normal (sin `*` para desreferenciar).

### Para qué sirven: paso por referencia a funciones

En C, para que una función modificara una variable, pasabas un **puntero** (`int *`). En C++
puedes pasar una **referencia**, más limpia (sin `&` en la llamada ni `*` dentro):

```cpp
void duplicar(int &n) {      // recibe una referencia
    n = n * 2;               // modifica el original directamente
}
int main() {
    int x = 5;
    duplicar(x);             // sin & en la llamada
    cout << x << endl;       // 10
}
```

Compara con la versión C (`void duplicar(int *n){ *n *= 2; } ... duplicar(&x);`): la de C++ es más
legible. Las referencias son el mecanismo preferido en C++ para "salida" y para evitar copias.

### Referencias `const`: eficiencia sin modificar

Pasar objetos **grandes** (como un `string`) por **valor** los **copia** (costoso). Pasarlos por
**referencia `const`** evita la copia **y** promete no modificarlos:

```cpp
void saludar(const string &nombre) {   // no se copia, no se modifica
    cout << "Hola, " << nombre << endl;
}
```
Regla práctica: para parámetros de objetos que **no** vas a modificar, usa `const T&`.

## `const`: prometer que algo no cambia

Ya lo viste en C; en C++ se usa aún más:

```cpp
const double PI = 3.14159;      // constante
const int MAX = 100;
```
Se prefiere `const` sobre `#define` porque tiene **tipo** y respeta el ámbito. Para constantes
conocidas en compilación existe además **`constexpr`** (`constexpr int N = 10;`).

## `auto`: que el compilador deduzca el tipo

Cuando el tipo es obvio (o muy largo), **`auto`** le pide al compilador que lo deduzca del valor
de inicialización:

```cpp
auto x = 5;              // int
auto pi = 3.14;         // double
auto nombre = string("Ana");   // std::string
```
`auto` es muy útil con tipos complejos (iteradores de la STL, lección 09), donde escribir el tipo
completo sería tedioso. No abuses de él cuando el tipo explícito aporte claridad.

## `nullptr`: el puntero nulo de C++

Para punteros nulos, usa **`nullptr`** en vez de `NULL` o `0`:

```cpp
int *p = nullptr;       // mas seguro y claro que NULL
```

## El `for` "para cada" (range-based for)

Un adelanto útil: C++ tiene un `for` que recorre **cada elemento** de una colección sin índices:

```cpp
int numeros[] = {10, 20, 30};
for (int n : numeros) {          // "para cada n en numeros"
    cout << n << " ";
}
// con auto y referencia const para no copiar:
for (const auto &n : numeros) { cout << n << " "; }
```
Lo usaremos mucho con los contenedores de la STL.

## Errores típicos

- Olvidar `#include <string>` al usar `std::string`.
- Declarar una referencia **sin** inicializar (`int &r;` es error).
- Pasar objetos grandes por valor (copia innecesaria) en vez de `const T&`.
- Mezclar `getline` y `cin >>` sin cuidar el `'\n'` pendiente (como en C con `scanf`).

## Resumen

- `std::string` es texto de verdad: `+`, `==`, `.length()`, crece solo.
- Una **referencia** (`int &r = x`) es un alias; se usa para **paso por referencia** limpio.
- **`const T&`** pasa objetos grandes sin copiarlos y sin poder modificarlos.
- `const`/`constexpr` para constantes; `auto` para deducir tipos; `nullptr` para punteros nulos.
- El `for (x : coleccion)` recorre cada elemento.

## Ejemplos

- [`ejemplos/strings.cpp`](ejemplos/strings.cpp)
- [`ejemplos/referencias.cpp`](ejemplos/referencias.cpp)
- [`ejemplos/auto_y_for.cpp`](ejemplos/auto_y_for.cpp)

## Ejercicios

En [`ejercicios/`](ejercicios/).

## Para profundizar

- **Stroustrup**, *A Tour of C++*, cap. 1–2.
- **learncpp.com**, "References" y "std::string".
- **cppreference**, "Reference declaration", "std::string".
  https://en.cppreference.com/w/cpp/string/basic_string
