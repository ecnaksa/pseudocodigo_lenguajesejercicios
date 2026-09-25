# Lección 07 — Ownership (propiedad)

Esta es **la lección más importante del curso**. El *ownership* es la idea que distingue a Rust de
todos los demás lenguajes populares y la que le permite ser **seguro sin recolector de basura**.
Tómate tu tiempo: lee despacio, ejecuta los ejemplos y **provoca los errores** a propósito para ver
qué dice el compilador. Todo lo que viene después (referencias, structs, colecciones, hilos) se
apoya en esta lección.

## El problema: ¿quién libera la memoria?

Todo programa necesita memoria para sus datos. Parte de esa memoria se pide **mientras el programa
se ejecuta** (por ejemplo, para un texto que escribe el usuario, cuyo tamaño no se conoce al
compilar). Esa memoria hay que **devolverla** cuando ya no se usa. Los lenguajes han resuelto esto
de tres formas:

| Estrategia | Lenguajes | Ventaja | Problema |
|---|---|---|---|
| **Manual**: el programador pide (`malloc`) y libera (`free`) | C, C++ (con `new`/`delete`) | Control total, sin coste extra | Olvidar liberar → **fuga de memoria**. Liberar dos veces → **doble liberación**. Usar tras liberar → ***use-after-free***. Todos son vulnerabilidades graves. |
| **Recolector de basura** (GC): un proceso busca la memoria que ya nadie usa y la libera | Java, Python, C#, Go, JavaScript | Cómodo y seguro | Consume CPU y memoria extra; **pausas** impredecibles; no apto para sistemas embebidos, núcleos de SO o tiempo real |
| **Ownership**: el compilador sabe, **al compilar**, en qué punto exacto deja de usarse cada valor, e inserta la liberación ahí | **Rust** | Seguro **y** sin coste en ejecución | Hay que aprender unas reglas nuevas (esta lección) |

Rust elige la tercera: **ni el programador ni un recolector deciden cuándo liberar; lo decide el
compilador, siguiendo tres reglas simples**. Si el programa las cumple, es imposible cometer los
errores de la primera fila. Si no las cumple, no compila.

## Antes de las reglas: la pila y el montículo

Para entender el *ownership* hay que saber **dónde** se guardan los datos. Un programa usa dos
zonas de memoria:

### La pila (*stack*)

- Guarda las **variables locales** de cada función.
- Funciona como una pila de platos: lo último que entra es lo primero que sale (**LIFO**). Al llamar
  a una función se "apila" un bloque (*frame*) con sus variables; al terminar, se "desapila" entero.
- Es **muy rápida**: reservar y liberar es solo mover un puntero.
- **Limitación:** solo admite datos de **tamaño fijo y conocido al compilar** (`i32` = 4 bytes,
  `[f64; 3]` = 24 bytes...).

### El montículo (*heap*)

- Guarda datos cuyo **tamaño se conoce al ejecutar** o que pueden **crecer**: un texto que escribe
  el usuario, una lista de elementos que va aumentando.
- Para usarlo, se **pide** un bloque del tamaño necesario al asignador de memoria, que devuelve su
  **dirección** (un puntero). Ese puntero, que sí tiene tamaño fijo, se guarda en la pila.
- Es **más lento** que la pila (hay que buscar un hueco libre, y acceder a través de un puntero).
- El bloque **debe liberarse** cuando ya no se use. **Este es el problema que resuelve el
  *ownership*.**

## El tipo `String`: un dato en el *heap*

Hasta ahora usaste textos literales (`"hola"`), de tipo `&str`. Son **fijos**: están grabados
dentro del propio ejecutable y no pueden cambiar. Para un texto que puede **crecer** o que se
conoce al ejecutar, Rust tiene el tipo **`String`**:

```rust
let mut s = String::from("hola");   // crea un String en el heap a partir de un literal
s.push_str(", mundo");              // puede crecer
println!("{s}");                    // hola, mundo
```

Así queda en memoria `let s = String::from("hola");`:

