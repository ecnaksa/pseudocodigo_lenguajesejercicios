/*
 * Problema 11 - Deteccion de Pico Maximo Absoluto
 * 15 muestras (valores unicos): imprimir el valor maximo y su posicion.
 */
#include <iostream>
#include <iomanip>
using namespace std;

void picoMaximo(double arr[], int tam) {
    double mayor = arr[0];
    int posicion = 0;
    for (int i = 1; i < tam; i++) {
        if (arr[i] > mayor) {
            mayor = arr[i];
            posicion = i;
        }
    }
    cout << fixed << setprecision(2);
    cout << "Pico maximo: " << mayor << endl;
    cout << "Posicion (indice) del pico: " << posicion << endl;
}

int main() {
    int tam = 15;
    double* arr = new double[tam];
    for (int i = 0; i < tam; i++) {
        cout << "Muestra " << i << " (V): ";
        cin >> arr[i];
    }
    picoMaximo(arr, tam);

    delete[] arr;
    return 0;
}
