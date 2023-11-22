/*
Logic: Separator char: ' ', '\t', '\n'
if prev char is any of separators and current char is any alpabet (A-Z or a-z) of them, then add 1 to word counter.
This will miss the 1st word (if no space before them). In order to count that init prev_ch = ' ' or any of the separators.
*/

#include <stdio.h>

#define SPACE           ' '
#define TAB             '\t'
#define NWLN            '\n'
#define ALPHA_START_CAP 65
#define ALPHA_END_CAP   90
#define ALPHA_START_SM  97
#define ALPHA_END_SM    122

int char_included_in_sep(int ch) {
    if (ch == SPACE || ch == TAB || ch == NWLN) {
        return 1;
    }
    return 0;
}

int char_included_in_alphabet(int ch) {
    if ( (ch >= ALPHA_START_CAP && ch <= ALPHA_END_CAP) || (ch >= ALPHA_START_SM && ch <= ALPHA_END_SM) ) {
        return 1;
    }
    return 0;
}

int main() {
    int ch;
    int prev_ch = ' ';
    int word_counter = 0;
    while ( (ch = getchar()) != EOF ) {
        if(char_included_in_sep(prev_ch) && char_included_in_alphabet(ch)) {
            word_counter++;
        }
        prev_ch = ch;
    }
    printf("\nTotal words entered: %d\n", word_counter);
    return 0;
}