```
        PILA (variable s)                  HEAP
      +-----------+---------+          +---+---+---+---+
      | puntero   | --------+--------> | h | o | l | a |
      +-----------+---------+          +---+---+---+---+
      | longitud  |    4    |           0   1   2   3
      +-----------+---------+
      | capacidad |    4    |
      +-----------+---------+
```

- En la **pila** hay tres números de tamaño fijo: la **dirección** del texto, su **longitud** (bytes
  usados) y su **capacidad** (bytes reservados).
- El **texto en sí** está en el **heap**.

Usaremos `String` en toda la lección porque es el ejemplo más sencillo de un valor que **posee
memoria en el heap**. Lo mismo vale para `Vec<T>`, `HashMap` y la mayoría de colecciones (lección
11).

## Las tres reglas del *ownership*

1. **Cada valor tiene un dueño** (*owner*): la variable que lo contiene.
2. **Solo puede haber un dueño a la vez.**
3. **Cuando el dueño sale de su ámbito, el valor se libera** (Rust llama automáticamente a `drop`).

Parece poco, pero de estas tres reglas se deduce todo lo demás. Veámoslas una por una.

## Regla 3: al salir del ámbito, se libera

El **ámbito** (*scope*) de una variable es la región del programa donde es válida: desde su
declaración hasta el final del bloque `{ }` que la contiene.

```rust
fn main() {
    {                                   // s todavia no existe
        let s = String::from("hola");   // s es valida desde aqui
        println!("{s}");
    }                                   // fin del ambito: Rust llama a drop(s) -> se libera el heap
    // aqui s ya no existe
}
```

Al cerrar la llave, Rust **inserta automáticamente** el código que libera la memoria del `String`.
No escribes `free`. No hay recolector. Es como si el compilador escribiera el `free` por ti, **en el
lugar exacto y una sola vez**.

> Si conoces C++: es el patrón **RAII** (*Resource Acquisition Is Initialization*): el recurso se
> libera en el destructor cuando el objeto sale de ámbito. En C++ es una buena práctica opcional;
> en Rust es **la regla del lenguaje**.

## Regla 2: un solo dueño — el **movimiento** (*move*)

### Con enteros: copia

```rust
let x = 5;
let y = x;
println!("x = {x}, y = {y}");   // x = 5, y = 5
```

Nada sorprendente: `5` es un entero de tamaño fijo que vive en la pila; `let y = x` **copia** los 4
bytes. Hay dos valores independientes.

### Con `String`: movimiento

```rust
let s1 = String::from("hola");
let s2 = s1;
```

¿Qué se copia aquí? Solo los datos de la **pila** (puntero, longitud, capacidad), **no** el texto
del heap. Quedaría así:

```
       s1                                         
  +-----------+----+                             
  | puntero   | ---+---------+                  
  | longitud  | 4  |         |      HEAP         
  | capacidad | 4  |         +--> +---+---+---+---+
  +-----------+----+         |    | h | o | l | a |
       s2                    |    +---+---+---+---+
  +-----------+----+         |
  | puntero   | ---+---------+
  | longitud  | 4  |
  | capacidad | 4  |
  +-----------+----+
```

**Dos variables apuntan al mismo bloque del heap.** Si ambas fueran válidas, al terminar el ámbito
Rust liberaría ese bloque **dos veces** (una por `s1` y otra por `s2`): una **doble liberación**, el
error clásico de C que corrompe la memoria.

**La solución de Rust:** después de `let s2 = s1;`, **`s1` deja de ser válida**. Se dice que el
valor **se movió** (*moved*) de `s1` a `s2`. Ahora `s2` es el **único dueño**, y solo `s2` liberará
la memoria. Si intentas usar `s1`:

```rust
let s1 = String::from("hola");
let s2 = s1;
println!("{s1}");   // ERROR
```

```
error[E0382]: borrow of moved value: `s1`
 --> mover.rs:5:20
  |
3 |     let s1 = String::from("hola");
  |         -- move occurs because `s1` has type `String`, which does not implement the `Copy` trait
4 |     let s2 = s1;
  |              -- value moved here
5 |     println!("{}", s1);
  |                    ^^ value borrowed here after move
```

