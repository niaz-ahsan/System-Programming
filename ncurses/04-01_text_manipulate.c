// insertln() creates a blank line. If there were contents, they'll be moved to the next row.

#include <ncurses.h>

int main() {
    char text1[] = "1st line of text\n";
    char text2[] = "2nd line of text\n";
    char text3[] = "3rd line of text\n";
    char text4[] = "4th line of text\n";
    char text5[] = "5th line of text\n";

    initscr();

    addstr(text1);
    addstr(text3);
    addstr(text5);
    refresh();
    
    move(1,0);
    insertln();
    addstr(text2);
    refresh();

    getch();
    endwin();

    return 0;
}