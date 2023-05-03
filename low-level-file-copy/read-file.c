#include <fcntl.h> // required for open()
#include <unistd.h> // required for read(), write(), close()
#include <stdio.h>

#define BUFFER_SIZE 100

int main() {
    int fd = open("m2c4_source.txt", O_RDONLY);
    char buffer[BUFFER_SIZE];
    int bytes_read = 0, bytes;
    
    while( (bytes = read(fd, buffer, BUFFER_SIZE)) > 0 ) {
        printf("%s\n", buffer);
        printf("----------------------------------------------------------------------------------------------\n");
        bytes_read += bytes;
    }

    close(fd);
    printf("%d Bytes read", bytes_read);
    return 0;
}    