Lee el error como una historia: *"`s1` es un `String`, que no se copia (no implementa `Copy`); el
valor se movió aquí (línea 4); y aquí (línea 5) intentaste usarlo después del movimiento"*.

> **Un *move* no copia nada en el heap y es muy barato**: solo se copian los tres números de la pila
> (24 bytes en un sistema de 64 bits) y el compilador "tacha" la variable vieja. El "tachado" existe solo al compilar; en el ejecutable no
> queda ninguna comprobación.

### ¿Por qué no copiar el heap automáticamente?

Otros lenguajes copian el contenido (C++ con `std::string s2 = s1;`) o comparten la referencia
(Java). Rust no hace ninguna de las dos por defecto:

- Copiar el heap **automáticamente** puede ser **muy caro** (imagina un texto de 1 GB) y quedaría
  **oculto** en un simple `=`.
- Compartir sin control reintroduce el problema de "¿quién libera?".

Rust elige: **mover por defecto** (gratis y seguro) y **copiar solo cuando lo pides
explícitamente**.

## `clone`: copia profunda explícita

Si de verdad quieres **dos** textos independientes, lo pides con **`.clone()`**:

```rust
let s1 = String::from("hola");
let s2 = s1.clone();          // copia TAMBIEN el contenido del heap
println!("s1 = {s1}, s2 = {s2}");   // ambas validas
```

Ahora hay **dos bloques** en el heap, cada uno con su dueño; cada uno se liberará una vez. Cuando
leas `.clone()` en código Rust, sabrás que ahí **se está gastando memoria y tiempo**: el coste está a
la vista.

> **Consejo de aprendiz:** cuando el compilador se queje de un valor movido y no sepas resolverlo
> de otra forma, un `.clone()` casi siempre funciona. Es perfectamente válido mientras aprendes. En
> la lección 08 verás la solución habitual, que no copia nada: **prestar** el valor.

## Tipos `Copy`: los que se copian solos

¿Por qué `let y = x;` con enteros no movía? Porque los enteros son de tipo **`Copy`**: su valor
entero vive en la pila y copiarlo es trivial, así que Rust lo copia en lugar de moverlo, y la
variable original sigue siendo válida.

Son `Copy`:

- Todos los enteros (`i32`, `u8`, `usize`…), los flotantes (`f64`, `f32`), `bool` y `char`.
- Las **tuplas** y los **arreglos**, si **todos** sus elementos son `Copy`: `(i32, f64)` sí;
  `(i32, String)` no.
- Las referencias compartidas `&T` (lección 08).

**No** son `Copy`: `String`, `Vec<T>`, `HashMap`, `Box<T>` y, en general, **todo lo que posea
memoria en el heap** o cualquier otro recurso que haya que liberar (un archivo abierto, una conexión
de red). Un tipo no puede ser `Copy` y a la vez necesitar liberar algo al destruirse.

## *Ownership* y funciones

Pasar un valor a una función funciona **exactamente igual que asignarlo**: se **mueve** o se
**copia** según su tipo.

```rust
fn main() {
    let saludo = String::from("hola");
    tomar(saludo);                // el String se MUEVE al parametro `s`
    // println!("{saludo}");      // ERROR: saludo ya no es valida

    let n = 5;
    copiar(n);                    // el i32 se COPIA
    println!("{n}");              // bien: n sigue siendo valida
}

fn tomar(s: String) {             // s es la nueva duena del String
    println!("{s}");
}                                 // s sale de ambito -> drop -> se libera el heap

fn copiar(x: i32) {
    println!("{x}");
}
```

El error, si descomentas la línea, es muy instructivo:

