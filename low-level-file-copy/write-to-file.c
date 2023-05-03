#include <fcntl.h> // required for open()
#include <unistd.h> // required for read(), write(), close()
#include <stdio.h>
#include <stdlib.h> 

#define BUFFER_SIZE 50

int main() {
    int fd = open("test_output.txt", O_WRONLY | O_CREAT | O_APPEND, S_IRWXU);
    char str[BUFFER_SIZE];

    printf("Type your input. Press [Enter] to finish.\n");
    scanf("%[^\n]s",str);

    int bytes = write(fd, str, BUFFER_SIZE);

    if(bytes) {
        printf("Writing to file is successful!\n");
    }

    close(fd);

    return 0;
}