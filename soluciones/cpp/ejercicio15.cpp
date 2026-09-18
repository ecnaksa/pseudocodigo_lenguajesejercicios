/*
 * Ejercicio 15 - Nivel Avanzado
 * int eliminaDuplicados(int Arr[], int tam)
 * Remueve los elementos duplicados y devuelve el nuevo tamano logico.
 */
#include <iostream>
using namespace std;

int eliminaDuplicados(int arr[], int tam) {
    for (int i = 0; i < tam; i++) {
        for (int j = i + 1; j < tam; j++) {
            if (arr[i] == arr[j]) {
                for (int k = j; k < tam - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                tam = tam - 1;
                j = j - 1;
            }
        }
    }
    return tam;
}

int main() {
    int tam = 8;
    int* arr = new int[tam];
    for (int i = 0; i < tam; i++) {
        cout << "Ingrese el elemento " << i << ": ";
        cin >> arr[i];
    }

    int ntam = eliminaDuplicados(arr, tam);

    cout << "Arreglo sin duplicados (" << ntam << " elementos): ";
    for (int i = 0; i < ntam; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}
