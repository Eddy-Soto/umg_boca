#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

// Estructura para almacenar informaciÃ³n de las palabras
struct Palabra {
    string palabra;
    string traduccion;
    string funcionalidad;
};

// FunciÃ³n para cargar las palabras desde el archivo
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

// FunciÃ³n para guardar las palabras en el archivo
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

// FunciÃ³n para crear una palabra nueva
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

// FunciÃ³n para leer una palabra
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

// FunciÃ³n para actualizar una palabra
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

// FunciÃ³n para borrar una palabra
void borrarPalabra(vector<Palabra>& palabras, const string& nombreArchivo) {
    string palabraBorrar;
    cout << "Ingrese la palabra a borrar: ";
    cin >> palabraBorrar;
    
    auto it = find_if(palabras.begin(), palabras.end(), [&](const Palabra& p) {
        return p.palabra == palabraBorrar;
    });

    if (it != palabras.end()) {
        palabras.erase(it);
        guardarPalabras(palabras, nombreArchivo);
        cout << "Palabra borrada correctamente." << endl;
    } else {
        cout << "La palabra no existe en el diccionario." << endl;
    }
}

// Función para mostrar todas las palabras
void mostrarPalabras(const vector<Palabra>& palabras) {
    if (palabras.empty()) {
        cout << "El diccionario esta vacio." << endl;
        return;
    }
    
    cout << "Listado de palabras en el diccionario:" << endl;
    cout << "--------------------------------------" << endl;
    for (const auto& p : palabras) {
        cout << "Palabra: " << p.palabra << endl;
        cout << "Traduccion: " << p.traduccion << endl;
        cout << "Funcionalidad: " << p.funcionalidad << endl;
        cout << "--------------------------------------" << endl;
    }
}

// Fase II: Función para traducir código C++
void traducirCodigo(const vector<Palabra>& palabras) {
    cout << "Ingrese el codigo C++ a traducir (escriba 'FIN' en una línea nueva para terminar):" << endl;
    
    string linea;
    vector<string> codigoOriginal;
    
    cin.ignore(); // Limpiar el buffer
    while (true) {
        getline(cin, linea);
        if (linea == "FIN") break;
        codigoOriginal.push_back(linea);
    }
    
    // Crear un mapa para búsqueda más rápida
    map<string, string> diccionario;
    for (const auto& p : palabras) {
        diccionario[p.palabra] = p.traduccion;
    }
    
    // Analizar el código y traducirlo
    vector<string> codigoTraducido;
    bool dentroDeFuncion = false;
    vector<string> estructuraControl;
    
    for (const auto& linea : codigoOriginal) {
        string lineaTraducida = linea;
        
        // Buscar partes del código para traducir
        for (const auto& p : palabras) {
            // Buscar la palabra completa (no como parte de otra palabra)
            size_t pos = 0;
            while ((pos = lineaTraducida.find(p.palabra, pos)) != string::npos) {
                // Verificar que sea una palabra completa
                bool esPalabraCompleta = true;
                if (pos > 0 && isalnum(lineaTraducida[pos-1])) {
                    esPalabraCompleta = false;
                }
                size_t endPos = pos + p.palabra.length();
                if (endPos < lineaTraducida.length() && isalnum(lineaTraducida[endPos])) {
                    esPalabraCompleta = false;
                }
                
                if (esPalabraCompleta) {
                    lineaTraducida.replace(pos, p.palabra.length(), p.traduccion);
                    pos += p.traduccion.length();
                } else {
                    pos += p.palabra.length();
                }
            }
        }
        
        // Procesar llaves
        size_t posApertura = lineaTraducida.find("{");
        if (posApertura != string::npos) {
            // Buscar qué estructura de control precede a la llave
            string estructura = "";
            size_t posCierre = lineaTraducida.find(")", posApertura);
            if (posCierre != string::npos && posCierre < posApertura) {
                // Encontrar la estructura de control
                string sublinea = lineaTraducida.substr(0, posCierre);
                size_t posEstructura = sublinea.rfind("(");
                if (posEstructura != string::npos) {
                    size_t inicio = sublinea.rfind(" ", posEstructura);
                    if (inicio == string::npos) inicio = 0; else inicio++;
                    estructura = sublinea.substr(inicio, posEstructura - inicio);
                }
            }
            
            // Verificar si estamos dentro de una función
            if (estructura == "main" || lineaTraducida.find("()") != string::npos || 
                lineaTraducida.find("( )") != string::npos) {
                dentroDeFuncion = true;
            } else if (!estructura.empty()) {
                estructuraControl.push_back(estructura);
                lineaTraducida.replace(posApertura, 1, " inicio " + estructura);
            } else {
                // Puede ser el inicio de una función o método
                dentroDeFuncion = true;
            }
        }
        
        // Procesar cierre de llaves
        size_t posCierre = lineaTraducida.find("}");
        if (posCierre != string::npos) {
            if (!dentroDeFuncion && !estructuraControl.empty()) {
                string estructura = estructuraControl.back();
                estructuraControl.pop_back();
                lineaTraducida.replace(posCierre, 1, " fin " + estructura);
            }
        }
        
        // Si hay un punto y coma después de una llave, hay que mantenerlo
        if (lineaTraducida.find("};") != string::npos) {
            dentroDeFuncion = false;
        }
        
        codigoTraducido.push_back(lineaTraducida);
    }
    
    cout << "\nCodigo traducido:" << endl;
    cout << "----------------" << endl;
    for (const auto& linea : codigoTraducido) {
        cout << linea << endl;
    }
}
