/*
 * Problema 10 - Multiplicacion Cruzada Inversa en Retardos
 * C[i] = A[i] * B[tam-1-i]  (vectores de 10)
 */
#include <iostream>
#include <iomanip>
using namespace std;

void multCruzada(int tam, double A[], double B[], double C[]) {
    for (int i = 0; i < tam; i++) {
        C[i] = A[i] * B[tam - 1 - i];
    }
    cout << fixed << setprecision(2);
    cout << "Vector resultante C (cruce A * B):" << endl;
    for (int i = 0; i < tam; i++) {
        cout << "C[" << i << "] = " << C[i] << endl;
    }
}

int main() {
    int tam = 10;
    double* A = new double[tam];
    double* B = new double[tam];
    double* C = new double[tam];
    for (int i = 0; i < tam; i++) {
        cout << "A[" << i << "]: ";
        cin >> A[i];
        cout << "B[" << i << "]: ";
        cin >> B[i];
    }
    multCruzada(tam, A, B, C);

    delete[] A;
    delete[] B;
    delete[] C;
    return 0;
}
