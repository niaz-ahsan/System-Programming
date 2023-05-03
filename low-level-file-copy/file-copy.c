#include <fcntl.h> // required for open()
#include <unistd.h> // required for read(), write(), close()
#include <stdio.h>
#include <stdlib.h> // required for exit()

#define BUFFER_SIZE 4096

int open_file(char * filename, char flag);

int main() {
    char source_file[50] = "m2c4_source.txt";
    char destination_file[50] = "m2c4_dest.txt";
    char buffer[BUFFER_SIZE];
    int bytes_read, total_bytes_read = 0, bytes_written, total_bytes_written = 0;

    int source_fd = open_file(source_file, 's');  
    if (! source_fd) {
        printf("Source file error\n");
        exit(1);
    }

    int destination_fd = open_file(destination_file, 'd');
    if (! destination_fd) {
        printf("Destination file error\n");
        exit(1);
    }

    while( (bytes_read = read(source_fd, buffer, BUFFER_SIZE)) > 0 ) {
        bytes_written = write(destination_fd, buffer, bytes_read);
        total_bytes_read += bytes_read;
        total_bytes_written += bytes_written;
    }

    close(source_fd);
    close(destination_fd);

    printf("Bytes Read: %d\nBytes Written: %d\n", total_bytes_read, total_bytes_written);

    return 0;
}

int open_file(char * filename, char flag) {
    int fd;
    if (flag == 's') {
        // open source file
        fd = open(filename, O_RDONLY);
    } else {
        // open dest file
        fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, S_IRWXU);
    }
    if (! fd) {
        return -1;
    }
    return fd;
}