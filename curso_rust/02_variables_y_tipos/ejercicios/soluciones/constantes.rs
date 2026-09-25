// Ejercicio 5 - Constantes calculadas al compilar.
//   rustc --edition 2021 constantes.rs && ./constantes
//
// Salida:
//   Un anio tiene 31536000 segundos
//   Maximo de i32: 2147483647
//   Cabe en un i32? true

const SEGUNDOS_POR_MINUTO: u64 = 60;
const MINUTOS_POR_HORA: u64 = 60;
const HORAS_POR_DIA: u64 = 24;
const DIAS_POR_ANIO: u64 = 365;
// Una constante puede calcularse a partir de otras: el compilador hace la cuenta.
const SEGUNDOS_POR_ANIO: u64 = SEGUNDOS_POR_MINUTO * MINUTOS_POR_HORA * HORAS_POR_DIA * DIAS_POR_ANIO;

fn main() {
    println!("Un anio tiene {SEGUNDOS_POR_ANIO} segundos");
    println!("Maximo de i32: {}", i32::MAX);
    // Para comparar, ambos lados deben ser del mismo tipo: convertimos i32::MAX a u64.
    println!("Cabe en un i32? {}", SEGUNDOS_POR_ANIO <= i32::MAX as u64);
}
