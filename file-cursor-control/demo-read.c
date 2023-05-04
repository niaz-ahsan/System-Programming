#include <stdio.h>
#include <fcntl.h> // required for open()
#include <unistd.h> // required for read(), write(), close()
#include <stdlib.h> // required for exit()

int main(void) {
    int fd = open("dummy.txt", O_RDONLY | O_CREAT, S_IRWXU);
    if (! fd) {
        printf("Failed to open the file\n");
        exit(1);
    }
    
    int bytes_to_read = 15;
    char buffer[bytes_to_read];
    int offset = 5;
    lseek(fd, offset, SEEK_CUR); //  by lseek() cursor is moved to the desired position. Then read data by read()
    int read_bytes = read(fd, buffer, bytes_to_read);
    if (read_bytes) {
        printf("%s\n", buffer);
    } else {
        printf("Error at reading the file");
    }

    return 0;
}