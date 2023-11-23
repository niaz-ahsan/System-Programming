#include <stdio.h>

#define MAX_CHAR 100

int get_line(char * line, int limit);
void reverse_line(char * line, int len);

int main(void) {
    int len;
    char line[MAX_CHAR];
    while ( (len = get_line(line, MAX_CHAR)) > 0 ) {
        reverse_line(line, len);
    }
    return 0;
}

int get_line(char * line, int limit) {
    int len = 0;
    int ch;
    while ( (ch = getchar()) != EOF && ch != '\n' && len < limit - 1 ) {
        line[len] = ch;
        len++;
    }
    line[len] = '\0';
    return len;
}

void reverse_line(char * line, int len) {
    for (int i = len - 1; i >= 0; i--) {
        putchar(line[i]);
    }
    putchar('\n');
}