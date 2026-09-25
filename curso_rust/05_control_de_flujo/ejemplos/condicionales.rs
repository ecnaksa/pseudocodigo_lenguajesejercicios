// Leccion 05 - if, if como expresion y match.
//
//   rustc --edition 2021 condicionales.rs && ./condicionales

fn main() {
    // ----- if / else if / else -----
    let temperatura = 28;
    if temperatura > 30 {
        println!("Hace mucho calor");
    } else if temperatura > 20 {
        println!("Hace buen tiempo");
    } else {
        println!("Hace frio");
    }

    // ----- if como expresion (sustituye al ternario) -----
    let edad = 16;
    let categoria = if edad >= 18 { "adulto" } else { "menor" };
    println!("Categoria: {categoria}");

    let a = 4;
    let b = 9;
    let mayor = if a > b { a } else { b };
    println!("El mayor entre {a} y {b} es {mayor}");

    // Tambien dentro de otra expresion:
    let n = 7;
    println!("{n} es {}", if n % 2 == 0 { "par" } else { "impar" });

    // ----- match con rangos -----
    let nota: u8 = 15;
    let calificacion = match nota {
        18..=20 => "Excelente",
        14..=17 => "Bueno",
        11..=13 => "Aprobado",
        0..=10 => "Desaprobado",
        _ => "Nota invalida", // 21..=255
    };
    println!("Nota {nota}: {calificacion}");

    // ----- match con varios valores (|) y bloques -----
    let dia = 6;
    let tipo = match dia {
        1..=5 => "laborable",
        6 | 7 => {
            println!("(es fin de semana!)");
            "descanso"
        }
        _ => "dia inexistente",
    };
    println!("Dia {dia}: {tipo}");

    // ----- match sobre un bool y sobre un char -----
    let lluvia = false;
    match lluvia {
        true => println!("Lleva paraguas"),
        false => println!("No hace falta paraguas"),
    }

    for letra in ['e', '7', 'x'] {
        let tipo = match letra {
            'a' | 'e' | 'i' | 'o' | 'u' => "vocal",
            '0'..='9' => "digito", // rangos de caracteres
            _ => "otro caracter",
        };
        println!("'{letra}' es {tipo}");
    }
}
