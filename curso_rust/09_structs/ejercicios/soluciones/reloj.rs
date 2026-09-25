// Ejercicio 6 (reto) - Reloj que normaliza cualquier hora.
//   rustc --edition 2021 reloj.rs && ./reloj
//
// Salida:
//   nuevo(8, 30)   -> 08:30
//   nuevo(25, 0)   -> 01:00
//   nuevo(0, -30)  -> 23:30
//   nuevo(-1, -61) -> 21:59
//   08:30 + 1000 min -> 01:10
//   01:10 - 75 min   -> 23:55
//   nuevo(10, 0) == nuevo(34, 0)? true

const MINUTOS_POR_DIA: i32 = 24 * 60;

#[derive(Debug, PartialEq)] // PartialEq compara el unico campo: los minutos normalizados
struct Reloj {
    minutos: i32, // siempre en 0..1440
}

impl Reloj {
    fn nuevo(horas: i32, minutos: i32) -> Reloj {
        let total = horas * 60 + minutos;
        Reloj {
            // rem_euclid siempre da un resultado en 0..MINUTOS_POR_DIA, incluso con negativos
            minutos: total.rem_euclid(MINUTOS_POR_DIA),
        }
    }

    fn sumar_minutos(&mut self, m: i32) {
        self.minutos = (self.minutos + m).rem_euclid(MINUTOS_POR_DIA);
    }

    fn a_texto(&self) -> String {
        format!("{:02}:{:02}", self.minutos / 60, self.minutos % 60)
    }
}

fn main() {
    for (h, m) in [(8, 30), (25, 0), (0, -30), (-1, -61)] {
        let texto = format!("nuevo({h}, {m})");
        println!("{:<14} -> {}", texto, Reloj::nuevo(h, m).a_texto());
    }

    let mut r = Reloj::nuevo(8, 30);
    r.sumar_minutos(1000);
    println!("08:30 + 1000 min -> {}", r.a_texto());
    r.sumar_minutos(-75);
    println!("01:10 - 75 min   -> {}", r.a_texto());

    println!("nuevo(10, 0) == nuevo(34, 0)? {}", Reloj::nuevo(10, 0) == Reloj::nuevo(34, 0));
}
