# Lección 05 — Constructores y destructores

En la lección anterior, tras crear un objeto había que inicializar sus atributos "a mano"
(`c.inicializar()`). Los **constructores** automatizan eso: se ejecutan **al crear** el objeto,
garantizando que nazca en un estado válido. Los **destructores** se ejecutan **al destruirlo**.

## El constructor

Un **constructor** es un método especial que:
- Se llama **igual que la clase**.
- **No** tiene tipo de retorno (ni siquiera `void`).
- Se ejecuta **automáticamente** al crear un objeto.

```cpp
class Punto {
public:
    double x, y;

    Punto() {            // constructor por defecto (sin parametros)
        x = 0;
        y = 0;
    }
};

Punto p;                 // se llama al constructor: p.x = 0, p.y = 0
```

### Constructor con parámetros

Permite crear el objeto **ya inicializado** con valores:

```cpp
class Punto {
public:
    double x, y;

    Punto(double px, double py) {
        x = px;
        y = py;
    }
};

Punto p(3, 4);           // x = 3, y = 4
```

### Lista de inicialización (la forma preferida)

En vez de asignar dentro del cuerpo, C++ tiene una sintaxis especial, la **lista de
inicialización**, que inicializa los atributos **directamente** (más eficiente, y necesaria para
`const` y referencias):

```cpp
class Punto {
public:
    double x, y;
    Punto(double px, double py) : x(px), y(py) {   // lista de inicializacion
        // cuerpo (a menudo vacio)
    }
};
```
Se lee: "construye `x` con `px` y `y` con `py`". Es el estilo idiomático moderno.

## Sobrecarga de constructores

Puedes tener **varios** constructores (como cualquier función sobrecargada), para distintas formas
de crear el objeto:

```cpp
class Punto {
public:
    double x, y;
    Punto() : x(0), y(0) {}                  // por defecto
    Punto(double v) : x(v), y(v) {}          // ambos iguales
    Punto(double px, double py) : x(px), y(py) {}   // ambos
};

Punto a;           // (0, 0)
Punto b(5);        // (5, 5)
Punto c(3, 4);     // (3, 4)
```

También puedes dar **valores por defecto** a los parámetros del constructor para reducir
sobrecargas: `Punto(double px = 0, double py = 0) : x(px), y(py) {}`.

## El puntero `this`

Dentro de un método, **`this`** es un puntero al **objeto actual** (sobre el que se llamó el
método). Sirve, por ejemplo, cuando un parámetro tiene el **mismo nombre** que un atributo:

```cpp
class Punto {
    double x, y;
public:
    Punto(double x, double y) {
        this->x = x;      // this->x es el atributo; x (a secas) es el parametro
        this->y = y;
    }
};
```
Como `this` es un puntero, se usa con `->`. (Con la lista de inicialización a menudo no hace
falta.)

## El destructor

Un **destructor** se ejecuta **automáticamente** cuando el objeto **deja de existir** (al salir de
su ámbito, o con `delete`). Se llama como la clase pero con `~` delante, y no recibe parámetros:

```cpp
class Recurso {
public:
    Recurso()  { cout << "Recurso creado\n"; }
    ~Recurso() { cout << "Recurso liberado\n"; }   // destructor
};

int main() {
    Recurso r;         // imprime "Recurso creado"
    // ...
}                      // al salir, imprime "Recurso liberado"
```

Su utilidad real es **liberar recursos** que el objeto haya pedido (memoria dinámica, archivos
abiertos, conexiones). Este patrón —adquirir en el constructor, liberar en el destructor— se llama
**RAII** y es central en C++ (lección 11). Para clases simples sin recursos, el destructor por
defecto (automático) basta.

## Miembros `static`: compartidos por toda la clase

Un miembro **`static`** pertenece a la **clase**, no a cada objeto: **todos** los objetos comparten
el mismo. Útil, por ejemplo, para **contar cuántos objetos** se han creado:

```cpp
class Usuario {
public:
    static int total;        // declaracion (compartida)
    Usuario() { total++; }
};
int Usuario::total = 0;      // definicion (fuera de la clase, una sola vez)

// ...
Usuario a, b, c;
cout << Usuario::total << endl;   // 3  (se accede con Clase::miembro)
```

## Errores típicos

- Ponerle **tipo de retorno** al constructor (no lleva, ni `void`).
- Olvidar inicializar algún atributo → valor basura.
- Confundir el orden de la lista de inicialización (los miembros se inicializan en el orden en que
  se **declaran** en la clase, no en el que aparecen en la lista).
- Olvidar definir el miembro `static` fuera de la clase → error de enlazado.

## Resumen

- El **constructor** (mismo nombre que la clase, sin retorno) inicializa el objeto al crearlo;
  usa la **lista de inicialización** `: a(x), b(y)`.
- Puedes **sobrecargar** constructores y darles parámetros por defecto.
- **`this`** apunta al objeto actual (útil con nombres repetidos).
- El **destructor** `~Clase()` se ejecuta al destruir el objeto; sirve para liberar recursos
  (RAII).
- Los miembros **`static`** son compartidos por toda la clase (`Clase::miembro`).

## Ejemplos

- [`ejemplos/punto.cpp`](ejemplos/punto.cpp)
- [`ejemplos/destructor.cpp`](ejemplos/destructor.cpp)
- [`ejemplos/contador_static.cpp`](ejemplos/contador_static.cpp)

## Ejercicios

En [`ejercicios/`](ejercicios/).

## Para profundizar

- **Stroustrup**, *A Tour of C++*, cap. 5 ("Essential Operations").
- **learncpp.com**, "Constructors" y "Destructors".
- **cppreference**, "Constructors". https://en.cppreference.com/w/cpp/language/constructor
