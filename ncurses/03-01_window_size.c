#include <ncurses.h>

int main() {
    int x, y;
        
    initscr();
    getmaxyx(stdscr, y, x);
    printw("Screen row %d and col %d\n", y, x);
    refresh();
    getch();
    endwin();

    return 0;
}