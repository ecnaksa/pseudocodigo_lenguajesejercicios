/*
 * Problema 26 - Desplazamiento Circular de Muestras
 * void rotaDerecha(double Arr[], int tam, int k)  -> rota a la derecha K posiciones (ciclico).
 */
#include <iostream>
#include <iomanip>
using namespace std;

void rotaDerecha(double arr[], int tam, int k) {
    k = k % tam;
    double* aux = new double[tam];
    for (int i = 0; i < tam; i++) {
        aux[(i + k) % tam] = arr[i];
    }
    for (int i = 0; i < tam; i++) {
        arr[i] = aux[i];
    }
    delete[] aux;
}

int main() {
    int tam, k;
    cout << "Ingrese el numero de muestras: ";
    cin >> tam;

    double* arr = new double[tam];
    for (int i = 0; i < tam; i++) {
        cout << "Muestra " << i << ": ";
        cin >> arr[i];
    }

    cout << "Ingrese K (posiciones a rotar a la derecha): ";
    cin >> k;

    rotaDerecha(arr, tam, k);

    cout << fixed << setprecision(2);
    cout << "Buffer desplazado: ";
    for (int i = 0; i < tam; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}
