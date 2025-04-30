#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

// Estructura para almacenar información de las palabras
struct Palabra {
    string palabra;
    string traduccion;
    string funcionalidad;
};

// Función para cargar las palabras desde el archivo
vector<Palabra> cargarPalabras(const string& nombreArchivo) {
    vector<Palabra> palabras;
    ifstream archivo(nombreArchivo);
    
    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            istringstream iss(linea);
            Palabra p;
            if (getline(iss, p.palabra, '|') && getline(iss, p.traduccion, '|') && getline(iss, p.funcionalidad)) {
                palabras.push_back(p);
            }
        }
        archivo.close();
    }
    
    return palabras;
}

// Función para guardar las palabras en el archivo
void guardarPalabras(const vector<Palabra>& palabras, const string& nombreArchivo) {
    ofstream archivo(nombreArchivo);
    
    if (archivo.is_open()) {
        for (const auto& p : palabras) {
            archivo << p.palabra << "|" << p.traduccion << "|" << p.funcionalidad << endl;
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo para escritura." << endl;
    }
}

// Función para crear una palabra nueva
void crearPalabra(vector<Palabra>& palabras, const string& nombreArchivo) {
    Palabra nuevaPalabra;
    
    cout << "Ingrese Palabra: ";
    cin >> nuevaPalabra.palabra;
    
    // Verificar si la palabra ya existe
    auto it = find_if(palabras.begin(), palabras.end(), [&](const Palabra& p) {
        return p.palabra == nuevaPalabra.palabra;
    });
    
    if (it != palabras.end()) {
        cout << "La palabra ya existe en el diccionario." << endl;
        return;
    }
    
    cout << "Ingrese Traduccion: ";
    cin >> nuevaPalabra.traduccion;
    
    cout << "Ingrese Funcionalidad: ";
    cin.ignore(); // Limpiar el buffer
    getline(cin, nuevaPalabra.funcionalidad);
    
    palabras.push_back(nuevaPalabra);
    guardarPalabras(palabras, nombreArchivo);
    cout << "Palabra agregada correctamente." << endl;
}

// Función para leer una palabra
void leerPalabra(const vector<Palabra>& palabras) {
    string palabraBuscar;
    cout << "Ingrese la palabra a buscar: ";
    cin >> palabraBuscar;
    
    auto it = find_if(palabras.begin(), palabras.end(), [&](const Palabra& p) {
        return p.palabra == palabraBuscar;
    });
    
    if (it != palabras.end()) {
        cout << "Palabra: " << it->palabra << endl;
        cout << "Traduccion: " << it->traduccion << endl;
        cout << "Funcionalidad: " << it->funcionalidad << endl;
    } else {
        cout << "La palabra no existe en el diccionario." << endl;
    }
}

// Función para actualizar una palabra
void actualizarPalabra(vector<Palabra>& palabras, const string& nombreArchivo) {
    string palabraBuscar;
    cout << "Ingrese la palabra a actualizar: ";
    cin >> palabraBuscar;
    
    auto it = find_if(palabras.begin(), palabras.end(), [&](const Palabra& p) {
        return p.palabra == palabraBuscar;
    });
    
    if (it != palabras.end()) {
        cout << "Palabra actual: " << it->palabra << endl;
        cout << "Traduccion actual: " << it->traduccion << endl;
        cout << "Funcionalidad actual: " << it->funcionalidad << endl;
        
        cout << "Ingrese nueva traduccion (deje en blanco para mantener la actual): ";
        string nuevaTraduccion;
        cin.ignore();
        getline(cin, nuevaTraduccion);
        if (!nuevaTraduccion.empty()) {
            it->traduccion = nuevaTraduccion;
        }
        
        cout << "Ingrese nueva funcionalidad (deje en blanco para mantener la actual): ";
        string nuevaFuncionalidad;
        getline(cin, nuevaFuncionalidad);
        if (!nuevaFuncionalidad.empty()) {
            it->funcionalidad = nuevaFuncionalidad;
        }
        
        guardarPalabras(palabras, nombreArchivo);
        cout << "Palabra actualizada correctamente." << endl;
    } else {
        cout << "La palabra no existe en el diccionario." << endl;
    }
}

// Función para borrar una palabra
void borrarPalabra(vector<Palabra>& palabras, const string& nombreArchivo) {
    string palabraBorrar;
    cout << "Ingrese la palabra a borrar: ";
    cin >> palabraBorrar;
    
    auto it = find_if(palabras.begin(), palabras.end(), [&](const Palabra& p) {
        return p.palabra == palabraBorrar;
    });