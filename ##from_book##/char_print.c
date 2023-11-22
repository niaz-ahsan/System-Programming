#include <stdio.h>

int main() {
    int ch; // need int as EOF is an int(symbolic const), EOF = -1
    int prev_ch = -1;
    while((ch = getchar()) != EOF) {
        if (ch == ' ' && ch == prev_ch) { // ommitting multiple whitespaces with a single one
            continue;
        }
        prev_ch = ch;
        putchar(ch);
    }
    return 0;
}