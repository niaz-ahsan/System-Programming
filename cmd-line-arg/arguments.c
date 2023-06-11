#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int a_option_provided = 0;
    int b_option_provided = 0;
    int c_option_provided = 0;
    char b_arg[128];
    char c_arg[128];
    int option;

    while( (option = getopt(argc, argv, "ab:c::")) != -1) {
        switch(option) {
            case 'a':
                a_option_provided = 1;
                break;
            case 'b':
                b_option_provided = 1;
                if (optarg != 0) {
                    strcpy(b_arg, optarg);
                }
                break;
            case 'c':
                c_option_provided = 1;
                if(optarg != 0) {
                    strcpy(c_arg, optarg);
                }
                break;
            case '?':
                printf("Usage: %s -a -b [-b arg] -c [-c arg (optional)]\n", argv[0]);
                exit(1);
        }
    }

    (a_option_provided == 1)? printf("-a is set\n") : printf("-a not set\n");
    if (b_option_provided == 1) {
        printf("-b is set with arg: %s\n", b_arg);
    } else {
        printf("-b not set\n");
    }
    if(c_option_provided) {
        if (strcmp(c_arg, "") != 0) {
            // c_arg is not empty, hence provided by user
            printf("-c is set with arg: %s\n", c_arg);
        } else {
            printf("-c is set with no arg\n");
        }
    } else {
        printf("-c not set\n");
    }
    
    for (int i = optind; i<argc; i++) {
        printf("Non option argument: %s\n", argv[i]);
    }

    return 0;
}