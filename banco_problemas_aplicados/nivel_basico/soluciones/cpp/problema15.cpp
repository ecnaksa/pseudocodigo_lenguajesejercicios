/*
 * Problema 15 - Conteo de Muestras Saturadas (Overflow)
 * int cuentaSaturadas(int Arr[], int tam)  -> cuenta cuantas valen 1023 (ADC de 10 bits)
 */
#include <iostream>
using namespace std;

int cuentaSaturadas(int arr[], int tam) {
    int contador = 0;
    for (int i = 0; i < tam; i++) {
        if (arr[i] == 1023) {
            contador = contador + 1;
        }
    }
    return contador;
}

int main() {
    int tam;
    cout << "Ingrese el numero de conversiones: ";
    cin >> tam;

    int* arr = new int[tam];
    for (int i = 0; i < tam; i++) {
        cout << "Conversion " << i << " (0..1023): ";
        cin >> arr[i];
    }

    cout << "Muestras saturadas (== 1023): " << cuentaSaturadas(arr, tam) << endl;

    delete[] arr;
    return 0;
}
