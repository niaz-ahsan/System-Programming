#include <fcntl.h> // required for open()
#include <unistd.h> // required for read(), write(), close()
#include <stdio.h>

#define BUFFER_SIZE 100

int main() {
    int fd = open("m2c4_source.txt", O_RDONLY);
    char buffer[BUFFER_SIZE];
    
    while(read(fd, buffer, BUFFER_SIZE)) {
        printf("%s\n", buffer);
        printf("----------------------------------------------------------------------------------------------\n");
    }

    close(fd);
    return 0;
}    