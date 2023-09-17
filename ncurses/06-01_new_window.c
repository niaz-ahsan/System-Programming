#include <ncurses.h>

int main() {
    initscr();
    
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    init_pair(2, COLOR_WHITE, COLOR_RED);

    bkgd(COLOR_PAIR(1));

    WINDOW * new_win = newwin(LINES/2, COLS/2, LINES/4, COLS/4);
    if(!new_win) {
        addstr("Window creation failed!\n");
        refresh();
        getch();
        endwin();
        return 0;
    } 

    wbkgd(new_win, COLOR_PAIR(2));

    addstr("This is my main screen!");
    refresh();
    getch();

    waddstr(new_win, "This is secondary screen!");
    wrefresh(new_win);
    wgetch(new_win);

    // to switch back to main screen, only refresh() won't work as refresh() won't bring anything until there's a change in the screen.
    touchwin(stdscr); // this brings the main window again. It's a forced refresh
    refresh();
    getch();

    endwin();

    return 0;
}