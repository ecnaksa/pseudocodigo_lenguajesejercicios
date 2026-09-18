/*
 * Problema 25 - Particion Pares/Impares en Vector
 * Primero los valores de indices pares, luego los de indices impares, en un vector auxiliar.
 */
#include <iostream>
using namespace std;

void particiona(int arr[], int tam, int res[]) {
    int k = 0;
    for (int i = 0; i < tam; i++) {
        if (i % 2 == 0) {
            res[k] = arr[i];
            k = k + 1;
        }
    }
    for (int i = 0; i < tam; i++) {
        if (i % 2 != 0) {
            res[k] = arr[i];
            k = k + 1;
        }
    }
}

int main() {
    int tam;
    cout << "Ingrese el tamano del vector: ";
    cin >> tam;

    int* arr = new int[tam];
    int* res = new int[tam];
    for (int i = 0; i < tam; i++) {
        cout << "Dato " << i << ": ";
        cin >> arr[i];
    }

    particiona(arr, tam, res);

    cout << "Vector particionado (pares | impares): ";
    for (int i = 0; i < tam; i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    delete[] arr;
    delete[] res;
    return 0;
}
