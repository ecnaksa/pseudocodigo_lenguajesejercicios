# Ejercicios — Lección 09

Compila cada solución con `rustc --edition 2021 archivo.rs`. En cada método, piensa qué necesita:
`&self` (leer), `&mut self` (modificar) o `self` (consumir).

1. **Punto.** Struct `Punto { x: f64, y: f64 }` con: `origen() -> Punto` (función asociada),
   `distancia(&self, otro: &Punto) -> f64`, `trasladar(&mut self, dx: f64, dy: f64)` y
   `punto_medio(&self, otro: &Punto) -> Punto`.
   → [`soluciones/punto.rs`](soluciones/punto.rs)

2. **Estudiante.** Struct `Estudiante { nombre: String, notas: [f64; 4] }` con `new(nombre: &str,
   notas: [f64; 4])`, `promedio(&self)`, `aprobado(&self) -> bool` (promedio ≥ 10.5) y
   `mejor_nota(&self)`. Escribe además una **función libre**
   `mejor_estudiante(lista: &[Estudiante]) -> &Estudiante` que devuelva una **referencia** al de
   mayor promedio (sin clonar).
   → [`soluciones/estudiante.rs`](soluciones/estudiante.rs)

3. **Temperaturas con *newtype*.** Define `struct Celsius(f64);` y `struct Fahrenheit(f64);` con
   métodos `a_fahrenheit(&self) -> Fahrenheit` y `a_celsius(&self) -> Celsius`. Escribe
   `fn alerta_calor(t: &Celsius) -> bool` (más de 35 °C). Comprueba que pasar un `Fahrenheit` a
   `alerta_calor` **no compila**.
   → [`soluciones/temperaturas.rs`](soluciones/temperaturas.rs)

4. **Contador circular.** Struct `Contador { valor: u32, maximo: u32 }` con `new(maximo)`,
   `incrementar(&mut self) -> bool` (al pasar del máximo vuelve a 0 y devuelve `true` para avisar
   de la vuelta), `reiniciar(&mut self)` y `terminar(self) -> u32` (consume el contador y devuelve
   su valor final).
   → [`soluciones/contador.rs`](soluciones/contador.rs)

5. **Fracciones.** Struct `Fraccion { num: i64, den: i64 }` con `nueva(num, den)`, que la guarde
   **simplificada** (divide ambos por su MCD) y con el signo en el numerador; `sumar(&self, otra:
   &Fraccion) -> Fraccion`, `multiplicar(...)`, `a_decimal(&self) -> f64` y `a_texto(&self) ->
   String` (como `"3/4"`, o `"2"` si el denominador es 1).
   → [`soluciones/fraccion.rs`](soluciones/fraccion.rs)

6. **Reto — reloj.** Struct `Reloj { minutos: i32 }` que guarde los minutos desde las 00:00 (0 a
   1439). `nuevo(horas: i32, minutos: i32)` debe aceptar valores fuera de rango y **normalizarlos**
   (`nuevo(25, 0)` → 01:00; `nuevo(0, -30)` → 23:30; `nuevo(-1, -61)` → 21:59). Añade
   `sumar_minutos(&mut self, m: i32)`, `a_texto(&self) -> String` con formato `HH:MM` e
   implementa comparación con `#[derive(PartialEq)]` (dos relojes que marcan la misma hora deben
   ser iguales). Pista: `rem_euclid` (lección 04).
   → [`soluciones/reloj.rs`](soluciones/reloj.rs)
