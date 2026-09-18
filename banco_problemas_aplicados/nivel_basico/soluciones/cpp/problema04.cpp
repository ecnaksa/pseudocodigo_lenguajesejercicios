/*
 * Problema 04 - Codigo de Error en Buffer
 * int buscaElemento(int Arr[], int x, int tam)  -> posicion de x, o -1
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
    cout << "Ingrese el tamano del buffer: ";
    cin >> tam;

    int* arr = new int[tam];
    for (int i = 0; i < tam; i++) {
        cout << "Estado " << i << ": ";
        cin >> arr[i];
    }

    cout << "Ingrese el codigo de falla a buscar: ";
    cin >> x;

    int pos = buscaElemento(arr, x, tam);
    if (pos < 0) {
        cout << "El codigo " << x << " no aparece en el buffer." << endl;
    } else {
        cout << "El codigo " << x << " esta en la posicion: " << pos << endl;
    }

    delete[] arr;
    return 0;
}
