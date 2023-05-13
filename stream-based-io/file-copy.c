#include <stdio.h> // include stdio for fopen(), fread(), fwrite(), fclose()
#include <stdlib.h> // include stdlib for exit()

#define BUFFER_SIZE 4096

int main(void) {
    FILE *src_fp, *des_fp;
    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    // open src file in read mode
    src_fp = fopen("source.txt", "r");
    if (src_fp == NULL) {
        printf("Source file open error");
        exit(1);
    }

    // open des file in write mode
    des_fp = fopen("destination.txt", "w");
    if (des_fp == NULL) {
        printf("Destination file open error");
        exit(1);
    }

    // keep reading the src file and write to the des file
    while( (bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, src_fp)) > 0) {
        fwrite(buffer, sizeof(char), bytes_read, des_fp);
    }

    fclose(src_fp);
    fclose(des_fp);

    printf("File copy is complete!\n");

    return 0;
}