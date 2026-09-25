// Leccion 07 - Ambitos y String en el heap.
//
//   rustc --edition 2021 ambito.rs && ./ambito
//
// (Las direcciones de memoria cambian en cada ejecucion.)

fn main() {
    // Un literal &str: fijo, grabado en el ejecutable.
    let literal = "hola";
    println!("literal: {literal}");

    // Un String: vive en el heap y puede crecer.
    let mut s = String::from("hola");
    println!("s = {s:?}  longitud = {}  capacidad = {}", s.len(), s.capacity());
    println!("  el texto esta en el heap, en la direccion {:p}", s.as_ptr());

    s.push_str(", mundo"); // crece: si no cabe, Rust pide un bloque mas grande
    println!("s = {s:?}  longitud = {}  capacidad = {}", s.len(), s.capacity());
    // La direccion puede cambiar (bloque nuevo + copia) o no (el asignador a veces puede
    // agrandar el bloque en el mismo sitio). En ambos casos el String sigue siendo el duenio.
    println!("  ahora el texto esta en {:p}", s.as_ptr());

    // La parte de la PILA de un String siempre mide lo mismo: puntero + longitud + capacidad.
    println!("tamanio de un String en la pila: {} bytes", std::mem::size_of::<String>());

    // Ambitos: una variable vive hasta el final de su bloque.
    {
        let interno = String::from("solo existo dentro del bloque");
        println!("{interno}");
    } // <- aqui Rust libera `interno` (llama a drop automaticamente)
    // println!("{interno}");   // error[E0425]: cannot find value `interno` in this scope

    println!("fin de main: ahora se libera `s`");
} // <- aqui se libera `s`
