// Ejercicio 5 - Intercambiar dos valores con referencias mutables.
//   rustc --edition 2021 intercambiar.rs && ./intercambiar
//
// Salida:
//   antes:   x = 1, y = 2
//   despues: x = 2, y = 1
//   con std::mem::swap: s = mundo, t = hola
//
// intercambiar(&mut x, &mut x) NO compila:
//   error[E0499]: cannot borrow `x` as mutable more than once at a time
// Rust tiene razon: dentro de la funcion, `a` y `b` serian el MISMO dato con dos nombres
// (aliasing). En C, una funcion que asume que a y b son distintos (por ejemplo, el truco
// del XOR: *a ^= *b; *b ^= *a; *a ^= *b;) pondria el valor a 0 en ese caso.

// Clippy sugiere usar std::mem::swap (lo hacemos abajo); aqui lo escribimos a mano a proposito.
#[allow(clippy::manual_swap)]
fn intercambiar(a: &mut i32, b: &mut i32) {
    let temporal = *a;
    *a = *b;
    *b = temporal;
}

fn main() {
    let mut x = 1;
    let mut y = 2;
    println!("antes:   x = {x}, y = {y}");
    intercambiar(&mut x, &mut y);
    println!("despues: x = {x}, y = {y}");

    // std::mem::swap funciona con cualquier tipo, incluidos los que no son Copy.
    let mut s = String::from("hola");
    let mut t = String::from("mundo");
    std::mem::swap(&mut s, &mut t);
    println!("con std::mem::swap: s = {s}, t = {t}");
}
