#include <ncurses.h>

int main() {
    int ch;

    initscr();

    addstr("Press Enter to stop the process. Keep pressing following keys:\nArrow\nBksp\n");
    refresh();

    move(5,0);
    keypad(stdscr, TRUE); // the main sauce to turn on keypad features
    while ( (ch = getch()) != '\n') {
        switch(ch) {
            case KEY_UP:
                addstr("UP\n");
                refresh();
                break;
            case KEY_DOWN:
                addstr("DOWN\n");
                refresh();
                break;
            case KEY_LEFT:
                addstr("LEFT\n");
                refresh();
                break;
            case KEY_RIGHT:
                addstr("RIGHT\n");
                refresh();
                break;
            case KEY_BACKSPACE:
                addstr("BKSP\n");
                refresh();
                break;
        }
    }

    endwin();

    return 0;
}