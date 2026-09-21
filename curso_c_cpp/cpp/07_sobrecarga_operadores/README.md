# Lección 07 — Sobrecarga de operadores

Ya viste que `std::string` se concatena con `+` y se compara con `==`. ¿Cómo? Sus autores
**sobrecargaron** esos operadores. Tú también puedes hacer que **tus** clases se usen con los
operadores nativos (`+`, `-`, `==`, `<<`…), haciéndolas más naturales.

## La idea

Un operador como `a + b` es, en realidad, una **llamada a función**. Sobrecargar un operador es
definir qué hace ese operador cuando se aplica a **objetos de tu clase**.

Tomemos una clase `Vector2D` (un vector matemático de dos componentes):

```cpp
class Vector2D {
public:
    double x, y;
    Vector2D(double x = 0, double y = 0) : x(x), y(y) {}
};
```

Sin sobrecarga, `v1 + v2` **no compila**: C++ no sabe sumar dos `Vector2D`. Vamos a enseñárselo.

## Sobrecargar `+`

Se define un método (o función) especial llamado `operator+`:

```cpp
class Vector2D {
public:
    double x, y;
    Vector2D(double x = 0, double y = 0) : x(x), y(y) {}

    Vector2D operator+(const Vector2D &otro) const {
        return Vector2D(x + otro.x, y + otro.y);
    }
};

Vector2D a(1, 2), b(3, 4);
Vector2D c = a + b;      // llama a a.operator+(b) -> (4, 6)
```

- `operator+` recibe el **otro** operando (`b`) y devuelve un **nuevo** `Vector2D` con la suma.
- El `const` final indica que sumar **no modifica** el objeto (`a`). Buena práctica.
- `a + b` se traduce a `a.operator+(b)`.

## Sobrecargar comparadores (`==`, `!=`, `<`)

Devuelven `bool`:

```cpp
bool operator==(const Vector2D &otro) const {
    return x == otro.x && y == otro.y;
}
```
Ahora `a == b` funciona. Igual puedes definir `!=`, `<`, `>`, etc. (Poder comparar con `<` es útil
para ordenar y para usar tu tipo en contenedores ordenados de la STL.)

## Sobrecargar `<<` para imprimir con `cout`

Para poder escribir `cout << v;`, se sobrecarga `operator<<`. Este **no** es un método de la clase
(el operando izquierdo es el `cout`, no tu objeto), sino una **función libre**, normalmente
declarada `friend` para acceder a los datos privados:

```cpp
#include <iostream>
class Vector2D {
    double x, y;
public:
    Vector2D(double x = 0, double y = 0) : x(x), y(y) {}
    friend std::ostream& operator<<(std::ostream &os, const Vector2D &v);
};

std::ostream& operator<<(std::ostream &os, const Vector2D &v) {
    os << "(" << v.x << ", " << v.y << ")";
    return os;      // devolver os permite encadenar: cout << a << b
}
```

Ahora:
```cpp
Vector2D a(1, 2);
cout << "a = " << a << endl;   // a = (1, 2)
```

- `friend` da a la función acceso a los miembros `private` de la clase.
- Se devuelve `std::ostream&` (el propio flujo) para poder **encadenar** varios `<<`.

## Otros operadores sobrecargables

Casi todos: `+ - * /`, `+= -=`, `== != < > <= >=`, `[]` (indexación), `()` (llamada), `++ --`,
etc. **No** se pueden sobrecargar unos pocos (`::`, `.`, `?:`, `sizeof`).

## Cuándo (y cuándo no) sobrecargar

- **Sí:** cuando el operador tiene un significado **natural e intuitivo** para tu tipo (sumar
  vectores, concatenar, comparar fracciones, imprimir).
- **No:** por "quedar listo". Si `+` no significa algo obvio para tu clase, un **método con
  nombre** (`combinar()`) es más claro. Un operador que hace algo inesperado confunde.

## Errores típicos

- Olvidar el `const` en operadores que no modifican, o en el parámetro (`const T&`).
- En `operator<<`, olvidar **devolver** el flujo (`return os;`) → no se puede encadenar.
- Intentar sobrecargar `<<` como método de la clase (debe ser función libre, porque el `cout` va a
  la izquierda).
- Sobrecargar con significados no intuitivos.

## Resumen

- Sobrecargar un operador = definir `operatorX` para que funcione con tus objetos.
- `a + b` ↔ `a.operator+(b)`; devuelve un objeto nuevo, marca `const` si no modifica.
- Comparadores (`==`, `<`) devuelven `bool`.
- `operator<<` es una **función libre** (a menudo `friend`) que devuelve el flujo para encadenar.
- Sobrecarga solo cuando el operador tiene un sentido **natural**.

## Ejemplos

- [`ejemplos/vector2d.cpp`](ejemplos/vector2d.cpp)
- [`ejemplos/fraccion.cpp`](ejemplos/fraccion.cpp)

## Ejercicios

En [`ejercicios/`](ejercicios/).

## Para profundizar

- **Stroustrup**, *A Tour of C++*, cap. 5 ("Essential Operations").
- **learncpp.com**, capítulo "Operator overloading".
- **cppreference**, "operator overloading".
  https://en.cppreference.com/w/cpp/language/operators
