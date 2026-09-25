// Ejercicio 1 - Arreglar tres errores de prestamo con el cambio minimo.
//   rustc --edition 2021 arreglar_prestamos.rs && ./arreglar_prestamos
//
// Salida:
//   a) hola!
//   b) n = 7
//   c) primero = Ana, nombres = ["Ana", "Luis", "Sara"]
//   c) (reordenado) nombres = ["Ana", "Luis", "Sara", "Eva"], primero = Ana

// a) E0596: no se puede modificar a traves de &String. Cambio: &mut String.
fn exclamar(s: &mut String) {
    s.push('!');
}

fn main() {
    let mut saludo = String::from("hola");
    exclamar(&mut saludo);
    println!("a) {saludo}");

    // b) E0499: dos &mut vivos a la vez (a se usa despues de crear b).
    //    Cambio: terminar de usar `a` antes de crear `b`.
    let mut n = 5;
    let a = &mut n;
    *a += 1; // ultimo uso de a: su prestamo termina aqui
    let b = &mut n;
    *b += 1;
    println!("b) n = {n}");

    // c) E0502: `primero` (prestamo inmutable) se usa despues de push (prestamo mutable).
    //    Cambio 1: guardar una COPIA del dato en lugar de una referencia.
    let mut nombres = vec![String::from("Ana"), String::from("Luis")];
    let primero = nombres[0].clone();
    nombres.push(String::from("Sara"));
    println!("c) primero = {primero}, nombres = {:?}", nombres);

    //    Cambio 2 (sin copiar): reordenar para que la referencia se tome DESPUES del push.
    nombres.push(String::from("Eva"));
    let primero = &nombres[0];
    println!("c) (reordenado) nombres = {:?}, primero = {primero}", nombres);
}
