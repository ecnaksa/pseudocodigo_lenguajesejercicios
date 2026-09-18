# Teoría — Nivel Intermedio Aplicado

Los problemas 21–39 suben el nivel: aparecen **matrices**, formas de **devolver varios
valores**, **estadística** (desviación estándar) y varias **transformaciones de vector**. Aquí
se explican esos conceptos nuevos; los fundamentos siguen en la teoría base.

> **Fundamentos generales** (arreglos, funciones, `for`, `if/else`, división real, `bool`):
> [`../../../teoria`](../../../teoria).
> **Conceptos del nivel básico aplicado** (arreglos `double`, índice vs valor, funciones
> booleanas, pares adyacentes, FIFO/espejo, producto punto, ADC):
> [`../../nivel_basico/teoria`](../../nivel_basico/teoria).

| # | Archivo | Aplica a |
|---|---------|----------|
| 01 | [`01_devolver_varios_valores.md`](01_devolver_varios_valores.md) | P21 (valor + índice: puntero / referencia / arreglo out) |
| 02 | [`02_matrices_2d.md`](02_matrices_2d.md) | P29–P32 (matrices: declaración, recorrido, paso a funciones) |
| 03 | [`03_transformaciones_de_vector.md`](03_transformaciones_de_vector.md) | P25, P26, P27, P28, P33, P36, P37, P38 (vector→vector) |
| 04 | [`04_estadistica_y_outliers.md`](04_estadistica_y_outliers.md) | P35 (media, varianza, desviación estándar, outliers) |
| 05 | [`05_verificaciones_orden_y_simetria.md`](05_verificaciones_orden_y_simetria.md) | P24, P34, P39 (booleanas; estricto vs inclusivo) |

## Mapa problema → concepto

| Problema | Concepto principal | Novedad |
|---|---|---|
| 21 Pico + índice | devolver 2 valores (paso por referencia) | ✦ |
| 22 Contar falla | contador por valor | (repaso) |
| 23 Invertir in-place | intercambio de extremos | (repaso) |
| 24 Histéresis | booleana de rango **estricto** | ✦ estricto vs inclusivo |
| 25 Partición pares/impares | reordenar por índice a auxiliar | ✦ |
| 26 Desplazamiento circular | rotación con módulo `%` | ✦ |
| 27 Derivada discreta | diferencias adyacentes (salida n-1) | ✦ |
| 28 Normalización | dividir entre el máximo absoluto | ✦ |
| 29 Suma por filas | **matriz**: acumular por filas | ✦ 2D |
| 30 Transposición | **matriz**: intercambiar índices | ✦ 2D |
| 31 Fila de mayor consumo | **matriz**: comparar sumas de filas | ✦ 2D |
| 32 Nodos críticos | **matriz**: contar sobre umbral | ✦ 2D |
| 33 Submuestreo | tomar índices `i*K` (salida menor) | ✦ |
| 34 Orden estricto | booleana `Arr[i] < Arr[i+1]` | ✦ estricto |
| 35 Outliers | media, desviación estándar, 2σ | ✦ estadística |
| 36 Concatenación | unir en vector mayor | ✦ |
| 37 Producto punto | acumular `A[i]*B[i]` → escalar | (repaso) |
| 38 Rectificación | valor absoluto condicional | ✦ |
| 39 Simetría espectral | palíndromo `Arr[i]==Arr[n-1-i]` | (repaso) |
