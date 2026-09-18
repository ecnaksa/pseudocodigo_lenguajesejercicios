# Banco de Problemas Aplicados

Carpeta **contenedora** de bancos de problemas aplicados a la ingeniería (electrónica,
instrumentación, señales), organizados por sets. Cada set vive en su propia subcarpeta y trae
lo mismo: **pseudocódigo híbrido**, **teoría detallada** y **soluciones en C, C++ y Java**.

## Sets

| Subcarpeta | Contenido | Estado |
|---|---|---|
| [`nivel_basico/`](nivel_basico) | 20 problemas (5 bloques): mediciones/contadores, polaridad/estadísticas, operaciones de vectores, análisis secuencial y cierre. | ✅ Completo |
| _(pendiente)_ | Segundo set — se agregará cuando estén las imágenes restantes. | ⏳ Por hacer |

> Cuando lleguen las siguientes imágenes, se creará **otra subcarpeta hermana** aquí dentro
> (por ejemplo `nivel_intermedio/` o el nombre que corresponda), con la misma estructura
> `pseudocodigo/ + teoria/ + soluciones/{c,cpp,java}/`, sin tocar lo ya hecho.

## Relación con el resto del repositorio

- Los **fundamentos** (arreglos, funciones, `for`, `if/else`, paso por referencia, división
  real, `bool`) están explicados en la teoría del primer set: [`../teoria`](../teoria).
- El **pseudocódigo corregido** de los 15 ejercicios originales está en
  [`../pseudocodigo_corregido`](../pseudocodigo_corregido), y su código en
  [`../soluciones`](../soluciones).
- Esta carpeta añade **problemas nuevos aplicados**, reutilizando esos mismos patrones en
  contextos de ingeniería.
