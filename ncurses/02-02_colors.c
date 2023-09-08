// has_colors() --> true if terminal is capable of coloring
// start_color() --> OK if colors are properly initialized
/*
Color_pair is a combination of foreground and background color
init_pair(1, COLOR_YELLOW, COLOR_RED) // means init a pair with foreground yellow and background red
attrset(COLOR_PAIR(1)) or attron(COLOR_PAIR(1));
*/

#include <ncurses.h>

int main() {
    initscr();

    if (!has_colors()) {
        // terminal doesn't support color
        endwin();
        printf("This terminal doesn't support colors!\n");
        return 0;
    }

    if (start_color() != OK) {
        // terminal color isn't initialized
        endwin();
        printf("Terminal color can't be initialized!\n");
        return 0;
    }

    // colors are ok
    printw("%d colors are available\n", COLORS);
    printw("%d color pairs are available\n", COLOR_PAIRS);

    // applying color_pair
    init_pair(1, COLOR_YELLOW, COLOR_RED);
    attron(COLOR_PAIR(1) | A_BOLD);
    printw("This is a colored text! Yayyyy!!!\n");

    refresh();
    getch();
    endwin();

    return 0;
}