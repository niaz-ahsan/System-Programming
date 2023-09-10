// clears half the lines
#include <ncurses.h>

int main() {
    initscr();
    getmaxyx(stdscr, LINES, COLS);
    int limit = (int) LINES / 3;
    int clear_from = limit / 2;

    for (int i=0; i<limit; i++) {
        addstr("Blah!\n");
        refresh();
    }
    printw("Press any key to clear from line %d\n", clear_from);
    getch();

    move(clear_from, 0);
    clrtobot();
    refresh(); // needed for sure to see that screen is cleared

    getch();
    endwin();

    return 0;
}