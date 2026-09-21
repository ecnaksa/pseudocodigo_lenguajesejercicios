# Lección 13 — Proyecto final en C++: sistema de biblioteca

¡Enhorabuena, has llegado al final del curso! Este proyecto **integra** lo esencial de C++
moderno: **clases y encapsulamiento** (POO), **herencia** conceptual, la **STL** (`vector`,
`string`, algoritmos) y un diseño limpio con métodos.

## Qué hace el programa

Un **sistema de gestión de biblioteca** por consola:

```
== BIBLIOTECA ==
1) Agregar libro
2) Listar libros
3) Prestar libro (por titulo)
4) Devolver libro (por titulo)
5) Buscar por autor
6) Estadisticas
0) Salir
```

Gestiona una colección de libros; cada libro tiene título, autor y estado (disponible o
prestado). Permite prestarlos, devolverlos, buscarlos y ver estadísticas.

## Cómo compilar y ejecutar

```bash
g++ -std=c++17 -Wall -Wextra biblioteca.cpp -o biblioteca
./biblioteca
```

Prueba automática (agrega dos libros, lista, presta uno, estadísticas, sale):

```bash
printf "1\nEl Quijote\nCervantes\n1\n1984\nOrwell\n2\n3\nEl Quijote\n6\n0\n" | ./biblioteca
```

## Qué conceptos usa (y dónde repasarlos)

| Concepto | Lección | Dónde aparece |
|---|---|---|
| Clases y encapsulamiento | 04 | `Libro`, `Biblioteca` con datos `private` |
| Constructores | 05 | inicializar `Libro` |
| `std::vector` | 09 | la colección de libros |
| `std::string` | 02 | títulos y autores |
| Referencias (`&`, `const&`) | 02, 03 | parámetros de métodos |
| Algoritmos / bucles | 06, 10 | búsquedas y conteos |

## Diseño (dos clases)

El programa (en [`biblioteca.cpp`](biblioteca.cpp)) se organiza en **dos clases** con
responsabilidades claras:

- **`Libro`**: representa un libro (título, autor, `disponible`). Encapsula su estado con métodos
  como `prestar()`, `devolver()`, `estaDisponible()`.
- **`Biblioteca`**: contiene un `vector<Libro>` y ofrece las operaciones de alto nivel
  (`agregar`, `listar`, `prestarPorTitulo`, `buscarPorAutor`, `estadisticas`).
- **`main`**: solo el bucle del menú, que delega en la `Biblioteca`.

Esta separación —cada clase responsable de lo suyo, el `main` limpio— es el corazón del **diseño
orientado a objetos**.

## Retos para extenderlo

1. Añadir un **año de publicación** a `Libro` y ordenar el listado por año (usa `sort` con una
   lambda, lección 10).
2. Guardar y cargar la biblioteca en un **archivo** (fusiona con lo aprendido en la pista C sobre
   archivos, adaptado a `fstream` de C++).
3. Impedir agregar un libro con un **título duplicado**.
4. Crear una jerarquía: una clase base `Material` y derivadas `Libro`, `Revista`, `DVD` con un
   método virtual `describir()` (herencia y polimorfismo, lección 06).
5. Guardar los libros como `vector<unique_ptr<Material>>` para el punto anterior (lección 11).

## ¡Terminaste el curso!

Has recorrido C (fundamentos, memoria, punteros, archivos) y C++ (POO, plantillas, STL, RAII,
excepciones). Con esto tienes una **base sólida** para leer código real, construir tus propios
proyectos y —volviendo al comentario que inició todo esto— **entender los sistemas** en lugar de
improvisar.

### Por dónde seguir

- Practica construyendo proyectos propios (una calculadora, un juego de consola, una to-do list).
- Profundiza con los libros de [`../../FUENTES.md`](../../FUENTES.md), sobre todo *A Tour of C++*
  (Stroustrup) y **learncpp.com**.
- Aprende un **sistema de construcción** (CMake) y **control de versiones** (Git) para proyectos
  más grandes.
- Explora temas siguientes: `move semantics`, concurrencia (`<thread>`), y las **C++ Core
  Guidelines**.

## Para profundizar

- **Stroustrup**, *Programming: Principles and Practice Using C++* — proyectos guiados.
- Vuelve a cualquier lección cuyo concepto quieras reforzar.
