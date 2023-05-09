// Reading from a buffer and writing to the file

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
    // initiate vars
    struct iovec iov[RECORD_LEN]; // 3x employees
    struct employee data[RECORD_LEN] = {
        {1, "Niaz", "Prodhan"},
        {2, "Salim", "Molla"},
        {3, "Sakib", "Ahmed"}
    };

    //store data to iov
    int i;
    for (i=0; i<RECORD_LEN; i++) {
        iov[i].iov_base = &data[i];
        iov[i].iov_len = sizeof(struct employee);
    }

    // open the file
    int fd = open("employee_data.txt", O_WRONLY | O_CREAT, S_IWUSR | S_IRUSR);
    if (fd < 0) {
        printf("File Open Error!");
        exit(1);
    }

    // do the writev()
    ssize_t bytes_written = writev(fd, iov, RECORD_LEN);

    printf("Bytes written: %ld\n", bytes_written);

    return 0;
}