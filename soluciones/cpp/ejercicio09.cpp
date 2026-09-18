/*
 * Ejercicio 09 - Nivel Intermedio
 * Llenar dos vectores A y B de 5 elementos, sumar elemento a elemento
 * (C[i] = A[i] + B[i]) e imprimir el vector C.
 */
#include <iostream>
using namespace std;

void sumarVectores(int A[], int B[], int C[], int tam) {
    for (int i = 0; i < tam; i++) {
        C[i] = A[i] + B[i];
    }
    cout << "Vector C (resultado A + B):" << endl;
    for (int i = 0; i < tam; i++) {
        cout << "C[" << i << "] = " << C[i] << endl;
    }
}

int main() {
    int tam = 5;
    int* A = new int[tam];
    int* B = new int[tam];
    int* C = new int[tam];
    for (int i = 0; i < tam; i++) {
        cout << "Ingrese el elemento " << i << " de A: ";
        cin >> A[i];
        cout << "Ingrese el elemento " << i << " de B: ";
        cin >> B[i];
    }
    sumarVectores(A, B, C, tam);

    delete[] A;
    delete[] B;
    delete[] C;
    return 0;
}
