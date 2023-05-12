#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// include sys/mman.h for mmap()
#include <sys/mman.h>

#define NAME_LEN 50

struct employee {
    int id;
    char fname[NAME_LEN];
    char lname[NAME_LEN];
};

int main(void) {
    // open the file
    int fd = open("employee_data.txt", O_RDWR);
    if (fd < 0) {
        printf("File Open Error!");
        exit(1);
    }
    
    // get the file size & each record size
    size_t file_size = lseek(fd, 0, SEEK_END); 
    size_t record_size = sizeof(struct employee);

    struct employee *records = (struct employee *) mmap(NULL, 
                                                        file_size, 
                                                        PROT_READ | PROT_WRITE, 
                                                        MAP_SHARED, 
                                                        fd, 
                                                        0); // readin the entire file from beginning

    // iterating and modifying necessary record
    int total_iterations = (int) file_size / (int) record_size;
    int i;

    // for demo purpose just changing the last name of the 2nd record
    for (i=0; i<total_iterations; i++) {
        if (records[i].id == 2) {
            strcpy(records[i].lname, "Armstrong");
        }
    }

    // flushing the changes to the file in the disk
    if (msync(records, file_size, MS_SYNC) < 0) {
        printf("Error on writing to file\n");
        exit(1);
    }

    // releasing the memory mapped to the file
    if (munmap(records, file_size) < 0) {
        printf("Error on releasing memory\n");
        exit(1);
    }

    printf("Change is committed\n");

    close(fd);
    return 0;
}