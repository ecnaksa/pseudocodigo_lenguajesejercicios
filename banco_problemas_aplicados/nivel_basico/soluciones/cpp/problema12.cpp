/*
 * Problema 12 - Verificacion de Rango de Operacion Segura
 * bool enRango(double Arr[], int tam)  -> true si TODAS estan en [3.3, 5.0]
 * Recuerda: "3.3 <= val <= 5.0" se escribe (val >= 3.3 && val <= 5.0).
 */
#include <iostream>
using namespace std;

bool enRango(double arr[], int tam) {
    for (int i = 0; i < tam; i++) {
        if (!(arr[i] >= 3.3 && arr[i] <= 5.0)) {
            return false;
        }
    }
    return true;
}

int main() {
    int tam = 10;
    double* arr = new double[tam];
    for (int i = 0; i < tam; i++) {
        cout << "Medicion " << i << " (V): ";
        cin >> arr[i];
    }

    if (enRango(arr, tam)) {
        cout << "OK: todas las mediciones estan dentro del rango seguro [3.3, 5.0]." << endl;
    } else {
        cout << "ALERTA: al menos una medicion esta fuera del rango [3.3, 5.0]." << endl;
    }

    delete[] arr;
    return 0;
}
