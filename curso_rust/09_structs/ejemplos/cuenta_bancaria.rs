// Leccion 09 - Un tipo que protege su estado: solo se modifica a traves de sus metodos.
//
//   rustc --edition 2021 cuenta_bancaria.rs && ./cuenta_bancaria
//
// Salida:
//   Cuenta de Ana: saldo 0.00
//   Deposito de 500.00: ok
//   Deposito de -20.00: rechazado
//   Retiro de 120.50: ok
//   Retiro de 1000.00: rechazado
//   Cuenta de Ana: saldo 379.50 (4 movimientos intentados, 2 aceptados)
//   Cuenta cerrada. Se entregan 379.50 a Ana.

struct CuentaBancaria {
    titular: String,
    saldo: f64,
    intentos: u32,
    aceptados: u32,
}

impl CuentaBancaria {
    fn new(titular: &str) -> Self {
        CuentaBancaria {
            titular: titular.to_string(), // &str -> String propio
            saldo: 0.0,
            intentos: 0,
            aceptados: 0,
        }
    }

    /// Devuelve true si el deposito fue aceptado.
    fn depositar(&mut self, monto: f64) -> bool {
        self.intentos += 1;
        if monto <= 0.0 {
            return false;
        }
        self.saldo += monto;
        self.aceptados += 1;
        true
    }

    fn retirar(&mut self, monto: f64) -> bool {
        self.intentos += 1;
        if monto <= 0.0 || monto > self.saldo {
            return false;
        }
        self.saldo -= monto;
        self.aceptados += 1;
        true
    }

    fn resumen(&self) -> String {
        format!("Cuenta de {}: saldo {:.2}", self.titular, self.saldo)
    }

    /// Consume la cuenta (recibe `self` por valor): despues de cerrarla ya no se puede usar.
    fn cerrar(self) -> f64 {
        println!("Cuenta cerrada. Se entregan {:.2} a {}.", self.saldo, self.titular);
        self.saldo
    } // aqui se libera la cuenta (y su String `titular`)
}

fn main() {
    let mut cuenta = CuentaBancaria::new("Ana");
    println!("{}", cuenta.resumen());

    for monto in [500.0, -20.0] {
        let ok = cuenta.depositar(monto);
        println!("Deposito de {monto:.2}: {}", if ok { "ok" } else { "rechazado" });
    }
    for monto in [120.5, 1000.0] {
        let ok = cuenta.retirar(monto);
        println!("Retiro de {monto:.2}: {}", if ok { "ok" } else { "rechazado" });
    }

    println!(
        "{} ({} movimientos intentados, {} aceptados)",
        cuenta.resumen(),
        cuenta.intentos,
        cuenta.aceptados
    );

    let _entregado = cuenta.cerrar();
    // cuenta.depositar(10.0);   // error[E0382]: borrow of moved value: `cuenta`
}
