# Ejercicios — Lección 04

Compila cada solución con `rustc --edition 2021 archivo.rs`.

1. **Calculadora de enteros.** Lee dos enteros `a` y `b` (en la misma línea) e imprime `a + b`,
   `a - b`, `a * b`, `a / b` (entera), `a % b` y la división **real** con 2 decimales. Para no
   detener el programa si `b` es 0, usa `a.checked_div(b)` y `a.checked_rem(b)`, que devuelven
   `None` en ese caso; imprímelos con `{:?}`.
   → [`soluciones/calculadora.rs`](soluciones/calculadora.rs)

2. **Segundos a horas.** Lee una cantidad de segundos (`u32`) y muéstrala como `HH:MM:SS` usando
   solo `/` y `%`. Ejemplo: `3725` → `01:02:05`. Pista: `{:02}` rellena con un cero.
   → [`soluciones/segundos.rs`](soluciones/segundos.rs)

3. **Promedio.** Lee tres notas enteras en una línea y muestra su promedio con 2 decimales. ¡Cuidado
   con la división entera! Prueba con `14 15 17` (el promedio correcto es 15.33, no 15).
   → [`soluciones/promedio.rs`](soluciones/promedio.rs)

4. **Manipulación de bits.** Parte de `let mut reg: u8 = 0b0000_1010;`. Imprime en binario (8 dígitos)
   el registro después de cada paso: (a) encender el bit 7, (b) apagar el bit 3, (c) invertir el
   bit 0 con `^`. Al final indica si el número es par mirando solo el bit 0 (`reg & 1`).
   → [`soluciones/bits.rs`](soluciones/bits.rs)

5. **Predice el resultado.** **Sin ejecutar**, escribe en papel el resultado de cada conversión y
   después compruébalo:
   `1000 as u8`, `-128i8 as u8`, `255u8 as i8`, `2.9 as u8`, `-0.9 as i32`, `300.7 as u8`,
   `'z' as u8`, `122u8 as char`, `u8::try_from(1000)`, `i64::from(-5i32)`.
   → [`soluciones/predice.rs`](soluciones/predice.rs)

6. **Reto — detector de desbordamiento.** Lee dos números `u8` en una línea. Muestra el resultado
   de sumarlos y multiplicarlos con las cuatro estrategias: `checked_`, `wrapping_`, `saturating_`
   y `overflowing_`. Prueba con `100 2` (sin desborde) y con `200 100` (con desborde). Calcula
   además, con un **bloque como expresión**, el porcentaje que representa la suma "real"
   (calculada en `u16` para que no desborde) respecto del máximo de `u8`.
   → [`soluciones/desbordamiento.rs`](soluciones/desbordamiento.rs)
