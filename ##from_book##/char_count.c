#include <stdio.h>

int main() {
    int count = 0;
    int ch;
    while ((ch = getchar()) != EOF) {
        if (ch != '\n')
            count++;
    }
    printf("Characters entered: %d\n", count);
    return 0;
}