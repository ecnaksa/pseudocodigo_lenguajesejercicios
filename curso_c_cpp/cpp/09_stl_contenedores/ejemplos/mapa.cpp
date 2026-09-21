/*
 * std::map: diccionario clave -> valor. Aqui contamos palabras.
 */
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, int> edades;
    edades["Ana"] = 25;
    edades["Luis"] = 30;
    edades["Sara"] = 19;

    cout << "Edad de Ana: " << edades["Ana"] << endl;

    cout << "Todos (ordenados por clave):\n";
    for (const auto &par : edades) {
        cout << "  " << par.first << " -> " << par.second << endl;
    }

    if (edades.count("Luis")) cout << "Luis esta en el mapa\n";
    if (!edades.count("Pedro")) cout << "Pedro NO esta\n";
    return 0;
}
