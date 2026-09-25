// Ejercicio 3 - Newtypes para no mezclar escalas.
//   rustc --edition 2021 temperaturas.rs && ./temperaturas
//
// Salida:
//   38.0 C = 100.4 F  -> alerta de calor: true
//   95.0 F = 35.0 C   -> alerta de calor: false
//
// alerta_calor(&Fahrenheit(95.0)) NO compila:
//   error[E0308]: mismatched types ... expected `&Celsius`, found `&Fahrenheit`

struct Celsius(f64);
struct Fahrenheit(f64);

impl Celsius {
    fn a_fahrenheit(&self) -> Fahrenheit {
        Fahrenheit(self.0 * 9.0 / 5.0 + 32.0)
    }
}

impl Fahrenheit {
    fn a_celsius(&self) -> Celsius {
        Celsius((self.0 - 32.0) * 5.0 / 9.0)
    }
}

fn alerta_calor(t: &Celsius) -> bool {
    t.0 > 35.0
}

fn main() {
    let fiebre = Celsius(38.0);
    println!(
        "{:.1} C = {:.1} F  -> alerta de calor: {}",
        fiebre.0,
        fiebre.a_fahrenheit().0,
        alerta_calor(&fiebre)
    );

    let tarde = Fahrenheit(95.0);
    let tarde_c = tarde.a_celsius(); // para usar alerta_calor hay que convertir explicitamente
    println!(
        "{:.1} F = {:.1} C   -> alerta de calor: {}",
        tarde.0,
        tarde_c.0,
        alerta_calor(&tarde_c)
    );
    // alerta_calor(&tarde);   // error[E0308]: expected `&Celsius`, found `&Fahrenheit`
}
