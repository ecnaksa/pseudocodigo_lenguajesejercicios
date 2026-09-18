/*
 * Problema 22 - Conteo Avanzado de Codigos de Falla
 * int contarFalla(int Arr[], int tam, int codigo)
 * Contexto: diagnostico en PLC. Cuenta las ocurrencias del codigo buscado.
 */
#include <stdio.h>

int contarFalla(int arr[], int tam, int codigo) {
    int contador = 0;
    for (int i = 0; i < tam; i++) {
        if (arr[i] == codigo) {
            contador = contador + 1;
        }
    }
    return contador;
}

int main(void) {
    int tam, codigo;
    printf("Ingrese el numero de fallas registradas: ");
    scanf("%d", &tam);

    int arr[tam];
    for (int i = 0; i < tam; i++) {
        printf("Falla %d: ", i);
        scanf("%d", &arr[i]);
    }

    printf("Ingrese el codigo a cuantificar: ");
    scanf("%d", &codigo);

    printf("El codigo %d aparece %d veces.\n", codigo, contarFalla(arr, tam, codigo));
    return 0;
}
