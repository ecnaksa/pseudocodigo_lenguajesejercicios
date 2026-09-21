# Lección 04 — Operadores

Los **operadores** combinan valores para producir resultados. Java los tiene muy parecidos a C/C++,
con algún detalle propio (como el `+` que también concatena texto).

## 1. Aritméticos

| Operador | Operación | Ejemplo | Resultado |
|---|---|---|---|
| `+` | suma (o concatenación de texto) | `3 + 2` | `5` |
| `-` | resta | `3 - 2` | `1` |
| `*` | multiplicación | `3 * 2` | `6` |
| `/` | división | `7 / 2` | `3` (entera) / `3.5` (real) |
| `%` | residuo (módulo) | `7 % 2` | `1` |

Como en C: si ambos operandos de `/` son enteros, la división es **entera**. El operador **`%`**
da el **residuo** (clave para par/impar: `n % 2 == 0`).

### El `+` con texto: concatenación

En Java, `+` **también** une cadenas. Si uno de los operandos es `String`, el otro se convierte a
texto:

```java
System.out.println("Total: " + 5);        // "Total: 5"
System.out.println("Suma: " + 3 + 4);      // "Suma: 34"  (¡ojo!)
System.out.println("Suma: " + (3 + 4));    // "Suma: 7"   (parentesis primero)
```
Cuidado con el segundo caso: `"Suma: " + 3` ya es texto, así que `+ 4` concatena "4". Usa
paréntesis para forzar la suma numérica primero.

## 2. Asignación (compuesta)

`=` asigna; y hay atajos:

| Atajo | Equivale a |
|---|---|
| `x += 5` | `x = x + 5` |
| `x -= 5` | `x = x - 5` |
| `x *= 2` | `x = x * 2` |
| `x /= 2` | `x = x / 2` |
| `x %= 3` | `x = x % 3` |

## 3. Incremento y decremento

`++` suma 1, `--` resta 1. Formas prefija (`++i`) y postfija (`i++`):

```java
int a = 5;
System.out.println(a++);   // imprime 5, luego a vale 6 (postfijo)
int b = 5;
System.out.println(++b);   // imprime 6 (prefijo: incrementa antes)
```
Cuando van solos en su línea (como en un bucle), ambas formas hacen lo mismo.

## 4. Relacionales (comparación)

Devuelven **`boolean`** (`true`/`false`):

| Operador | Significado |
|---|---|
| `==` | igual a |
| `!=` | distinto de |
| `<` `>` | menor / mayor |
| `<=` `>=` | menor o igual / mayor o igual |

> **Diferencia con C:** en Java el resultado es un `boolean`, no un número. Y una condición
> **debe** ser `boolean`: `if (x)` con `x` entero **no compila** (evita el clásico error `if (x =
> 5)`).

> **¡Importante con objetos!** `==` compara si dos **referencias** apuntan al mismo objeto, **no**
> su contenido. Para comparar el **contenido** de objetos (como `String`) se usa el método
> **`.equals()`**:
> ```java
> String a = "hola", b = "hola";
> a == b;         // puede ser true o false segun el caso: NO fiable
> a.equals(b);    // true: compara el contenido (esto es lo correcto)
> ```
> Lo veremos en la lección de cadenas, pero recuérdalo: **objetos → `.equals()`, no `==`**.

## 5. Lógicos

Combinan condiciones booleanas:

| Operador | Nombre | Verdadero cuando… |
|---|---|---|
| `&&` | Y (AND) | **ambas** verdaderas |
| `\|\|` | O (OR) | **al menos una** verdadera |
| `!` | NO (NOT) | niega |

```java
int edad = 20;
boolean tieneEntrada = true;
if (edad >= 18 && tieneEntrada) {
    System.out.println("Puede pasar");
}
```

**Cortocircuito:** en `A && B`, si `A` es falso, `B` no se evalúa; en `A || B`, si `A` es
verdadero, `B` no se evalúa.

## 6. A nivel de bits (breve)

Operan sobre los bits de los enteros: `&` (AND), `|` (OR), `^` (XOR), `~` (NOT), `<<` (desplazar
izquierda), `>>` (derecha). Se usan en programación de bajo nivel; no los necesitarás al empezar.

## 7. Precedencia

De mayor a menor (simplificado): `()` → `!`, `++`, `--` → `*`, `/`, `%` → `+`, `-` → `<`, `>`,
`<=`, `>=` → `==`, `!=` → `&&` → `||` → `=`.

```java
int r = 2 + 3 * 4;      // 14 (primero *)
int s = (2 + 3) * 4;    // 20 (parentesis mandan)
```
**Consejo:** ante la duda, usa paréntesis.

## Errores típicos

- Confundir concatenación con suma: `"x" + 3 + 4` da `"x34"`, no `"x7"`.
- Comparar objetos (`String`) con `==` en vez de `.equals()`.
- Olvidar que `/` entre enteros trunca.
- Usar `&` (bit a bit) donde querías `&&` (lógico).

## Resumen

- Aritméticos `+ - * / %`; `+` también **concatena** texto (cuidado con el orden).
- Asignación compuesta (`+=`...) e incremento (`++`, `--`).
- Relacionales devuelven `boolean`; una condición debe ser `boolean`.
- **Objetos se comparan con `.equals()`, no con `==`.**
- Lógicos `&& || !` con cortocircuito. Los paréntesis controlan la precedencia.

## Ejemplos

- [`ejemplos/Aritmeticos.java`](ejemplos/Aritmeticos.java)
- [`ejemplos/Concatenacion.java`](ejemplos/Concatenacion.java)
- [`ejemplos/Logicos.java`](ejemplos/Logicos.java)

## Ejercicios

En [`ejercicios/`](ejercicios/).

## Para profundizar

- **The Java Tutorials (Oracle)**, "Operators".
  https://docs.oracle.com/javase/tutorial/java/nutsandbolts/operators.html
- **Baeldung**, "Operators in Java". https://www.baeldung.com/java-operators
