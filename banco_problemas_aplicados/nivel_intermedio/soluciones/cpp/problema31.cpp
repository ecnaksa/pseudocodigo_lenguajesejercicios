/*
 * Problema 31 - Busqueda de Fila con Mayor Consumo
 * Devuelve el indice de la fila cuya suma es la mayor.
 */
#include <iostream>
#include <vector>
using namespace std;

int filaMayorConsumo(const vector<vector<double>>& mat) {
    int filaMax = 0;
    double mayorSuma = 0.0;
    for (size_t j = 0; j < mat[0].size(); j++) {
        mayorSuma = mayorSuma + mat[0][j];
    }
    for (size_t i = 1; i < mat.size(); i++) {
        double suma = 0.0;
        for (size_t j = 0; j < mat[i].size(); j++) {
            suma = suma + mat[i][j];
        }
        if (suma > mayorSuma) {
            mayorSuma = suma;
            filaMax = (int) i;
        }
    }
    return filaMax;
}

int main() {
    int n, m;
    cout << "Numero de buses/filas (N): ";
    cin >> n;
    cout << "Numero de columnas (M): ";
    cin >> m;

    vector<vector<double>> mat(n, vector<double>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "mat[" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }

    cout << "La fila con mayor consumo es la " << filaMayorConsumo(mat) << "." << endl;
    return 0;
}
