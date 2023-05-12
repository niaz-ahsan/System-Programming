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

int main() {
    // open the file
    int fd = open("employee_data.txt", O_RDONLY);
    if (fd < 0) {
        printf("File Open Error!");
        exit(1);
    }
    
    // get the file size & each record size
    size_t file_size = lseek(fd, 0, SEEK_END); 
    size_t record_size = sizeof(struct employee);

    //printf("file size: %ld\n record size: %ld\n %d", file_size, record_size, (int) file_size / (int) record_size);

    // mapping file into the memory and reading all at once
    struct employee *records = (struct employee *) mmap(NULL, 
                                                        file_size, 
                                                        PROT_READ, 
                                                        MAP_PRIVATE, 
                                                        fd, 
                                                        0); // readin the entire file from beginning

    // iterating and print each record
    int total_iterations = (int) file_size / (int) record_size;
    int i;
    for (i=0; i<total_iterations; i++) {
        struct employee data = records[i];
        printf("Employee Data id: %d\n=================\n", data.id);
        printf("First name: %s\nLast name: %s\n\n", data.fname, data.lname);
    }

    // releasing the memory mapped to the file
    if (munmap(records, file_size) < 0) {
        printf("Error on releasing memory\n");
        exit(1);
    }
    
    close(fd);

    
    return 0;
}