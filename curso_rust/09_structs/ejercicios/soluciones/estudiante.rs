// Ejercicio 2 - Estudiantes y una funcion que devuelve una referencia.
//   rustc --edition 2021 estudiante.rs && ./estudiante
//
// Salida:
//   Ana    promedio 16.25  mejor nota 18.0  aprobado: true
//   Luis   promedio  9.00  mejor nota 12.0  aprobado: false
//   Sara   promedio 17.50  mejor nota 20.0  aprobado: true
//   Mejor estudiante: Sara (17.50)

struct Estudiante {
    nombre: String,
    notas: [f64; 4],
}

impl Estudiante {
    fn new(nombre: &str, notas: [f64; 4]) -> Self {
        Estudiante {
            nombre: nombre.to_string(),
            notas,
        }
    }

    fn promedio(&self) -> f64 {
        let mut suma = 0.0;
        for n in self.notas {
            suma += n;
        }
        suma / self.notas.len() as f64
    }

    fn aprobado(&self) -> bool {
        self.promedio() >= 10.5 // un metodo puede llamar a otros metodos con self.
    }

    fn mejor_nota(&self) -> f64 {
        let mut mejor = self.notas[0];
        for n in self.notas {
            if n > mejor {
                mejor = n;
            }
        }
        mejor
    }
}

/// Devuelve una REFERENCIA al estudiante de mayor promedio: no copia ni mueve nada.
/// (Suponemos que la lista no esta vacia; en la leccion 10 lo haremos con Option.)
fn mejor_estudiante(lista: &[Estudiante]) -> &Estudiante {
    let mut mejor = &lista[0];
    for e in lista {
        if e.promedio() > mejor.promedio() {
            mejor = e;
        }
    }
    mejor
}

fn main() {
    let curso = [
        Estudiante::new("Ana", [15.0, 18.0, 16.0, 16.0]),
        Estudiante::new("Luis", [8.0, 12.0, 7.0, 9.0]),
        Estudiante::new("Sara", [20.0, 15.0, 17.0, 18.0]),
    ];

    for e in &curso {
        println!(
            "{:<6} promedio {:5.2}  mejor nota {:.1}  aprobado: {}",
            e.nombre,
            e.promedio(),
            e.mejor_nota(),
            e.aprobado()
        );
    }

    let mejor = mejor_estudiante(&curso);
    println!("Mejor estudiante: {} ({:.2})", mejor.nombre, mejor.promedio());
}
