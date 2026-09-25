# Lección 05 — Control de flujo: decisiones y bucles

Hasta ahora los programas se ejecutaban de arriba abajo, línea por línea. El **control de flujo**
permite **decidir** qué código ejecutar (`if`, `match`) y **repetir** código (`loop`, `while`,
`for`). Verás que en Rust estas construcciones son **expresiones** (lección 04): pueden producir un
valor.

## `if`, `else if`, `else`

```rust
let temperatura = 28;

if temperatura > 30 {
    println!("Hace mucho calor");
} else if temperatura > 20 {
    println!("Hace buen tiempo");
} else {
    println!("Hace frio");
}
```

Diferencias con C y Java:

1. **La condición no lleva paréntesis.** Puedes ponerlos, pero el compilador te avisará de que
   sobran:

   ```
   warning: unnecessary parentheses around `if` condition
   help: remove these parentheses
   ```

2. **Las llaves son obligatorias**, aunque el cuerpo tenga una sola línea. Esto evita el famoso
   error de C de añadir una segunda línea a un `if` sin llaves creyendo que queda dentro.
3. **La condición debe ser `bool`.** No vale `if n` con un número (lección 02). Y el error clásico
   de C, asignar en lugar de comparar, se detecta al compilar:

   ```rust
   if x = 5 { ... }
   ```
   ```
   error[E0308]: mismatched types
     |
   3 |     if x = 5 {
     |        ^^^^^ expected `bool`, found `()`
     |
   help: you might have meant to compare for equality
     |
   3 |     if x == 5 {
     |           +
   ```

### `if` es una expresión

Como viste en la lección 04, `if` **produce un valor**: el de la rama que se ejecute. Esto sustituye
al operador ternario `condicion ? a : b` de C y Java, que Rust **no tiene**:

```rust
let edad = 20;
let categoria = if edad >= 18 { "adulto" } else { "menor" };
```

Reglas:

- **Todas las ramas deben producir el mismo tipo:**

  ```rust
  let y = if c { 5 } else { "cinco" };   // ERROR
  ```
  ```
  error[E0308]: `if` and `else` have incompatible types
    |
  3 |     let y = if c { 5 } else { "cinco" };
    |                    -          ^^^^^^^ expected integer, found `&str`
    |                    |
    |                    expected because of this
  ```

  Tiene sentido: el compilador debe conocer el tipo de `y` **antes** de ejecutar el programa, sin
  saber qué rama se tomará.

- **Si usas el valor, necesitas `else`.** Un `if` sin `else` vale `()` cuando la condición es falsa:

  ```
  error[E0317]: `if` may be missing an `else` clause
    = note: `if` expressions without `else` evaluate to `()`
  ```

## `match`: elegir entre muchos casos

`match` compara un valor con una lista de **patrones** y ejecuta la rama del **primero** que
coincida. Es como el `switch` de C/Java, pero mucho más potente y seguro. Aquí verás su uso básico;
en la lección 10 lo estudiarás a fondo.

```rust
let nota: u8 = 15;

let calificacion = match nota {
    18..=20 => "Excelente",
    14..=17 => "Bueno",
    11..=13 => "Aprobado",
    0..=10 => "Desaprobado",
    _ => "Nota invalida",          // _ = "cualquier otro valor"
};
```

- Cada **brazo** tiene la forma `patrón => expresión,`.
- Los patrones pueden ser valores (`1`), varios valores (`1 | 2 | 3`), rangos inclusivos
  (`11..=13`) o el comodín `_`.
- `match` es una **expresión**: todos los brazos deben dar el mismo tipo.
- **No hay "caída"** (*fall-through*) al siguiente caso como en el `switch` de C, así que no hace
  falta `break`.
- **Es exhaustivo**: el compilador **obliga** a cubrir **todos** los valores posibles. Si olvidas
  alguno, no compila, y te dice exactamente cuáles faltan:

  ```rust
  let t = match nota {        // nota: u8 (0..=255)
      0..=10 => "desaprobado",
      11..=20 => "aprobado",
  };
  ```
  ```
  error[E0004]: non-exhaustive patterns: `21_u8..=u8::MAX` not covered
    |
  3 |     let t = match nota {
    |                   ^^^^ pattern `21_u8..=u8::MAX` not covered
  ```

  El compilador sabe que un `u8` puede valer hasta 255 y que no dijiste qué hacer entre 21 y 255.
  En C, un `switch` sin `default` simplemente no hace nada en esos casos, en silencio.

