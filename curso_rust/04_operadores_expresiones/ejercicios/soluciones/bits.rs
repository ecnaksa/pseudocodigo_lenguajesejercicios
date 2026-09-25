// Ejercicio 4 - Encender, apagar e invertir bits.
//   rustc --edition 2021 bits.rs && ./bits
//
// Salida:
//   inicial:            00001010
//   bit 7 encendido:    10001010
//   bit 3 apagado:      10000010
//   bit 0 invertido:    10000011
//   es par? false

fn main() {
    let mut reg: u8 = 0b0000_1010;
    println!("inicial:            {reg:08b}");

    reg |= 1 << 7; // OR con una mascara que tiene solo el bit 7 en 1
    println!("bit 7 encendido:    {reg:08b}");

    reg &= !(1 << 3); // AND con una mascara que tiene todos en 1 salvo el bit 3
    println!("bit 3 apagado:      {reg:08b}");

    reg ^= 1 << 0; // XOR invierte el bit: 0 -> 1, 1 -> 0
    println!("bit 0 invertido:    {reg:08b}");

    // Un numero es par si su bit menos significativo (bit 0) es 0.
    println!("es par? {}", reg & 1 == 0);
}
