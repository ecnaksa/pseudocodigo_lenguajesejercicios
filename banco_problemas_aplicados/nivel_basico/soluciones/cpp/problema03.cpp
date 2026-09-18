/*
 * Problema 03 - Deteccion de Transitorios Impares
 * int cuentaImpares(int Arr[], int tam)  -> cuenta muestras en INDICES impares (i % 2 != 0)
 * (condicion sobre el indice, no sobre el valor)
 */
#include <iostream>
using namespace std;

int cuentaImpares(int arr[], int tam) {
    (void) arr;  // el arreglo forma parte de la firma, aunque no se lea su contenido
    int contador = 0;
    for (int i = 0; i < tam; i++) {
        if (i % 2 != 0) {
            contador = contador + 1;
        }
    }
    return contador;
}

int main() {
    int tam;
    cout << "Ingrese el numero de muestras: ";
    cin >> tam;

    int* arr = new int[tam];
    for (int i = 0; i < tam; i++) {
        cout << "Muestra " << i << ": ";
        cin >> arr[i];
    }

    cout << "Muestras en indices impares: " << cuentaImpares(arr, tam) << endl;

    delete[] arr;
    return 0;
}
