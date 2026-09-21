/* Ejercicio 4 (reto) - Agenda con map<string,string>. */
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, string> agenda;
    agenda["Ana"] = "555-1234";
    agenda["Luis"] = "555-5678";
    agenda["Sara"] = "555-9012";

    cout << "Contactos:\n";
    for (const auto &par : agenda) {
        cout << "  " << par.first << ": " << par.second << endl;
    }

    string quien = "Luis";
    if (agenda.count(quien)) {
        cout << "Telefono de " << quien << ": " << agenda[quien] << endl;
    } else {
        cout << quien << " no esta en la agenda\n";
    }
    return 0;
}
