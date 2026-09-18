# Teoría — del pseudocódigo a C, C++ y Java

Esta carpeta explica **en detalle** cómo funciona cada componente que aparece en los
ejercicios y **cómo se traduce** el pseudocódigo híbrido a los tres lenguajes. Está pensada
para leerse en orden, pero cada archivo es independiente.

| # | Archivo | Contenido |
|---|---------|-----------|
| 00 | [`00_introduccion.md`](00_introduccion.md) | Qué es el "pseudocódigo híbrido", qué toma de PSeInt y qué de C/C++/Java. Cómo compilar y ejecutar cada lenguaje. |
| 01 | [`01_estructura_de_un_programa.md`](01_estructura_de_un_programa.md) | `main`, funciones, tipo de retorno (`int`/`void`/`bool`), `return`, ámbito de variables. |
| 02 | [`02_arreglos.md`](02_arreglos.md) | Arreglos: declaración, `Dimension`, índices base 0, límites, tamaño estático vs dinámico, `.length`. |
| 03 | [`03_paso_de_arreglos_a_funciones.md`](03_paso_de_arreglos_a_funciones.md) | Paso por valor vs por referencia; por qué al modificar un arreglo dentro de una función el cambio persiste. |
| 04 | [`04_entrada_y_salida.md`](04_entrada_y_salida.md) | `Escribir`/`Leer` → `printf`/`scanf`, `cin`/`cout`, `Scanner`/`println`. El "escribir sin saltar". |
| 05 | [`05_control_de_flujo.md`](05_control_de_flujo.md) | `for`, `while`, `if/else`, operadores relacionales y lógicos, el operador `%`. |
| 06 | [`06_tipos_y_division.md`](06_tipos_y_division.md) | Tipos de dato, `int` vs `double`/`float`, división entera vs real, casteo, el tipo `bool`. |

## Tabla rápida de equivalencias

| Concepto | Pseudocódigo híbrido | C | C++ | Java |
|---|---|---|---|---|
| Programa principal | `int main(){ … }` / `Algoritmo…FinAlgoritmo` | `int main(void){ … }` | `int main(){ … }` | `public static void main(String[] args){ … }` |
| Definir entero | `Definir x como entero` | `int x;` | `int x;` | `int x;` |
| Declarar arreglo (tam dinámico) | `Definir A[] como entero` + `Dimension A[tam]` | `int A[tam];` (VLA) o `malloc` | `int* A = new int[tam];` | `int[] A = new int[tam];` |
| Escribir texto + valor | `Escribir "S:", x` | `printf("S: %d\n", x);` | `cout << "S: " << x << endl;` | `System.out.println("S: " + x);` |
| Escribir sin salto | `Escribir sin saltar x` | `printf("%d", x);` | `cout << x;` | `System.out.print(x);` |
| Leer un entero | `Leer x` | `scanf("%d", &x);` | `cin >> x;` | `x = sc.nextInt();` |
| Bucle contado | `for (i=0; i<n; i++){ }` | igual | igual | igual |
| Condicional | `if (c){ } else { }` | igual | igual | igual |
| Comparar igualdad | `==` (distinto: `!=`) | `==` / `!=` | `==` / `!=` | `==` / `!=` |
| Residuo (par/impar) | `x % 2` | `x % 2` | `x % 2` | `x % 2` |
| Función con retorno | `funcion int f(int A[], int n){ … return v }` | `int f(int A[], int n){…}` | igual | `static int f(int[] A, int n){…}` |
| Función sin retorno | `funcion void f(…)` | `void f(…)` | `void f(…)` | `static void f(…)` |
| Verdadero/Falso | `bool` / `true` / `false` | `bool` (`<stdbool.h>`) | `bool` nativo | `boolean` |

> Los ejemplos de código completos y compilables están en
> [`../soluciones`](../soluciones); el pseudocódigo corregido en
> [`../pseudocodigo_corregido`](../pseudocodigo_corregido).
