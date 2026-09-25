// Ejercicio 4 - Funciones sobre &str que devuelven slices del texto original.
//   rustc --edition 2021 palabras.rs && ./palabras
//
// Salida:
//   texto: "Rust es un lenguaje extraordinariamente seguro"
//   palabras: 6
//   mas larga: "extraordinariamente"
//   ultima: "seguro"
//   texto vacio -> palabras: 0, mas larga: "", ultima: ""

fn main() {
    let texto = String::from("Rust es un lenguaje extraordinariamente seguro");
    println!("texto: {:?}", texto);
    println!("palabras: {}", contar_palabras(&texto));
    println!("mas larga: {:?}", palabra_mas_larga(&texto));
    println!("ultima: {:?}", ultima_palabra(&texto));

    let vacio = "";
    println!(
        "texto vacio -> palabras: {}, mas larga: {:?}, ultima: {:?}",
        contar_palabras(vacio),
        palabra_mas_larga(vacio),
        ultima_palabra(vacio)
    );
}

fn contar_palabras(texto: &str) -> usize {
    let mut cuenta = 0;
    for _ in texto.split_whitespace() {
        cuenta += 1;
    }
    cuenta
}

/// Devuelve un slice que apunta DENTRO de `texto` (no copia nada).
fn palabra_mas_larga(texto: &str) -> &str {
    let mut mejor = "";
    for palabra in texto.split_whitespace() {
        if palabra.len() > mejor.len() {
            mejor = palabra;
        }
    }
    mejor
}

fn ultima_palabra(texto: &str) -> &str {
    let mut ultima = "";
    for palabra in texto.split_whitespace() {
        ultima = palabra;
    }
    ultima
}
