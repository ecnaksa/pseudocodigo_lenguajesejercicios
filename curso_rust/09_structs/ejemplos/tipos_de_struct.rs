// Leccion 09 - Tuple structs, newtype, unit structs, composicion y actualizacion con `..`.
//
//   rustc --edition 2021 tipos_de_struct.rs && ./tipos_de_struct
//
// Salida:
//   rojo = Color(255, 0, 0), componente verde = 0
//   luminosidad del rojo = 85.0
//   total = 5.00 m (3 m + 2 m)
//   10 pies = 3.05 m
//   tamanio de Metros: 8 bytes (igual que un f64)
//   circulo con centro (1, 2) y radio 3: area = 28.27
//   el punto (2, 2) esta dentro? true
//   el punto (5, 5) esta dentro? false
//   base: Config { volumen: 50, brillo: 70, modo_oscuro: false }
//   nueva: Config { volumen: 50, brillo: 70, modo_oscuro: true }
//   nueva -> volumen 50, brillo 70, modo oscuro true
//   tamanio de Marcador: 0 bytes

// ---- Tuple struct ----
#[derive(Debug)]
struct Color(u8, u8, u8);

impl Color {
    /// Luminosidad media de los tres canales (0 = negro, 255 = blanco).
    fn luminosidad(&self) -> f64 {
        (self.0 as f64 + self.1 as f64 + self.2 as f64) / 3.0
    }
}

// ---- Newtype: el compilador no deja mezclar unidades ----
struct Metros(f64);
struct Pies(f64);

impl Pies {
    fn a_metros(&self) -> Metros {
        Metros(self.0 * 0.3048)
    }
}

fn sumar_distancias(a: Metros, b: Metros) -> Metros {
    Metros(a.0 + b.0)
}

// ---- Composicion: un Circulo TIENE un Punto ----
struct Punto {
    x: f64,
    y: f64,
}

impl Punto {
    fn distancia(&self, otro: &Punto) -> f64 {
        ((self.x - otro.x).powi(2) + (self.y - otro.y).powi(2)).sqrt()
    }
}

struct Circulo {
    centro: Punto,
    radio: f64,
}

impl Circulo {
    fn area(&self) -> f64 {
        std::f64::consts::PI * self.radio * self.radio
    }

    fn contiene(&self, p: &Punto) -> bool {
        self.centro.distancia(p) <= self.radio // usamos el metodo del Punto
    }
}

// ---- Actualizacion con `..` (todos los campos son Copy: nada se mueve) ----
#[derive(Debug, Clone, Copy)]
struct Config {
    volumen: u8,
    brillo: u8,
    modo_oscuro: bool,
}

// ---- Unit struct: sin campos ----
struct Marcador;

fn main() {
    let rojo = Color(255, 0, 0);
    println!("rojo = {:?}, componente verde = {}", rojo, rojo.1);
    println!("luminosidad del rojo = {:.1}", rojo.luminosidad());

    let total = sumar_distancias(Metros(3.0), Metros(2.0));
    println!("total = {:.2} m (3 m + 2 m)", total.0);
    // sumar_distancias(Metros(3.0), Pies(10.0));  // error[E0308]: expected `Metros`, found `Pies`
    println!("10 pies = {:.2} m", Pies(10.0).a_metros().0);
    println!("tamanio de Metros: {} bytes (igual que un f64)", std::mem::size_of::<Metros>());

    let c = Circulo {
        centro: Punto { x: 1.0, y: 2.0 },
        radio: 3.0,
    };
    println!(
        "circulo con centro ({}, {}) y radio {}: area = {:.2}",
        c.centro.x,
        c.centro.y,
        c.radio,
        c.area()
    );
    for p in [Punto { x: 2.0, y: 2.0 }, Punto { x: 5.0, y: 5.0 }] {
        println!("el punto ({}, {}) esta dentro? {}", p.x, p.y, c.contiene(&p));
    }

    let base = Config {
        volumen: 50,
        brillo: 70,
        modo_oscuro: false,
    };
    let nueva = Config {
        modo_oscuro: true,
        ..base // el resto, copiado de base (Config es Copy: base sigue valida)
    };
    println!("base: {:?}", base);
    println!("nueva: {:?}", nueva);
    println!(
        "nueva -> volumen {}, brillo {}, modo oscuro {}",
        nueva.volumen, nueva.brillo, nueva.modo_oscuro
    );

    let _m = Marcador;
    println!("tamanio de Marcador: {} bytes", std::mem::size_of::<Marcador>());
}
