/*
 * Problema 08 - Umbral de Disipacion Termica Media
 * 5 temperaturas: media, cuantas la superan y la lista de esas.
 */
#include <iostream>
#include <iomanip>
using namespace std;

void umbralMedia(double arr[], int tam) {
    double suma = 0.0;
    for (int i = 0; i < tam; i++) {
        suma = suma + arr[i];
    }
    double media = suma / tam;
    cout << fixed << setprecision(2);
    cout << "Temperatura media (umbral): " << media << endl;

    int cuenta = 0;
    cout << "Sensores por encima del umbral:" << endl;
    for (int i = 0; i < tam; i++) {
        if (arr[i] > media) {
            cuenta = cuenta + 1;
            cout << "  sensor " << i << " = " << arr[i] << endl;
        }
    }
    cout << "Cantidad que supera el umbral: " << cuenta << endl;
}

int main() {
    int tam = 5;
    double* arr = new double[tam];
    for (int i = 0; i < tam; i++) {
        cout << "Temperatura del sensor " << i << " (C): ";
        cin >> arr[i];
    }
    umbralMedia(arr, tam);

    delete[] arr;
    return 0;
}
