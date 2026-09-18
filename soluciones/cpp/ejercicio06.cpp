/*
 * Ejercicio 06 - Nivel Intermedio
 * int cuentaRepeticiones(int Arr[], int x, int tam)
 * Regresa el numero de veces que se repite el valor x dentro del arreglo.
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
    cout << "Ingrese el tamano del arreglo: ";
    cin >> tam;

    int* arr = new int[tam];
    for (int i = 0; i < tam; i++) {
        cout << "Ingrese el elemento " << i << ": ";
        cin >> arr[i];
    }

    cout << "Ingrese el valor a contar (x): ";
    cin >> x;

    cout << "El valor " << x << " se repite " << cuentaRepeticiones(arr, x, tam) << " veces." << endl;

    delete[] arr;
    return 0;
}
