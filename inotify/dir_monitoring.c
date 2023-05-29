/*
Add a directory to inotify API and keep watch for changes
*/

#include <stdio.h>
#include <limits.h> // for PATH_MAX, NAME_MAX
#include <sys/inotify.h>
#include <sys/stat.h>
#include <stdlib.h>

// 250x inotify_events and for each - space of length of name is taken. 
#define BUFFER_SIZE (250 * (sizeof(struct inotify_event) + NAME_MAX + 1 ))

int main(int argc, char *argv[]) {
    // check if user provided directory to watch
    if (argc < 2) {
        printf("Error: Provide directory path for monitoring\n");
        exit(1);
    }
    // collect metadata of path
    struct stat *path_metadata = malloc(sizeof(struct stat));;
    if ( stat(argv[1], path_metadata) < 0 ) {
        printf("Error: Unable to collect metadata of provided path\n");
        exit(1);
    }
    // check if provided path is a directory
    if ( (path_metadata->st_mode & S_IFMT) != S_IFDIR) {
        printf("Error: Provided path is not a valid directory\n");
        exit(1);
    }
    // initialize inotify instance
    int inotify_instance = inotify_init();
    if (inotify_instance < 0) {
        printf("Failed to load inotify API\n");
        exit(1);
    }
    // Add dir to the watch list
    int events = IN_ACCESS |IN_CREATE | IN_ATTRIB | IN_DELETE;
    if ( inotify_add_watch(inotify_instance, argv[1], events) < 0 ) {
        printf("Directory is unable to be added in the inotify watch list\n");
        exit(1);
    }
    // Continuously look for changes
    printf("Monitoring %s for file creation, modification, deletion\n", argv[1]);
    char event_buffer[BUFFER_SIZE];
    struct inotify_event *event;
    while (1) {
        int bytes_read = read(inotify_instance, event_buffer, BUFFER_SIZE);
        for (char * p = event_buffer; p < event_buffer + bytes_read;) {
            event = (struct inotify_event *) p;
            p += sizeof(struct inotify_event) + event->len; // increment p's location to next block
            switch(event->mask) {
                case IN_ACCESS:
                    printf("%s/%s was accessed\n", argv[1], event->name);
                    break;
                case IN_CREATE:
                    printf("%s/%s was created\n", argv[1], event->name);
                    break;
                case IN_ATTRIB:
                    printf("%s/%s was modified\n", argv[1], event->name);
                    break;
                case IN_DELETE:
                    printf("%s/%s was deleted\n", argv[1], event->name);
                    break;
            }
        }
    }

    return 0;
}