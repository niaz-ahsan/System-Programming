/*
Move cursor and print string by functions following
mvddch(y,x,ch)
mvaddstr(y,x,str)
mvprintw(y,x,format,args)
*/

#include <ncurses.h>
#include <string.h>

void print_at_center(int row, char * text) {
    int width;
    int len = strlen(text);
    getmaxyx(stdscr, LINES, width);
    int indent = (width - len) / 2;
    mvaddstr(row, indent, text);
    refresh();
}

int main() {
    initscr();

    // adding some colore
    if (has_colors())
        start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    bkgd(COLOR_PAIR(1));
    attrset(A_BOLD);
    // calling the centering function
    print_at_center(1, "Hello World!");
    print_at_center(2, "I am doing ncurses");
    getch();
    endwin();
    return 0;
}