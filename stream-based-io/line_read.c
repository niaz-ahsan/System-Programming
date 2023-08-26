#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char * line = NULL;
    size_t line_len = 0;
    ssize_t bytes_read;

    fp = fopen("source.txt", "r");
    if (! fp) {
        perror("File can't be opened!\n");
        exit(1);
    }

    int itr = 0;
    while ((bytes_read = getline(&line, &line_len, fp)) != -1) {
        itr++;
        printf("[itr %d] total bytes read: %zu\n", itr, bytes_read);
        printf("[%d]: %s\n", itr, line);
        printf("==========================\n");
    }

    return 0;
}