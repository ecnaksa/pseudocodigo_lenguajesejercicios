# Teoría — Nivel Básico Aplicado (electrónica)

Estos 20 problemas reutilizan los mismos patrones de arreglos del primer set, pero aplicados a
contextos de electrónica (ADC, banco solar, PLC, osciloscopio, buffers FIFO…) y usando
**`double`** en muchos casos. Aquí se explican **los conceptos nuevos o con un giro distinto**
respecto a la teoría base.

> **Fundamentos generales** (qué es un arreglo, `main`, funciones, `for`, `if/else`, paso por
> referencia, división real, `bool`): están en la teoría del primer set,
> [`../../../teoria`](../../../teoria). No se repiten aquí; esta carpeta se enfoca en lo específico.

| # | Archivo | Aplica a |
|---|---------|----------|
| 01 | [`01_arreglos_de_punto_flotante.md`](01_arreglos_de_punto_flotante.md) | P1, P2, P5, P7–P14, P16, P17, P19 (arreglos `double`) |
| 02 | [`02_condicion_sobre_indice_vs_valor.md`](02_condicion_sobre_indice_vs_valor.md) | P3, P5 (condición sobre el índice `i`, no el valor) |
| 03 | [`03_funciones_booleanas_validacion_rango.md`](03_funciones_booleanas_validacion_rango.md) | P12, P18 (retornar `bool`; la trampa `3.3<=x<=5.0`) |
| 04 | [`04_pares_adyacentes_y_deteccion_de_flanco.md`](04_pares_adyacentes_y_deteccion_de_flanco.md) | P16 (comparar `Arr[i]` con `Arr[i+1]`, límites) |
| 05 | [`05_desplazamiento_fifo_e_inversion_espejo.md`](05_desplazamiento_fifo_e_inversion_espejo.md) | P17, P19 (sentido del recorrido, posición espejo) |
| 06 | [`06_producto_punto_y_potencia_promedio.md`](06_producto_punto_y_potencia_promedio.md) | P10, P13 (multiplicar-y-acumular, promedio) |
| 07 | [`07_contexto_hardware_adc.md`](07_contexto_hardware_adc.md) | P1, P12, P15, P16 (qué es un ADC, 1023, saturación, umbrales) |

## Mapa problema → patrón

| Problema | Patrón principal | Tipo del arreglo |
|---|---|---|
| 1 Suma de corrientes | acumulador | double |
| 2 Voltaje mínimo | mínimo secuencial | double |
| 3 Transitorios impares | contador por **índice** | int |
| 4 Código de error | búsqueda lineal → índice/-1 | int |
| 5 Cargas pares | acumulador por **índice** | double |
| 6 Frecuencia de falla | contador por **valor** (== x) | int |
| 7 Polaridad AC | contadores + acumuladores múltiples | double |
| 8 Umbral térmico | media + filtro por comparación | double |
| 9 Superposición A+B | operación elemento a elemento | double |
| 10 Cruzada inversa | índice espejo `tam-1-i` | double |
| 11 Pico máximo | máximo + su posición | double |
| 12 Rango seguro | función booleana + rango con `&&` | double |
| 13 Potencia promedio | producto punto + promedio | double |
| 14 Ordenamiento | burbuja (dos bucles) | double |
| 15 Saturadas | contador por **valor** (== 1023) | int |
| 16 Flanco de subida | pares adyacentes `Arr[i]`,`Arr[i+1]` | double |
| 17 Buffer FIFO | desplazamiento (sentido del recorrido) | double |
| 18 Comparar canales | función booleana de igualdad | int |
| 19 Espejo | asignación a posición espejo | double |
| 20 Exposición | síntesis conceptual (sin código) | — |
