/*
 * Proyecto final de la pista C++: Sistema de biblioteca por consola.
 * Integra: clases y encapsulamiento (POO), std::vector, std::string, referencias,
 * bucles/condicionales y un menu.
 *
 * Compilar: g++ -std=c++17 -Wall -Wextra biblioteca.cpp -o biblioteca
 * Ejecutar: ./biblioteca
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// --------- Clase Libro: representa un libro y encapsula su estado ---------
class Libro {
private:
    string titulo;
    string autor;
    bool disponible;

public:
    Libro(const string &t, const string &a) : titulo(t), autor(a), disponible(true) {}

    string getTitulo() const { return titulo; }
    string getAutor()  const { return autor; }
    bool estaDisponible() const { return disponible; }

    void prestar()  { disponible = false; }
    void devolver() { disponible = true; }

    void mostrar() const {
        cout << "  \"" << titulo << "\" - " << autor
             << " [" << (disponible ? "disponible" : "prestado") << "]" << endl;
    }
};

// --------- Clase Biblioteca: gestiona la coleccion de libros ---------
class Biblioteca {
private:
    vector<Libro> libros;

    // Devuelve el indice de un libro por titulo, o -1 si no existe.
    int indicePorTitulo(const string &titulo) const {
        for (size_t i = 0; i < libros.size(); i++) {
            if (libros[i].getTitulo() == titulo) return (int) i;
        }
        return -1;
    }

public:
    void agregar(const string &titulo, const string &autor) {
        libros.push_back(Libro(titulo, autor));
        cout << "Libro agregado. Total: " << libros.size() << endl;
    }

    void listar() const {
        if (libros.empty()) { cout << "(no hay libros)\n"; return; }
        cout << "--- " << libros.size() << " libro(s) ---\n";
        for (const Libro &l : libros) l.mostrar();
    }

    void prestarPorTitulo(const string &titulo) {
        int i = indicePorTitulo(titulo);
        if (i < 0) { cout << "No existe ese titulo.\n"; return; }
        if (!libros[i].estaDisponible()) { cout << "Ya esta prestado.\n"; return; }
        libros[i].prestar();
        cout << "Prestado: " << titulo << endl;
    }

    void devolverPorTitulo(const string &titulo) {
        int i = indicePorTitulo(titulo);
        if (i < 0) { cout << "No existe ese titulo.\n"; return; }
        libros[i].devolver();
        cout << "Devuelto: " << titulo << endl;
    }

    void buscarPorAutor(const string &autor) const {
        int encontrados = 0;
        for (const Libro &l : libros) {
            if (l.getAutor() == autor) { l.mostrar(); encontrados++; }
        }
        if (encontrados == 0) cout << "Sin libros de ese autor.\n";
    }

    void estadisticas() const {
        int disponibles = 0;
        for (const Libro &l : libros) if (l.estaDisponible()) disponibles++;
        cout << "Total: " << libros.size()
             << " | Disponibles: " << disponibles
             << " | Prestados: " << (libros.size() - disponibles) << endl;
    }
};

// --------- Utilidad: leer una linea completa ---------
string leerLinea(const string &prompt) {
    cout << prompt;
    string s;
    getline(cin, s);
    return s;
}

int main() {
    Biblioteca biblio;
    int opcion;

    do {
        cout << "\n== BIBLIOTECA ==\n"
             << "1) Agregar  2) Listar  3) Prestar  4) Devolver\n"
             << "5) Buscar por autor  6) Estadisticas  0) Salir\n"
             << "Opcion: ";
        if (!(cin >> opcion)) break;      // fin de entrada
        cin.ignore();                     // descarta el '\n' tras el numero

        switch (opcion) {
            case 1: {
                string t = leerLinea("Titulo: ");
                string a = leerLinea("Autor: ");
                biblio.agregar(t, a);
                break;
            }
            case 2: biblio.listar(); break;
            case 3: biblio.prestarPorTitulo(leerLinea("Titulo a prestar: ")); break;
            case 4: biblio.devolverPorTitulo(leerLinea("Titulo a devolver: ")); break;
            case 5: biblio.buscarPorAutor(leerLinea("Autor: ")); break;
            case 6: biblio.estadisticas(); break;
            case 0: cout << "Hasta luego.\n"; break;
            default: cout << "Opcion invalida.\n";
        }
    } while (opcion != 0);

    return 0;
}
