// Leccion 07 - VER cuando se libera cada valor.
//
// Para "ver" las liberaciones creamos un tipo propio que imprime un mensaje cuando Rust lo
// destruye. La sintaxis (`struct`, `impl Drop`) se explica en las lecciones 09, 13 y 18:
// por ahora solo mira la SALIDA para comprobar las reglas del ownership.
//
//   rustc --edition 2021 ver_drop.rs && ./ver_drop
//
// Salida:
//   == 1. Fin de ambito ==
//     creado: bloque
//     dentro del bloque
//     liberado: bloque
//   == 2. Move a una funcion ==
//     creado: viajero
//     la funcion recibio: viajero
//     liberado: viajero
//     main sigue (viajero ya fue liberado dentro de la funcion)
//   == 3. drop() explicito ==
//     creado: temporal
//     liberado: temporal
//     despues de drop
//   == 4. Orden inverso ==
//     creado: primero
//     creado: segundo
//     creado: tercero
//     fin de main
//     liberado: tercero
//     liberado: segundo
//     liberado: primero

struct Recurso {
    nombre: String,
}

impl Recurso {
    fn nuevo(nombre: &str) -> Recurso {
        println!("  creado: {nombre}");
        Recurso {
            nombre: nombre.to_string(),
        }
    }
}

// Drop se ejecuta automaticamente cuando el valor se libera.
impl Drop for Recurso {
    fn drop(&mut self) {
        println!("  liberado: {}", self.nombre);
    }
}

fn consumir(r: Recurso) {
    println!("  la funcion recibio: {}", r.nombre);
} // r (duenia del Recurso) sale de ambito aqui

fn main() {
    println!("== 1. Fin de ambito ==");
    {
        let _r = Recurso::nuevo("bloque");
        println!("  dentro del bloque");
    }

    println!("== 2. Move a una funcion ==");
    let v = Recurso::nuevo("viajero");
    consumir(v);
    println!("  main sigue (viajero ya fue liberado dentro de la funcion)");

    println!("== 3. drop() explicito ==");
    let t = Recurso::nuevo("temporal");
    drop(t);
    println!("  despues de drop");

    println!("== 4. Orden inverso ==");
    let _a = Recurso::nuevo("primero");
    let _b = Recurso::nuevo("segundo");
    let _c = Recurso::nuevo("tercero");
    println!("  fin de main");
}
