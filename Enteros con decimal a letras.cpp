#include <iostream>
using namespace std;

// Función para convertir números de 1 a 9999 a letras
string convertirALetras(int num) {
    if (num < 1 || num > 9999) return "Número fuera de rango (1-9999)";

    string unidades[] = {"", "Uno", "Dos", "Tres", "Cuatro", "Cinco", "Seis", "Siete", "Ocho", "Nueve"};
    string especiales[] = {"Diez", "Once", "Doce", "Trece", "Catorce", "Quince", "Dieciséis", "Diecisiete", "Dieciocho", "Diecinueve"};
    string decenas[] = {"", "", "Veinte", "Treinta", "Cuarenta", "Cincuenta", "Sesenta", "Setenta", "Ochenta", "Noventa"};
    string centenas[] = {"", "Cien", "Doscientos", "Trescientos", "Cuatrocientos", "Quinientos", "Seiscientos", "Setecientos", "Ochocientos", "Novecientos"};

    string resultado = "";

    // Miles
    if (num >= 1000) {
        if (num / 1000 == 1)
            resultado += "Mil ";
        else
            resultado += unidades[num / 1000] + " Mil ";
        num %= 1000;  // Extraer la parte de los miles
    }

    // Centenas
    if (num >= 100) {
        if (num == 100)
            resultado += "Cien";
        else
            resultado += centenas[num / 100] + " ";
        num %= 100;  // Extraer la parte de las centenas
    }

    // Decenas y Unidades
    if (num >= 10 && num <= 19) {
        resultado += especiales[num - 10];
    } else {
        if (num >= 20) {
            resultado += decenas[num / 10];
            if (num % 10 != 0)
                resultado += " y " + unidades[num % 10];
        } else {
            resultado += unidades[num];  // Solo unidades
        }
    }

    return resultado;
}

int main() {
    char repetir;

    do {
        int numero;
        cout << "Ingrese un número entero (1 - 9999): ";
        cin >> numero;

        cout << "Número en letras: " << convertirALetras(numero) << endl;

        // Preguntar si desea realizar otra consulta
        cout << "¿Desea realizar otra consulta? (s/n): ";
        cin >> repetir;
    } while (repetir == 's' || repetir == 'S');

    return 0;
}

