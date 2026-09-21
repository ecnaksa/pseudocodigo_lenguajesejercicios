# Lección 03 — Funciones en C++

Las funciones en C++ funcionan como en C (tipo de retorno, parámetros, `return`), pero C++ añade
tres mejoras muy útiles: **sobrecarga**, **parámetros por defecto** y el **paso por referencia**
(que ya conociste en la lección 02).

## Repaso rápido

```cpp
int sumar(int a, int b) {
    return a + b;
}
```
Igual que en C. También puedes usar **prototipos** para declarar antes de definir.

## 1. Sobrecarga de funciones (overloading)

En C, cada función necesita un **nombre único**. En C++ puedes tener **varias funciones con el
mismo nombre**, siempre que se distingan por sus **parámetros** (número o tipos). El compilador
elige la correcta según cómo la llames:

```cpp
int    sumar(int a, int b)          { return a + b; }
double sumar(double a, double b)    { return a + b; }
int    sumar(int a, int b, int c)   { return a + b + c; }

sumar(3, 4);          // llama a la de dos int
sumar(3.5, 4.2);      // llama a la de dos double
sumar(1, 2, 3);       // llama a la de tres int
```

Esto es cómodo: un mismo nombre conceptual (`sumar`, `imprimir`, `max`) para variantes según el
tipo. Lo que **no** basta para distinguir es solo el **tipo de retorno**: las firmas deben
diferir en los **parámetros**.

## 2. Parámetros por defecto

Puedes dar un **valor por defecto** a un parámetro; si quien llama lo omite, se usa ese valor:

```cpp
double potencia(double base, int exp = 2) {   // exp por defecto = 2
    double r = 1;
    for (int i = 0; i < exp; i++) r *= base;
    return r;
}

potencia(5);       // 25  (usa exp = 2)
potencia(5, 3);    // 125 (exp = 3)
```

Reglas:
- Los parámetros con valor por defecto van **al final** (después de los obligatorios).
- El valor por defecto se pone en la **declaración** (o en el prototipo), no en ambos.

Evita escribir varias sobrecargas cuando un valor por defecto basta.

## 3. Paso por referencia (repaso aplicado)

De la lección 02: pasar `int &` permite **modificar** el original, y `const T&` evita **copiar**
objetos grandes. En C++ es lo idiomático para funciones que "devuelven" a través de parámetros o
que reciben objetos pesados:

```cpp
void incrementar(int &n)          { n++; }            // modifica el original
void mostrar(const string &s)     { cout << s << endl; }  // no copia, no modifica
```

Compara con C, donde todo esto se hacía con punteros y `*`. Las referencias hacen el código más
limpio.

## 4. Funciones `inline` (breve)

`inline` sugiere al compilador que **inserte** el cuerpo de la función en el lugar de la llamada,
evitando el coste de la llamada para funciones muy pequeñas:

```cpp
inline int doble(int x) { return x * 2; }
```
Hoy los compiladores deciden esto solos casi siempre; no te preocupes mucho por `inline` al
principio. (En C++ también sirve para poder **definir** funciones en cabeceras sin errores de
enlazado.)

## Sobre la organización (igual que en C)

Puedes dividir en varios archivos con cabeceras `.h`/`.hpp` (declaraciones) y `.cpp`
(definiciones), como en la lección 13 de C. Compilas pasando todos los `.cpp`:

```bash
g++ -std=c++17 main.cpp utilidades.cpp -o programa
```

## Errores típicos

- Dos sobrecargas que solo difieren en el **tipo de retorno** → error (ambiguo).
- Poner el valor por defecto en la definición **y** en el prototipo → error de redefinición.
- Sobrecargas ambiguas (el compilador no sabe cuál elegir con ciertos argumentos).

## Resumen

- **Sobrecarga:** varias funciones con el mismo nombre, distintas por sus parámetros.
- **Parámetros por defecto:** valores que se usan si se omiten (van al final).
- **Paso por referencia** (`&`, `const &`): modificar u optimizar sin punteros.
- `inline` (opcional) para funciones muy pequeñas.

## Ejemplos

- [`ejemplos/sobrecarga.cpp`](ejemplos/sobrecarga.cpp)
- [`ejemplos/por_defecto.cpp`](ejemplos/por_defecto.cpp)

## Ejercicios

En [`ejercicios/`](ejercicios/).

## Para profundizar

- **Stroustrup**, *A Tour of C++*, cap. 3 ("Modularity").
- **learncpp.com**, "Function overloading" y "Default arguments".
- **cppreference**, "Function overloading". https://en.cppreference.com/w/cpp/language/overload_resolution
