# Lección 11 — Punteros inteligentes y RAII

En C (lección 10 de la pista C) viste `malloc`/`free`, y el peligro constante de las **fugas de
memoria** (olvidar liberar) y los *use-after-free*. C++ tiene `new`/`delete`, pero además ofrece
algo mucho mejor: **RAII** y los **punteros inteligentes**, que liberan la memoria
**automáticamente**.

## `new` y `delete` (el equivalente a malloc/free)

En C++, la memoria dinámica se pide con `new` y se libera con `delete`:

```cpp
int *p = new int(42);      // reserva un int con valor 42
cout << *p << endl;
delete p;                  // libera

int *arr = new int[5];     // reserva un arreglo de 5 int
delete[] arr;              // liberar arreglos: delete[]
```

**El problema es el mismo que en C:** si olvidas `delete`, hay fuga; si borras dos veces o usas
tras borrar, hay corrupción. Y si ocurre una excepción entre `new` y `delete`, el `delete` puede
no ejecutarse. Escribir código correcto a mano es difícil.

## RAII: la gran idea de C++

**RAII** = *Resource Acquisition Is Initialization* ("adquirir un recurso es inicializar"). La
idea: **atar** la vida de un recurso (memoria, archivo, conexión) a la vida de un **objeto**. El
recurso se adquiere en el **constructor** y se libera en el **destructor**. Como el destructor se
ejecuta **automáticamente** al salir del ámbito (¡incluso si hay una excepción!), el recurso
**siempre** se libera. No hay que acordarse de nada.

Los **punteros inteligentes** aplican RAII a la memoria dinámica: son objetos que envuelven un
puntero y llaman a `delete` **solos** cuando dejan de usarse. Están en `<memory>`.

## `std::unique_ptr`: propiedad exclusiva

Un `unique_ptr` posee un objeto de forma **exclusiva**: solo un `unique_ptr` puede apuntar a él, y
lo libera automáticamente al destruirse. Es la opción **por defecto**.

```cpp
#include <memory>

unique_ptr<int> p = make_unique<int>(42);   // reserva un int con valor 42
cout << *p << endl;      // 42, se usa como un puntero normal
// ...
// NO hace falta delete: al salir del ambito, p libera la memoria solo
```

- `make_unique<T>(args)` crea el objeto y el `unique_ptr` (forma recomendada).
- Se desreferencia con `*p`, y si es un objeto, se accede a miembros con `p->miembro`.
- **No** se puede copiar (sería "propiedad compartida", que rompe la exclusividad); se puede
  **mover** (`std::move`).

Con clases:
```cpp
class Recurso {
public:
    Recurso()  { cout << "adquirido\n"; }
    ~Recurso() { cout << "liberado\n"; }
    void usar() { cout << "usando\n"; }
};

{
    unique_ptr<Recurso> r = make_unique<Recurso>();  // "adquirido"
    r->usar();
}   // aqui r se destruye y libera el Recurso automaticamente -> "liberado"
```

## `std::shared_ptr`: propiedad compartida

A veces **varios** dueños comparten un mismo objeto y no está claro quién debe liberarlo. Un
`shared_ptr` lleva un **contador de referencias**: cuando el último `shared_ptr` que apunta al
objeto desaparece, se libera.

```cpp
shared_ptr<int> a = make_shared<int>(100);
shared_ptr<int> b = a;          // ahora a y b comparten el mismo int
cout << a.use_count() << endl;  // 2 (dos dueños)
// el int se libera cuando tanto a como b dejan de existir
```

`shared_ptr` es más flexible pero un poco más costoso (por el contador). **Regla práctica:** usa
`unique_ptr` por defecto; usa `shared_ptr` solo cuando de verdad necesites compartir la propiedad.

(Existe también `weak_ptr`, para romper ciclos de referencias; es un tema avanzado.)

## `std::vector` ya es RAII

Nota importante: `std::vector`, `std::string` y los demás contenedores de la STL **ya** aplican
RAII: gestionan su memoria y la liberan solos. Por eso, en C++ moderno, la mayoría de las veces
**ni siquiera necesitas punteros inteligentes**: un `vector` sustituye a un arreglo dinámico sin
que tú toques `new`/`delete`. Los punteros inteligentes brillan sobre todo con **polimorfismo**
(guardar objetos derivados por la base) y recursos que no son memoria.

Ejemplo con polimorfismo (recuerda la lección 06, pero ahora sin fugas):
```cpp
vector<unique_ptr<Figura>> figuras;
figuras.push_back(make_unique<Circulo>(2));
figuras.push_back(make_unique<Rectangulo>(3, 4));
for (const auto &f : figuras) {
    cout << f->area() << endl;
}   // al destruir el vector, cada figura se libera sola
```

## Errores típicos

- Seguir usando `new`/`delete` a mano cuando un `unique_ptr` o un `vector` lo harían solo.
- Mezclar `delete` con `delete[]` (arreglos usan `delete[]`).
- Intentar **copiar** un `unique_ptr` (usa `std::move` o un `shared_ptr`).
- Usar `shared_ptr` donde bastaba `unique_ptr` (sobrecoste innecesario).

## Resumen

- `new`/`delete` (y `new[]`/`delete[]`) son la memoria dinámica cruda; propensa a fugas.
- **RAII**: atar el recurso a un objeto; el destructor lo libera automáticamente (incluso ante
  excepciones).
- **`unique_ptr`** (propiedad exclusiva, por defecto) y **`shared_ptr`** (compartida, con contador)
  liberan la memoria solos. Créalos con `make_unique`/`make_shared`.
- Los contenedores STL (`vector`, `string`) ya son RAII: a menudo no necesitas punteros a mano.

## Ejemplos

- [`ejemplos/unique.cpp`](ejemplos/unique.cpp)
- [`ejemplos/shared.cpp`](ejemplos/shared.cpp)

## Ejercicios

En [`ejercicios/`](ejercicios/).

## Para profundizar

- **Stroustrup**, *A Tour of C++*, cap. 5 (§5.3 "Resource Management") y cap. 13.
- **learncpp.com**, capítulo "Smart pointers".
- **cppreference**, `unique_ptr`, `shared_ptr`.
  https://en.cppreference.com/w/cpp/memory/unique_ptr
- **C++ Core Guidelines**, sección "R" (Resource management).
