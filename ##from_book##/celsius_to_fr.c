#include <stdio.h>

#define LOWER   0
#define UPPER   300
#define STEP    20

int main() {
    int fahr;
    printf("Farenhite\tCelsius\n");
    for(fahr = LOWER; fahr <= UPPER; fahr += STEP) {
        //printf("%7.2f\n", (5.0 / 9.0) * (fahr - 32));
        printf("%5d %16.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    }
    return 0;
}