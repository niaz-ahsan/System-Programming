#include <ncurses.h>

int main() {
    initscr();

    start_color();
    init_pair(1, COLOR_WHITE, COLOR_RED);
    init_pair(2, COLOR_WHITE, COLOR_BLUE);

    WINDOW * red = newwin(20,20, 0,0);
    WINDOW * blue = newwin(20, 20, 5,5);

    /*if (! red || ! blue) {
        endwin();
        puts("Window creation failed\n");
        return 0;
    }*/

    wbkgd(red, COLOR_PAIR(1));
    wbkgd(blue, COLOR_PAIR(2));

    box(red, 0,0);
    box(blue, 0,0);

    mvwaddstr(red, 3,0, "This is red"); // relatively moving window cursor and print
    mvwaddstr(blue, 3,0, "This is blue");

    wrefresh(red);
    wrefresh(blue);

    wgetch(red);
    wgetch(blue);

    //getch();

    overwrite(red, blue); // the overlapping part of red is brought to the blue window
    wrefresh(blue);
    wgetch(red);
    wgetch(blue);

    endwin();
    return 0;
}