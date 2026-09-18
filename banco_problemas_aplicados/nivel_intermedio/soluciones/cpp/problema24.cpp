/*
 * Problema 24 - Verificacion de Rango de Histeresis
 * bool enHisteresis(double Arr[], int tam, double vmin, double vmax)
 * "Estricta": se usan < y > (los extremos NO se permiten).
 */
#include <iostream>
using namespace std;

bool enHisteresis(double arr[], int tam, double vmin, double vmax) {
    for (int i = 0; i < tam; i++) {
        if (!(arr[i] > vmin && arr[i] < vmax)) {
            return false;
        }
    }
    return true;
}

int main() {
    int tam;
    double vmin, vmax;
    cout << "Ingrese el numero de lecturas: ";
    cin >> tam;

    double* arr = new double[tam];
    for (int i = 0; i < tam; i++) {
        cout << "Lectura " << i << ": ";
        cin >> arr[i];
    }

    cout << "Ingrese Vmin: ";
    cin >> vmin;
    cout << "Ingrese Vmax: ";
    cin >> vmax;

    if (enHisteresis(arr, tam, vmin, vmax)) {
        cout << "OK: todas las lecturas estan estrictamente dentro del intervalo." << endl;
    } else {
        cout << "ALERTA: alguna lectura toca o cruza los limites." << endl;
    }

    delete[] arr;
    return 0;
}
