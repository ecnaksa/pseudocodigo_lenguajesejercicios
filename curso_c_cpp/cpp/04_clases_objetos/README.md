# Lección 04 — Clases y objetos

Llegamos al corazón de C++: la **Programación Orientada a Objetos (POO)**. Es una forma de
organizar el código agrupando **datos** y las **funciones que operan sobre ellos** en una misma
unidad: la **clase**.

## De `struct` a `class`

En C, una `struct` solo agrupaba **datos**. En C++, una **clase** agrupa **datos** (llamados
**atributos** o *miembros*) **y** **funciones** (llamadas **métodos**) que trabajan con esos
datos.

Una **clase** es el **molde**; un **objeto** es una **instancia** concreta creada a partir de ese
molde. (Analogía: la clase "Coche" es el plano; tu coche particular es un objeto.)

## Una primera clase

```cpp
#include <iostream>
using namespace std;

class Rectangulo {
public:
    double base;      // atributos (datos)
    double altura;

    double area() {   // metodo (funcion que usa los atributos)
        return base * altura;
    }
};

int main() {
    Rectangulo r;          // r es un OBJETO de la clase Rectangulo
    r.base = 4;            // acceder a atributos con .
    r.altura = 3;
    cout << "Area: " << r.area() << endl;   // llamar a un metodo con .
    return 0;
}
```

- `class Rectangulo { ... };` define la clase (¡ojo al `;` final!).
- Dentro hay **atributos** (`base`, `altura`) y **métodos** (`area`).
- En `main`, `Rectangulo r;` crea un objeto; se accede a sus miembros con `.`, igual que en una
  `struct`.
- Dentro de `area()`, `base` y `altura` se refieren a los del **objeto sobre el que se llama** el
  método (`r.area()` usa `r.base` y `r.altura`).

## Encapsulamiento: `public` y `private`

La gran idea de la POO es el **encapsulamiento**: **ocultar** los detalles internos y exponer solo
lo necesario. Los miembros pueden ser:

- **`public`**: accesibles desde fuera de la clase.
- **`private`**: accesibles **solo** desde dentro de la clase (sus propios métodos). Es el valor
  por defecto en `class`.

```cpp
class CuentaBancaria {
private:
    double saldo;            // nadie fuera puede tocar 'saldo' directamente

public:
    void depositar(double monto) {
        if (monto > 0) saldo += monto;      // control desde dentro
    }
    void retirar(double monto) {
        if (monto > 0 && monto <= saldo) saldo -= monto;
    }
    double consultar() {
        return saldo;
    }
    void inicializar() { saldo = 0; }
};
```

Ahora, desde fuera, **no** puedes hacer `cuenta.saldo = -1000;` (error de compilación). Solo
puedes usar los métodos públicos (`depositar`, `retirar`, `consultar`), que **protegen** los datos
(por ejemplo, impiden retirar más de lo que hay). Esto hace el código **más seguro** y **más fácil
de mantener**: la clase controla su propio estado.

> **`class` vs `struct` en C++:** son casi lo mismo; la única diferencia es que en `class` los
> miembros son `private` por defecto, y en `struct` son `public` por defecto. Por convención, se
> usa `class` para tipos con lógica/encapsulamiento y `struct` para agrupar datos simples.

## Métodos: declarar dentro, definir fuera (opcional)

Puedes definir los métodos **dentro** de la clase (como arriba) o solo **declararlos** dentro y
**definirlos fuera** con el operador de ámbito `::`:

```cpp
class Rectangulo {
public:
    double base, altura;
    double area();            // solo la declaracion
};

double Rectangulo::area() {   // definicion fuera, con Clase::metodo
    return base * altura;
}
```
Definir fuera es lo habitual en proyectos grandes (la clase en el `.h`, los métodos en el `.cpp`).

## Getters y setters

Un patrón común: atributos `private` con métodos públicos para **leerlos** (*getter*) y
**modificarlos** con validación (*setter*):

```cpp
class Persona {
private:
    int edad;
public:
    int getEdad() { return edad; }              // getter
    void setEdad(int e) { if (e >= 0) edad = e; } // setter con validacion
};
```

## Errores típicos

- Olvidar el **`;`** después de la llave de cierre de la clase.
- Intentar acceder a un miembro `private` desde fuera → error de compilación.
- Usar un objeto sin **inicializar** sus atributos (basura). En la próxima lección veremos los
  **constructores**, que resuelven esto elegantemente.
- Olvidar `Clase::` al definir un método fuera de la clase.

## Resumen

- Una **clase** agrupa **atributos** (datos) y **métodos** (funciones).
- Un **objeto** es una instancia de la clase; se accede a sus miembros con `.`.
- **Encapsulamiento:** `private` oculta los datos, `public` expone la interfaz. En `class`, lo
  privado es el valor por defecto.
- Métodos: se definen dentro, o fuera con `Clase::metodo`.
- *Getters/setters* dan acceso controlado a los atributos.

## Ejemplos

- [`ejemplos/rectangulo.cpp`](ejemplos/rectangulo.cpp)
- [`ejemplos/cuenta.cpp`](ejemplos/cuenta.cpp)

## Ejercicios

En [`ejercicios/`](ejercicios/).

## Para profundizar

- **Stroustrup**, *A Tour of C++*, cap. 4–5 ("Classes").
- **learncpp.com**, capítulo sobre "Classes" (secciones 13.x).
- **cppreference**, "Classes". https://en.cppreference.com/w/cpp/language/classes
