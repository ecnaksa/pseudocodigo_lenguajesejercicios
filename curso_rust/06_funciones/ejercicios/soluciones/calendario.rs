// Ejercicio 2 - es_bisiesto y dias_en_mes.
//   rustc --edition 2021 calendario.rs && ./calendario
//
// Salida:
//   1900: no bisiesto, febrero tiene 28 dias
//   2000: bisiesto, febrero tiene 29 dias
//   2024: bisiesto, febrero tiene 29 dias
//   2026: no bisiesto, febrero tiene 28 dias
//   Dias de cada mes en 2024: 31 29 31 30 31 30 31 31 30 31 30 31

fn main() {
    for anio in [1900, 2000, 2024, 2026] {
        let texto = if es_bisiesto(anio) { "bisiesto" } else { "no bisiesto" };
        println!("{anio}: {texto}, febrero tiene {} dias", dias_en_mes(2, anio));
    }

    print!("Dias de cada mes en 2024:");
    for mes in 1..=12 {
        print!(" {}", dias_en_mes(mes, 2024));
    }
    println!();
}

/// Regla del calendario gregoriano.
fn es_bisiesto(anio: i32) -> bool {
    (anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0
}

/// Dias del mes (1 = enero ... 12 = diciembre). Devuelve 0 si el mes no existe.
fn dias_en_mes(mes: u32, anio: i32) -> u32 {
    match mes {
        1 | 3 | 5 | 7 | 8 | 10 | 12 => 31,
        4 | 6 | 9 | 11 => 30,
        2 => {
            if es_bisiesto(anio) {
                29
            } else {
                28
            }
        }
        _ => 0,
    }
}
