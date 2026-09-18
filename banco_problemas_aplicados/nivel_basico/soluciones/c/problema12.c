/*
 * Problema 12 - Verificacion de Rango de Operacion Segura
 * bool enRango(double Arr[], int tam)
 * Contexto: 10 mediciones de voltaje. Devuelve true si TODAS estan dentro de [3.3, 5.0].
 *
 * IMPORTANTE: la comparacion doble "3.3 <= val <= 5.0" NO se puede escribir asi en
 * C/C++/Java; hay que unir dos comparaciones con && :  (val >= 3.3 && val <= 5.0).
 * (Ver teoria/03_funciones_booleanas_validacion_rango.md)
 */
#include <stdio.h>
#include <stdbool.h>

bool enRango(double arr[], int tam) {
    for (int i = 0; i < tam; i++) {
        if (!(arr[i] >= 3.3 && arr[i] <= 5.0)) {
            return false;            /* en cuanto UNO se sale del rango, ya es false */
        }
    }
    return true;                     /* todos pasaron */
}

int main(void) {
    int tam = 10;
    double arr[tam];
    for (int i = 0; i < tam; i++) {
        printf("Medicion %d (V): ", i);
        scanf("%lf", &arr[i]);
    }

    if (enRango(arr, tam)) {
        printf("OK: todas las mediciones estan dentro del rango seguro [3.3, 5.0].\n");
    } else {
        printf("ALERTA: al menos una medicion esta fuera del rango [3.3, 5.0].\n");
    }
    return 0;
}
