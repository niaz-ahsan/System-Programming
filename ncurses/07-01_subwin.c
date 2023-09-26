#include <ncurses.h>

int main() {
    initscr();

    start_color();

    init_pair(1, COLOR_WHITE, COLOR_BLUE);

    WINDOW * subw = subwin(stdscr, LINES/3, COLS/3, LINES/4, COLS/4);
    if (! subw) {
        endwin();
        puts("Sub window creation failed\n");
        return 0;
    }
    box(subw, 0,0); // adding border in subwin
    wbkgd(subw, COLOR_PAIR(1)); // adding background col on subwin

    addstr("This is parent stdscr");
    waddstr(subw, "This is in the subwin");
    refresh();
    
    getch();
    endwin();

    return 0;
}