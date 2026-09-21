# Lección 08 — Plantillas (templates)

Imagina que escribes una función `maximo` para `int`. Luego la necesitas para `double`, y para
`string`... En la lección 03 lo resolvías con **sobrecarga** (copiar la función para cada tipo).
Las **plantillas** lo hacen mucho mejor: escribes el código **una vez**, de forma **genérica**, y
el compilador lo genera para **cualquier tipo**.

## Plantillas de función

```cpp
template <typename T>
T maximo(T a, T b) {
    return (a > b) ? a : b;
}
```

- `template <typename T>` dice: "lo que sigue usa un **tipo genérico** llamado `T`".
- `T` es un **marcador** que se reemplazará por el tipo real al usar la función.

Al llamarla, el compilador **deduce** `T` de los argumentos y genera la versión adecuada:

```cpp
cout << maximo(3, 7) << endl;         // T = int    -> 7
cout << maximo(2.5, 1.8) << endl;     // T = double -> 2.5
cout << maximo(string("a"), string("b")) << endl;   // T = string -> "b"
```

Una sola función sirve para **todos** los tipos que soporten `>`. Esto es la **programación
genérica**, y es la base de la biblioteca estándar (STL, próximas lecciones).

> `typename` y `class` son intercambiables aquí: `template <class T>` significa lo mismo.

### Varios parámetros de tipo

```cpp
template <typename A, typename B>
void mostrarPar(A primero, B segundo) {
    cout << primero << ", " << segundo << endl;
}
mostrarPar(1, "hola");       // A = int, B = const char*
mostrarPar(3.14, 'x');       // A = double, B = char
```

## Plantillas de clase

También puedes hacer **clases genéricas**. El ejemplo clásico es un contenedor que guarda
elementos de un tipo cualquiera. Aquí una "caja" simple:

```cpp
template <typename T>
class Caja {
    T contenido;
public:
    Caja(T valor) : contenido(valor) {}
    T obtener() const { return contenido; }
    void poner(T valor) { contenido = valor; }
};
```

Al crear un objeto, especificas el tipo entre `< >`:

```cpp
Caja<int> ci(42);
Caja<string> cs("hola");
cout << ci.obtener() << endl;   // 42
cout << cs.obtener() << endl;   // hola
```

De hecho, `std::vector<int>`, `std::vector<string>`, etc. (lección 09) **son** plantillas de
clase: `vector` es una plantilla, y `<int>` le dice qué tipo guardar.

## Una pila genérica (ejemplo más completo)

```cpp
template <typename T>
class Pila {
    T datos[100];
    int tope = 0;
public:
    void push(T valor) { datos[tope++] = valor; }
    T pop() { return datos[--tope]; }
    bool vacia() const { return tope == 0; }
};

Pila<int> p;
p.push(1); p.push(2);
cout << p.pop() << endl;    // 2 (ultimo en entrar, primero en salir)
```
La misma `Pila` sirve para `int`, `double`, `string`... sin reescribir nada.

## Requisitos sobre el tipo

Una plantilla funciona con un tipo `T` **siempre que** `T` soporte las operaciones que la
plantilla usa. `maximo` usa `>`, así que `T` debe ser comparable con `>` (los tipos numéricos y
`string` lo son; una clase tuya lo será si sobrecargaste `operator>`). Si el tipo no cumple, el
error de compilación aparece al **instanciar** la plantilla.

## Dónde se escriben

Por cómo funciona la instanciación, las plantillas suelen escribirse **completas en el `.h`**
(declaración y definición juntas), no separadas en `.cpp`. Es una diferencia con las funciones y
clases normales.

## Errores típicos

- Usar en la plantilla una operación que `T` no soporta (error al instanciar).
- Separar declaración e implementación de una plantilla en `.h`/`.cpp` (suele dar errores de
  enlazado; ponlas juntas en el `.h`).
- Olvidar `<Tipo>` al instanciar una **clase** plantilla (`Caja c;` no basta; `Caja<int> c;`).

## Resumen

- Las **plantillas** escriben código genérico una vez, para cualquier tipo.
- `template <typename T>` antes de una función o clase; `T` es el tipo genérico.
- En funciones, `T` se **deduce** de los argumentos; en clases, se **indica** con `<Tipo>`.
- Son la base de la **STL** (`vector`, `map`, algoritmos...).
- El tipo `T` debe soportar las operaciones que la plantilla use.

## Ejemplos

- [`ejemplos/maximo.cpp`](ejemplos/maximo.cpp)
- [`ejemplos/caja.cpp`](ejemplos/caja.cpp)
- [`ejemplos/pila.cpp`](ejemplos/pila.cpp)

## Ejercicios

En [`ejercicios/`](ejercicios/).

## Para profundizar

- **Stroustrup**, *A Tour of C++*, cap. 6 ("Templates").
- **learncpp.com**, capítulos "Function templates" y "Class templates".
- **cppreference**, "Templates". https://en.cppreference.com/w/cpp/language/templates
