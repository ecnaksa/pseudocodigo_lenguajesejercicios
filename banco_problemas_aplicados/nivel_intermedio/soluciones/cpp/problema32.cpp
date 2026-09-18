/*
 * Problema 32 - Conteo de Nodos con Voltaje Critico
 * Cuenta cuantas celdas de la matriz superan un umbral.
 */
#include <iostream>
#include <vector>
using namespace std;

int cuentaCriticos(const vector<vector<double>>& mat, double umbral) {
    int contador = 0;
    for (size_t i = 0; i < mat.size(); i++) {
        for (size_t j = 0; j < mat[i].size(); j++) {
            if (mat[i][j] > umbral) {
                contador = contador + 1;
            }
        }
    }
    return contador;
}

int main() {
    int n, m;
    double umbral;
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

    cout << "Umbral critico de sobretension: ";
    cin >> umbral;

    cout << "Nodos que superan el umbral: " << cuentaCriticos(mat, umbral) << endl;
    return 0;
}
