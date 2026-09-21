# Lección 14 — Proyecto final en C: agenda de contactos

¡Felicidades por llegar hasta aquí! Este proyecto **integra** casi todo lo aprendido en la pista
de C: `struct`, arreglos, funciones, punteros, `scanf`/`fgets`, bucles, condicionales, `switch` y
**archivos** para guardar los datos.

## Qué hace el programa

Una **agenda de contactos** por consola, con un menú:

```
== AGENDA DE CONTACTOS ==
1) Agregar contacto
2) Listar contactos
3) Buscar por nombre
4) Eliminar contacto
5) Guardar en archivo
6) Cargar desde archivo
0) Salir
```

Guarda los contactos (nombre y teléfono) en memoria, y puede **persistirlos** en un archivo de
texto `contactos.txt` para no perderlos entre ejecuciones.

## Cómo compilar y ejecutar

```bash
gcc -std=c11 -Wall -Wextra agenda.c -o agenda
./agenda
```

Para probarlo automáticamente puedes alimentar el menú por la entrada estándar, por ejemplo:

```bash
printf "1\nAna\n5551234\n1\nLuis\n5555678\n2\n5\n0\n" | ./agenda
```
(Agrega Ana, agrega Luis, lista, guarda y sale.)

## Qué conceptos usa (y dónde repasarlos)

| Concepto | Lección | Dónde aparece en el proyecto |
|---|---|---|
| `struct` + `typedef` | 11 | el tipo `Contacto` |
| Arreglos | 08 | `Contacto agenda[MAX]` |
| Funciones + punteros | 07, 09 | operaciones que modifican la agenda (`int *n`) |
| Bucles y `switch` | 05, 06 | el menú principal |
| Cadenas + `fgets` | 03, 08 | leer el nombre con espacios |
| Archivos | 12 | `guardar` y `cargar` |

## Anatomía del código

El programa está en [`agenda.c`](agenda.c), dividido en **funciones pequeñas**, cada una con una
responsabilidad clara:

- `agregar(...)` — añade un contacto (comprueba que no esté llena la agenda).
- `listar(...)` — muestra todos.
- `buscar(...)` — busca por nombre y muestra coincidencias.
- `eliminar(...)` — quita un contacto desplazando los siguientes.
- `guardar(...)` / `cargar(...)` — persistencia en archivo.
- `main` — el bucle del menú que llama a lo anterior.

Lee el archivo con calma: verás cómo cada tema del curso encaja en un programa "de verdad".

## Retos para extenderlo (practica por tu cuenta)

Una vez lo entiendas, intenta mejorarlo. Ideas, de menor a mayor dificultad:

1. Añadir un campo **correo** a `Contacto`.
2. Impedir agregar dos contactos con el **mismo nombre**.
3. **Ordenar** la lista alfabéticamente antes de mostrarla (repasa la burbuja).
4. Cargar la agenda **automáticamente** al iniciar y guardar al salir.
5. Cambiar el arreglo fijo por **memoria dinámica** (`malloc`/`realloc`) para no tener límite
   (lección 10).
6. Separar el código en **varios archivos** (`agenda.h`, `agenda.c`, `main.c`) con un `Makefile`
   (lección 13).

## Siguiente paso

Con esto **completaste la pista de C**. Ya entiendes cómo funciona un programa por dentro:
memoria, tipos, punteros, archivos. Ahora estás listo para la
[**pista de C++**](../../cpp), que construye sobre todo esto y añade la Programación Orientada a
Objetos y la biblioteca estándar.

## Para profundizar

- **King**, cap. 15 ("Writing Large Programs") — cómo estructurar proyectos.
- Vuelve a cualquier lección cuyo concepto te haya costado en este proyecto.
