/*
 * Problema 18 - Comparacion de Dos Canales de Telemetria
 * bool sonIguales(int A[], int B[], int tam)  -> true si A y B son identicos elemento por elemento
 */
#include <iostream>
using namespace std;

bool sonIguales(int A[], int B[], int tam) {
    for (int i = 0; i < tam; i++) {
        if (A[i] != B[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int tam;
    cout << "Ingrese el tamano de los canales: ";
    cin >> tam;

    int* A = new int[tam];
    int* B = new int[tam];
    for (int i = 0; i < tam; i++) {
        cout << "Canal A, dato " << i << ": ";
        cin >> A[i];
        cout << "Canal B, dato " << i << ": ";
        cin >> B[i];
    }

    if (sonIguales(A, B, tam)) {
        cout << "Los dos canales son identicos." << endl;
    } else {
        cout << "Los canales difieren." << endl;
    }

    delete[] A;
    delete[] B;
    return 0;
}
