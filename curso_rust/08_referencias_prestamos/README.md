# Lección 08 — Referencias, préstamos y *slices*

En la lección 07 viste que pasar un `String` a una función le **transfiere la propiedad**, y que
para "recuperarlo" había que devolverlo: incómodo. La solución es **prestar** el valor sin
entregarlo, mediante **referencias**. Esta lección completa el núcleo de Rust: junto con el
*ownership*, las **reglas de préstamo** son lo que permite al compilador garantizar que no hay
errores de memoria. Al final verás los ***slices***, referencias a una **parte** de un texto o de un
arreglo.

## Referencias: usar un valor sin adueñarse de él

```rust
fn calcular_longitud(s: &String) -> usize {   // recibe una REFERENCIA a un String
    s.len()
}                                             // s sale de ambito, pero NO era duenia: no se libera nada

fn main() {
    let s1 = String::from("hola");
    let largo = calcular_longitud(&s1);       // &s1: creamos una referencia a s1
    println!("{s1} tiene {largo} bytes");     // s1 sigue siendo nuestra
}
```

- **`&s1`** crea una **referencia** a `s1`: un valor que **apunta** a `s1` sin ser su dueño.
- El tipo **`&String`** significa "referencia a un `String`".
- A la acción de crear una referencia se le llama **tomar prestado** (*borrowing*): como en la vida
  real, si te presto algo, lo usas y me lo devuelves; **sigue siendo mío**.
- Cuando `s` sale de ámbito al terminar la función, **no se libera nada**: la función nunca fue dueña
  del `String`.

En memoria:

```
   s (en calcular_longitud)       s1 (en main)                      HEAP
  +-----------+               +-----------+------+           +---+---+---+---+
  | puntero --+-------------->| puntero   | -----+---------->| h | o | l | a |
  +-----------+               | longitud  |  4   |           +---+---+---+---+
                              | capacidad |  4   |
                              +-----------+------+
```

Una referencia es, por dentro, una **dirección de memoria**, como un puntero de C. La diferencia es
que el compilador **garantiza** que siempre apunta a algo válido (lo verás enseguida).

## Las referencias son inmutables por defecto

Igual que las variables, una referencia `&T` solo permite **leer**:

```rust
fn cambiar(s: &String) {
    s.push_str(", mundo");    // ERROR
}
```

```
error[E0596]: cannot borrow `*s` as mutable, as it is behind a `&` reference
 --> b1.rs:2:5
  |
2 |     s.push_str(", mundo");
  |     ^ `s` is a `&` reference, so it cannot be borrowed as mutable
  |
help: consider changing this to be a mutable reference
  |
1 | fn cambiar(s: &mut String) {
  |                +++
```

## Referencias mutables: `&mut`

Para permitir que quien recibe el préstamo **modifique** el valor, se usa **`&mut`**:

```rust
fn cambiar(s: &mut String) {
    s.push_str(", mundo");
}

fn main() {
    let mut s = String::from("hola");   // la variable debe ser mut
    cambiar(&mut s);                    // prestamo MUTABLE
    println!("{s}");                    // hola, mundo
}
```

Hacen falta **tres** `mut`: en la variable (`let mut s`), al prestar (`&mut s`) y en el tipo del
parámetro (`&mut String`). Es deliberado: al leer `cambiar(&mut s)` sabes, **sin mirar la función**,
que `s` puede cambiar. En C, `cambiar(s)` no te dice nada.

### Desreferenciar: `*`

Para leer o escribir **el valor al que apunta** una referencia se usa `*` (igual que con punteros en
C):

```rust
fn duplicar(x: &mut i32) {
    *x *= 2;             // "el valor apuntado por x" se multiplica por 2
}

let mut n = 21;
duplicar(&mut n);
println!("{n}");         // 42
```

