// Leccion 07 - Ownership al pasar y devolver valores de funciones.
//
//   rustc --edition 2021 propiedad_funciones.rs && ./propiedad_funciones
//
// Salida:
//   tomar recibio: hola
//   copiar recibio: 5
//   n sigue valida: 5
//   b = nuevo!
//   "Rust" tiene 4 bytes (y lo recuperamos)

fn main() {
    let saludo = String::from("hola");
    tomar(saludo); // el String se MUEVE a la funcion
    // println!("{saludo}");  // error[E0382]: borrow of moved value: `saludo`

    let n = 5;
    copiar(n); // el i32 se COPIA
    println!("n sigue valida: {n}");

    let a = crear(); // la funcion nos DA la propiedad de un String nuevo
    let b = agregar_signo(a); // a se mueve dentro; el resultado se mueve a b
    println!("b = {b}");

    // Patron incomodo: devolver el String para no perderlo.
    // (En la leccion 08 se resuelve con referencias: &String / &str.)
    let texto = String::from("Rust");
    let (texto, largo) = calcular_longitud(texto);
    println!("{:?} tiene {largo} bytes (y lo recuperamos)", texto);
}

fn tomar(s: String) {
    println!("tomar recibio: {s}");
} // s sale de ambito -> el String se libera AQUI

fn copiar(x: i32) {
    println!("copiar recibio: {x}");
}

fn crear() -> String {
    let mut s = String::new(); // String vacio en el heap...
    s.push_str("nuevo"); // ...que llenamos
    s // se mueve hacia quien llama: NO se libera aqui
}

fn agregar_signo(mut s: String) -> String {
    s.push('!');
    s
}

fn calcular_longitud(s: String) -> (String, usize) {
    let longitud = s.len();
    (s, longitud) // devolvemos el String junto con el resultado
}
