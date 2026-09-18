/*
 * Ejercicio 10 - Nivel Intermedio
 * Multiplicar A y B "cruzados": C[i] = A[i] * B[tam-1-i], guardando de izq. a der.
 */
#include <iostream>
using namespace std;

void multiplicarVectores(int tam, int A[], int B[], int C[]) {
    for (int i = 0; i < tam; i++) {
        C[i] = A[i] * B[tam - 1 - i];
    }
    cout << "Vector C (resultado del cruce A * B):" << endl;
    for (int i = 0; i < tam; i++) {
        cout << "C[" << i << "] = " << C[i] << endl;
    }
}

int main() {
    int tam = 10;
    int* A = new int[tam];
    int* B = new int[tam];
    int* C = new int[tam];
    for (int i = 0; i < tam; i++) {
        cout << "Ingrese el elemento " << i << " de A: ";
        cin >> A[i];
        cout << "Ingrese el elemento " << i << " de B: ";
        cin >> B[i];
    }
    multiplicarVectores(tam, A, B, C);

    delete[] A;
    delete[] B;
    delete[] C;
    return 0;
}
