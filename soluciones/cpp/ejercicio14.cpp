/*
 * Ejercicio 14 - Nivel Avanzado
 * void ordenaBurbuja(int Arr[], int tam)
 * Ordena el arreglo de forma ascendente con el metodo de la burbuja.
 */
#include <iostream>
using namespace std;

void ordenaBurbuja(int arr[], int tam) {
    for (int i = 0; i < tam; i++) {
        for (int f = 0; f < tam - 1 - i; f++) {
            if (arr[f] > arr[f + 1]) {
                int aux = arr[f];
                arr[f] = arr[f + 1];
                arr[f + 1] = aux;
            }
        }
    }
}

int main() {
    int tam = 5;
    int* arr = new int[tam];
    for (int i = 0; i < tam; i++) {
        cout << "Ingrese el elemento " << i << ": ";
        cin >> arr[i];
    }

    ordenaBurbuja(arr, tam);

    cout << "El arreglo ordenado es: ";
    for (int i = 0; i < tam; i++) {
        /* "Escribir sin saltar": se usa << sin endl para no bajar de linea. */
        cout << arr[i] << " ";
    }
    cout << endl;   /* Un unico salto de linea al final. */

    delete[] arr;
    return 0;
}
