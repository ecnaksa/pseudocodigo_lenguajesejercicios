# Ejercicios — Lección 06

Compila cada solución con `rustc --edition 2021 archivo.rs`. En todos, **`main` solo debe
coordinar**: el trabajo lo hacen funciones con nombres claros.

1. **Áreas.** Escribe `area_rectangulo(base, altura)`, `area_circulo(radio)` y
   `area_triangulo(base, altura)` (todas con `f64`) y úsalas desde `main` para imprimir las áreas de
   un rectángulo 4×3, un círculo de radio 2 y un triángulo 6×5, con 2 decimales.
   → [`soluciones/areas.rs`](soluciones/areas.rs)

2. **Calendario.** Escribe `es_bisiesto(anio: i32) -> bool` (divisible entre 4, salvo los divisibles
   entre 100 que no lo sean entre 400) y `dias_en_mes(mes: u32, anio: i32) -> u32` (usa `match`;
   febrero depende de `es_bisiesto`). Prueba con los años 1900, 2000, 2024 y 2026.
   → [`soluciones/calendario.rs`](soluciones/calendario.rs)

3. **Estadísticas.** Escribe `estadisticas(datos: [f64; 6]) -> (f64, f64, f64)` que devuelva el
   mínimo, el máximo y el promedio, y `desviacion_estandar(datos: [f64; 6], promedio: f64) -> f64`.
   Desestructura la tupla en `main`.
   → [`soluciones/estadisticas.rs`](soluciones/estadisticas.rs)

4. **MCD y MCM.** Escribe `mcd` de forma **iterativa** (con `while`) y `mcm(a, b) = a / mcd(a, b) * b`
   (¿por qué conviene dividir **antes** de multiplicar?). Calcula ambos para los pares (12, 18),
   (7, 13) y (100, 75).
   → [`soluciones/mcd_mcm.rs`](soluciones/mcd_mcm.rs)

5. **Fibonacci: recursivo vs. iterativo.** Escribe `fib_recursivo(n)` y `fib_iterativo(n)` y
   comprueba que dan lo mismo para n = 0..=20. Luego mide cuánto tarda cada uno con n = 35 usando
   `std::time::Instant` (`let inicio = Instant::now(); ... inicio.elapsed()`). ¿Por qué el
   recursivo es tan lento?
   → [`soluciones/fibonacci.rs`](soluciones/fibonacci.rs)

6. **Fecha válida.** Escribe una función reutilizable
   `leer_entero_en_rango(mensaje: &str, min: i32, max: i32) -> i32` que pregunte hasta obtener un
   entero válido dentro del rango. Úsala para leer año (1–9999), mes (1–12) y día; el día máximo
   depende del mes y del año (reutiliza las funciones del ejercicio 2).
   → [`soluciones/fecha.rs`](soluciones/fecha.rs)

7. **Reto — Torres de Hanói.** Mover `n` discos de la torre A a la C usando B como auxiliar, sin
   poner nunca un disco sobre otro más pequeño. La solución recursiva: mover `n-1` discos de A a B,
   mover el disco grande de A a C, y mover los `n-1` de B a C. Escribe
   `hanoi(n: u32, origen: char, destino: char, auxiliar: char, imprimir: bool) -> u64` que imprima
   los movimientos (si `imprimir` es `true`) y **devuelva cuántos hizo**. Muestra los 7 movimientos
   para n = 3 y solo la cantidad para n = 1..=20. ¿Qué fórmula siguen?
   → [`soluciones/hanoi.rs`](soluciones/hanoi.rs)
