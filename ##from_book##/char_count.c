#include <stdio.h>

int main() {
    int ch_count = 0;
    int line_count = 0;
    int tab_count = 0;
    int space_count = 0;
    int ch;
    while ((ch = getchar()) != EOF) {
        if (ch == '\n')
            line_count++;
        else if (ch == '\t') 
            tab_count++;
        else if (ch == ' ')
            space_count++;
        else
            ch_count++;
    }
    printf("Characters entered: %d\nLines entered: %d\nSpaces entered: %d\nTabs entered: %d\n", 
        ch_count, line_count, space_count, tab_count);
    return 0;
}