// taking user input using getch() and print it later

#include <ncurses.h>

int main() {
    char ch;
    initscr();
    addstr("Type a few lines of text\nPress ~ to quit\n");
    refresh();
    while (ch != '~') {
        ch = getch();
    }

    endwin();
    return 0;
}