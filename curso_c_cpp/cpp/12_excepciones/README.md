# Lección 12 — Manejo de excepciones

¿Qué haces cuando algo **sale mal** en tiempo de ejecución? Dividir entre cero, un índice fuera de
rango, un archivo que no existe, datos inválidos... En C se usaban **códigos de error** (devolver
`-1`, `NULL`), fáciles de ignorar. C++ ofrece las **excepciones**: un mecanismo limpio para
**señalar** y **manejar** errores.

## La idea: lanzar y atrapar

- **`throw`**: "lanza" una excepción cuando detectas un problema. Interrumpe el flujo normal.
- **`try`**: envuelve el código que **podría** fallar.
- **`catch`**: "atrapa" la excepción y la maneja.

```cpp
#include <iostream>
#include <stdexcept>
using namespace std;

double dividir(double a, double b) {
    if (b == 0) {
        throw runtime_error("division entre cero");   // lanza un error
    }
    return a / b;
}

int main() {
    try {
        cout << dividir(10, 2) << endl;    // 5
        cout << dividir(10, 0) << endl;    // lanza -> salta al catch
        cout << "esto NO se ejecuta" << endl;
    } catch (const runtime_error &e) {
        cout << "Error: " << e.what() << endl;   // Error: division entre cero
    }
    cout << "el programa continua" << endl;
    return 0;
}
```

Cuando `throw` se ejecuta, el programa **abandona** de inmediato el flujo normal y busca un `catch`
compatible (deshaciendo el camino, destruyendo objetos locales correctamente — aquí brilla RAII).
Si lo encuentra, ejecuta ese `catch`; si no, el programa termina.

## `e.what()` y las excepciones estándar

Las excepciones de la biblioteca estándar (en `<stdexcept>`) tienen un método **`.what()`** que
devuelve un mensaje. Las más comunes:

| Excepción | Cuándo usarla |
|---|---|
| `std::runtime_error` | error detectado en ejecución (genérico) |
| `std::logic_error` | error de lógica del programa (bug) |
| `std::invalid_argument` | un argumento no válido |
| `std::out_of_range` | índice/rango fuera de límites (la lanza `vector::at`, por ejemplo) |

```cpp
vector<int> v = {1, 2, 3};
try {
    cout << v.at(10) << endl;    // at() comprueba limites y lanza out_of_range
} catch (const out_of_range &e) {
    cout << "Fuera de rango: " << e.what() << endl;
}
```

## Atrapar varios tipos

Puedes tener varios `catch`, del más específico al más general. `catch (const exception &e)` atrapa
**cualquier** excepción estándar (todas heredan de `std::exception`):

```cpp
try {
    // ...
} catch (const out_of_range &e) {
    cout << "rango: " << e.what() << endl;
} catch (const exception &e) {          // atrapa el resto de las estandar
    cout << "otro error: " << e.what() << endl;
}
```
(`catch (...)` —con tres puntos— atrapa **absolutamente todo**, pero pierdes la información; úsalo
como último recurso.)

## Lanzar tus propias excepciones

Puedes lanzar una excepción estándar con un mensaje propio (lo más simple):

```cpp
if (edad < 0) {
    throw invalid_argument("la edad no puede ser negativa");
}
```

O crear una **clase de excepción** propia, heredando de `std::exception` (para casos que quieras
distinguir con su propio `catch`):

```cpp
class SaldoInsuficiente : public exception {
public:
    const char* what() const noexcept override {
        return "saldo insuficiente";
    }
};
// ...
throw SaldoInsuficiente();
```

## ¿Cuándo usar excepciones?

- **Sí:** para errores **excepcionales** que impiden continuar normalmente (datos corruptos,
  recurso no disponible, precondición violada).
- **No** para el **flujo normal** (que un usuario elija "salir" no es una excepción; usa un `if`).
  Las excepciones tienen un coste y no deben ser el control de flujo habitual.

## Relación con RAII (importante)

Cuando se lanza una excepción, C++ **destruye correctamente** todos los objetos locales del camino
(*stack unwinding*). Por eso los **punteros inteligentes** y contenedores (lección 11) son tan
importantes: garantizan que la memoria y los recursos se liberen **aunque** ocurra una excepción,
algo muy difícil de lograr a mano con `new`/`delete`.

## Errores típicos

- Atrapar por **valor** (`catch (exception e)`) en vez de por **referencia** (`catch (const
  exception &e)`): lo correcto es por referencia (evita copias y el problema del *slicing*).
- Usar excepciones para el flujo normal.
- Olvidar `#include <stdexcept>`.
- No manejar una excepción que puede lanzarse → el programa aborta.

## Resumen

- `throw` lanza, `try` envuelve el código riesgoso, `catch` maneja.
- Las excepciones estándar (`<stdexcept>`) tienen `.what()`; hay tipos como `runtime_error`,
  `out_of_range`, `invalid_argument`.
- Varios `catch` de específico a general; `catch (const exception &e)` cubre las estándar.
- Puedes lanzar excepciones con mensaje propio o crear tu clase (hereda de `std::exception`).
- Úsalas para errores **excepcionales**, no para el flujo normal. RAII garantiza limpieza al
  lanzarse.

## Ejemplos

- [`ejemplos/dividir.cpp`](ejemplos/dividir.cpp)
- [`ejemplos/vector_rango.cpp`](ejemplos/vector_rango.cpp)
- [`ejemplos/propia.cpp`](ejemplos/propia.cpp)

## Ejercicios

En [`ejercicios/`](ejercicios/).

## Para profundizar

- **Stroustrup**, *A Tour of C++*, cap. 3 (§3.5 "Error Handling").
- **learncpp.com**, capítulo "Exceptions".
- **cppreference**, "Exceptions". https://en.cppreference.com/w/cpp/error/exception
