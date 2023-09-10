#include <ncurses.h>

int main() {
    initscr();
    getmaxyx(stdscr, LINES, COLS);
    int limit = (int) LINES / 3;

    for (int i=0; i<limit; i++) {
        addstr("Blah!\n");
        refresh();
    }
    addstr("Press any key to clear the screen\n");
    getch();

    clear();
    refresh(); // needed for sure to see that screen is cleared

    getch();
    endwin();

    return 0;
}