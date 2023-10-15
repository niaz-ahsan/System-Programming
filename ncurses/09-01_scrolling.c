#include <ncurses.h>

int main() {
    char text[] = "This is a text\n";
    initscr();

    scrollok(stdscr, TRUE);
    for (int x=0; x<199; x++) {
        printw("%d: %s", x, text);
        refresh();
        napms(100);
    }
    getch();

    endwin();
    return 0;
}