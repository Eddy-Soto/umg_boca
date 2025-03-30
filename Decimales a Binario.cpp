#include <iostream>
#include <stack>  // Para usar la pila (stack)
using namespace std;

void decimalABinario(int num) {
    stack<int> binario;  // Usamos una pila para almacenar los restos

    // Si el número es 0, lo manejamos específicamente
    if (num == 0) {
        cout << "El número en binario es: 0" << endl;
        return;
    }

    // Mientras el número sea mayor que 0, dividimos entre 2
    while (num > 0) {
        binario.push(num % 2);  // Guardamos el resto (0 o 1)
        num = num / 2;  // Dividimos el número entre 2
    }

    // Mostramos el número binario en orden correcto (de arriba a abajo)
    cout << "El número en binario es: ";
    while (!binario.empty()) {
        cout << binario.top();  // Mostrar el valor en la cima de la pila
        binario.pop();  // Eliminar el valor de la pila
    }
    cout << endl;
}

int main() {
    int numero;
    char opcion;

    do {
        // Pedimos al usuario que ingrese un número decimal
        cout << "Introduce un número decimal: ";
        cin >> numero;

        // Convertimos el número decimal a binario
        decimalABinario(numero);

        // Preguntar si el usuario quiere realizar otra conversión
        cout << "¿Quieres convertir otro número? (s/n): ";
        cin >> opcion;

    } while (opcion == 's' || opcion == 'S');  // Repite si la opción es 's' o 'S'

    cout << "¡Hasta luego!" << endl;

    return 0;
}

