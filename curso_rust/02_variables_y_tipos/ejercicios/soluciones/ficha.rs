// Ejercicio 1 - Ficha de estudiante con tipos anotados.
//   rustc --edition 2021 ficha.rs && ./ficha

fn main() {
    let nombre: &str = "Luis Quispe";
    let edad: u8 = 19; // una edad nunca es negativa ni mayor que 255
    let promedio: f64 = 15.75;
    let matriculado: bool = true;
    let inicial_apellido: char = 'Q';

    println!("Nombre:      {nombre}");
    println!("Edad:        {edad}");
    println!("Promedio:    {promedio}");
    println!("Matriculado: {matriculado}");
    println!("Inicial:     {inicial_apellido}");
}
