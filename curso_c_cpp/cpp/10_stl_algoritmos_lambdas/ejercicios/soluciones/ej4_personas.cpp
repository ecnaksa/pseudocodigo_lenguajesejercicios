/* Ejercicio 4 (reto) - Ordenar personas por edad con lambda. */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    vector<pair<string, int>> personas = {
        {"Ana", 30}, {"Luis", 22}, {"Sara", 27}, {"Beto", 19}
    };

    // ordenar por edad (el segundo campo del pair)
    sort(personas.begin(), personas.end(), [](const pair<string,int> &a,
                                              const pair<string,int> &b) {
        return a.second < b.second;
    });

    for (const auto &p : personas) {
        cout << p.first << " (" << p.second << ")" << endl;
    }
    return 0;
}
