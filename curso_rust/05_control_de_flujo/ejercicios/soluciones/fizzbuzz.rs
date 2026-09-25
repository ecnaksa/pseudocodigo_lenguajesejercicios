// Ejercicio 3 - FizzBuzz con match sobre una tupla.
//   rustc --edition 2021 fizzbuzz.rs && ./fizzbuzz
//
// Salida:
//   1 2 Fizz 4 Buzz Fizz 7 8 Fizz Buzz 11 Fizz 13 14 FizzBuzz 16 17 Fizz 19 Buzz

fn main() {
    for n in 1..=20 {
        // La tupla (resto entre 3, resto entre 5) resume los cuatro casos posibles.
        match (n % 3, n % 5) {
            (0, 0) => print!("FizzBuzz "),
            (0, _) => print!("Fizz "),
            (_, 0) => print!("Buzz "),
            _ => print!("{n} "),
        }
    }
    println!();
}