Para ejecutar varias instrucciones en un brazo, usa un bloque: `1 => { println!("uno"); 1 }`.

## Bucles

Rust tiene tres bucles: `loop`, `while` y `for`.

### `loop`: repetir para siempre (hasta un `break`)

```rust
let mut contador = 0;
loop {
    contador += 1;
    if contador == 3 {
        continue;               // salta el resto de esta vuelta
    }
    if contador > 5 {
        break;                  // sale del bucle
    }
    println!("{contador}");     // 1 2 4 5
}
```

Es la forma idiomática de escribir un bucle infinito (en lugar de `while true` o `for(;;)`). El
compilador **sabe** que `loop` solo termina con `break`, y usa esa información (por ejemplo, para
saber que una variable queda inicializada).

**`break` con valor.** Como `loop` es una expresión, `break` puede **devolver un valor**:

```rust
let mut n = 1;
let primera_potencia_mayor_que_1000 = loop {
    n *= 2;
    if n > 1000 {
        break n;                // el loop "vale" n
    }
};
println!("{primera_potencia_mayor_que_1000}");   // 1024
```

Un uso muy común: **pedir un dato hasta que sea válido**:

```rust
let edad: u32 = loop {
    println!("Edad:");
    let mut entrada = String::new();
    io::stdin().read_line(&mut entrada).expect("Error al leer");
    match entrada.trim().parse() {
        Ok(numero) => break numero,                        // valido: sale del loop con el valor
        Err(_) => println!("Eso no es una edad valida, intenta de nuevo."),
    }
};
```

### `while`: repetir mientras se cumpla una condición

```rust
let mut cuenta_regresiva = 3;
while cuenta_regresiva > 0 {
    println!("{cuenta_regresiva}...");
    cuenta_regresiva -= 1;
}
println!("Despegue!");
```

Úsalo cuando **no sabes cuántas vueltas** darás, pero sí la condición para seguir. (No existe
`do-while`; se escribe con `loop` + `if ... { break; }` al final.)

### `for`: recorrer un rango o una colección

`for` es el bucle **más usado** en Rust. Recorre cualquier cosa **iterable**: rangos, arreglos,
vectores, caracteres de un texto…

**Rangos:**

```rust
for i in 0..5 { print!("{i} "); }        // 0 1 2 3 4       (excluye el 5)
for i in 1..=5 { print!("{i} "); }       // 1 2 3 4 5       (incluye el 5)
for i in (1..=5).rev() { print!("{i} "); }        // 5 4 3 2 1
for i in (0..=10).step_by(2) { print!("{i} "); }  // 0 2 4 6 8 10
```

- `a..b` es un rango **semiabierto** [a, b): incluye `a`, excluye `b`. Es el que corresponde a
  `for (i = a; i < b; i++)` en C.
- `a..=b` es **cerrado** [a, b]: incluye ambos extremos.

**Arreglos:**

```rust
let notas = [15, 18, 12, 20];

for nota in notas {                       // cada elemento
    println!("{nota}");
}

for (i, nota) in notas.iter().enumerate() {   // indice y elemento a la vez
    println!("nota {i}: {nota}");
}
```

- `enumerate()` produce pares `(índice, elemento)`.
- `.iter()` recorre el arreglo **sin consumirlo** (tomando referencias a sus elementos; lo
  entenderás en la lección 08). Para arreglos de números da igual; para colecciones de textos
  importará.

**¿Por qué no hay `for (i = 0; i < n; i++)`?** Rust no tiene el `for` de tres partes de C, a
propósito:

- Es la fuente de muchos errores de "uno de más o de menos" (*off-by-one*: `i <= n` en lugar de
  `i < n`).
- Recorrer **directamente los elementos** hace imposible salirse del arreglo.
- Como el compilador sabe que el índice nunca se sale, **elimina las comprobaciones de límites**:
  el `for` sobre elementos es tan rápido como el de C.

Si de verdad necesitas el índice, usa `for i in 0..a.len()` (o mejor, `enumerate()`).

### Etiquetas: salir de bucles anidados

`break` y `continue` afectan al bucle **más interno**. Para afectar a uno exterior, ponle una
**etiqueta** (un nombre que empieza con `'`):

