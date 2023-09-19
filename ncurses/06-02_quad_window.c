#include <ncurses.h>

int main() {
    initscr();

    // declare color pairs
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    init_pair(2, COLOR_RED, COLOR_GREEN);
    init_pair(3, COLOR_WHITE, COLOR_RED);
    init_pair(4, COLOR_WHITE, COLOR_MAGENTA);

    // init the windows
    WINDOW * win1 = newwin(LINES/2, COLS/2, 0, 0); // top left
    WINDOW * win2 = newwin(LINES/2, COLS/2, 0, COLS/2); // top right 
    WINDOW * win3 = newwin(LINES/2, COLS/2, LINES/2, 0); // bottom left
    WINDOW * win4 = newwin(LINES/2, COLS/2, LINES/2, COLS/2);

    // set bkgd color
    wbkgd(win1, COLOR_PAIR(1));
    wbkgd(win2, COLOR_PAIR(2));
    wbkgd(win3, COLOR_PAIR(3));
    wbkgd(win4, COLOR_PAIR(4));

    // set some text
    waddstr(win1, "1st screen");
    waddstr(win2, "2nd screen");
    waddstr(win3, "3rd screen");
    waddstr(win4, "4th screen");

    // refresh all screens to make them visible
    wrefresh(win1);
    wrefresh(win2);
    wrefresh(win3);
    wrefresh(win4);

    wgetch(win1);
    wgetch(win2);
    wgetch(win3);
    wgetch(win4);

    endwin();

    return 0;
}