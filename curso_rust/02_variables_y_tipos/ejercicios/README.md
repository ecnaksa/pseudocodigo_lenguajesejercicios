# Ejercicios — Lección 02

Compila cada solución con `rustc --edition 2021 archivo.rs` y ejecútala con `./archivo`.

1. **Ficha de estudiante.** Declara variables (sin `mut`) para el nombre (`&str`), la edad (`u8`),
   el promedio (`f64`), si está matriculado (`bool`) y la inicial del apellido (`char`). Anota el
   tipo de cada una explícitamente e imprímelas.
   → [`soluciones/ficha.rs`](soluciones/ficha.rs)

2. **Límites.** Imprime el mínimo y el máximo de `i8`, `u8`, `i16`, `u16`, `i32`, `u32`, `i64` y
   `u64` usando las constantes `MIN` y `MAX`. ¿Cuál es el mayor número que cabe en un `u8`? ¿Por
   qué `i8` llega a −128 pero solo a 127?
   → [`soluciones/limites.rs`](soluciones/limites.rs)

3. **Precio con impuesto (shadowing).** Parte de `let precio = 100.0;`. Usando **shadowing** (sin
   `mut`), calcula el precio con un 18 % de impuesto, luego con un 10 % de descuento sobre ese
   resultado, e imprime cada paso. Al final, sombrea `precio` con su parte entera
   (`precio as i64`).
   → [`soluciones/precio.rs`](soluciones/precio.rs)

4. **Temperaturas de la semana.** Guarda en un arreglo `[f64; 7]` las temperaturas de lunes a
   domingo. Imprime la del lunes, la del miércoles, la del domingo y cuántos días hay. Después
   corrige la del domingo (el arreglo debe ser `mut`) e imprime el arreglo entero con `{:?}`.
   → [`soluciones/temperaturas.rs`](soluciones/temperaturas.rs)

5. **Constantes de tiempo.** Declara constantes `SEGUNDOS_POR_MINUTO`, `MINUTOS_POR_HORA`,
   `HORAS_POR_DIA` y `DIAS_POR_ANIO` (tipo `u64`) y calcula con ellas otra constante,
   `SEGUNDOS_POR_ANIO`. Imprime el resultado y comprueba si cabría en un `i32` comparándolo con
   `i32::MAX as u64`.
   → [`soluciones/constantes.rs`](soluciones/constantes.rs)

6. **Reto — punto en 3D.** Representa un punto como una tupla `(f64, f64, f64)`. Desestructúralo
   en `x`, `y`, `z` y calcula su distancia al origen: √(x² + y² + z²) (usa el método `.sqrt()`).
   Luego intercambia dos variables `a` y `b` en una sola línea usando una tupla:
   `let (a, b) = (b, a);`
   → [`soluciones/punto3d.rs`](soluciones/punto3d.rs)
