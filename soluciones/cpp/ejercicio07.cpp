/*
 * Ejercicio 07 - Nivel Intermedio
 * Almacenar 10 numeros enteros. Imprimir cuantos son ceros, negativos y positivos,
 * ademas de la suma de los negativos y la suma de los positivos.
 */
#include <iostream>
using namespace std;

void analizarArreglo(int arr[], int tam) {
    int ceros = 0, pos = 0, neg = 0, spos = 0, sneg = 0;
    for (int i = 0; i < tam; i++) {
        if (arr[i] == 0) {
            ceros = ceros + 1;
        } else if (arr[i] < 0) {
            neg = neg + 1;
            sneg = sneg + arr[i];
        } else {
            pos = pos + 1;
            spos = spos + arr[i];
        }
    }
    cout << "Cantidad de ceros: " << ceros << endl;
    cout << "Cantidad de positivos: " << pos << endl;
    cout << "Cantidad de negativos: " << neg << endl;
    cout << "Suma de los positivos: " << spos << endl;
    cout << "Suma de los negativos: " << sneg << endl;
}

int main() {
    int tam = 10;
    int* arr = new int[tam];
    for (int i = 0; i < tam; i++) {
        cout << "Ingrese el elemento " << i << ": ";
        cin >> arr[i];
    }
    analizarArreglo(arr, tam);

    delete[] arr;
    return 0;
}
