/*
 * Problema 36 - Concatenacion Segura de Dos Buffers
 * Une A y B en C (de tamano nA + nB), copiando secuencialmente.
 */
#include <iostream>
using namespace std;

void concatena(int A[], int nA, int B[], int nB, int C[]) {
    int k = 0;
    for (int i = 0; i < nA; i++) {
        C[k] = A[i];
        k = k + 1;
    }
    for (int i = 0; i < nB; i++) {
        C[k] = B[i];
        k = k + 1;
    }
}

int main() {
    int nA, nB;
    cout << "Tamano del Vector 1: ";
    cin >> nA;
    int* A = new int[nA];
    for (int i = 0; i < nA; i++) {
        cout << "A[" << i << "]: ";
        cin >> A[i];
    }

    cout << "Tamano del Vector 2: ";
    cin >> nB;
    int* B = new int[nB];
    for (int i = 0; i < nB; i++) {
        cout << "B[" << i << "]: ";
        cin >> B[i];
    }

    int* C = new int[nA + nB];
    concatena(A, nA, B, nB, C);

    cout << "Vector combinado (" << (nA + nB) << " elementos): ";
    for (int i = 0; i < nA + nB; i++) {
        cout << C[i] << " ";
    }
    cout << endl;

    delete[] A;
    delete[] B;
    delete[] C;
    return 0;
}
