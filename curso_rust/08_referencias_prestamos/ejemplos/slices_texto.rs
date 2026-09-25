// Leccion 08 - Slices de texto (&str).
//
//   rustc --edition 2021 slices_texto.rs && ./slices_texto
//
// Salida:
//   [hola] [mundo] [hola] [mundo] [hola mundo]
//   primera palabra de un String:  "hola"
//   primera palabra de un slice:   "mundo"
//   primera palabra de un literal: "Rust"
//   sin espacios: "palabra"
//   "cangrejo" empieza por "can"? true
//   iniciales: F.E.C.

fn main() {
    let s = String::from("hola mundo");

    // Rangos de BYTES (con texto ASCII, cada caracter es un byte).
    let hola = &s[0..4];
    let mundo = &s[5..10];
    let hola2 = &s[..4];
    let mundo2 = &s[5..];
    let todo = &s[..];
    println!("[{hola}] [{mundo}] [{hola2}] [{mundo2}] [{todo}]");

    // Una funcion que recibe &str acepta String prestado, slices y literales.
    println!("primera palabra de un String:  {:?}", primera_palabra(&s));
    println!("primera palabra de un slice:   {:?}", primera_palabra(&s[5..]));
    println!("primera palabra de un literal: {:?}", primera_palabra("Rust es genial"));
    println!("sin espacios: {:?}", primera_palabra("palabra"));

    // Muchos metodos de texto devuelven o reciben &str.
    let animal = "cangrejo";
    println!("{:?} empieza por {:?}? {}", animal, &animal[..3], animal.starts_with("can"));

    // Recorrer palabras (split_whitespace da &str que apuntan DENTRO del texto original).
    let nombre = "Ferris el cangrejo";
    print!("iniciales: ");
    for palabra in nombre.split_whitespace() {
        let inicial = &palabra[..1]; // primer byte (ASCII): seguro aqui
        print!("{}.", inicial.to_uppercase());
    }
    println!();

    // Esto NO compilaria: `palabra` toma prestado `texto`, y clear() necesita &mut.
    // let mut texto = String::from("hola mundo");
    // let palabra = primera_palabra(&texto);
    // texto.clear();            // error[E0502]
    // println!("{palabra}");
}

/// Devuelve la primera palabra (hasta el primer espacio) como un slice del texto original.
fn primera_palabra(s: &str) -> &str {
    for (i, b) in s.bytes().enumerate() {
        if b == b' ' {
            return &s[..i];
        }
    }
    s // no hay espacios: la palabra es todo el texto
}
