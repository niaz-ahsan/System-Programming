/*
Logic: Separator char: ' ', '\t', '\n'
if prev char is any of separators and current char is none of them, then add 1 to word counter.
This will miss the 1st word (if no space before them). In order to count that init prev_ch = ' ' or any of the separators.
*/

#include <stdio.h>

int char_included_in_sep(int ch) {
    if (ch == ' ' || ch == '\t' || ch == '\n') {
        return 1;
    }
    return 0;
}

int main() {
    int ch;
    int prev_ch = ' ';
    int word_counter = 0;
    while ( (ch = getchar()) != EOF ) {
        if(char_included_in_sep(prev_ch) && !char_included_in_sep(ch)) {
            word_counter++;
        }
        prev_ch = ch;
    }
    printf("\nTotal words entered: %d\n", word_counter);
    return 0;
}