// Ejercicio 4 - Contador circular con &mut self y un metodo que consume self.
//   rustc --edition 2021 contador.rs && ./contador
//
// Salida:
//   1 2 3 0(vuelta) 1 2 3 0(vuelta) 1 2
//   tras reiniciar: 0
//   valor final: 1

struct Contador {
    valor: u32,
    maximo: u32,
}

impl Contador {
    fn new(maximo: u32) -> Self {
        Contador { valor: 0, maximo }
    }

    /// Avanza uno; si pasa del maximo vuelve a 0 y devuelve true.
    fn incrementar(&mut self) -> bool {
        if self.valor == self.maximo {
            self.valor = 0;
            true
        } else {
            self.valor += 1;
            false
        }
    }

    fn reiniciar(&mut self) {
        self.valor = 0;
    }

    /// Consume el contador: despues de llamarlo, el contador ya no existe.
    fn terminar(self) -> u32 {
        self.valor
    }
}

fn main() {
    let mut c = Contador::new(3);
    for _ in 0..10 {
        let dio_vuelta = c.incrementar();
        if dio_vuelta {
            print!("{}(vuelta) ", c.valor);
        } else {
            print!("{} ", c.valor);
        }
    }
    println!();

    c.reiniciar();
    println!("tras reiniciar: {}", c.valor);

    c.incrementar();
    let final_ = c.terminar();
    println!("valor final: {final_}");
    // c.incrementar();   // error[E0382]: borrow of moved value: `c`
}
