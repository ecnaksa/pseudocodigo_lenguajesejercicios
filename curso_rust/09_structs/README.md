# Lección 09 — Structs y métodos

Hasta ahora, cada dato vivía en su propia variable (o en una tupla sin nombres). Un **`struct`**
(estructura) agrupa varios datos relacionados bajo **un nombre de tipo**, con **un nombre para cada
campo**. Con un bloque **`impl`** le añades **comportamiento** (métodos). Es la herramienta principal
de Rust para **modelar** los conceptos de tu programa: un estudiante, una cuenta bancaria, un sensor,
un punto en el plano.

Si vienes de Java o C++, un `struct` con `impl` se parece a una **clase**, pero verás diferencias
importantes: no hay herencia, no hay constructores especiales y no hay `null`.

## Definir un struct

```rust
struct Estudiante {
    nombre: String,
    edad: u8,
    promedio: f64,
    activo: bool,
}
```

- El nombre del tipo va en **`PascalCase`**; los campos, en `snake_case`.
- Cada campo tiene un **tipo obligatorio**.
- La definición **no crea ningún dato**: define un **tipo nuevo**, un molde.

## Crear una instancia

```rust
let ana = Estudiante {
    nombre: String::from("Ana"),
    edad: 20,
    promedio: 16.5,
    activo: true,
};

println!("{} tiene {} anios", ana.nombre, ana.edad);   // acceso con .
```

- Hay que dar valor a **todos** los campos (en cualquier orden). Si falta uno, no compila:

  ```
  error[E0063]: missing field `alto` in initializer of `Rectangulo`
  ```

  No existen campos "sin inicializar" ni valores `null` por defecto como en Java.

### Mutabilidad: toda la instancia o nada

Para modificar un campo, la **instancia completa** debe ser `mut`. Rust no permite marcar solo
algunos campos como mutables:

```rust
let mut ana = Estudiante { /* ... */ };
ana.edad = 21;               // bien, porque `ana` es mut
```

Sin `mut`:

```
error[E0594]: cannot assign to `r.ancho`, as `r` is not declared as mutable
help: consider changing this to be mutable
  |
6 |     let mut r = Rectangulo { ancho: 3.0, alto: 2.0 };
  |         +++
```

### Atajos de inicialización

**Abreviatura de campos** (*field init shorthand*): si una variable se llama igual que el campo,
basta con escribirla una vez:

```rust
fn nuevo_estudiante(nombre: String, edad: u8) -> Estudiante {
    Estudiante {
        nombre,              // equivale a  nombre: nombre
        edad,                // equivale a  edad: edad
        promedio: 0.0,
        activo: true,
    }
}
```

**Actualización a partir de otra instancia** (*struct update syntax*): `..otra` toma los campos que
no indiques de otra instancia:

```rust
let luis = Estudiante {
    nombre: String::from("Luis"),
    ..ana                    // el resto de campos, copiados/movidos desde ana
};
```

Cuidado: funciona como una **asignación**, así que los campos que no son `Copy` **se mueven**. Si
el `nombre` (un `String`) viniera de `ana`, `ana` quedaría "parcialmente movida":

```
error[E0382]: borrow of partially moved value: `u1`
  = note: partial move occurs because `u1.nombre` has type `String`, which does not implement the `Copy` trait
```

### ¿`String` o `&str` en los campos?

Observa que `Estudiante` usa `nombre: String` y no `&str`. Es lo recomendable: así el struct **es
dueño de sus datos** y vive tanto como quiera. Un campo `&str` sería una **referencia** a un texto
que pertenece a otro, y el compilador exigiría garantizar que ese texto vive más que el struct
(eso requiere *lifetimes*, lección 14). **Regla práctica: en los structs, usa tipos con propiedad
(`String`, `Vec<T>`)** salvo que tengas un buen motivo.

## Imprimir un struct: `#[derive(Debug)]`

