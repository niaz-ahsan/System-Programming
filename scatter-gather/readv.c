// Reading from a file and writing to the buffer

#include <fcntl.h> // required for open()
#include <unistd.h> // required for read(), write(), close()
#include <stdlib.h> // required for exit()
#include <stdio.h>
#include <string.h> 
#include <sys/uio.h> // for iovec, readv(), writev()

#define RECORD_LEN 3
#define NAME_LEN 50

struct employee {
    int id;
    char fname[NAME_LEN];
    char lname[NAME_LEN];
};

int main(void) {
    // init vars
    struct iovec iov[RECORD_LEN];
    ssize_t bytes_read;
    
    // allocate size to iov
    int i;
    for (i=0; i<RECORD_LEN; i++) {
        iov[i].iov_base = malloc(sizeof(struct employee));
        iov[i].iov_len = sizeof(struct employee);
    }

    // open file
    int fd = open("employee_data.txt", O_RDONLY);
    if (fd < 0) {
        printf("File Open Error!");
        exit(1);
    }

    // do the readv() and print data
    while ( (bytes_read = readv(fd, iov, RECORD_LEN)) > 0 ) {
        printf("Bytes Read: %ld\n", bytes_read);
        for (i=0; i<RECORD_LEN; i++) {
            struct employee *data = (struct employee *) iov[i].iov_base;
            printf("Employee data:\n==================\nid:%d\nfirst name: %s\nlast name: %s\n", data->id, data->fname, data->lname);
        }
    }

    return 0;
}