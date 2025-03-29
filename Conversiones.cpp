#include <iostream>
using namespace std;

int main() {
    char repetir;

    do {
        int opcion;
        double valor;  // Variable para almacenar el valor a convertir

        // Mostrar opciones disponibles
        cout << "Seleccione la conversi�n:\n";
        cout << "1. Km a millas\n2. Metros a pulgadas\n3. Libras a kilos\n4. Millas a Km\n5. Pulgadas a metros\n6. Kilos a libras\n";
        cin >> opcion;
        
        // Solicitar el valor a convertir
        cout << "Ingrese el valor: ";
        cin >> valor;

        // Realizar la conversi�n seg�n la opci�n elegida
        switch (opcion) {
            case 1: cout << "Resultado: " << valor * 0.621371 << " millas\n"; break;
            case 2: cout << "Resultado: " << valor * 39.3701 << " pulgadas\n"; break;
            case 3: cout << "Resultado: " << valor * 0.453592 << " kilos\n"; break;
            case 4: cout << "Resultado: " << valor / 0.621371 << " km\n"; break;
            case 5: cout << "Resultado: " << valor / 39.3701 << " metros\n"; break;
            case 6: cout << "Resultado: " << valor / 0.453592 << " libras\n"; break;
            default: cout << "Opci�n no v�lida.\n";  // Mensaje en caso de opci�n inv�lida
        }

        // Preguntar si desea realizar otra consulta
        cout << "�Desea realizar otra consulta? (s/n): ";
        cin >> repetir;
    } while (repetir == 's' || repetir == 'S');

    return 0;
}


