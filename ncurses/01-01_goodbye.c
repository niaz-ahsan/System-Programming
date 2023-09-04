#include <ncurses.h>

int main() {
    initscr(); // enters ncurses mode from actual terminal

    // ========= everything ncurses happens after initscr() ============

    addstr("Goodbye, Cruel World!"); // outputs a line of text in the terminal
    refresh(); // must refresh the window to display text
    getch(); // waits to fetch any keyboard char to terminate the program

    // ========= everything ncurses ends before endwin() ============

    endwin(); // closes ncurses session

    return 0;
}