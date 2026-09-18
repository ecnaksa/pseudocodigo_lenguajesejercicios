/*
 * Problema 30 - Transposicion de Matriz de Admitancias
 * Devuelve la transpuesta M x N:  Trans[j][i] = Mat[i][j].
 */
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

vector<vector<double>> transpone(const vector<vector<double>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<double>> trans(m, vector<double>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            trans[j][i] = mat[i][j];
        }
    }
    return trans;
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

    vector<vector<double>> trans = transpone(mat);

    cout << fixed << setprecision(2);
    cout << "Matriz transpuesta (" << m << " x " << n << "):" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << trans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
