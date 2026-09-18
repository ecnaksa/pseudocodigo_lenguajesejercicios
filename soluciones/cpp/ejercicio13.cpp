/*
 * Ejercicio 13 - Nivel Avanzado
 * bool esPalindromo(int Arr[], int tam)
 * Determina si un arreglo es simetrico (se lee igual en ambos sentidos).
 */
#include <iostream>
using namespace std;   /* En C++ bool, true y false son parte del lenguaje. */

bool esPalindromo(int arr[], int tam) {
    for (int i = 0; i < tam / 2; i++) {
        if (arr[i] != arr[tam - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int tam;
    cout << "Ingrese el tamano del arreglo: ";
    cin >> tam;

    int* arr = new int[tam];
    for (int i = 0; i < tam; i++) {
        cout << "Ingrese el elemento " << i << ": ";
        cin >> arr[i];
    }

    if (esPalindromo(arr, tam)) {
        cout << "El arreglo es simetrico (palindromo)." << endl;
    } else {
        cout << "El arreglo NO es simetrico." << endl;
    }

    delete[] arr;
    return 0;
}