```rust
'externo: for i in 1..=3 {
    for j in 1..=3 {
        if i * j == 4 {
            println!("encontrado: {i} x {j} = 4");
            break 'externo;           // sale de AMBOS bucles
        }
    }
}
```

En C harías esto con una variable bandera o con `goto`; en Java también existen las etiquetas.

## Patrones de bucle que usarás siempre

| Patrón | Idea | Ejemplo |
|---|---|---|
| **Acumulador** | Variable `mut` que va sumando | `let mut suma = 0; for x in a { suma += x; }` |
| **Contador** | Cuenta cuántos cumplen algo | `if x % 2 == 0 { pares += 1; }` |
| **Máximo / mínimo** | Guardar el mejor visto hasta ahora | `if x > max { max = x; }` |
| **Búsqueda** | Recorrer hasta encontrar y salir | `if x == buscado { encontrado = true; break; }` |
| **Validación** | Repetir la pregunta hasta que el dato sea válido | `loop { ... break valor; }` |
| **Menú** | Repetir: mostrar opciones, leer, actuar, hasta "salir" | `loop { ... match opcion { ... 0 => break, ... } }` |

(En la lección 15 verás que muchos de estos patrones se escriben en una sola línea con
**iteradores**: `a.iter().sum()`, `a.iter().max()`, `a.iter().filter(...).count()`.)

## Comparación con C y Java

| C / Java | Rust |
|---|---|
| `if (x > 0) { ... }` | `if x > 0 { ... }` |
| `y = c ? a : b;` | `let y = if c { a } else { b };` |
| `switch (x) { case 1: ...; break; default: ... }` | `match x { 1 => ..., _ => ... }` (exhaustivo, sin `break`) |
| `while (1) { ... }` / `for (;;)` | `loop { ... }` |
| `while (c) { ... }` | `while c { ... }` |
| `do { ... } while (c);` | `loop { ...; if !c { break; } }` |
| `for (i = 0; i < n; i++)` | `for i in 0..n` |
| `for (i = n - 1; i >= 0; i--)` | `for i in (0..n).rev()` |
| `for (int x : arreglo)` (Java) | `for x in arreglo` |

## Errores típicos

- Paréntesis en la condición → solo una advertencia, pero quítalos.
- `if` usado como valor sin `else`, o con ramas de tipos distintos → `E0317` / `E0308`.
- `match` que no cubre todos los casos → `E0004` (añade los que faltan o un `_`).
- Confundir `0..n` (excluye `n`) con `0..=n` (incluye `n`).
- Olvidar `mut` en el acumulador o el contador del bucle.
- Un `loop` o `while` que nunca cumple su condición de salida → bucle infinito (Ctrl+C para
  detenerlo).

## Resumen

- `if` / `else if` / `else`: condición `bool` sin paréntesis, llaves obligatorias. **Es una
  expresión** (sustituye al ternario); sus ramas deben tener el mismo tipo.
- `match`: compara con patrones (valores, `|`, rangos `a..=b`, `_`); **exhaustivo**, sin caída entre
  casos, y también es expresión.
- `loop` (infinito, `break valor`), `while` (mientras), `for` (rangos y colecciones).
- Rangos: `a..b` (excluye `b`), `a..=b` (incluye `b`), `.rev()`, `.step_by(n)`; `enumerate()`
  para índice + elemento.
- `break` / `continue`, con **etiquetas** `'nombre` para bucles anidados.

## Ejemplos

- [`ejemplos/condicionales.rs`](ejemplos/condicionales.rs) — `if`, `if` como expresión, `match`.
- [`ejemplos/bucles.rs`](ejemplos/bucles.rs) — `loop`, `while`, `for`, rangos, etiquetas.
- [`ejemplos/validar_entrada.rs`](ejemplos/validar_entrada.rs) — pedir un dato hasta que sea
  válido.
- [`ejemplos/menu.rs`](ejemplos/menu.rs) — un menú interactivo con `loop` + `match`.

## Ejercicios

En [`ejercicios/`](ejercicios/).

## Para profundizar

- ***The Rust Programming Language***, 3.5 "Control Flow".
  https://doc.rust-lang.org/book/ch03-05-control-flow.html
- ***Rust by Example***, "Flow of Control" (if/else, loop, while, for, match).
  https://doc.rust-lang.org/rust-by-example/flow_control.html
- ***Programming Rust*** (2.ª ed.), cap. 6 "Expressions" (secciones sobre `if`, `match` y bucles).
