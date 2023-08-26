#include <stdio.h> // include stdio for fopen(), fread(), fwrite(), fclose()
#include <stdlib.h> // include stdlib for exit()

#define BUFFER_SIZE 50

int main(int argc, char *argv[]) {
    FILE *src_fp, *des_fp;
    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    if (argc < 3) {
        printf("Syntax: <exe> <file source path> <file destination path>\n");
        exit(1);
    }

    char *source = argv[1];
    char *destination = argv[2];

    // open src file in read mode
    src_fp = fopen(source, "r");
    if (src_fp == NULL) {
        printf("Source file open error\n");
        exit(1);
    }

    // open des file in write mode
    des_fp = fopen(destination, "w");
    if (des_fp == NULL) {
        printf("Destination file open error\n");
        exit(1);
    }

    // keep reading the src file and write to the des file
    int itr = 0;
    while( (bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, src_fp)) > 0) {
        itr++;
        printf("[itr %d]: bytes read: %zu\n", itr, bytes_read);
        fwrite(buffer, sizeof(char), bytes_read, des_fp);
    }

    fclose(src_fp);
    fclose(des_fp);

    printf("Total iterations: %d\n", itr);
    printf("File copy is complete!\n");

    return 0;
}