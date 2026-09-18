/*
 * Problema 24 - Verificacion de Rango de Histeresis
 * bool enHisteresis(double Arr[], int tam, double vmin, double vmax)
 * Contexto: sensor termico. Comprueba si TODAS las lecturas estan de manera ESTRICTA
 * dentro de (vmin, vmax). "Estricta" => se usan < y > (no <= ni >=).
 * (Ver teoria/05_verificaciones_orden_y_simetria.md)
 */
#include <stdio.h>
#include <stdbool.h>

bool enHisteresis(double arr[], int tam, double vmin, double vmax) {
    for (int i = 0; i < tam; i++) {
        if (!(arr[i] > vmin && arr[i] < vmax)) {   /* estricto: extremos NO permitidos */
            return false;
        }
    }
    return true;
}

int main(void) {
    int tam;
    double vmin, vmax;
    printf("Ingrese el numero de lecturas: ");
    scanf("%d", &tam);

    double arr[tam];
    for (int i = 0; i < tam; i++) {
        printf("Lectura %d: ", i);
        scanf("%lf", &arr[i]);
    }

    printf("Ingrese Vmin: ");
    scanf("%lf", &vmin);
    printf("Ingrese Vmax: ");
    scanf("%lf", &vmax);

    if (enHisteresis(arr, tam, vmin, vmax)) {
        printf("OK: todas las lecturas estan estrictamente dentro del intervalo.\n");
    } else {
        printf("ALERTA: alguna lectura toca o cruza los limites.\n");
    }
    return 0;
}
