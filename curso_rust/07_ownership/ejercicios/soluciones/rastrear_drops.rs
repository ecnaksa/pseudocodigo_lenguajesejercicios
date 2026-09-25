// Ejercicio 5 - Rastrear liberaciones: shadowing y el patron `_`.
//   rustc --edition 2021 rastrear_drops.rs && ./rastrear_drops
//
// Salida:
//   creado: A
//   creado: B
//   creado: C
//   liberado: C        <- `let _ = ...` NO liga el valor a ninguna variable: se libera YA
//   creado: D
//   creado: E
//   liberado: E        <- fin del bloque: `_movido` (la duenia actual de E) sale de ambito
//   fin de main (x es B)
//   liberado: D        <- fin de main: orden INVERSO de declaracion: _d, x (B), x (A)
//   liberado: B
//   liberado: A        <- el shadowing NO libera A: solo la oculta; vive hasta el final
//
// Conclusiones:
//   * Shadowing no es asignacion: la variable vieja sigue existiendo (oculta) hasta el
//     final del ambito.
//   * `let _ = valor;` descarta el valor inmediatamente. `let _nombre = valor;` lo conserva
//     hasta el final del ambito (el `_` inicial solo silencia el aviso de variable sin usar).

struct Recurso {
    nombre: String,
}

impl Recurso {
    fn nuevo(nombre: &str) -> Recurso {
        println!("creado: {nombre}");
        Recurso {
            nombre: nombre.to_string(),
        }
    }
}

impl Drop for Recurso {
    fn drop(&mut self) {
        println!("liberado: {}", self.nombre);
    }
}

fn main() {
    // Si compilas el fragmento tal cual, el compilador AVISA: "unused variable: `x`" en esta
    // linea. Tiene razon: tras el shadowing, la primera x (A) ya no se puede usar... pero
    // sigue viva (ocupando memoria) hasta el final de main. El atributo silencia el aviso.
    #[allow(unused_variables)]
    let x = Recurso::nuevo("A");
    let x = Recurso::nuevo("B");
    let _ = Recurso::nuevo("C");
    let _d = Recurso::nuevo("D");
    {
        let e = Recurso::nuevo("E");
        let _movido = e;
    }
    println!("fin de main (x es {})", x.nombre);
}
