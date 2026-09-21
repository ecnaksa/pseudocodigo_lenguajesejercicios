# Lección 10 — STL: algoritmos y lambdas

Los contenedores guardan datos; los **algoritmos** de `<algorithm>` operan sobre ellos: ordenar,
buscar, contar, transformar... sin que escribas los bucles. Y las **funciones lambda** te permiten
pasarles "trocitos de código" a medida.

## Algoritmos que reciben `begin()` y `end()`

Casi todos los algoritmos trabajan sobre un **rango**, indicado por dos iteradores:
`contenedor.begin()` (primer elemento) y `contenedor.end()` (uno después del último).

### `std::sort`: ordenar

```cpp
#include <algorithm>
#include <vector>
vector<int> v = {5, 2, 8, 1, 9};
sort(v.begin(), v.end());          // orden ascendente: 1 2 5 8 9
```
Ordenar un `vector` con `sort` es una línea, y es muy eficiente. Para orden **descendente**:
`sort(v.begin(), v.end(), greater<int>());`.

### `std::find`: buscar

Devuelve un iterador al elemento (o `end()` si no está):

```cpp
auto it = find(v.begin(), v.end(), 8);
if (it != v.end()) cout << "encontrado en posicion " << (it - v.begin()) << endl;
else cout << "no esta\n";
```

### `std::count`: contar

```cpp
int cuantos = count(v.begin(), v.end(), 5);   // cuantos 5 hay
```

### `std::max_element` / `std::min_element`

Devuelven un iterador al mayor / menor:

```cpp
auto mayor = max_element(v.begin(), v.end());
cout << "Maximo: " << *mayor << endl;
```

### `std::accumulate`: sumar (de `<numeric>`)

```cpp
#include <numeric>
int suma = accumulate(v.begin(), v.end(), 0);   // el 0 es el valor inicial
```

### `std::reverse`: invertir

```cpp
reverse(v.begin(), v.end());       // da la vuelta al contenedor
```

## Funciones lambda: código "al vuelo"

Muchos algoritmos aceptan una **función** para personalizar su comportamiento (con qué criterio
ordenar, qué contar, qué hacer con cada elemento). Una **lambda** es una función **anónima** que
escribes en el sitio:

```cpp
[](int x) { return x * x; }        // lambda que devuelve el cuadrado de x
```

Anatomía:
- `[]` — la **lista de captura** (qué variables de fuera usa; vacía por ahora).
- `(int x)` — parámetros, como cualquier función.
- `{ ... }` — el cuerpo.

### Ejemplos con algoritmos

**Ordenar con un criterio propio** (por ejemplo, de mayor a menor):

```cpp
sort(v.begin(), v.end(), [](int a, int b) {
    return a > b;      // "a va antes que b si a es mayor" -> descendente
});
```

**Contar los que cumplen una condición** (`count_if`):

```cpp
int pares = count_if(v.begin(), v.end(), [](int x) {
    return x % 2 == 0;
});
```

**Hacer algo con cada elemento** (`for_each`):

```cpp
for_each(v.begin(), v.end(), [](int x) {
    cout << x << " ";
});
```

**Transformar** cada elemento (`transform`):

```cpp
transform(v.begin(), v.end(), v.begin(), [](int x) {
    return x * 2;      // duplica cada elemento, guardando en el mismo vector
});
```

### Capturas: usar variables de fuera

La lista `[]` puede **capturar** variables del entorno para usarlas dentro:

```cpp
int umbral = 5;
int cuantos = count_if(v.begin(), v.end(), [umbral](int x) {
    return x > umbral;      // usa 'umbral', capturado por valor
});
```
- `[umbral]` captura por **valor** (una copia).
- `[&umbral]` captura por **referencia** (la variable original).
- `[=]` captura todo por valor; `[&]` todo por referencia. Al empezar, captura solo lo que
  necesitas y por valor.

## Por qué esto importa

Combinar contenedores + algoritmos + lambdas te deja expresar operaciones complejas en **pocas
líneas, legibles y eficientes**, sin escribir bucles a mano ni gestionar memoria. Es el estilo
moderno de C++.

```cpp
// "de los numeros, ordena y quedate con la suma de los pares"
sort(v.begin(), v.end());
int sumaPares = 0;
for_each(v.begin(), v.end(), [&sumaPares](int x){ if (x % 2 == 0) sumaPares += x; });
```

## Errores típicos

- Olvidar `#include <algorithm>` (o `<numeric>` para `accumulate`).
- Pasar `begin()`/`end()` de **contenedores distintos**.
- Usar el iterador devuelto por `find` sin comprobar que no sea `end()`.
- En una lambda, usar una variable de fuera **sin capturarla** → error de compilación.

## Resumen

- `<algorithm>`: `sort`, `find`, `count`, `max_element`, `reverse`...; `<numeric>`: `accumulate`.
- Trabajan sobre rangos `begin()`..`end()`.
- Las **lambdas** `[captura](params){cuerpo}` son funciones anónimas para personalizar algoritmos
  (`sort` con criterio, `count_if`, `for_each`, `transform`).
- Las **capturas** `[x]` (valor) o `[&x]` (referencia) dan acceso a variables externas.

## Ejemplos

- [`ejemplos/ordenar_buscar.cpp`](ejemplos/ordenar_buscar.cpp)
- [`ejemplos/lambdas.cpp`](ejemplos/lambdas.cpp)

## Ejercicios

En [`ejercicios/`](ejercicios/).

## Para profundizar

- **Stroustrup**, *A Tour of C++*, cap. 12 ("Algorithms") y §6.3 (lambdas).
- **learncpp.com**, "Introduction to lambdas".
- **cppreference**, "Algorithms library". https://en.cppreference.com/w/cpp/algorithm