Un struct nuevo no sabe imprimirse:

```
error[E0277]: `Rectangulo` doesn't implement `Debug`
  = help: the trait `Debug` is not implemented for `Rectangulo`
  = note: add `#[derive(Debug)]` to `Rectangulo` or manually `impl Debug for Rectangulo`
```

Tal como sugiere el compilador, basta con **derivar** `Debug`:

```rust
#[derive(Debug)]
struct Rectangulo {
    ancho: f64,
    alto: f64,
}

let r = Rectangulo { ancho: 3.0, alto: 2.0 };
println!("{:?}", r);    // Rectangulo { ancho: 3.0, alto: 2.0 }
println!("{:#?}", r);   // una linea por campo
dbg!(&r);               // [archivo:linea:col] &r = Rectangulo { ... }
```

`#[derive(...)]` es un **atributo** que le pide al compilador que **genere automáticamente** cierto
código. Otros que usarás a menudo:

| Derive | Qué genera | Permite |
|---|---|---|
| `Debug` | formato para depurar | `{:?}`, `dbg!` |
| `Clone` | copia profunda | `.clone()` |
| `Copy` | copia implícita (solo si **todos** los campos son `Copy`) | `let b = a;` sin mover |
| `PartialEq` | comparación campo a campo | `==`, `!=` |
| `Default` | valor por defecto de cada campo (0, `false`, `""`...) | `Tipo::default()` |

(Qué son exactamente estos "traits" lo verás en la lección 13. Para mostrar un struct **al usuario**
con `{}` hay que implementar `Display` a mano; también en la lección 13.)

## Métodos: el bloque `impl`

Los **métodos** son funciones asociadas a un tipo. Se definen en un bloque **`impl`**:

```rust
#[derive(Debug)]
struct Rectangulo {
    ancho: f64,
    alto: f64,
}

impl Rectangulo {
    fn area(&self) -> f64 {
        self.ancho * self.alto
    }

    fn escalar(&mut self, factor: f64) {
        self.ancho *= factor;
        self.alto *= factor;
    }

    fn puede_contener(&self, otro: &Rectangulo) -> bool {
        self.ancho >= otro.ancho && self.alto >= otro.alto
    }
}

let mut r = Rectangulo { ancho: 3.0, alto: 2.0 };
println!("{}", r.area());   // 6
r.escalar(2.0);             // ahora 6 x 4
```

El **primer parámetro** de un método es **`self`**: la instancia sobre la que se llama. Y aquí
aparece todo lo que aprendiste en las lecciones 07 y 08, porque `self` puede recibirse de tres
formas:

| Primer parámetro | Significa | Úsalo cuando el método… | Ejemplo |
|---|---|---|---|
| **`&self`** | presta la instancia para **leer** | solo consulta datos | `area`, `perimetro`, `es_cuadrado` |
| **`&mut self`** | presta la instancia para **modificar** | cambia su estado | `escalar`, `depositar`, `agregar_nota` |
| **`self`** | **toma la propiedad** de la instancia | la transforma en otra cosa o la "consume" | `cerrar`, `into_...`, `terminar` |

(`&self` es la abreviatura de `self: &Self`, y `Self` es un alias del tipo del `impl`, aquí
`Rectangulo`.)

**No hay flecha `->` como en C++.** En C++ se escribe `p->metodo()` si `p` es un puntero y
`o.metodo()` si es un objeto. En Rust siempre es `.`: el compilador añade `&`, `&mut` o `*` según
lo que pida el método (*auto-referencing*). `r.area()` equivale a `Rectangulo::area(&r)`.

### Funciones asociadas y el "constructor" `new`

Una función dentro de `impl` **sin `self`** es una **función asociada**: pertenece al tipo, no a una
instancia (como los métodos `static` de Java). Se llama con **`::`**:

