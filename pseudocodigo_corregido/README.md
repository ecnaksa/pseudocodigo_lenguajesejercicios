# Pseudocódigo híbrido corregido

Esta carpeta contiene la **versión corregida** del pseudocódigo de los 15 ejercicios,
manteniendo el estilo "híbrido" original: mezcla el vocabulario de **PSeInt**
(`Algoritmo`, `Definir ... como entero`, `Dimension`, `Escribir`, `Leer`) con la
**estructura de C/C++/Java** (`int main(){ }`, funciones con tipo de retorno,
`for (…;…;…)`, `if (…){ } else { }`, `return`).

La idea es corregir los **errores reales** (bugs de lógica, nombres que no coinciden,
sintaxis imposible) **sin perder la esencia** del razonamiento en pseudocódigo, para
que sirva de puente natural hacia el código real de las carpetas `soluciones/c`,
`soluciones/cpp` y `soluciones/java`.

## Archivos

| Archivo | Ejercicios |
|---|---|
| [`nivel_1_basico.md`](nivel_1_basico.md) | 01 a 04 |
| [`nivel_2_intermedio.md`](nivel_2_intermedio.md) | 05 a 11 |
| [`nivel_3_avanzado.md`](nivel_3_avanzado.md) | 12 a 15 |

## Convención usada en la corrección

Para que el pseudocódigo sea coherente y traducible 1‑a‑1 a los tres lenguajes, se
fijó esta convención (y se explica en detalle en la carpeta [`../teoria`](../teoria)):

- **Programa principal:** `int main(){ … return 0 }`. El único caso especial es el
  Ejercicio 12, que se deja en estilo PSeInt puro (`Algoritmo … FinAlgoritmo` actuando
  como `main`) para ilustrar esa equivalencia; ver la nota del propio ejercicio.
- **Funciones:** `funcion <tipo> nombre(<parámetros>){ … }`, con el **tipo de retorno**
  explícito (`int`, `void`, `bool`) igual que lo pide cada enunciado.
- **Declaración de variables:** `Definir a, b, i como enteros`.
- **Arreglos:** se **declara** con `Definir Arr[] como entero` y se **dimensiona**
  con `Dimension Arr[tam]`, siempre **después** de conocer `tam` (después de `Leer tam`).
- **Entrada / salida:** `Escribir "texto", valor` y `Leer variable`.
  `Escribir sin saltar …` = imprimir **sin** salto de línea al final (se conserva tal
  cual porque es un concepto legítimo de pseudocódigo).
- **Llamadas a funciones:** se pasan **solo los argumentos**, nunca los tipos.
  Correcto: `sumaElementos(Arr, tam)`. Incorrecto (como venía): `suma(int Arr[], int tam)`.
- **`int(x/y)`** indica **división entera** (por ejemplo `int(tam/2)` = mitad del arreglo).

## Correcciones globales (aplican a casi todos los ejercicios)

Estos tres errores se repetían en casi todos los ejercicios del JSON original; se
corrigieron en todos y aquí se listan una sola vez para no repetirlos ejercicio por
ejercicio:

1. **`for` con comas → punto y coma.** El original escribía `for (i=0, i<tam, i++)`.
   En C/C++/Java el `for` separa sus tres partes con **`;`**: `for (i=0; i<tam; i++)`.
   (Con comas, `i=0, i<tam` sería el "operador coma" y el bucle no haría lo esperado.)
2. **`=` vs `==`.** En las **comparaciones** se usa `==` (igual) y `!=` (distinto);
   `=` es **asignación**. El original comparaba con un solo `=` en varios `if`.
3. **Tipos dentro de la llamada.** Los tipos (`int`, `int[]`) solo van en la
   **definición** de la función, no cuando se la **invoca**.

Cada ejercicio añade, además, su bloque **"Correcciones aplicadas"** con los errores
propios (bugs de lógica, nombres que no coinciden, variables sin declarar, etc.).
