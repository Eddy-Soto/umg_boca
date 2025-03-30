#include <iostream>
#include <cmath>
using namespace std;

// Funci�n para dibujar un cuadrado
void dibujarCuadrado(int lado) {
    for (int i = 0; i < lado; i++) {
        for (int j = 0; j < lado; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

// Funci�n para dibujar un c�rculo
void dibujarCirculo(int radio) {
    for (int i = -radio; i <= radio; i++) {
        for (int j = -radio; j <= radio; j++) {
            if (i * i + j * j <= radio * radio) {
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

// Funci�n para dibujar un rombo
void dibujarRombo(int lado) {
    for (int i = 0; i < lado; i++) {
        for (int j = 0; j < lado - i - 1; j++) {
            cout << "  ";
        }
        for (int j = 0; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
    for (int i = lado - 2; i >= 0; i--) {
        for (int j = 0; j < lado - i - 1; j++) {
            cout << "  ";
        }
        for (int j = 0; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

// Funci�n para dibujar un tri�ngulo
void dibujarTriangulo(int altura) {
    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < altura - i - 1; j++) {
            cout << "  ";
        }
        for (int j = 0; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

int main() {
    int opcion;
    int lado;

    cout << "Figuras geom�tricas con asteriscos" << endl;
    cout << "----------------------------------------" << endl;
    cout << "1. Cuadrado" << endl;
    cout << "2. C�rculo" << endl;
    cout << "3. Rombo" << endl;
    cout << "4. Tri�ngulo" << endl;
    cout << "5. Salir" << endl;

    do {
        cout << "Ingrese su opci�n: ";
        cin >> opcion;

        if (opcion >= 1 && opcion <= 4) {
            cout << "Ingrese el lado o radio de la figura: ";
            cin >> lado;

            switch (opcion) {
                case 1:
                    dibujarCuadrado(lado);
                    break;
                case 2:
                    dibujarCirculo(lado);
                    break;
                case 3:
                    dibujarRombo(lado);
                    break;
                case 4:
                    dibujarTriangulo(lado);
                    break;
            }
        } else if (opcion != 5) {
            cout << "Opci�n inv�lida. Por favor, ingrese un n�mero entre 1 y 5." << endl;
        }
    } while (opcion != 5);

    return 0;
}