En la práctica escribirás `*` menos de lo que crees, porque Rust **desreferencia automáticamente**
al llamar a métodos (`s.len()` funciona igual si `s` es `String` o `&String`), al imprimir con
`println!` y al comparar referencias entre sí.

## Las reglas del préstamo

El *borrow checker* (verificador de préstamos) aplica **dos reglas**:

> **1. En cada momento puedes tener O BIEN una referencia mutable, O BIEN cualquier número de
> referencias inmutables (pero no ambas cosas a la vez).**
>
> **2. Las referencias deben ser siempre válidas.**

Dicho de otro modo: **o muchos lectores, o un solo escritor**. Es la misma regla que protege una base
de datos o un documento compartido: varios pueden leer a la vez; pero mientras alguien escribe,
nadie más debe leer ni escribir.

### Regla 1a: no dos préstamos mutables a la vez

```rust
let mut s = String::from("hola");
let r1 = &mut s;
let r2 = &mut s;          // ERROR
println!("{r1} {r2}");
```

```
error[E0499]: cannot borrow `s` as mutable more than once at a time
 --> b2.rs:4:14
  |
3 |     let r1 = &mut s;
  |              ------ first mutable borrow occurs here
4 |     let r2 = &mut s;
  |              ^^^^^^ second mutable borrow occurs here
5 |     println!("{r1} {r2}");
  |                -- first borrow later used here
```

Esto impide las ***data races*** (carreras de datos): dos partes del programa modificando el mismo
dato sin coordinarse. En programas con hilos, las carreras de datos son de los errores más difíciles
de encontrar, porque aparecen solo a veces. Rust las detecta **al compilar** (lección 19).

### Regla 1b: no mezclar préstamo mutable con préstamos inmutables

Este es un ejemplo real y muy instructivo con un `Vec` (una lista que puede crecer; lección 11):

```rust
let mut v = vec![1, 2, 3];
let primero = &v[0];      // referencia inmutable a un elemento
v.push(4);                // prestamo mutable del vector: ERROR
println!("primero = {primero}");
```

```
error[E0502]: cannot borrow `v` as mutable because it is also borrowed as immutable
 --> b3.rs:4:5
  |
3 |     let primero = &v[0];
  |                    - immutable borrow occurs here
4 |     v.push(4);
  |     ^^^^^^^^^ mutable borrow occurs here
5 |     println!("primero = {primero}");
  |                          ------- immutable borrow later used here
```

¿Por qué importa? Porque `push` puede necesitar **más espacio**: si el bloque del heap está lleno,
el vector pide un bloque **más grande**, copia los elementos y **libera el bloque viejo**. Entonces
`primero` apuntaría a memoria **liberada**. En C++ este error existe y tiene nombre: **invalidación
de iteradores** (*iterator invalidation*); compila sin problemas y falla (o no) al ejecutarse. En
Rust, no compila.

### El préstamo dura hasta su **último uso**

El ámbito de una referencia no es todo el bloque: termina en el **último lugar donde se usa**. Esto
es válido:

```rust
let mut s = String::from("hola");

let r1 = &s;
let r2 = &s;
println!("{r1} y {r2}");   // ultimo uso de r1 y r2: sus prestamos terminan aqui

let r3 = &mut s;           // bien: ya no hay prestamos inmutables activos
r3.push('!');
println!("{r3}");
```

(Esta capacidad del compilador se llama *non-lexical lifetimes*, NLL.) Por eso, muchas veces un error
de préstamo se arregla **reordenando** las líneas para que los usos no se solapen.

### Regla 2: nada de referencias colgantes

En C es fácil devolver la dirección de una variable local, que deja de existir al terminar la
función (un **puntero colgante**):

```c
char *colgante(void) {
    char s[] = "hola";
    return s;              /* compila (con un aviso); s ya no existe al volver */
}
```

En Rust:

```rust
fn colgante() -> &String {
    let s = String::from("hola");
    &s                     // s se libera al terminar la funcion...
}
```

