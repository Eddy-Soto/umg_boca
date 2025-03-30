#include <ncurses.h>
#include <unistd.h>

int main() {
    initscr();              // Inicializa la pantalla
    noecho();               // Desactiva el eco de caracteres
    curs_set(FALSE);       // Oculta el cursor
    keypad(stdscr, TRUE);  // Activa la tecla de función

    int x = 0;  // Coordenada x del punto
    int y = 0;  // Coordenada y del punto

    while (true) {
        clear();  // Limpia la pantalla
        mvprintw(y, x, "*");  // Imprime el punto en la pantalla
        refresh();  // Actualiza la pantalla

        int c = getch();  // Lee una tecla

        switch (c) {
            case KEY_UP:
                if (y > 0) y--;
                break;
            case KEY_DOWN:
                if (y < LINES - 1) y++;
                break;
            case KEY_LEFT:
                if (x > 0) x--;
                break;
            case KEY_RIGHT:
                if (x < COLS - 1) x++;
                break;
            case 'q':
                endwin();  // Cierra la pantalla
                return 0;
        }

        usleep(100000);  // Espera 100 milisegundos
    }

    return 0;
}