```
error[E0382]: borrow of moved value: `saludo`
 --> o1.rs:8:16
  |
6 |     let saludo = String::from("hola");
  |         ------ move occurs because `saludo` has type `String`, which does not implement the `Copy` trait
7 |     tomar(saludo);
  |           ------ value moved here
8 |     println!("{saludo}");
  |                ^^^^^^ value borrowed here after move
  |
note: consider changing this parameter type in function `tomar` to borrow instead if owning the value isn't necessary
 --> o1.rs:1:13
  |
1 | fn tomar(s: String) {
  |    -----    ^^^^^^ this parameter takes ownership of the value
  |    |
  |    in this function
help: consider cloning the value if the performance cost is acceptable
  |
7 |     tomar(saludo.clone());
  |                 ++++++++
```

El compilador ofrece **dos** soluciones: clonar, o cambiar el parámetro para que **pida prestado**
el valor en lugar de adueñarse de él (*"to borrow instead"*). La segunda es el tema de la lección 08.

### Devolver valores también transfiere la propiedad

```rust
fn crear() -> String {
    let s = String::from("nuevo");
    s                         // se MUEVE al que llama (no se libera aqui)
}

fn agregar_signo(mut s: String) -> String {
    s.push('!');
    s                         // devolvemos la propiedad
}

let a = crear();              // a es la duena
let b = agregar_signo(a);     // a se mueve a la funcion; el resultado se mueve a b
println!("{b}");              // nuevo!
```

Así, un valor puede "viajar" entre funciones y siempre tiene **exactamente un dueño**.

### El problema: ¿y si solo quiero **mirar** el valor?

Imagina una función que calcula la longitud de un texto. Si recibe un `String`, se lo queda, y
quien llama lo pierde. Tendría que **devolverlo** junto al resultado:

```rust
fn calcular_longitud(s: String) -> (String, usize) {
    let longitud = s.len();
    (s, longitud)             // devolver el String para no perderlo... muy incomodo
}

let s1 = String::from("hola");
let (s1, largo) = calcular_longitud(s1);
```

Funciona, pero es incómodo. En la práctica casi nunca se escribe así: Rust permite **prestar** un
valor sin transferir su propiedad, mediante **referencias** (`&`). Es exactamente la lección 08.

## ¿Dónde más se mueve un valor?

Además de `let b = a;`, pasar argumentos y devolver valores, un valor que no es `Copy` también se
mueve cuando:

- se guarda dentro de otra estructura: un `struct` (lección 09), un `Vec` con `push` (lección 11);
- se recorre por valor con `for x in coleccion` (la colección se consume; lección 11);
- se usa dentro de un bucle, **la primera vuelta ya lo movió**:

  ```rust
  let s = String::from("hola");
  for _ in 0..3 {
      let t = s;          // ERROR en la 2.a vuelta
  }
  ```
  ```
  error[E0382]: use of moved value: `s`
    |
  3 |     for _ in 0..3 {
    |     ------------- inside of this loop
  4 |         let t = s;
    |                 ^ value moved here, in previous iteration of loop
  ```

## Liberar antes de tiempo: `drop`

Normalmente dejas que el valor se libere al final de su ámbito. Si quieres liberarlo **antes**
(por ejemplo, un búfer enorme que ya no necesitas), pásaselo a la función `drop`:

```rust
let datos = String::from("muchos datos...");
drop(datos);        // se mueve a drop, que lo libera en ese momento
// datos ya no es valida
```

`drop` no tiene nada de mágico: es una función que **toma la propiedad** de su argumento y... no
hace nada con él. Al terminar, el parámetro sale de ámbito y se libera. Es la regla 3 en acción.

Cuando varias variables salen de ámbito a la vez, se liberan en **orden inverso** al de su
declaración (la última declarada, primero). Puedes verlo en
[`ejemplos/ver_drop.rs`](ejemplos/ver_drop.rs).

## Resumen visual: qué pasa con `=` según el tipo

| Código | Tipo `Copy` (`i32`, `f64`, `bool`, `char`...) | Tipo que posee heap (`String`, `Vec`...) |
|---|---|---|
| `let b = a;` | **copia**: `a` y `b` válidas | **mueve**: solo `b` válida |
| `f(a);` | **copia**: `a` sigue válida | **mueve**: `a` ya no es válida |
| `let b = a.clone();` | (innecesario) | **copia profunda**: ambas válidas, doble memoria |
| Fin del ámbito | nada que liberar | **`drop`**: se libera el heap (una sola vez) |

