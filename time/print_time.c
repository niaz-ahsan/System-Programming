#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define BUFFER_SIZE 4096

void print_time(char * template, struct tm * tm) {
    // +1 to have null terminating pointer
    int buffer_size = (strftime(NULL, BUFFER_SIZE, template, tm) + 1);
    char time_str[buffer_size];
    if (strftime(time_str, buffer_size, template, tm) > 0) {
        printf("%s\n", time_str);
    } else {
        printf("Unable to print the time in: %s\n", template);
    }
}

int main(void) {
    struct tm *now_tm;

    //setting locale
    setlocale(LC_ALL, "");

    char * current_locale; 
    current_locale = setlocale(LC_ALL, NULL);
    printf("Locale: %s\n", current_locale);

    // fetching current time
    time_t now = time(NULL);
    now_tm = localtime(&now);

    print_time("%m/%d/%Y", now_tm);
    print_time("%a | %d %b %Y | %I:%M %p (%Z)", now_tm);

    return 0;
}