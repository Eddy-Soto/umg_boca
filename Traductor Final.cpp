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

// Función para inicializar el archivo con las palabras predefinidas
void inicializarArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.good()) {
        vector<Palabra> palabrasPredefinidas = {
            {"asm", "asm", "Permite insertar código en lenguaje ensamblador."},
            {"auto", "auto", "Especificador de almacenamiento automático."},
            {"bool", "booleano", "Tipo de dato que puede tener valores true o false."},
            {"break", "romper", "Termina la ejecución de un bucle o switch."},
            {"case", "caso", "Etiqueta en una instrucción switch."},
            {"catch", "capturar", "Captura excepciones en bloques try."},
            {"char", "caracter", "Tipo de dato para caracteres."},
            {"class", "clase", "Define una clase."},
            {"const", "constante", "Define una variable de solo lectura."},
            {"const_cast", "conversion_constante", "Operador de conversión que quita la constancia."},
            {"continue", "continuar", "Salta a la siguiente iteración de un bucle."},
            {"default", "defecto", "Caso por defecto en una estructura switch."},
            {"delete", "eliminar", "Libera memoria dinámica."},
            {"do", "hacer", "Inicia un bucle do-while."},
            {"double", "doble", "Tipo de dato de punto flotante de doble precisión."},
            {"dynamic_cast", "conversion_dinamica", "Operador de conversión en tiempo de ejecución."},
            {"else", "entonces", "Parte alternativa de una estructura if."},
            {"enum", "enumeracion", "Define un tipo de enumeración."},
            {"explicit", "explicito", "Especifica que un constructor no se puede usar para conversiones implícitas."},
            {"extern", "externo", "Declara una variable definida externamente."},
            {"false", "falso", "Valor booleano falso."},
            {"float", "flotante", "Tipo de dato de punto flotante de precisión simple."},
            {"for", "para", "Inicia un bucle for."},
            {"friend", "amigo", "Declara una función o clase amiga."},
            {"goto", "ir_a", "Salta a una etiqueta específica."},
            {"if", "si", "Estructura de control condicional."},
            {"inline", "en_linea", "Sugiere al compilador insertar el código de una función."},
            {"int", "entero", "Tipo de dato entero."},
            {"long", "largo", "Modificador de tipo para enteros largos."},
            {"mutable", "mutable", "Permite que una variable miembro sea modificada en un objeto const."},
            {"namespace", "espacio_de_nombres", "Define un espacio de nombres."},
            {"new", "nuevo", "Asigna memoria dinámica."},
            {"operator", "operador", "Define un operador sobrecargado."},
            {"private", "privado", "Especificador de acceso para miembros de clase."},
            {"protected", "protegido", "Especificador de acceso para miembros de clase."},
            {"public", "publico", "Especificador de acceso para miembros de clase."},
            {"register", "registro", "Sugiere al compilador usar un registro para la variable."},
            {"reinterpret_cast", "conversion_reinterpretada", "Operador de conversión para reinterpretar bits."},
            {"return", "retorno", "Devuelve un valor de una función."},
            {"short", "corto", "Modificador de tipo para enteros cortos."},
            {"signed", "con_signo", "Especifica que un tipo puede tener signo."},
            {"sizeof", "tamanio_de", "Devuelve el tamaño en bytes de un tipo o variable."},
            {"static", "estatico", "Especificador de almacenamiento estático."},
            {"static_cast", "conversion_estatica", "Operador de conversión en tiempo de compilación."},
            {"struct", "estructura", "Define una estructura."},
            {"switch", "seleccionar", "Estructura de control de selección múltiple."},
            {"template", "plantilla", "Define una plantilla genérica."},
            {"this", "este", "Puntero al objeto actual."},
            {"throw", "lanzar", "Lanza una excepción."},
            {"true", "verdadero", "Valor booleano verdadero."},
            {"try", "intentar", "Inicia un bloque de código que puede lanzar excepciones."},
            {"typedef", "tipo_definido", "Define un alias para un tipo."},
            {"typeid", "identificador_tipo", "Retorna información sobre el tipo."},
            {"typename", "nombre_tipo", "Especifica un nombre de tipo en una plantilla."},
            {"union", "union", "Define una unión."},
            {"unsigned", "sin_signo", "Especifica que un tipo no tiene signo."},
            {"using", "usando", "Introduce un nombre desde un espacio de nombres."},
            {"virtual", "virtual", "Especifica que una función puede ser sobrescrita."},
            {"void", "vacio", "Tipo que no representa ningún valor."},
            {"volatile", "volatil", "Especifica que el valor puede cambiar externamente."},
            {"while", "mientras", "Inicia un bucle while."},
            {"string", "cadena", "Tipo de dato para cadenas de caracteres."},
            {"endl", "finalizar", "Finaliza una línea y vacía el buffer."},
            {"exit", "salir", "Termina la ejecución del programa."}
        };
        
        guardarPalabras(palabrasPredefinidas, nombreArchivo);
        cout << "Archivo inicializado con palabras predefinidas." << endl;
    }
    archivo.close();
}

int main() {
    const string nombreArchivo = "diccionario.txt";
    
    // Inicializar el archivo si no existe
    inicializarArchivo(nombreArchivo);
    
    // Cargar las palabras desde el archivo
    vector<Palabra> palabras = cargarPalabras(nombreArchivo);
    
    int opcion;
    bool continuar = true;
    
    while (continuar) {
        cout << "\nMenu Principal:" << endl;
        cout << "1. Fase I: Gestion de Diccionario" << endl;
        cout << "2. Fase II: Traducir Codigo C++" << endl;
        cout << "3. Salir" << endl;
        cout << "Elija una opcion: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1: {
                bool continuarFase1 = true;
                while (continuarFase1) {
                    cout << "\nFase I - Gestion de Diccionario:" << endl;
                    cout << "1. Crear nueva palabra" << endl;
                    cout << "2. Leer palabra" << endl;
                    cout << "3. Actualizar palabra" << endl;
                    cout << "4. Borrar palabra" << endl;
                    cout << "5. Mostrar todas las palabras" << endl;
                    cout << "6. Volver al menu principal" << endl;
                    cout << "Elija una opcion: ";
                    cin >> opcion;
                    
                    switch (opcion) {
                        case 1:
                            crearPalabra(palabras, nombreArchivo);
                            break;
                        case 2:
                            leerPalabra(palabras);
                            break;
                        case 3:
                            actualizarPalabra(palabras, nombreArchivo);
                            break;
                        case 4:
                            borrarPalabra(palabras, nombreArchivo);
                            break;
                        case 5:
                            mostrarPalabras(palabras);
                            break;
                        case 6:
                            continuarFase1 = false;
                            break;
                        default:
                            cout << "Opcion no valida." << endl;
                            break;
                    }
                }
                break;
            }
            case 2:
                traducirCodigo(palabras);
                break;
            case 3:
                continuar = false;
                break;
            default:
                cout << "Opcion no valida." << endl;
                break;
        }
    }
    
    return 0;
}