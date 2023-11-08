#include <stdio.h>

int main() {
    int ch; // need int as EOF is an int
    while((ch = getchar()) != EOF) {
        putchar(ch);
    }
    return 0;
}