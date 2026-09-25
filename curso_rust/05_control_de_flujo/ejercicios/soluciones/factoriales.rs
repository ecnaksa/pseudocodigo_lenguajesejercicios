// Ejercicio 5 - Factoriales en u64 hasta que el siguiente desborda.
//   rustc --edition 2021 factoriales.rs && ./factoriales
//
// Salida (final):
//   20! = 2432902008176640000
//   21! ya no cabe en un u64 (maximo 18446744073709551615).
//   El mayor factorial que cabe en u64 es 20!

fn main() {
    let mut n: u64 = 1;
    let mut factorial: u64 = 1;

    let ultimo = loop {
        println!("{n:2}! = {factorial}");
        let siguiente = n + 1;
        match factorial.checked_mul(siguiente) {
            Some(valor) => {
                factorial = valor;
                n = siguiente;
            }
            None => {
                println!("{siguiente}! ya no cabe en un u64 (maximo {}).", u64::MAX);
                break n; // el loop devuelve el ultimo n que si cupo
            }
        }
    };

    println!("El mayor factorial que cabe en u64 es {ultimo}!");
}
