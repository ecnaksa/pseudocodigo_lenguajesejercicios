// Leccion 09 - Struct con metodos (&self, &mut self) y funciones asociadas.
//
//   rustc --edition 2021 rectangulo.rs && ./rectangulo
//
// Salida:
//   r = Rectangulo { ancho: 3.0, alto: 2.0 }
//   area = 6, perimetro = 10, es cuadrado? false
//   tras escalar x2: Rectangulo { ancho: 6.0, alto: 4.0 }
//   c = Rectangulo { ancho: 5.0, alto: 5.0 } es cuadrado? true
//   r puede contener a pequenio? true
//   r puede contener a c? false
//   r == copia? true
//   Rectangulo {
//       ancho: 6.0,
//       alto: 4.0,
//   }

#[derive(Debug, Clone, PartialEq)] // imprimir con {:?}, clonar y comparar con ==
struct Rectangulo {
    ancho: f64,
    alto: f64,
}

impl Rectangulo {
    // ----- Funciones asociadas (sin self): se llaman con Rectangulo::... -----

    /// "Constructor" por convencion.
    fn new(ancho: f64, alto: f64) -> Rectangulo {
        Rectangulo { ancho, alto } // abreviatura de campos
    }

    /// Otro "constructor", con un nombre descriptivo.
    fn cuadrado(lado: f64) -> Self {
        Self {
            ancho: lado,
            alto: lado,
        }
    }

    // ----- Metodos que leen (&self) -----

    fn area(&self) -> f64 {
        self.ancho * self.alto
    }

    fn perimetro(&self) -> f64 {
        2.0 * (self.ancho + self.alto)
    }

    fn es_cuadrado(&self) -> bool {
        self.ancho == self.alto
    }

    fn puede_contener(&self, otro: &Rectangulo) -> bool {
        self.ancho >= otro.ancho && self.alto >= otro.alto
    }

    // ----- Metodos que modifican (&mut self) -----

    fn escalar(&mut self, factor: f64) {
        self.ancho *= factor;
        self.alto *= factor;
    }
}

fn main() {
    let mut r = Rectangulo::new(3.0, 2.0);
    println!("r = {:?}", r);
    println!(
        "area = {}, perimetro = {}, es cuadrado? {}",
        r.area(),
        r.perimetro(),
        r.es_cuadrado()
    );

    r.escalar(2.0); // r debe ser `mut` porque escalar recibe &mut self
    println!("tras escalar x2: {:?}", r);

    let c = Rectangulo::cuadrado(5.0);
    println!("c = {:?} es cuadrado? {}", c, c.es_cuadrado());

    let pequenio = Rectangulo::new(1.0, 1.0);
    println!("r puede contener a pequenio? {}", r.puede_contener(&pequenio));
    println!("r puede contener a c? {}", r.puede_contener(&c));

    let copia = r.clone();
    println!("r == copia? {}", r == copia);

    println!("{:#?}", r); // Debug "bonito"
}
