/*
 * Ejercicio 04 - Nivel Basico
 * int buscaElemento(int Arr[], int x, int tam)
 * Busca x y regresa su posicion, o -1 si no se encuentra.
 */
#include <iostream>
using namespace std;

int buscaElemento(int arr[], int x, int tam) {
    for (int i = 0; i < tam; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
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

    cout << "Ingrese el elemento a buscar: ";
    cin >> x;

    int pos = buscaElemento(arr, x, tam);
    if (pos < 0) {
        cout << "No existe elemento coincidente." << endl;
    } else {
        cout << "La posicion del elemento es: " << pos << endl;
    }

    delete[] arr;
    return 0;
}