```rust
impl Rectangulo {
    fn new(ancho: f64, alto: f64) -> Rectangulo {
        Rectangulo { ancho, alto }
    }

    fn cuadrado(lado: f64) -> Self {      // Self = Rectangulo
        Self { ancho: lado, alto: lado }
    }
}

let r = Rectangulo::new(3.0, 2.0);
let c = Rectangulo::cuadrado(5.0);
```

- Ya las usabas: `String::from("hola")`, `String::new()`.
- **`new` no es una palabra reservada** ni un constructor especial: es una **convención** para la
  función asociada que crea instancias. Rust no tiene constructores; se escriben funciones normales
  que devuelven `Self`, y puede haber varias con nombres descriptivos (`cuadrado`, `desde_texto`,
  `vacio`...).
- Una ventaja: el "constructor" puede **validar** los datos antes de crear la instancia (verás cómo
  devolver un error en la lección 12).

Puede haber **varios bloques `impl`** para el mismo tipo; es útil para organizar.

## Otras formas de struct

### *Tuple structs*: campos sin nombre

```rust
struct Color(u8, u8, u8);
struct Punto3D(f64, f64, f64);

let rojo = Color(255, 0, 0);
println!("{}", rojo.0);         // acceso por posicion
```

Útiles cuando los nombres de campo no aportan nada. Y muy útiles para el **patrón *newtype***:
envolver un valor en un tipo propio para que el compilador **no los confunda**:

```rust
struct Metros(f64);
struct Pies(f64);

fn distancia_total(a: Metros, b: Metros) -> Metros {
    Metros(a.0 + b.0)
}

let x = Metros(3.0);
let y = Pies(10.0);
distancia_total(x, y);          // ERROR
```

```
error[E0308]: mismatched types
  |
7 |     let t = distancia_total(x, y);
  |             ---------------    ^ expected `Metros`, found `Pies`
```

Ambos contienen un `f64`, pero son **tipos distintos**: mezclar unidades es un error de compilación.
Este tipo de error no es teórico: en 1999, la NASA perdió la sonda *Mars Climate Orbiter* porque un
programa entregaba impulsos en libras-fuerza·segundo y otro los interpretaba como newton·segundo. En
memoria, `Metros(3.0)` ocupa exactamente lo mismo que un `f64`: la seguridad no cuesta nada al
ejecutar.

### *Unit-like structs*: sin campos

```rust
struct Marcador;
```

Sin datos. Se usan con los traits (lección 13), cuando interesa el **comportamiento** y no los
datos.

## Structs dentro de structs: composición

Un campo puede ser de otro tipo struct:

```rust
struct Punto { x: f64, y: f64 }

struct Circulo {
    centro: Punto,       // un Circulo TIENE un Punto
    radio: f64,
}

let c = Circulo { centro: Punto { x: 0.0, y: 0.0 }, radio: 2.0 };
println!("{}", c.centro.x);
```

Rust **no tiene herencia** de clases. En lugar de "un `Circulo` **es una** `Figura`" (herencia), se
modela "un `Circulo` **tiene un** `Punto`" (**composición**). El comportamiento compartido entre tipos
distintos se expresa con **traits** (lección 13). Es el principio "favorece la composición sobre la
herencia", que el libro *Design Patterns* (1994) ya recomendaba y que Rust convierte en la única
opción.

## Structs en memoria

Los campos de un struct se guardan **uno junto a otro**, sin punteros ni cabeceras ocultas (a
diferencia de los objetos de Java, que viven en el heap con una cabecera):

```rust
struct Punto { x: f64, y: f64 }
println!("{}", std::mem::size_of::<Punto>());   // 16  (dos f64 de 8 bytes)
```

Un `Punto` creado con `let` vive **en la pila**, igual que un `i32`. Solo va al heap si lo pides
(dentro de un `Vec`, un `Box`...). El compilador puede **reordenar** los campos para ahorrar
espacio; si necesitas el orden exacto de C (para comunicarte con código C o con hardware), se usa
`#[repr(C)]`.

