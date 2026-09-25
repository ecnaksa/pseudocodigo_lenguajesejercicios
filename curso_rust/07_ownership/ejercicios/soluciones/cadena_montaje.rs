// Ejercicio 6 (reto) - Una cadena de montaje de Strings.
//   rustc --edition 2021 cadena_montaje.rs && ./cadena_montaje
//
// Salida:
//   *** RUST ES SEGURO Y RAPIDO ***
//
// Cuantos String se crean en el heap y cuando se liberan:
//   1. crear() crea "rust" .......................... se mueve de funcion en funcion
//      (agregar lo recibe, lo MODIFICA y lo devuelve: sigue siendo el MISMO String)
//   2. en_mayusculas() crea uno NUEVO con to_uppercase(); el viejo (el nro. 1) se libera
//      al terminar en_mayusculas, porque su parametro `s` sale de ambito.
//   3. con_marco() crea uno NUEVO con format!; el nro. 2 se libera al terminar con_marco.
//   El nro. 3 llega a `frase` en main y se libera al final de main.
//   En ningun momento hay dos duenios del mismo String, ni hace falta un solo clone().

fn main() {
    let frase = con_marco(en_mayusculas(agregar(agregar(crear(), "es seguro"), "y rapido")));
    println!("{frase}");
}

fn crear() -> String {
    String::from("rust")
}

fn agregar(mut s: String, palabra: &str) -> String {
    s.push(' ');
    s.push_str(palabra);
    s
}

fn en_mayusculas(s: String) -> String {
    s.to_uppercase() // String nuevo; `s` se libera al salir de la funcion
}

fn con_marco(s: String) -> String {
    format!("*** {s} ***") // String nuevo; `s` se libera al salir de la funcion
}
