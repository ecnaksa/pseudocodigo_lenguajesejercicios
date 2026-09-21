# Ejercicios — Lección 13

1. **Macro de conversión.** Define `#define A_FAHRENHEIT(c) ((c) * 9.0 / 5.0 + 32.0)` y úsala para
   imprimir 0, 25 y 100 °C en Fahrenheit. Fíjate en el uso de los paréntesis.
   → [`soluciones/ej1_macro.c`](soluciones/ej1_macro.c)

2. **Módulo de geometría.** Crea un módulo `geometria` (`.h` + `.c`) con:
   - `double areaCirculo(double r);`
   - `double areaRectangulo(double base, double altura);`

   y un `main.c` que las use. Compila con
   `gcc -std=c11 -Wall main.c geometria.c -o geo -lm`.
   → Solución completa en [`soluciones/geometria/`](soluciones/geometria/) (incluye `Makefile`).

3. **Reto — include guard.** Explica (en un comentario dentro de tu `.h`) qué pasaría si quitaras
   el `#ifndef/#define/#endif` y dos archivos incluyeran esa cabecera. Compruébalo si te animas.
   (Referencia: el `geometria.h` de la solución del ejercicio 2.)
