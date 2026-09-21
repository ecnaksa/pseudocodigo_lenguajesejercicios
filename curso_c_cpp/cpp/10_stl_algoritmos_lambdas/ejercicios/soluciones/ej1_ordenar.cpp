/* Ejercicio 1 - Ordenar un vector con sort. */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {42, 7, 19, 3, 88, 25};
    sort(v.begin(), v.end());
    for (int x : v) cout << x << " ";     // 3 7 19 25 42 88
    cout << endl;
    return 0;
}
