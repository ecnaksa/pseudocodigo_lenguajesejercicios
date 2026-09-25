// Ejercicio 5 - Fracciones siempre simplificadas.
//   rustc --edition 2021 fraccion.rs && ./fraccion
//
// Salida:
//   6/8 -> 3/4
//   3/-9 -> -1/3
//   3/4 + -1/3 = 5/12 (0.4167)
//   3/4 * -1/3 = -1/4
//   1/2 + 1/2 = 1

struct Fraccion {
    num: i64,
    den: i64,
}

impl Fraccion {
    /// Crea la fraccion simplificada y con el signo en el numerador.
    /// (Suponemos den != 0; en la leccion 12 veremos como devolver un error.)
    fn nueva(num: i64, den: i64) -> Fraccion {
        let divisor = mcd(num.abs(), den.abs());
        let signo = if den < 0 { -1 } else { 1 };
        Fraccion {
            num: signo * num / divisor,
            den: signo * den / divisor,
        }
    }

    fn sumar(&self, otra: &Fraccion) -> Fraccion {
        Fraccion::nueva(self.num * otra.den + otra.num * self.den, self.den * otra.den)
    }

    fn multiplicar(&self, otra: &Fraccion) -> Fraccion {
        Fraccion::nueva(self.num * otra.num, self.den * otra.den)
    }

    fn a_decimal(&self) -> f64 {
        self.num as f64 / self.den as f64
    }

    fn a_texto(&self) -> String {
        if self.den == 1 {
            format!("{}", self.num)
        } else {
            format!("{}/{}", self.num, self.den)
        }
    }
}

fn mcd(mut a: i64, mut b: i64) -> i64 {
    while b != 0 {
        let r = a % b;
        a = b;
        b = r;
    }
    if a == 0 { 1 } else { a } // mcd(0, 0): devolvemos 1 para no dividir entre 0
}

fn main() {
    let a = Fraccion::nueva(6, 8);
    let b = Fraccion::nueva(3, -9);
    println!("6/8 -> {}", a.a_texto());
    println!("3/-9 -> {}", b.a_texto());

    let suma = a.sumar(&b);
    println!("{} + {} = {} ({:.4})", a.a_texto(), b.a_texto(), suma.a_texto(), suma.a_decimal());
    println!("{} * {} = {}", a.a_texto(), b.a_texto(), a.multiplicar(&b).a_texto());

    let medio = Fraccion::nueva(1, 2);
    println!("1/2 + 1/2 = {}", medio.sumar(&medio).a_texto());
}
