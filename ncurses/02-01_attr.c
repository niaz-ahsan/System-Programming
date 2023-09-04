// attron() and attroff() turns on and off attributes
// attrset() discards previous attributes and overwrites with its own.

#include <ncurses.h>

int main() {
    initscr();

    attron(A_BOLD);
    addstr("Twinkle twinke little star\n"); // this is just bold
    attron(A_BLINK);
    addstr("How I wonder what you are\n"); // both bold and blinking
    attroff(A_BOLD);

    addstr("Up above thw world so high\n"); // only blinking
    addstr("Like a dimaond in the sky.\n"); // only blinking
    
    attrset(A_NORMAL);
    addstr("Twinkle twinke little star\n"); // normal
    addstr("How I wonder what you are\n"); // normal
    refresh();

    getch();
    endwin();
    return 0;
}