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
struct employee fetch_data(int, int);
void print_record(struct employee *);
void update_record(struct employee *, char *, char *, int);

int main(int argc, char * argv[]) {
    int fd = open("employee_database", O_RDWR | O_CREAT, S_IRWXU);
    if (! fd) {
        printf("Error opening file\nExiting ...\n");
        exit(1);
    }
    int choice;

    while (1) {
        printf("\nPress your choice:\nPress (1) for generating db\nPress (2) for fetch data by id\nPress (3) for updating data\nPress (0) to quit\n");
        scanf("%d", &choice);
        
        if (choice == 1) {
            // generate the db file
            initiate_db(fd);
        } else if (choice == 2) {
            // fetch record
            int id;
            printf("Provide employee id:\n");
            scanf("%d", &id);
            struct employee record = fetch_data(id, fd);
            if (record.id > 0) {
                print_record(&record);
            } else {
                printf("No record found!\n");
            }
        } else if (choice == 3) {
            // update record
            int id;
            printf("Provide employee id:\n");
            scanf("%d", &id);
            struct employee record = fetch_data(id, fd);
            if(record.id > 0) {
                char fname[50]; 
                char lname[50];
                printf("Employee first name:\n");
                scanf("%s", fname);
                printf("Employee last name:\n");
                scanf("%s", lname);
                update_record(&record, fname, lname, fd);

            } else {
                printf("This record not found!\n");
            }
        } else if (choice == 0) {
            printf("Quitting...\n");
            break;
        } else {
            printf("I dont know what you want!\n");
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

struct employee fetch_data(int record_to_fetch, int fd) {
    int record_size = sizeof(struct employee);
    int offset = (record_to_fetch - 1) * record_size;
    lseek(fd, offset, SEEK_SET);
    struct employee fetched_data;
    int bytes = read(fd, &fetched_data, record_size);
    if (! bytes) {
        fetched_data.id = -1;
    }
    return fetched_data;    
}

void update_record(struct employee * record, char * fname, char * lname, int fd) {
    strcpy(record->fname, fname);
    strcpy(record->lname, lname);
    int record_size = sizeof(struct employee);
    int offset = (record->id - 1) * record_size;
    lseek(fd, offset, SEEK_SET);
    int success = write_to_file(fd, record, record_size);
}

void print_record(struct employee * record) {
    printf("\nEmployee Record\n========================================\n");
    printf("Employee id: %d\n", record->id);
    printf("Employee first name: %s\n", record->fname);
    printf("Employee last name: %s\n", record->lname);
}