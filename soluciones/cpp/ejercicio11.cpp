/*
 * Ejercicio 11 - Nivel Intermedio
 * Llenar un vector de 20 elementos e imprimir la posicion y el valor del mayor.
 */
#include <iostream>
using namespace std;

void encontrarMayor(int arr[], int tam) {
    int mayor = arr[0];
    int posicion = 0;
    for (int i = 1; i < tam; i++) {
        if (arr[i] > mayor) {
            mayor = arr[i];
            posicion = i;
        }
    }
    cout << "El elemento mayor es: " << mayor << endl;
    cout << "Se encuentra en la posicion: " << posicion << endl;
}

int main() {
    int tam = 20;
    int* arr = new int[tam];
    for (int i = 0; i < tam; i++) {
        cout << "Ingrese el elemento " << i << ": ";
        cin >> arr[i];
    }
    encontrarMayor(arr, tam);

    delete[] arr;
    return 0;
}