## Lo que Rust impide (comparación con C)

| Error en C | Ejemplo en C | En Rust |
|---|---|---|
| Doble liberación | `char *b = a; free(a); free(b);` | Imposible: tras `let b = a;`, solo `b` es dueña y solo ella libera. |
| Uso tras liberar | `free(a); printf("%s", a);` | Imposible: usar una variable movida o liberada no compila (`E0382`). |
| Fuga de memoria | `a = malloc(...);` sin `free` | Se libera automáticamente al salir del ámbito. (Aún son posibles fugas en casos raros y deliberados, pero no por olvido.) |

## Consejos para "pelear" con el *borrow checker*

Al principio, el compilador rechazará código que en otros lenguajes funcionaría. Es normal: todos
los programadores de Rust pasaron por eso. Algunas pautas:

1. **Lee el error completo**, incluidas las notas y la ayuda. Dice qué valor se movió, dónde y
   dónde lo usaste después.
2. Pregúntate: *¿quién debería ser el dueño de este dato?* A menudo la respuesta aclara el diseño.
3. Si una función solo necesita **leer** un valor, no debería adueñarse de él: usa una referencia
   (lección 08).
4. Mientras aprendes, `.clone()` es una salida válida. Más adelante aprenderás a evitarlo.
5. El compilador no es tu enemigo: cada error que te muestra es un error que **no** llegará a
   producción.

## Resumen

- La memoria de la **pila** se libera sola; la del **heap** hay que liberarla. Rust lo resuelve con
  *ownership*, verificado **al compilar** y sin coste en ejecución.
- Tres reglas: **cada valor tiene un dueño**, **solo uno a la vez**, y **se libera cuando el dueño
  sale de ámbito**.
- Asignar o pasar un valor que no es `Copy` lo **mueve**: la variable original queda inválida
  (`E0382` si la usas).
- `.clone()` hace una **copia profunda explícita**.
- Los tipos simples (`i32`, `f64`, `bool`, `char` y tuplas/arreglos de ellos) son **`Copy`**: se
  copian en vez de moverse.
- Pasar a una función o devolver desde ella también mueve o copia.
- Para usar un valor **sin quedarse con él**, se usan **referencias** → lección 08.

## Ejemplos

- [`ejemplos/ambito.rs`](ejemplos/ambito.rs) — ámbitos, `String` en el heap, direcciones de
  memoria.
- [`ejemplos/mover_clonar.rs`](ejemplos/mover_clonar.rs) — *move*, `clone` y tipos `Copy`.
- [`ejemplos/propiedad_funciones.rs`](ejemplos/propiedad_funciones.rs) — mover a funciones y
  devolver la propiedad.
- [`ejemplos/ver_drop.rs`](ejemplos/ver_drop.rs) — ver **cuándo** se libera cada valor.

## Ejercicios

En [`ejercicios/`](ejercicios/). En esta lección la mayoría de los ejercicios consiste en **leer
código y predecir** si compila, y en **arreglar** programas que no compilan. Es la mejor forma de
interiorizar las reglas.

## Para profundizar

- ***The Rust Programming Language***, 4.1 "What is Ownership?" — la explicación de referencia,
  con los diagramas originales de la pila y el heap.
  https://doc.rust-lang.org/book/ch04-01-what-is-ownership.html
- ***Rust by Example***, "Scoping rules → RAII" y "Ownership and moves".
  https://doc.rust-lang.org/rust-by-example/scope/move.html
- ***Programming Rust*** (2.ª ed.), cap. 4 "Ownership and Moves" — el tratamiento más completo, con
  comparaciones detalladas con C++ y Python.
- **Microsoft Security Response Center**, "A proactive approach to more secure code" (2019) — por
  qué importa: ~70 % de las vulnerabilidades son errores de memoria.
