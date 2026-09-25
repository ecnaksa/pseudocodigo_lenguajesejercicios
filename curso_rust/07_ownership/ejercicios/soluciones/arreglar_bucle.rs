// Ejercicio 3 - Mover dentro de un bucle.
//   rustc --edition 2021 arreglar_bucle.rs && ./arreglar_bucle
//
// Por que falla el original: en la 1.a vuelta, `let copia = mensaje;` MUEVE el String a
// `copia` (que se libera al final de esa vuelta). En la 2.a vuelta, `mensaje` ya no tiene
// valor: "value moved here, in previous iteration of loop".
//
// Salida:
//   con clone 0: hola
//   con clone 1: hola
//   con clone 2: hola
//   sin copiar 0: hola
//   sin copiar 1: hola
//   sin copiar 2: hola

fn main() {
    // Forma 1: clonar en cada vuelta (3 copias en el heap; funciona, pero gasta memoria).
    let mensaje = String::from("hola");
    for i in 0..3 {
        let copia = mensaje.clone();
        println!("con clone {i}: {copia}");
    }

    // Forma 2: no hace falta ninguna variable nueva. println! solo MIRA el valor
    // (lo toma prestado), asi que `mensaje` no se mueve nunca.
    for i in 0..3 {
        println!("sin copiar {i}: {mensaje}");
    }
}
