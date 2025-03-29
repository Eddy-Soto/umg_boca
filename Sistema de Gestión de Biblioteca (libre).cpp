#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Libro {
    string titulo;
    string autor;
    int anio;
};

void mostrarLibros(const vector<Libro>& biblioteca) {
    if (biblioteca.empty()) {
        cout << "\nLa biblioteca esta vacia." << endl;
        return;
    }
    cout << "\n--- Lista de Libros ---" << endl;
    for (size_t i = 0; i < biblioteca.size(); ++i) {
        cout << "Libro " << i+1 << ":\n";
        cout << "Titulo: " << biblioteca[i].titulo << endl;
        cout << "Autor: " << biblioteca[i].autor << endl;
        cout << "Año: " << biblioteca[i].anio << "\n" << endl;
    }
}

void buscarLibro(const vector<Libro>& biblioteca, const string& busqueda) {
    bool encontrado = false;
    for (const auto& libro : biblioteca) {
        if (libro.titulo.find(busqueda) != string::npos || libro.autor.find(busqueda) != string::npos) {
            cout << "Titulo: " << libro.titulo << endl;
            cout << "Autor: " << libro.autor << endl;
            cout << "Año: " << libro.anio << "\n" << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No se encontraron coincidencias." << endl;
    }
}

int main() {
    vector<Libro> biblioteca;
    int opcion;
    string entrada;

    do {
        cout << "\n--- Gestion de Biblioteca ---" << endl;
        cout << "1. Agregar libro" << endl;
        cout << "2. Mostrar todos los libros" << endl;
        cout << "3. Buscar libro (titulo/autor)" << endl;
        cout << "4. Eliminar libro" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer

        switch(opcion) {
            case 1: {
                Libro nuevoLibro;
                cout << "Ingrese el titulo: ";
                getline(cin, nuevoLibro.titulo);
                cout << "Ingrese el autor: ";
                getline(cin, nuevoLibro.autor);
                cout << "Ingrese el año: ";
                cin >> nuevoLibro.anio;
                biblioteca.push_back(nuevoLibro);
                cout << "Libro agregado exitosamente!" << endl;
                break;
            }
            case 2:
                mostrarLibros(biblioteca);
                break;
            case 3: {
                cout << "Ingrese titulo o autor a buscar: ";
                getline(cin, entrada);
                buscarLibro(biblioteca, entrada);
                break;
            }
            case 4: {
                if (biblioteca.empty()) {
                    cout << "La biblioteca esta vacia." << endl;
                    break;
                }
                int posicion;
                mostrarLibros(biblioteca);
                cout << "Ingrese el numero del libro a eliminar: ";
                cin >> posicion;
                if (posicion > 0 && posicion <= biblioteca.size()) {
                    biblioteca.erase(biblioteca.begin() + posicion - 1);
                    cout << "Libro eliminado." << endl;
                } else {
                    cout << "Posicion invalida." << endl;
                }
                break;
            }
            case 5:
                cout << "¡Hasta luego!" << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
    } while (opcion != 5);

    return 0;
}
