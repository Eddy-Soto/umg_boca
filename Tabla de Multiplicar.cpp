#include <iostream>
using namespace std;

int main() {
    int numero;
    char opcion;

    do {
        // Pedir al usuario el número para la tabla de multiplicar
        cout << "Introduce el número para ver su tabla de multiplicar: ";
        cin >> numero;

        // Mostrar la tabla de multiplicar del número
        cout << "Tabla de multiplicar del " << numero << ":\n";
        for (int i = 1; i <= 10; ++i) {
            cout << numero << " x " << i << " = " << numero * i << endl;
        }

        // Preguntar si el usuario quiere realizar otra operación
        cout << "¿Quieres ver otra tabla de multiplicar? (s/n): ";
        cin >> opcion;

    } while (opcion == 's' || opcion == 'S'); // Repite si la opción es 's' o 'S'

    cout << "¡Hasta luego!" << endl;

    return 0;
}

