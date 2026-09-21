# Lección 09 — STL: contenedores

La **STL** (*Standard Template Library*) es una de las mayores ventajas de C++: una colección de
**contenedores** (estructuras de datos) y **algoritmos** ya hechos, genéricos y eficientes. En vez
de reinventar listas, mapas y ordenamientos, los usas. Esta lección cubre los **contenedores** más
importantes; la siguiente, los **algoritmos**.

## `std::vector`: el arreglo que crece

`std::vector` (de `<vector>`) es como un arreglo, pero **dinámico**: crece y encoge solo, conoce su
tamaño y gestiona su memoria. Es el contenedor que usarás el 90% del tiempo.

```cpp
#include <vector>
#include <iostream>
using namespace std;

vector<int> v;              // vector vacio de enteros
v.push_back(10);            // agrega al final
v.push_back(20);
v.push_back(30);

cout << v.size() << endl;   // 3  (numero de elementos)
cout << v[0] << endl;       // 10 (acceso por indice, como un arreglo)
v[1] = 99;                  // modificar

for (int x : v) {           // recorrer con for "para cada"
    cout << x << " ";
}
```

Operaciones habituales de `vector`:

| Operación | Qué hace |
|---|---|
| `v.push_back(x)` | agrega `x` al final |
| `v.pop_back()` | quita el último |
| `v.size()` | número de elementos |
| `v.empty()` | ¿está vacío? |
| `v[i]` | acceso por índice (sin comprobar límites) |
| `v.at(i)` | acceso por índice (lanza excepción si te sales) |
| `v.front()` / `v.back()` | primero / último |
| `v.clear()` | vacía el vector |

Inicialización directa:
```cpp
vector<int> primos = {2, 3, 5, 7, 11};
vector<string> nombres(3);          // 3 strings vacios
vector<double> ceros(5, 0.0);       // 5 doubles, todos 0.0
```

`vector` sustituye con ventaja a los arreglos crudos de C: sin `malloc`/`free`, sin llevar el
tamaño aparte, sin fugas.

## `std::string` (repaso)

Ya lo viste (lección 02): es el contenedor de texto. Comparte muchas operaciones con `vector`
(`.size()`, `s[i]`, recorrer con `for`).

## `std::pair`: dos valores juntos

`std::pair` (de `<utility>`) agrupa **dos** valores, posiblemente de tipos distintos:

```cpp
#include <utility>
pair<string, int> persona = {"Ana", 25};
cout << persona.first << " tiene " << persona.second << endl;
```
Se usa mucho combinado con `map` (abajo).

## `std::map`: diccionario (clave → valor)

`std::map` (de `<map>`) asocia **claves** con **valores**, como un diccionario. Buscar por clave es
rápido:

```cpp
#include <map>
map<string, int> edades;
edades["Ana"] = 25;             // insertar / asignar
edades["Luis"] = 30;

cout << edades["Ana"] << endl;  // 25  (acceso por clave)

// recorrer (cada elemento es un pair<clave, valor>):
for (const auto &par : edades) {
    cout << par.first << " -> " << par.second << endl;
}

// comprobar si una clave existe:
if (edades.count("Ana")) cout << "Ana esta\n";
```

Las claves de un `map` están **ordenadas** automáticamente. (Existe `unordered_map`, más rápido
pero sin orden.)

## `std::set`: conjunto de elementos únicos

`std::set` (de `<set>`) guarda elementos **únicos** y **ordenados**: no admite duplicados.

```cpp
#include <set>
set<int> s;
s.insert(3);
s.insert(1);
s.insert(3);        // ignorado: ya estaba
// s contiene {1, 3} (ordenado, sin repetir)

if (s.count(1)) cout << "el 1 esta\n";
cout << "tamano: " << s.size() << endl;   // 2
```
Útil para eliminar duplicados o comprobar pertenencia rápidamente.

## Iteradores (visión práctica)

Los contenedores se recorren con **iteradores**, objetos que "apuntan" a un elemento (como
punteros generalizados). `begin()` apunta al primero, `end()` a **uno después** del último:

```cpp
for (auto it = v.begin(); it != v.end(); ++it) {
    cout << *it << " ";     // *it es el valor apuntado
}
```
En la práctica, el `for (x : contenedor)` (que internamente usa iteradores) es más cómodo y
legible. Pero los iteradores son necesarios para los **algoritmos** de la próxima lección (que
reciben `begin()`/`end()`).

## ¿Cuál elegir?

- **`vector`**: lista de elementos por posición. La opción por defecto.
- **`map`**: asociar clave → valor (contar, indexar por nombre).
- **`set`**: elementos únicos / comprobar pertenencia.
- **`pair`**: devolver o agrupar dos valores.

Hay más (`list`, `deque`, `stack`, `queue`, `unordered_map`...), pero con estos cubres la mayoría
de casos al empezar.

## Errores típicos

- Acceder a `v[i]` fuera de rango (no avisa; usa `.at(i)` si quieres seguridad).
- Olvidar `#include <vector>`, `<map>`, `<set>`, etc.
- Modificar un contenedor mientras lo recorres (puede invalidar iteradores).
- Confundir `map` (clave→valor) con `set` (solo claves únicas).

## Resumen

- La **STL** trae contenedores y algoritmos listos y eficientes.
- **`vector`**: arreglo dinámico (el más usado); `push_back`, `size`, `v[i]`, recorrer con `for`.
- **`pair`**: dos valores; **`map`**: diccionario clave→valor; **`set`**: únicos y ordenados.
- Los **iteradores** (`begin()`/`end()`) recorren y alimentan a los algoritmos (lección 10).

## Ejemplos

- [`ejemplos/vector.cpp`](ejemplos/vector.cpp)
- [`ejemplos/mapa.cpp`](ejemplos/mapa.cpp)
- [`ejemplos/conjunto.cpp`](ejemplos/conjunto.cpp)

## Ejercicios

En [`ejercicios/`](ejercicios/).

## Para profundizar

- **Stroustrup**, *A Tour of C++*, cap. 11–12 ("Containers", "Algorithms").
- **learncpp.com**, capítulos sobre `std::vector`.
- **cppreference**, "Containers library". https://en.cppreference.com/w/cpp/container
