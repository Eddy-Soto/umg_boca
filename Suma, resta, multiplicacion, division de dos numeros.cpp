#include <iostream>  // Librería para entrada y salida de datos
using namespace std;

int main() {
    char repetir;  // Variable para repetir la consulta

    do {
        double num1, num2; // Variables para los números ingresados
        cout << "Ingrese dos números: ";
        cin >> num1 >> num2;

        // Mostrar resultados de las operaciones
        cout << "Suma: " << num1 + num2 << endl;
        cout << "Resta: " << num1 - num2 << endl;
        cout << "Multiplicación: " << num1 * num2 << endl;

        // Evitar la división por cero
        if (num2 != 0)
            cout << "División: " << num1 / num2 << endl;
        else
            cout << "No se puede dividir entre 0." << endl;

        // Preguntar si desea repetir la operación
        cout << "¿Desea realizar otra consulta? (s/n): ";
        cin >> repetir;
    } while (repetir == 's' || repetir == 'S');  // Se repite si el usuario ingresa 's

