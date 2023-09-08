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

    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    bkgd(COLOR_PAIR(1));
    move(5, 5);
    printw("We've got a nice colored window!\n");
    refresh();


    getch();
    endwin();

    return 0;
}