/*
user has 3 options g/s/r sent via cmd line arg
-g - get env var followed by the name(s) of the var
-s - set env var followed by "name value" format
-r - removes env var followed by name(s) of the var
*/

#include <stdio.h>
#include <stdlib.h> // for getenv(), setenv(), unsetenv() etc.
#include <unistd.h>

int main(int argc, char *argv[]) {
    int g_set = 0;
    int s_set = 0;
    int r_set = 0;
    int c;
    while( (c = getopt(argc, argv, "gsr")) != -1 ) {
        switch(c) {
            case 'g':
                g_set = 1;
                break;
            case 's':
                s_set = 1;
                break;
            case 'r':
                r_set = 1;
                break;
            case '?':
                printf("Usage:[exe] -g ENV_VAR_NAME\n");
                printf("Usage:[exe] -s ENV_VAR_NAME value\n");
                printf("Usage:[exe] -r ENV_VAR_NAME\n");
                printf("Multiple ENV_VAR are accepted!\n");
                exit(1);
                break;
        }
    }

    int options = g_set + s_set + r_set;
    if (options == 0) {
        printf("No option provided\n");
        printf("Usage:[exe] -g ENV_VAR_NAME\n");
        printf("Usage:[exe] -s ENV_VAR_NAME value\n");
        printf("Usage:[exe] -r ENV_VAR_NAME\n");
        printf("Multiple ENV_VAR are accepted!\n");
        exit(1);
    } else if (options > 1) {
        printf("Only one option from below should be provided\n");
        printf("Usage:[exe] -g ENV_VAR_NAME\n");
        printf("Usage:[exe] -s ENV_VAR_NAME value\n");
        printf("Usage:[exe] -r ENV_VAR_NAME\n");
        printf("Multiple ENV_VAR are accepted!\n");
        exit(1);
    }

    if (g_set) {
        for (int i = optind; i<argc; i++) {
            char *value = getenv(argv[i]);
            if(value == NULL) {
                printf("%s : No Env var found\n", argv[i]);
            } else {
                printf("%s : %s\n", argv[i], value);
            }
        }
    } else if (s_set) {
        for (int i = optind; i<argc; i+=2) {
            char *key = argv[i];
            char *value;
            if (argc >= i+1) {
                value = argv[i+1];
                int flag = setenv(key, value, 1); 
                if (flag == 0) { // success
                    printf("%s: %s is set\n", argv[i], argv[i+1]);
                } else { // error
                    printf("%s: Error setting\n", argv[i]);
                }
            } else {
                printf("%s: No value provided\n", argv[i]);
            }
            
        }
    } else if (r_set) {
        for (int i = optind; i<argc; i++) {
            int flag = unsetenv(argv[i]);
            if (flag == 0) {
                printf("%s: Properly removed/unset\n", argv[i]);
            } else {
                printf("%s: Failed to remove\n", argv[i]);
            }
        }
    }
    return 0;
}