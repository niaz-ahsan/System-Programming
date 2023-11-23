#include <stdio.h>

#define MAX 1000

int get_line(char * line, int limit);
void copy_line(char * from, char * to);

int main(void) {
    int len;
    int max = 0;
    char line[MAX];
    char longest[MAX];
    while( (len = get_line(line, MAX)) > 0 ) {
        if (len > max) {
            max = len;
            copy_line(line, longest);
        }
    }
    if (max > 0) {
        printf("\n\nLongest line len: %d\n", max);
        printf("Longest line entered: %s\n", longest);
    }
    return 0;
}

int get_line(char * line, int limit) {
    int ch;
    int len = 0;
    while( (ch = getchar()) != EOF && ch != '\n' && len < limit-1 ) {
        line[len] = ch;
        len++;
    }
    line[len] = '\0';
    return len;
}

void copy_line(char * from, char * to) {
    int i = 0;
    while ( (to[i] = from[i]) != '\0' ) {
        i++;
    }
}