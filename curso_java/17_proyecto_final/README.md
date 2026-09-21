# Lección 17 — Proyecto final: gestor de tareas

¡Enhorabuena, has llegado al final del curso! Este proyecto **integra** lo esencial de Java: una
**clase** propia con encapsulamiento (POO), una **colección** (`ArrayList`), **entrada** con
`Scanner`, **enum**, **excepciones** y un menú con `switch`.

## Qué hace el programa

Un **gestor de tareas** (*to-do list*) por consola:

```
== GESTOR DE TAREAS ==
1) Agregar tarea
2) Listar tareas
3) Marcar como completada
4) Eliminar tarea
5) Ver solo pendientes
6) Estadisticas
0) Salir
```

Gestiona una lista de tareas; cada tarea tiene una descripción, una prioridad y un estado
(pendiente o completada).

## Cómo compilar y ejecutar

```bash
javac GestorTareas.java
java GestorTareas
```

Prueba automática (agrega dos tareas, lista, completa la 1, ve pendientes, estadísticas, sale):

```bash
printf "1\nEstudiar Java\nALTA\n1\nComprar pan\nBAJA\n2\n3\n1\n5\n6\n0\n" | java GestorTareas
```

## Qué conceptos usa (y dónde repasarlos)

| Concepto | Lección | Dónde aparece |
|---|---|---|
| Clases y encapsulamiento | 10 | la clase `Tarea` (campos `private`) |
| Constructores y `toString` | 11 | crear e imprimir tareas |
| `enum` | (nuevo aquí) | la prioridad `ALTA/MEDIA/BAJA` |
| `ArrayList` | 14 | la lista de tareas |
| Excepciones | 15 | validar la entrada del usuario |
| Streams | 16 | contar completadas / filtrar pendientes |
| Menú con `switch` | 05 | el bucle principal |

## Diseño (dos clases)

El programa (en [`GestorTareas.java`](GestorTareas.java)) se organiza en:

- **`Tarea`**: representa una tarea (descripción, prioridad, completada). Encapsula su estado con
  métodos (`completar`, `estaCompletada`, `toString`).
- **`GestorTareas`**: contiene la lógica (la lista, el menú, las operaciones) y el `main`.

Esta separación —una clase para el "dato", otra para la lógica y el `main`— es un patrón muy común
y limpio en Java.

## Retos para extenderlo

1. Añadir una **fecha límite** a `Tarea` y ordenar las tareas por prioridad o fecha (usa
   `Comparable` o un `Comparator` con lambda, lecciones 13 y 16).
2. **Guardar y cargar** las tareas en un archivo de texto (investiga `java.nio.file.Files` o
   `BufferedReader`/`BufferedWriter`).
3. Impedir agregar dos tareas con la **misma descripción**.
4. Separar el código en **varios archivos** (`Tarea.java` y `GestorTareas.java`) y compilarlos
   juntos (`javac *.java`).
5. Añadir **pruebas** con JUnit para la clase `Tarea`.

## ¡Terminaste el curso de Java!

Has recorrido los fundamentos (tipos, control de flujo, métodos, arreglos, cadenas), la
**Programación Orientada a Objetos** (clases, herencia, polimorfismo, interfaces), las
**colecciones**, las **excepciones** y la **programación funcional** con lambdas y streams. Tienes
una **base sólida** para leer código Java real y construir tus propios proyectos.

### Por dónde seguir

- Practica construyendo proyectos propios (un juego de consola, una calculadora, una agenda).
- Profundiza con los libros de [`../FUENTES.md`](../FUENTES.md), sobre todo *Head First Java* (para
  afianzar) y *Effective Java* (para escribir Java de calidad).
- Aprende un **sistema de construcción** (Maven o Gradle) y **pruebas** (JUnit).
- Explora el siguiente nivel: **genéricos avanzados**, **concurrencia** (`Thread`, `ExecutorService`),
  y frameworks como **Spring** (backend) o **Android** (móviles), según lo que te interese.

## Para profundizar

- **Head First Java** — proyectos guiados paso a paso.
- **The Java Tutorials (Oracle)** — la referencia oficial completa.
