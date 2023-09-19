#include <ncurses.h>

int main() {
    initscr();

    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    WINDOW * win = newwin(LINES/2, COLS/2, LINES/4, COLS/4);

    wbkgd(win, COLOR_PAIR(1));
    //wborder(win, '|','|','-','-','+','+','+','+');
    box(win, '|','-');
    wrefresh(win);
    wgetch(win);

    wmove(win, 2,2);
    waddstr(win, "A text inside the window\nAnother text\n Another text");
    wrefresh(win);
    wgetch(win);

    endwin();

    return 0;
}