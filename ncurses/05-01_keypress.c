// nodelay(stdscr, TRUE) --> disable default block of getch(). At this point getch() would return ERR if no key pressed
// nodelay(stdscr, FALSE) --> enable default block of getch(). getch() will wait for the next keypress

#include <ncurses.h>

int main(void) {
    int val = 0;
    
    initscr();
    addstr("Press a key to commence a keypress waiting\n");
    refresh();
    getch();

    nodelay(stdscr, TRUE); // stop default blocking behavior of getch()
    while (getch() == ERR) {
        printw("%d\r", val++);
        refresh();
    }
    nodelay(stdscr, FALSE); // enabling getch() blocking behavior

    //move(5,5);
    printw("Ah! You've pressed a key!\n Press another key to terminate program\n");
    refresh();
    getch();

    endwin();

    return 0;
}