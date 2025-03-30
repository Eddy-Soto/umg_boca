#include <iostream>
using namespace std;

int main() {
    // Mostrar las tablas de multiplicar del 1 al 10
    for (int i = 1; i <= 10; ++i) {
        cout << "Tabla de multiplicar del " << i << ":\n";
        
        // Imprimir los resultados de la tabla de multiplicar de 'i'
        for (int j = 1; j <= 10; ++j) {
            cout << i << " x " << j << " = " << i * j << endl;
        }
        
        // Salto de línea entre tablas para mejor formato
        cout << endl;
    }

    return 0;
}

