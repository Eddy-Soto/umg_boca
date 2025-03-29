#include <iostream>
using namespace std;

int main() {
    float saldo = 1000.00;
    int opcion;
    float cantidad;

    do {
        cout << "\n--- Cajero Automatico ---" << endl;
        cout << "1. Ver saldo" << endl;
        cout << "2. Retirar dinero" << endl;
        cout << "3. Depositar dinero" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                cout << "Saldo actual: Q" << saldo << endl;
                break;
            case 2:
                cout << "Ingrese la cantidad a retirar: Q";
                cin >> cantidad;
                if (cantidad > saldo) {
                    cout << "Fondos insuficientes." << endl;
                } else {
                    saldo -= cantidad;
                    cout << "Retiro exitoso. Saldo restante: Q" << saldo << endl;
                }
                break;
            case 3:
                cout << "Ingrese la cantidad a depositar: Q";
                cin >> cantidad;
                saldo += cantidad;
                cout << "Depósito exitoso. Saldo actual: Q" << saldo << endl;
                break;
            case 4:
                cout << "Gracias por usar el cajero. Hasta luego!" << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
    } while (opcion != 4);

    return 0;
}
