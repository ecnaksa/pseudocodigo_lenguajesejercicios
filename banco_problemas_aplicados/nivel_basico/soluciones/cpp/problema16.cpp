/*
 * Problema 16 - Busqueda de Primer Flanco de Subida
 * int buscaFlanco(double Arr[], int tam)  -> primer i con Arr[i] < 0 y Arr[i+1] >= 0, o -1
 * El bucle llega hasta tam-2 porque se usa Arr[i+1].
 */
#include <iostream>
using namespace std;

int buscaFlanco(double arr[], int tam) {
    for (int i = 0; i < tam - 1; i++) {
        if (arr[i] < 0 && arr[i + 1] >= 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    int tam;
    cout << "Ingrese el numero de muestras: ";
    cin >> tam;

    double* arr = new double[tam];
    for (int i = 0; i < tam; i++) {
        cout << "Voltaje " << i << " (V): ";
        cin >> arr[i];
    }

    int idx = buscaFlanco(arr, tam);
    if (idx < 0) {
        cout << "No se detecto ningun flanco de subida." << endl;
    } else {
        cout << "Primer flanco de subida entre los indices " << idx << " y " << idx + 1 << "." << endl;
    }

    delete[] arr;
    return 0;
}