## Comparación

| | C | Java | Rust |
|---|---|---|---|
| Agrupar datos | `struct` | `class` | `struct` |
| Comportamiento | funciones sueltas que reciben `struct *` | métodos dentro de la clase | métodos en `impl` |
| Constructor | función de inicialización manual | `new Clase(...)` + constructor | función asociada `Tipo::new(...)` (convención) |
| Referencia al objeto | parámetro puntero | `this` (implícito) | `self` (explícito, con `&`, `&mut` o por valor) |
| Campos sin inicializar | posibles (basura) | `null` / 0 por defecto | **imposible** |
| Herencia | no | sí | **no** (composición + traits) |
| Dónde vive | pila o heap | siempre heap | pila (salvo que lo pongas en el heap) |

## Errores típicos

- Olvidar un campo al crear la instancia → `E0063`.
- Modificar un campo de una instancia no `mut` → `E0594`.
- Imprimir con `{:?}` sin `#[derive(Debug)]` → `E0277`.
- Usar `&self` en un método que modifica → `E0596` (cambia a `&mut self`).
- Llamar a un método que recibe `self` y usar la instancia después → `E0382` (la instancia se movió).
- Llamar a una función asociada con punto (`r.new()`) en vez de `Rectangulo::new()`.
- Advertencia `field ... is never read`: declaraste un campo que tu código nunca lee. Ojo: imprimirlo
  con `{:?}` **no cuenta** como lectura (la nota del compilador lo dice: *"has a derived impl for
  the trait `Debug`, but this is intentionally ignored during dead code analysis"*). Suele indicar
  un campo que sobra o una función que falta.

## Resumen

- `struct Nombre { campo: Tipo, ... }` define un tipo; `Nombre { campo: valor, ... }` crea una
  instancia (con **todos** los campos).
- La mutabilidad es de la **instancia completa** (`let mut`).
- Atajos: `Nombre { campo, .. }` (abreviatura) y `..otra` (actualización; puede mover campos).
- `#[derive(Debug, Clone, PartialEq, ...)]` genera código automáticamente.
- `impl Nombre { ... }`: métodos con `&self` (leer), `&mut self` (modificar) o `self` (consumir);
  funciones asociadas sin `self`, llamadas con `Tipo::funcion()` (`new` es una convención).
- *Tuple structs* (`struct Metros(f64);`) para el patrón *newtype*; *unit structs* sin campos.
- Sin herencia: **composición** (structs dentro de structs) y, en la lección 13, **traits**.

## Ejemplos

- [`ejemplos/rectangulo.rs`](ejemplos/rectangulo.rs) — struct, `impl`, `&self` / `&mut self`,
  funciones asociadas, `derive`.
- [`ejemplos/cuenta_bancaria.rs`](ejemplos/cuenta_bancaria.rs) — un tipo que protege su estado con
  métodos, y un método que consume `self`.
- [`ejemplos/tipos_de_struct.rs`](ejemplos/tipos_de_struct.rs) — *tuple structs*, *newtype*, *unit
  structs*, composición, actualización `..`.

## Ejercicios

En [`ejercicios/`](ejercicios/).

## Para profundizar

- ***The Rust Programming Language***, cap. 5 "Using Structs to Structure Related Data".
  https://doc.rust-lang.org/book/ch05-00-structs.html
- ***Rust by Example***, "Custom Types → Structures".
  https://doc.rust-lang.org/rust-by-example/custom_types/structs.html
- ***Programming Rust*** (2.ª ed.), cap. 9 "Structs".
- ***Rust API Guidelines***, "Naming" y "Constructors are static, inherent methods" (por qué `new` es
  una convención). https://rust-lang.github.io/api-guidelines/predictability.html
- **NASA, *Mars Climate Orbiter Mishap Investigation Board Phase I Report*** (10 de noviembre de
  1999) — el caso de las unidades mezcladas.