```
error[E0106]: missing lifetime specifier
 --> b4.rs:1:18
  |
1 | fn colgante() -> &String {
  |                  ^ expected named lifetime parameter
  |
  = help: this function's return type contains a borrowed value, but there is no value for it to be borrowed from
...
help: instead, you are more likely to want to return an owned value
  |
1 - fn colgante() -> &String {
1 + fn colgante() -> String {
```

El mensaje dice: *"el tipo de retorno contiene un valor prestado, pero no hay ningún valor del que
pueda estar prestado"*. La solución es la que sugiere: **devolver el `String` en sí** (moverlo a
quien llama), no una referencia. (Los *lifetimes* que menciona el error son el tema de la lección
14.)

## Resumen de los tres modos de pasar un valor

| Parámetro | Quién es dueño | ¿Puede leer? | ¿Puede modificar? | ¿Cuántos a la vez? | Después de la llamada… |
|---|---|---|---|---|---|
| `x: T` | la **función** (se movió o copió) | sí | sí (si es `mut x`) | — | si `T` no es `Copy`, el original ya no se puede usar |
| `x: &T` | **quien llama** | sí | no | muchos | todo sigue igual |
| `x: &mut T` | **quien llama** | sí | sí | **uno solo** | el original refleja los cambios |

**Cómo elegir** (de más a menos habitual):

1. ¿La función solo necesita **mirar** el valor? → **`&T`**.
2. ¿Necesita **modificarlo** pero quien llama lo sigue usando? → **`&mut T`**.
3. ¿Necesita **quedárselo** (guardarlo en una estructura, enviarlo a otro hilo, consumirlo)? →
   **`T`**.

## *Slices*: referencias a una parte

Un ***slice*** (rebanada) es una referencia a una **secuencia contigua** de elementos dentro de una
colección, en lugar de a la colección entera.

### *Slices* de texto: `&str`

```rust
let s = String::from("hola mundo");

let hola = &s[0..4];     // bytes 0, 1, 2, 3  -> "hola"
let mundo = &s[5..10];   // bytes 5..9        -> "mundo"
let hola = &s[..4];      // desde el principio
let mundo = &s[5..];     // hasta el final
let todo = &s[..];       // todo el texto
```

Un *slice* guarda **un puntero al primer elemento y una longitud** (un "puntero gordo", *fat
pointer*):

```
   mundo                          s                            HEAP
  +-----------+------+        +-----------+------+       +---+---+---+---+---+---+---+---+---+---+
  | puntero --+---+  |        | puntero --+------+------>| h | o | l | a |   | m | u | n | d | o |
  | longitud  | 5 |  |        | longitud  |  10  |       +---+---+---+---+---+---+---+---+---+---+
  +-----------+---+--+        | capacidad |  10  |         0   1   2   3   4   5   6   7   8   9
                  |           +-----------+------+                           ^
                  +----------------------------------------------------------+
```

El tipo de un *slice* de texto es **`&str`**. Y ahora entiendes por fin el tipo de los literales:

```rust
let saludo = "hola";      // tipo &str: un slice que apunta a texto guardado DENTRO del ejecutable
```

Por eso los literales son inmutables: son una referencia inmutable a datos del propio programa.

> **Cuidado — los índices son de *bytes*, no de caracteres.** Los textos en Rust son UTF-8, donde
> letras como `ñ` o `á` ocupan **2 bytes**. Si cortas por la mitad de un carácter, el programa se
> detiene:
> ```
> byte index 2 is not a char boundary; it is inside 'ñ' (bytes 1..3) of `año`
> ```
> Con texto que puede tener caracteres no ASCII, recorre con `.chars()` en lugar de cortar por
> índices. Lo verás a fondo en la lección 11.

### El ejemplo clásico: la primera palabra

Queremos una función que devuelva la primera palabra de un texto. Primer intento: devolver el
**índice** donde termina:

