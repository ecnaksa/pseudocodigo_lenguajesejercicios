/*
 * Problema 29 - Suma de Matriz de Nodos por Filas
 * En C++ una matriz dinamica se representa comodamente con vector<vector<double>>,
 * que lleva sus propias dimensiones (mat.size() filas, mat[i].size() columnas).
 * (Ver teoria/02_matrices_2d.md)
 */
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

vector<double> sumaFilas(const vector<vector<double>>& mat) {
    vector<double> res(mat.size());
    for (size_t i = 0; i < mat.size(); i++) {
        double suma = 0.0;
        for (size_t j = 0; j < mat[i].size(); j++) {
            suma = suma + mat[i][j];
        }
        res[i] = suma;
    }
    return res;
}

int main() {
    int n, m;
    cout << "Numero de filas (N): ";
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

    vector<double> res = sumaFilas(mat);

    cout << fixed << setprecision(2);
    cout << "Suma por filas:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "  fila " << i << " = " << res[i] << endl;
    }
    return 0;
}
