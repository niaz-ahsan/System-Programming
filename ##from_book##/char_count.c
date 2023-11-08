#include <stdio.h>

int main() {
    int count = 0;
    while (getchar() != EOF) {
        count++;
    }
    printf("Characters entered: %d\n", count);
    return 0;
}