```rust
fn fin_primera_palabra(s: &String) -> usize {
    for (i, b) in s.bytes().enumerate() {   // bytes(): recorre los bytes del texto
        if b == b' ' {
            return i;
        }
    }
    s.len()
}

let mut s = String::from("hola mundo");
let fin = fin_primera_palabra(&s);   // 4
s.clear();                           // vaciamos el texto...
// ...pero `fin` sigue valiendo 4: un indice DESINCRONIZADO que apunta a nada
```

El índice es un número suelto, sin relación con `s`: si `s` cambia, nadie te avisa. Con un
***slice***, en cambio, el compilador **sabe** que el resultado depende de `s`:

```rust
fn primera_palabra(s: &str) -> &str {
    for (i, b) in s.bytes().enumerate() {
        if b == b' ' {
            return &s[..i];
        }
    }
    s
}

let mut s = String::from("hola mundo");
let palabra = primera_palabra(&s);   // prestamo inmutable de s
s.clear();                           // prestamo mutable: ERROR mientras `palabra` siga en uso
println!("{palabra}");
```

```
error[E0502]: cannot borrow `s` as mutable because it is also borrowed as immutable
  --> b5.rs:12:5
   |
11 |     let palabra = primera_palabra(&s);
   |                                   -- immutable borrow occurs here
12 |     s.clear();
   |     ^^^^^^^^^ mutable borrow occurs here
13 |     println!("{palabra}");
   |                ------- immutable borrow later used here
```

Un error lógico (usar un resultado obsoleto) se convirtió en un **error de compilación**. Esto es
Rust en estado puro: usar los tipos para que ciertos errores **no se puedan escribir**.

### Idioma: prefiere `&str` a `&String` en los parámetros

Observa que la versión buena de `primera_palabra` recibe **`&str`**, no `&String`. Es más general:

```rust
let s = String::from("hola mundo");
primera_palabra(&s);          // &String se convierte solo en &str ("deref coercion")
primera_palabra(&s[5..]);     // un slice de un String
primera_palabra("hola mundo");// un literal (ya es &str)
```

Regla práctica: **si una función solo lee texto, que reciba `&str`**.

### *Slices* de arreglos: `&[T]`

Lo mismo funciona con arreglos (y con vectores, lección 11):

```rust
let a = [10, 20, 30, 40, 50];
let parte: &[i32] = &a[1..4];     // [20, 30, 40]
println!("{:?} tiene {} elementos", parte, parte.len());
```

Y esto resuelve algo que en C siempre fue incómodo. Recuerda la firma del ejercicio 01 de este
repositorio:

```c
int sumaElementos(int Arr[], int tam);   /* C: el arreglo no sabe su tamanio, hay que pasarlo */
```

En Rust, un *slice* **lleva su longitud consigo**:

```rust
fn suma_elementos(arr: &[i32]) -> i32 {   // acepta arreglos de CUALQUIER tamanio, vectores y slices
    let mut suma = 0;
    for x in arr {
        suma += x;
    }
    suma
}

suma_elementos(&[1, 2, 3]);          // arreglo de 3
suma_elementos(&a);                  // arreglo de 5
suma_elementos(&a[1..3]);            // una parte
```

No hay forma de pasar un tamaño equivocado, ni de leer fuera del arreglo.

### *Slices* mutables: `&mut [T]`

Para **modificar** los elementos de un arreglo desde una función, se pasa un `&mut [T]`. Así se
escribe el ejercicio 12 de este repositorio (`invierteArreglo`):

```rust
fn invierte_arreglo(arr: &mut [i32]) {
    let n = arr.len();
    for i in 0..n / 2 {
        arr.swap(i, n - 1 - i);       // intercambia dos posiciones
    }
}

let mut a = [1, 2, 3, 4, 5];
invierte_arreglo(&mut a);
println!("{:?}", a);                  // [5, 4, 3, 2, 1]
```

