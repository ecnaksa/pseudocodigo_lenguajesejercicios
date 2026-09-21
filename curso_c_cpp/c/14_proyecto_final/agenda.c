/*
 * Proyecto final de la pista C: Agenda de contactos por consola.
 * Integra: struct, arreglos, funciones, punteros, cadenas, switch, bucles y archivos.
 *
 * Compilar: gcc -std=c11 -Wall -Wextra agenda.c -o agenda
 * Ejecutar: ./agenda
 */
#include <stdio.h>
#include <string.h>

#define MAX 100          /* capacidad maxima de la agenda */
#define LARGO 50         /* largo maximo de nombre/telefono */

typedef struct {
    char nombre[LARGO];
    char telefono[LARGO];
} Contacto;

/* Lee una linea completa (con espacios) y quita el salto de linea final. */
void leerLinea(const char *prompt, char *destino, int tam) {
    printf("%s", prompt);
    if (fgets(destino, tam, stdin) != NULL) {
        destino[strcspn(destino, "\n")] = '\0';   /* elimina el '\n' */
    }
}

/* Agrega un contacto. 'n' es puntero para poder incrementar el contador de main. */
void agregar(Contacto agenda[], int *n) {
    if (*n >= MAX) {
        printf("La agenda esta llena.\n");
        return;
    }
    leerLinea("Nombre: ", agenda[*n].nombre, LARGO);
    leerLinea("Telefono: ", agenda[*n].telefono, LARGO);
    (*n)++;
    printf("Contacto agregado. Total: %d\n", *n);
}

void listar(const Contacto agenda[], int n) {
    if (n == 0) {
        printf("(agenda vacia)\n");
        return;
    }
    printf("--- %d contacto(s) ---\n", n);
    for (int i = 0; i < n; i++) {
        printf("%2d) %-20s %s\n", i + 1, agenda[i].nombre, agenda[i].telefono);
    }
}

void buscar(const Contacto agenda[], int n) {
    char clave[LARGO];
    leerLinea("Nombre a buscar: ", clave, LARGO);

    int encontrados = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(agenda[i].nombre, clave) == 0) {
            printf("  %s -> %s\n", agenda[i].nombre, agenda[i].telefono);
            encontrados++;
        }
    }
    if (encontrados == 0) {
        printf("No se encontro '%s'.\n", clave);
    }
}

/* Elimina por posicion desplazando los siguientes una posicion a la izquierda. */
void eliminar(Contacto agenda[], int *n) {
    listar(agenda, *n);
    if (*n == 0) return;

    int pos;
    printf("Numero a eliminar (1-%d): ", *n);
    if (scanf("%d", &pos) != 1) { return; }
    getchar();                              /* consume el '\n' pendiente */

    if (pos < 1 || pos > *n) {
        printf("Posicion invalida.\n");
        return;
    }
    for (int i = pos - 1; i < *n - 1; i++) {
        agenda[i] = agenda[i + 1];          /* copia de struct */
    }
    (*n)--;
    printf("Contacto eliminado. Total: %d\n", *n);
}

void guardar(const Contacto agenda[], int n) {
    FILE *f = fopen("contactos.txt", "w");
    if (f == NULL) {
        printf("No se pudo guardar.\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        fprintf(f, "%s;%s\n", agenda[i].nombre, agenda[i].telefono);
    }
    fclose(f);
    printf("Guardados %d contacto(s) en contactos.txt\n", n);
}

/* Devuelve cuantos contactos cargo. Formato por linea: nombre;telefono */
int cargar(Contacto agenda[]) {
    FILE *f = fopen("contactos.txt", "r");
    if (f == NULL) {
        printf("No hay archivo contactos.txt para cargar.\n");
        return 0;
    }
    int n = 0;
    char linea[2 * LARGO + 2];
    while (n < MAX && fgets(linea, sizeof(linea), f) != NULL) {
        linea[strcspn(linea, "\n")] = '\0';
        char *sep = strchr(linea, ';');     /* busca el separador */
        if (sep == NULL) continue;
        *sep = '\0';                        /* corta la linea en dos */
        strncpy(agenda[n].nombre, linea, LARGO - 1);
        agenda[n].nombre[LARGO - 1] = '\0';
        strncpy(agenda[n].telefono, sep + 1, LARGO - 1);
        agenda[n].telefono[LARGO - 1] = '\0';
        n++;
    }
    fclose(f);
    printf("Cargados %d contacto(s).\n", n);
    return n;
}

void menu(void) {
    printf("\n== AGENDA DE CONTACTOS ==\n");
    printf("1) Agregar   2) Listar   3) Buscar\n");
    printf("4) Eliminar  5) Guardar  6) Cargar   0) Salir\n");
    printf("Opcion: ");
}

int main(void) {
    Contacto agenda[MAX];
    int n = 0;
    int opcion;

    do {
        menu();
        if (scanf("%d", &opcion) != 1) break;   /* fin de entrada */
        getchar();                              /* consume el '\n' tras el numero */

        switch (opcion) {
            case 1: agregar(agenda, &n); break;
            case 2: listar(agenda, n);   break;
            case 3: buscar(agenda, n);   break;
            case 4: eliminar(agenda, &n); break;
            case 5: guardar(agenda, n);  break;
            case 6: n = cargar(agenda);  break;
            case 0: printf("Hasta luego.\n"); break;
            default: printf("Opcion invalida.\n");
        }
    } while (opcion != 0);

    return 0;
}
