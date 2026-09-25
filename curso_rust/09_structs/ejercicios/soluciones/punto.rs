// Ejercicio 1 - Punto con funcion asociada y metodos.
//   rustc --edition 2021 punto.rs && ./punto
//
// Salida:
//   origen: Punto { x: 0.0, y: 0.0 }
//   distancia de (0, 0) a (3, 4) = 5
//   punto medio = Punto { x: 1.5, y: 2.0 }
//   tras trasladar (3, 4) en (-1, 2): Punto { x: 2.0, y: 6.0 }

#[derive(Debug)]
struct Punto {
    x: f64,
    y: f64,
}

impl Punto {
    fn origen() -> Punto {
        Punto { x: 0.0, y: 0.0 }
    }

    fn distancia(&self, otro: &Punto) -> f64 {
        let dx = self.x - otro.x;
        let dy = self.y - otro.y;
        (dx * dx + dy * dy).sqrt()
    }

    fn trasladar(&mut self, dx: f64, dy: f64) {
        self.x += dx;
        self.y += dy;
    }

    fn punto_medio(&self, otro: &Punto) -> Punto {
        Punto {
            x: (self.x + otro.x) / 2.0,
            y: (self.y + otro.y) / 2.0,
        }
    }
}

fn main() {
    let o = Punto::origen();
    let mut p = Punto { x: 3.0, y: 4.0 };
    println!("origen: {:?}", o);
    println!("distancia de (0, 0) a (3, 4) = {}", o.distancia(&p));
    println!("punto medio = {:?}", o.punto_medio(&p));
    p.trasladar(-1.0, 2.0);
    println!("tras trasladar (3, 4) en (-1, 2): {:?}", p);
}
