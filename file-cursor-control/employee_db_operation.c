#include <stdio.h>
#include <fcntl.h> // required for open()
#include <unistd.h> // required for read(), write(), close()
#include <stdlib.h> // required for exit()
#include <string.h> 

struct employee {
    int id;
    char fname[50];
    char lname[50];
};

void populate_data(struct employee *, int, char *, char *);
int write_to_file(int, struct employee *, int);
void initiate_db(int);

int main(int argc, char * argv[]) {
    int fd = open("employee_database", O_RDWR | O_CREAT, S_IRWXU);
    if (! fd) {
        printf("Error opening file\nExiting ...\n");
        exit(1);
    }
    if (argc == 1) {
        // generate the db file
        initiate_db(fd);
    } else {
        // find the record
        int record_to_fetch = atoi(argv[1]);
        int record_size = sizeof(struct employee);
        int offset = (record_to_fetch - 1) * record_size;
        lseek(fd, offset, SEEK_SET);
        struct employee fetched_data;
        int bytes = read(fd, &fetched_data, record_size);
        if(bytes > 0) {
            printf("Employee id: %d\n", fetched_data.id);
            printf("Employee first name: %s\n", fetched_data.fname);
            printf("Employee last name: %s\n", fetched_data.lname);
        } else {
            printf("Record not found!\n");
        }
    }

    return 0;
}

void initiate_db(int fd) {
    struct employee e1, e2, e3;
    populate_data(&e1, 1, "Md Niaz", "Prodhan");
    populate_data(&e2, 2, "Khadija", "Siddiqua");
    populate_data(&e3, 3, "John", "Doe");
    int record_size = sizeof (struct employee);
    int success1 = write_to_file(fd, &e1, record_size);
    int success2 = write_to_file(fd, &e2, record_size);
    int success3 = write_to_file(fd, &e3, record_size);
}

void populate_data(struct employee *e, int id, char *fname, char *lname) {
    e->id = id;
    strcpy(e->fname, fname);
    strcpy(e->lname, lname);
}

int write_to_file(int fd, struct employee *e, int size) {
    int bytes = write(fd, e, size);
    if (bytes) {
        return 1;
    } else { 
        return -1;
    }
}