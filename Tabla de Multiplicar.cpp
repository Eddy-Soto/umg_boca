#include <iostream>
using namespace std;

int main() {
    int numero;
    char opcion;

    do {
        // Pedir al usuario el n�mero para la tabla de multiplicar
        cout << "Introduce el n�mero para ver su tabla de multiplicar: ";
        cin >> numero;

        // Mostrar la tabla de multiplicar del n�mero
        cout << "Tabla de multiplicar del " << numero << ":\n";
        for (int i = 1; i <= 10; ++i) {
            cout << numero << " x " << i << " = " << numero * i << endl;
        }

        // Preguntar si el usuario quiere realizar otra operaci�n
        cout << "�Quieres ver otra tabla de multiplicar? (s/n): ";
        cin >> opcion;

    } while (opcion == 's' || opcion == 'S'); // Repite si la opci�n es 's' o 'S'

    cout << "�Hasta luego!" << endl;

    return 0;
}

