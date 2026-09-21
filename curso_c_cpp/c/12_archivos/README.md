# Lección 12 — Archivos

Hasta ahora, todo lo que leías (teclado) y escribías (pantalla) desaparecía al terminar el
programa. Los **archivos** permiten **guardar datos de forma permanente** en el disco y volver a
leerlos después. En C se manejan con funciones de `<stdio.h>`.

## El tipo `FILE *` y el flujo de trabajo

Para trabajar con un archivo:

1. **Abrir** el archivo con `fopen`, que devuelve un puntero `FILE *`.
2. **Leer o escribir** con funciones como `fprintf`, `fscanf`, `fgets`, `fputs`.
3. **Cerrar** con `fclose` (importante: vacía los datos pendientes y libera el archivo).

```c
FILE *f = fopen("datos.txt", "w");   // abrir para escribir
if (f == NULL) {                     // SIEMPRE comprobar
    printf("No se pudo abrir el archivo\n");
    return 1;
}
fprintf(f, "Hola archivo\n");        // escribir
fclose(f);                           // cerrar
```

## Modos de apertura

El segundo argumento de `fopen` es el **modo**:

| Modo | Significado |
|---|---|
| `"r"` | leer (el archivo debe existir) |
| `"w"` | escribir (crea el archivo; **si existe, lo borra**) |
| `"a"` | añadir (*append*): escribe al final, sin borrar lo anterior |
| `"r+"` | leer y escribir (debe existir) |
| `"rb"`, `"wb"` | como los anteriores, pero en **modo binario** |

> **Cuidado con `"w"`:** trunca (vacía) el archivo si ya existía. Si quieres conservar el
> contenido y agregar, usa `"a"`.

## Escribir texto: `fprintf` y `fputs`

`fprintf` es como `printf`, pero el primer argumento es el `FILE *`:

```c
FILE *f = fopen("notas.txt", "w");
if (f == NULL) return 1;
fprintf(f, "Ana %d\n", 90);
fprintf(f, "Luis %d\n", 85);
fclose(f);
```
`fputs(cadena, f)` escribe una cadena tal cual (sin formato).

## Leer texto: `fscanf` y `fgets`

`fscanf` es como `scanf` pero desde el archivo:

```c
FILE *f = fopen("notas.txt", "r");
if (f == NULL) return 1;
char nombre[50];
int nota;
while (fscanf(f, "%49s %d", nombre, &nota) == 2) {   // hasta que no lea 2 valores
    printf("%s saco %d\n", nombre, nota);
}
fclose(f);
```

`fscanf` **devuelve** cuántos elementos leyó; cuando llega al final del archivo, devuelve menos de
lo pedido (o `EOF`), y así sabes cuándo parar.

Para leer **líneas completas** (con espacios), usa **`fgets`**:

```c
char linea[256];
while (fgets(linea, sizeof(linea), f) != NULL) {   // lee una linea por vuelta
    printf("%s", linea);      // linea ya incluye el '\n'
}
```
`fgets` lee hasta el salto de línea o hasta llenar el buffer, y devuelve `NULL` al final. Es **más
seguro** que `fscanf("%s")` porque respeta el tamaño del buffer.

## Detectar el final del archivo (EOF)

**EOF** (*End Of File*) marca el fin. Los bucles de lectura suelen basarse en el valor de retorno:

- `fscanf(...) == n` mientras lea `n` valores.
- `fgets(...) != NULL` mientras haya líneas.
- `fgetc(f) != EOF` al leer carácter a carácter.

## Ejemplo completo: escribir y volver a leer

```c
#include <stdio.h>

int main(void) {
    // Escribir
    FILE *f = fopen("saludo.txt", "w");
    if (f == NULL) return 1;
    fprintf(f, "Hola\nMundo\n");
    fclose(f);

    // Leer
    f = fopen("saludo.txt", "r");
    if (f == NULL) return 1;
    char linea[100];
    while (fgets(linea, sizeof(linea), f) != NULL) {
        printf("Leido: %s", linea);
    }
    fclose(f);
    return 0;
}
```

## Archivos binarios (breve): `fread` y `fwrite`

Para guardar datos "tal cual están en memoria" (por ejemplo, un arreglo de structs) se usa el
modo binario con `fwrite`/`fread`:

```c
FILE *f = fopen("datos.bin", "wb");
int nums[3] = {10, 20, 30};
fwrite(nums, sizeof(int), 3, f);   // escribe 3 enteros en binario
fclose(f);
```
Es más rápido y compacto que el texto, pero **no** es legible por humanos y depende de la
plataforma. Para empezar, los archivos de **texto** son más que suficientes.

## Errores típicos

- **No comprobar si `fopen` devolvió `NULL`** (archivo inexistente, sin permisos…).
- **Olvidar `fclose`** → datos que no se escriben del todo, o archivos "bloqueados".
- Abrir con `"w"` cuando querías **conservar** el contenido (usa `"a"`).
- Usar `fscanf("%s")` sin límite de tamaño → desbordamiento (mejor `fgets`).
- Confundir el orden de argumentos: en `fprintf`/`fscanf`, el `FILE *` va **primero**.

## Resumen

- `fopen(nombre, modo)` → `FILE *`; **comprueba** que no sea `NULL`; cierra con `fclose`.
- Modos: `"r"` leer, `"w"` escribir (trunca), `"a"` añadir; añade `b` para binario.
- Escribe con `fprintf`/`fputs`; lee con `fscanf`/`fgets` (prefiere `fgets` para líneas).
- El fin de archivo (EOF) se detecta por el valor de retorno.
- `fread`/`fwrite` para binario (avanzado).

## Ejemplos

- [`ejemplos/escribir.c`](ejemplos/escribir.c)
- [`ejemplos/leer_lineas.c`](ejemplos/leer_lineas.c)
- [`ejemplos/copiar_archivo.c`](ejemplos/copiar_archivo.c)

## Ejercicios

En [`ejercicios/`](ejercicios/).

## Para profundizar

- **K&R**, cap. 7 ("Input and Output").
- **King**, cap. 22 ("Input/Output").
- **cppreference**, "File input/output". https://en.cppreference.com/w/c/io
