/*
 * Problema 17 - Desplazamiento Lineal de Buffer FIFO
 * void desplazaFIFO(double Arr[], int tam, double nueva)
 * Mueve todo una posicion a la derecha (recorriendo DESDE EL FINAL) e inserta 'nueva' en Arr[0].
 */
#include <iostream>
#include <iomanip>
using namespace std;

void desplazaFIFO(double arr[], int tam, double nueva) {
    for (int i = tam - 1; i >= 1; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = nueva;
}

int main() {
    int tam;
    cout << "Ingrese el tamano del buffer: ";
    cin >> tam;

    double* arr = new double[tam];
    for (int i = 0; i < tam; i++) {
        cout << "Registro " << i << ": ";
        cin >> arr[i];
    }

    double nueva;
    cout << "Nueva lectura a insertar: ";
    cin >> nueva;

    desplazaFIFO(arr, tam, nueva);

    cout << fixed << setprecision(2);
    cout << "Buffer tras el desplazamiento: ";
    for (int i = 0; i < tam; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}
