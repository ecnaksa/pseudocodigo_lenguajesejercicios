# Lección 04 — Operadores

Los **operadores** combinan valores para producir resultados. Ya usaste `+` y `/`; aquí vemos
todos los grupos importantes.

## 1. Aritméticos

| Operador | Operación | Ejemplo | Resultado |
|---|---|---|---|
| `+` | suma | `3 + 2` | `5` |
| `-` | resta | `3 - 2` | `1` |
| `*` | multiplicación | `3 * 2` | `6` |
| `/` | división | `7 / 2` | `3` (entera) / `3.5` (real) |
| `%` | residuo (módulo) | `7 % 2` | `1` |

Recuerda de la lección 02: si ambos operandos de `/` son enteros, la división es **entera**. El
operador **`%`** solo funciona con enteros y da el **residuo**; es clave para saber si un número
es par (`n % 2 == 0`), múltiplo, etc.

```c
printf("%d\n", 17 / 5);   // 3
printf("%d\n", 17 % 5);   // 2   (17 = 5*3 + 2)
```

## 2. De asignación

`=` **asigna** (guarda un valor en una variable). Además hay **asignaciones compuestas**, atajos
muy usados:

| Atajo | Equivale a |
|---|---|
| `x += 5` | `x = x + 5` |
| `x -= 5` | `x = x - 5` |
| `x *= 2` | `x = x * 2` |
| `x /= 2` | `x = x / 2` |
| `x %= 3` | `x = x % 3` |

```c
int total = 10;
total += 5;    // 15
total *= 2;    // 30
```

## 3. Incremento y decremento

`++` suma 1; `--` resta 1. Son atajos de `x = x + 1`.

```c
int i = 5;
i++;    // ahora 6
i--;    // ahora 5
```

Hay dos formas, y la diferencia importa cuando se usan **dentro de otra expresión**:

- **Postfijo** `i++`: usa el valor **actual** y **luego** incrementa.
- **Prefijo** `++i`: incrementa **primero** y usa el valor **nuevo**.

```c
int a = 5;
printf("%d\n", a++);   // imprime 5, luego a vale 6
int b = 5;
printf("%d\n", ++b);   // imprime 6 (incrementa antes)
```
Cuando `i++` va solo en su línea (como en un bucle), ambas formas hacen lo mismo.

## 4. Relacionales (comparación)

Devuelven **verdadero (1)** o **falso (0)**. En C no hay un tipo `bool` "clásico" (aunque
`<stdbool.h>` añade `bool`, `true`, `false`): **cualquier valor distinto de 0 es "verdadero", y 0
es "falso"**.

| Operador | Significado |
|---|---|
| `==` | igual a |
| `!=` | distinto de |
| `<` `>` | menor / mayor |
| `<=` `>=` | menor o igual / mayor o igual |

```c
printf("%d\n", 5 > 3);    // 1 (verdadero)
printf("%d\n", 5 == 3);   // 0 (falso)
```

> **El error clásico:** `=` (asignar) frente a `==` (comparar). `if (x = 5)` **asigna** 5 a `x` y
> siempre es verdadero; lo correcto para comparar es `if (x == 5)`.

## 5. Lógicos

Combinan condiciones:

| Operador | Nombre | Verdadero cuando… |
|---|---|---|
| `&&` | Y (AND) | **ambas** son verdaderas |
| `\|\|` | O (OR) | **al menos una** es verdadera |
| `!` | NO (NOT) | niega (invierte) la condición |

```c
int edad = 20;
int tieneEntrada = 1;
if (edad >= 18 && tieneEntrada) {
    printf("Puede pasar\n");
}
```

**Evaluación en cortocircuito:** en `A && B`, si `A` es falso, `B` **no se evalúa** (ya no puede
cambiar el resultado). En `A || B`, si `A` es verdadero, `B` no se evalúa. Esto es útil y a veces
necesario (por ejemplo, comprobar que un divisor no es 0 antes de dividir).

## 6. A nivel de bits (bitwise) — introducción

Operan sobre los **bits** individuales de los enteros. Se usan en programación de bajo nivel
(hardware, banderas, optimizaciones):

| Operador | Significado |
|---|---|
| `&` | AND bit a bit |
| `\|` | OR bit a bit |
| `^` | XOR bit a bit |
| `~` | NOT bit a bit (invierte) |
| `<<` | desplazar bits a la izquierda |
| `>>` | desplazar bits a la derecha |

```c
printf("%d\n", 6 & 3);    // 2   (110 & 011 = 010)
printf("%d\n", 6 | 3);    // 7   (110 | 011 = 111)
printf("%d\n", 1 << 3);   // 8   (desplazar 1 tres posiciones = 2^3)
```
No los necesitarás al principio, pero es bueno saber que existen. `x << n` equivale a multiplicar
por 2ⁿ.

## 7. Precedencia: ¿en qué orden se evalúa?

Como en matemáticas, unos operadores se aplican antes que otros. De mayor a menor (simplificado):

1. `()` paréntesis
2. `!`, `++`, `--`, `(cast)`, `~`
3. `*`, `/`, `%`
4. `+`, `-`
5. `<`, `<=`, `>`, `>=`
6. `==`, `!=`
7. `&&`
8. `||`
9. `=`, `+=`, …

```c
int r = 2 + 3 * 4;      // 14, no 20: primero 3*4, luego +2
int s = (2 + 3) * 4;    // 20: los parentesis mandan
```

> **Consejo:** si dudas del orden, **usa paréntesis**. Hacen el código más claro aunque no sean
> estrictamente necesarios.

## Errores típicos

- Confundir `=` con `==`.
- Olvidar que `/` entre enteros trunca.
- Asumir un orden de operaciones equivocado (usa paréntesis).
- Confundir `&` (bit a bit) con `&&` (lógico) o `|` con `||`.

## Resumen

- Aritméticos: `+ - * / %` (ojo con `/` entera y `%` solo enteros).
- Asignación compuesta (`+=`, …) e incremento (`++`, `--`, pre/postfijo).
- Relacionales devuelven 1/0; lógicos `&& || !` con cortocircuito.
- Bit a bit para bajo nivel.
- La **precedencia** decide el orden; los **paréntesis** la controlan.

## Ejemplos

- [`ejemplos/aritmeticos.c`](ejemplos/aritmeticos.c)
- [`ejemplos/incremento.c`](ejemplos/incremento.c)
- [`ejemplos/logicos.c`](ejemplos/logicos.c)

## Ejercicios

En [`ejercicios/`](ejercicios/).

## Para profundizar

- **K&R**, cap. 2 (§2.5–2.12).
- **King**, cap. 4 ("Expressions") y cap. 20 ("Low-Level Programming") para bits.
- **cppreference**, "C operator precedence".
  https://en.cppreference.com/w/c/language/operator_precedence
