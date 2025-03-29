#include <iostream>
#include <map>
using namespace std;

// Función para convertir números a palabras (versión básica)
string convertirALetras(int num) {
    map<int, string> numeros = {
        {1, "Uno"}, {2, "Dos"}, {3, "Tres"}, {4, "Cuatro"}, {5, "Cinco"},
        {6, "Seis"}, {7, "Siete"}, {8, "Ocho"}, {9, "Nueve"}, {10, "Diez"},
        {20, "Veinte"}, {30, "Treinta"}, {40, "Cuarenta"}, {50, "Cincuenta"},
        {100, "Cien"}, {200, "Doscientos"}, {500, "Quinientos"}, {1000, "Mil"}
    };

    if (numeros.find(num) != numeros.end()) return numeros[num];

    return "Número no soportado";
}

int main() {
    char repetir;

    do {
        int numero;
        cout << "Ingrese un número entero: ";
        cin >> numero;

        cout << "Número en letras: " << convertirALetras(numero) << endl;

        // Preguntar si desea realizar otra consulta
        cout << "¿Desea realizar otra consulta? (s/n): ";
        cin >> repetir;
    } while (repetir == 's' || repetir == 'S');

    return 0;
}

