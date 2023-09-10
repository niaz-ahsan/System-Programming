// clears the 2nd line from the bottom
#include <ncurses.h>

int main() {
    initscr();
    getmaxyx(stdscr, LINES, COLS);
    int limit = (int) LINES / 3;
    int clearing_line = limit - 2;

    for (int i=0; i<limit; i++) {
        addstr("Blah!\n");
        refresh();
    }
    printw("Press any key to clear line %d\n", clearing_line);
    getch();

    move(clearing_line, 0);
    clrtoeol();
    refresh(); // needed for sure to see that screen is cleared

    getch();
    endwin();

    return 0;
}