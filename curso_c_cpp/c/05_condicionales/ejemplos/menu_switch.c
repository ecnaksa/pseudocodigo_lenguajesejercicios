/*
 * switch: un menu simple. Observa el break en cada case.
 * Prueba: printf "2\n" | ./prog
 */
#include <stdio.h>

int main(void) {
    int opcion;
    printf("1) Iniciar  2) Cargar  3) Salir\n");
    printf("Elige: ");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            printf("Iniciando partida...\n");
            break;
        case 2:
            printf("Cargando partida...\n");
            break;
        case 3:
            printf("Hasta luego\n");
            break;
        default:
            printf("Opcion invalida\n");
    }
    return 0;
}
