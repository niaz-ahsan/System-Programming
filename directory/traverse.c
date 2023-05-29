#include <stdio.h>
#include <dirent.h> // for opendir(), readdir(), closedir(), dirent struct
#include <limits.h> // for PATH_MAX const - determines max file path length of the current OS
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

void print_file_name(char *filepath, int depth) {
    int i;
    for (i=0; i<depth; i++) {
        printf("\t");
    }
    printf("|_ %s\n", filepath);
}

void traverse_directory(char *path, int depth) {
    //printf("Inside function: %s & %d", path, depth);
    DIR *dir;
    dir = opendir(path);
    if (dir == NULL) {
        printf("Error: Failed to open: %s\n", path);
        exit(1);
    }
    struct dirent *dir_entry;
    while ( (dir_entry = readdir(dir)) != NULL ) {
        if (dir_entry->d_type != DT_DIR) { // dir entry is not a dir
            print_file_name(dir_entry->d_name, depth);
        } else { // dir entry is a dir
            // no need to print ./ (current dir) and ../ (parent dir)
            int cur_dir = strcmp(dir_entry->d_name, ".");
            int parent_dir = strcmp(dir_entry->d_name, "..");
            if ((cur_dir != 0) && (parent_dir != 0)) {
                /* 
                if the dir is not . or .. - then 
                print dir name
                reshape the dir path
                call this function recursively
                */
                print_file_name(dir_entry->d_name, depth);
                char dir_path[PATH_MAX];
                strcpy(dir_path, path);
                strcat(dir_path, "/");
                strcat(dir_path, dir_entry->d_name);
                traverse_directory(dir_path, (depth + 1));
            }
        }
    }
    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Error: Provide directory path\n");
        exit(1);
    }

    // check metadata of the provided path
    struct stat *dir_metadata = (struct stat *) malloc(sizeof(struct stat));
    if (stat(argv[1], dir_metadata) < 0) {
        printf("Error: Failed to load directory metadata\n");
        exit(1);
    } 

    // check if path is a directory
    if ((dir_metadata->st_mode & S_IFMT) != S_IFDIR) {
        printf("Error: Provided path is not a directory!\n");
        exit(1);
    }

    // all checks done, traverse now...
    traverse_directory(argv[1], 0);
    return 0;
}