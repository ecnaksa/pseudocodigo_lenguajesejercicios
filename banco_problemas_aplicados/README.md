# Banco de Problemas Aplicados

Carpeta **contenedora** de bancos de problemas aplicados a la ingeniería (electrónica,
instrumentación, señales), organizados por sets. Cada set vive en su propia subcarpeta y trae
lo mismo: **pseudocódigo híbrido**, **teoría detallada** y **soluciones en C, C++ y Java**.

## Sets

| Subcarpeta | Contenido | Estado |
|---|---|---|
| [`nivel_basico/`](nivel_basico) | 20 problemas (5 bloques): mediciones/contadores, polaridad/estadísticas, operaciones de vectores, análisis secuencial y cierre. | ✅ Completo |
| [`nivel_intermedio/`](nivel_intermedio) | 19 problemas (5 bloques): señales y buffers, manipulación de estructuras, **matrices**, procesamiento de buffers y cierre. | ✅ Completo |
| _(pendiente)_ | Siguientes sets — se agregarán cuando estén las imágenes restantes. | ⏳ Por hacer |

> Cada nuevo set se crea como **otra subcarpeta hermana** aquí dentro, con la misma estructura
> `pseudocodigo/ + teoria/ + soluciones/{c,cpp,java}/`, sin tocar lo ya hecho.

## Novedades por set

- **nivel_basico:** arreglos `double`, condición sobre índice vs valor, funciones booleanas de
  rango, detección de flanco, FIFO/espejo, producto punto, contexto ADC.
- **nivel_intermedio:** devolver varios valores (paso por referencia), **matrices 2D**,
  transformaciones de vector (rotación, derivada, normalización, submuestreo, concatenación),
  desviación estándar y outliers, verificaciones estricto vs inclusivo.

## Relación con el resto del repositorio

- Los **fundamentos** (arreglos, funciones, `for`, `if/else`, paso por referencia, división
  real, `bool`) están explicados en la teoría del primer set: [`../teoria`](../teoria).
- El **pseudocódigo corregido** de los 15 ejercicios originales está en
  [`../pseudocodigo_corregido`](../pseudocodigo_corregido), y su código en
  [`../soluciones`](../soluciones).
- Esta carpeta añade **problemas nuevos aplicados**, reutilizando esos mismos patrones en
  contextos de ingeniería.
