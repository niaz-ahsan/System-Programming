#include <ncurses.h>

int main() {
    initscr();

    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    
    addstr("Press a key to start");
    refresh();
    getch();

    clear();
    refresh();

    WINDOW * win = newwin(10, 20, 0,10);
    wbkgd(win, COLOR_PAIR(1));
    box(win, 0,0);
    waddstr(win, "My default content");
    
    wrefresh(win);
    //wgetch(win);
    getch();

    // moving the window
    mvwin(win, 20,10);

    touchwin(stdscr); // switching to stdscr in order to remove the previous drawing of the window
    refresh(); // and refresh stdscr

    wrefresh(win);
    getch();


    endwin();

    return 0;
}