#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> tareas;
    int opcion;
    string tarea;
    
    do {
        cout << "\n--- Lista de Tareas ---" << endl;
        cout << "1. Agregar tarea" << endl;
        cout << "2. Ver tareas" << endl;
        cout << "3. Eliminar tarea" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer
        
        switch(opcion) {
            case 1:
                cout << "Ingrese la tarea: ";
                getline(cin, tarea);
                tareas.push_back(tarea);
                break;
            case 2:
                cout << "\nTareas:" << endl;
                for (size_t i = 0; i < tareas.size(); ++i) {
                    cout << i+1 << ". " << tareas[i] << endl;
                }
                break;
            case 3:
                if (tareas.empty()) {
                    cout << "La lista esta vacia." << endl;
                } else {
                    int posicion;
                    cout << "Ingrese el numero de tarea a eliminar: ";
                    cin >> posicion;
                    if (posicion > 0 && posicion <= tareas.size()) {
                        tareas.erase(tareas.begin() + posicion - 1);
                        cout << "Tarea eliminada." << endl;
                    } else {
                        cout << "Posicion invalida." << endl;
                    }
                }
                break;
            case 4:
                cout << "Hasta luego!" << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
    } while (opcion != 4);
    
    return 0;
}
