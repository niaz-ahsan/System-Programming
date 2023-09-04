// observing napms() to create a delay while refreshing the screen 

#include <ncurses.h>

int main() {
    char text[] = "Hello World from ncurses!";
    char * t;

    initscr();
    t = text;
    while(* t) {
        addch(*(t));
        refresh();
        t++;
        napms(200); // delays 0.2 sec
    }

    move(2,0); // moving to 3rd row, 1st col.
    char t2[] = "Just another text";
    addstr(t2);
    refresh();

    move(4,0); 
    int page_count = 238;
    printw("I am reading a book of ncurses with %d pages", page_count); // counterpart of printf() is printw().. works the same way

    getch();
    endwin();

    return 0;
}