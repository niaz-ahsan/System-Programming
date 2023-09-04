#include <ncurses.h>

int main() {
    char fname[32];
    char lname[32];

    initscr();
    addstr("Your first name: ");
    refresh();
    getnstr(fname, 31);

    addstr("Your last name: ");
    refresh();
    getnstr(lname, 31);

    move(3,0);
    printw("Pleased to meet you Mr. %s %s", fname, lname);

    getch();

    endwin();
    return 0;

}