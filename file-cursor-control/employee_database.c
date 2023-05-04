#include <stdio.h>
#include <fcntl.h> // required for open()
#include <unistd.h> // required for read(), write(), close()
#include <stdlib.h> // required for exit()
#include <string.h> 

struct employee {
    int id;
    char fname[20];
    char lname[20];
};

void populate_data(struct employee *, int, char *, char *);
int write_to_file(int, struct employee *, int);

int main(void) {
    struct employee e1, e2, e3;
    
    populate_data(&e1, 1, "Md Niaz", "Prodhan");
    populate_data(&e2, 2, "Khadija", "Siddiqua");
    populate_data(&e3, 3, "John", "Doe");

    int record_size = sizeof (struct employee);

    int fd = open("employee_database", O_RDWR | O_CREAT, S_IRWXU);

    if (! fd) {
        printf("Error opening file\nExiting ...\n");
        exit(1);
    }

    int success1 = write_to_file(fd, &e1, record_size);
    int success2 = write_to_file(fd, &e2, record_size);
    int success3 = write_to_file(fd, &e3, record_size);

    return 0;
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