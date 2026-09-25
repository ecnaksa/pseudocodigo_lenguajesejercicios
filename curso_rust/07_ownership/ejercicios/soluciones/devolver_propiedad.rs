// Ejercicio 4 - Pasar y devolver la propiedad sin clone.
//   rustc --edition 2021 devolver_propiedad.rs && ./devolver_propiedad
//
// Salida:
//   "Hola, Ferris el cangrejo" tiene 8 vocales

fn main() {
    let nombre = String::from("Ferris el cangrejo");
    let saludo = agregar_saludo(nombre); // nombre se mueve; recibimos un String nuevo
    let (saludo, vocales) = contar_vocales(saludo); // se mueve y nos lo devuelven
    println!("{:?} tiene {vocales} vocales", saludo);
}

fn agregar_saludo(s: String) -> String {
    let mut resultado = String::from("Hola, ");
    resultado.push_str(&s); // &s: le prestamos s a push_str (leccion 08)
    resultado
} // aqui se libera `s` (el nombre original): ya copiamos su contenido en `resultado`

fn contar_vocales(s: String) -> (String, usize) {
    let mut cuenta = 0;
    for c in s.chars() {
        // chars() recorre los caracteres del texto
        match c.to_ascii_lowercase() {
            'a' | 'e' | 'i' | 'o' | 'u' => cuenta += 1,
            _ => {}
        }
    }
    (s, cuenta) // devolvemos la propiedad del texto junto al resultado
}
