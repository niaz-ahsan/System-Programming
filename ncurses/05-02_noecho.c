#include <ncurses.h>

int main(void) {
    int key1, key2;
    initscr();
    
    addstr("Press a key\n");
    refresh();
    key1 = getch();
    napms(200);
    
    clear();

    addstr("Try pressing the same key or different\n");
    refresh();
    noecho();
    key2 = getch();

    if(key1 == key2) 
        addstr("Keypresses match !!!\n");
    else 
        addstr("Keypresses dont match\n");
    refresh();

    addstr("Press any key to terminate\n");
    refresh();
    getch();

    endwin();

    return 0;
}