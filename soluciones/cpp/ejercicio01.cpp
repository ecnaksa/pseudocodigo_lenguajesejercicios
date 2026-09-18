/*
 * Ejercicio 01 - Nivel Basico
 * int sumaElementos(int Arr[], int tam)
 * Recibe un arreglo de enteros y regresa el resultado de sumar todos sus elementos.
 */
#include <iostream>
using namespace std;

int sumaElementos(int arr[], int tam) {
    int suma = 0;
    for (int i = 0; i < tam; i++) {
        suma = suma + arr[i];
    }
    return suma;
}

int main() {
    int tam;
    cout << "Ingrese el tamano del arreglo: ";
    cin >> tam;

    /* Reserva dinamica: se pide memoria para 'tam' enteros en tiempo de ejecucion. */
    int* arr = new int[tam];
    for (int i = 0; i < tam; i++) {
        cout << "Ingrese el elemento " << i << ": ";
        cin >> arr[i];
    }

    cout << "La suma de los elementos del arreglo es: " << sumaElementos(arr, tam) << endl;

    delete[] arr;   /* Se libera la memoria reservada con new[]. */
    return 0;
}
