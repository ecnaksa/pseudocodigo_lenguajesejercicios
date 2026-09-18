# 01 · Arreglos de punto flotante (`double`)

En el primer set los arreglos eran de enteros (`int`). Aquí muchos son de **`double`** porque
se miden magnitudes físicas continuas: amperios, voltios, grados. Cambia el tipo, pero la
lógica de recorrido es idéntica.

## 1. ¿Por qué `double` y no `int`?

Un `int` solo guarda números enteros: `3`, `-7`, `1023`. Una corriente de `2.75 A` o una
temperatura de `36.6 °C` **necesitan decimales**, y para eso está el punto flotante.

- **`float`**: ~7 cifras significativas (precisión simple).
- **`double`**: ~15–16 cifras (precisión doble). **Es el que usamos**, porque es el tipo real
  por defecto en C/C++ y el más común en cálculos.

En el pseudocódigo híbrido esto se escribe `Definir Arr[] como real`.

## 2. Declarar el arreglo `double` en cada lenguaje

```c
/* C */
int tam = 10;
double arr[tam];               /* arreglo de longitud variable de doubles */
```
```cpp
// C++
double* arr = new double[tam]; // reserva dinamica; al final delete[] arr;
```
```java
// Java
double[] arr = new double[tam];
```

## 3. Leer e imprimir doubles (la diferencia importante)

### Leer

| | Entero | Double |
|---|---|---|
| **C** | `scanf("%d", &x);` | `scanf("%lf", &x);` ← **`%lf`** para `double` |
| **C++** | `cin >> x;` | `cin >> x;` (igual, `cin` sabe el tipo) |
| **Java** | `sc.nextInt();` | `sc.nextDouble();` |

> En C el error típico es leer un `double` con `%d` o `%f`. Para **leer** un `double` con
> `scanf` se usa **`%lf`**. (Para **imprimir** con `printf`, en cambio, basta `%f`.)

### Imprimir con 2 decimales

```c
printf("%.2f", x);                                  // C
```
```cpp
cout << fixed << setprecision(2) << x;              // C++  (#include <iomanip>)
```
```java
System.out.printf(Locale.US, "%.2f", x);            // Java (Locale.US = punto decimal)
```

## 4. Cuidado: comparar doubles por igualdad

Dos `double` que "deberían" ser iguales a veces difieren en la 16.ª cifra por cómo se guardan
en binario. Por eso:

- **`==` con doubles es arriesgado** cuando el valor viene de un cálculo (`0.1 + 0.2` no es
  exactamente `0.3`).
- En estos problemas se usa `==` solo con valores **leídos directamente** o **exactos**
  (P7 "ceros exactos": `arr[i] == 0.0`; el usuario teclea `0`). Para P18 (comparar dos
  canales) se usó `int` justamente para que la igualdad sea limpia.
- Cuando de verdad haga falta comparar dos doubles calculados, lo correcto es mirar si su
  diferencia es muy pequeña: `if (fabs(a - b) < 0.0001)`.

Para **rangos** (P12) no hay problema, porque se usan `>=` y `<=`, no `==`.

## 5. Divisiones con doubles (P8, P13)

Si el arreglo ya es `double`, `suma` también lo es y `suma / tam` es **división real**
automáticamente (aunque `tam` sea `int`, se convierte). Por eso el promedio del P8 y del P13
sale con decimales sin necesidad de castear:

```c
double media = suma / tam;   // suma es double -> division real -> 36.64, no 36
```
(En el primer set, con `int`, sí hacía falta el casteo `(double)`; aquí no, porque el arreglo
ya es `double`.)
