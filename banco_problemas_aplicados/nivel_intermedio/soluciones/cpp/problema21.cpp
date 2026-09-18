/*
 * Problema 21 - Pico Maximo y Su Indice Modular
 * En C++ el indice se entrega por REFERENCIA (int &pos): la funcion escribe directamente
 * en la variable de main. El valor pico se retorna normal.
 */
#include <iostream>
#include <iomanip>
using namespace std;

double picoMaximo(double arr[], int tam, int &pos) {
    double mayor = arr[0];
    pos = 0;
    for (int i = 1; i < tam; i++) {
        if (arr[i] > mayor) {
            mayor = arr[i];
            pos = i;
        }
    }
    return mayor;
}

int main() {
    int tam = 20;
    double* arr = new double[tam];
    for (int i = 0; i < tam; i++) {
        cout << "Muestra " << i << ": ";
        cin >> arr[i];
    }

    int posicion;
    double valor = picoMaximo(arr, tam, posicion);
    cout << fixed << setprecision(2);
    cout << "Pico maximo: " << valor << endl;
    cout << "Indice de muestreo: " << posicion << endl;

    delete[] arr;
    return 0;
}
