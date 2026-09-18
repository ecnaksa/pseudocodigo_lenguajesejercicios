/*
 * Problema 06 - Frecuencia de Falla Especifica en PLC
 * int cuentaRepeticiones(int Arr[], int x, int tam)
 */
#include <iostream>
using namespace std;

int cuentaRepeticiones(int arr[], int x, int tam) {
    int contador = 0;
    for (int i = 0; i < tam; i++) {
        if (arr[i] == x) {
            contador = contador + 1;
        }
    }
    return contador;
}

int main() {
    int tam, x;
    cout << "Ingrese el numero de registros: ";
    cin >> tam;

    int* arr = new int[tam];
    for (int i = 0; i < tam; i++) {
        cout << "Registro " << i << ": ";
        cin >> arr[i];
    }

    cout << "Ingrese el codigo de error a rastrear (x): ";
    cin >> x;

    cout << "El codigo " << x << " se repite " << cuentaRepeticiones(arr, x, tam) << " veces." << endl;

    delete[] arr;
    return 0;
}