## Comparación: punteros y referencias en cada lenguaje

| | C (punteros) | C++ (referencias) | Java (referencias) | **Rust (`&` / `&mut`)** |
|---|---|---|---|---|
| ¿Pueden ser nulas? | sí (`NULL`) | no (pero los punteros sí) | sí (`null`) | **no, nunca** |
| ¿Pueden quedar colgantes? | sí | sí | no (hay GC) | **no** (lo verifica el compilador) |
| ¿Varios pueden modificar a la vez? | sí | sí | sí | **no**: un solo `&mut` |
| ¿Se distingue lectura de escritura? | con `const` (opcional) | con `const` (opcional) | no | **sí**: `&` vs `&mut`, obligatorio |
| ¿Coste en ejecución? | ninguno | ninguno | GC | **ninguno** (todo se verifica al compilar) |

## Errores típicos

| Error | Causa | Solución habitual |
|---|---|---|
| `E0596` cannot borrow as mutable, behind a `&` reference | modificar a través de `&T` | usar `&mut T` (y `let mut`) |
| `E0499` cannot borrow as mutable more than once | dos `&mut` activos a la vez | usar uno, terminar de usarlo, y luego el otro |
| `E0502` cannot borrow as mutable because it is also borrowed as immutable | modificar mientras existe una referencia de lectura que se usa después | reordenar el código, o copiar el dato que necesitas (`let x = v[0];` en lugar de `&v[0]`) |
| `E0106` missing lifetime specifier | devolver una referencia a algo local | devolver el valor con propiedad (`String` en lugar de `&String`) |
| panic `byte index ... is not a char boundary` | cortar un texto UTF-8 por la mitad de un carácter | recorrer con `.chars()` |

## Resumen

- `&x` presta `x` para **leer**; `&mut x` lo presta para **modificar**. El dueño sigue siendo el
  mismo y el préstamo no libera nada.
- **Reglas**: o **muchas `&`** o **una sola `&mut`** a la vez; y las referencias **siempre son
  válidas** (nada de colgantes ni nulas).
- Un préstamo dura hasta su **último uso**.
- `*` desreferencia; en métodos, `println!` y comparaciones se hace solo.
- Los ***slices*** (`&str`, `&[T]`, `&mut [T]`) son referencias a una parte contigua y **conocen su
  longitud**.
- Los literales de texto son `&str`. En parámetros de solo lectura, prefiere **`&str`** y **`&[T]`**.
- Elección de parámetros: **`&T`** para leer, **`&mut T`** para modificar, **`T`** para quedárselo.

## Ejemplos

- [`ejemplos/prestamos.rs`](ejemplos/prestamos.rs) — `&`, `&mut`, `*` y las reglas del préstamo.
- [`ejemplos/slices_texto.rs`](ejemplos/slices_texto.rs) — `&str`, la primera palabra, `&str` vs
  `&String`.
- [`ejemplos/slices_arreglos.rs`](ejemplos/slices_arreglos.rs) — `&[T]` y `&mut [T]`: los
  ejercicios 01, 12, 13 y 14 del repositorio en Rust.

## Ejercicios

En [`ejercicios/`](ejercicios/).

## Para profundizar

- ***The Rust Programming Language***, 4.2 "References and Borrowing" y 4.3 "The Slice Type".
  https://doc.rust-lang.org/book/ch04-02-references-and-borrowing.html
- ***Rust by Example***, "Scoping rules → Borrowing".
  https://doc.rust-lang.org/rust-by-example/scope/borrow.html
- ***Programming Rust*** (2.ª ed.), cap. 5 "References" — incluye una excelente explicación de por
  qué la regla "muchos lectores o un escritor" elimina clases enteras de errores.
- **Documentación de `slice`**: todos los métodos de `&[T]` (`len`, `swap`, `sort`, `contains`,
  `iter`...). https://doc.rust-lang.org/std/primitive.slice.html
