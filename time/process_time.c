#include <stdio.h>
#include <sys/times.h> // for struct tms
#include <time.h> // for the time related functions - clock(), times()
#include <fcntl.h> // required for open()
#include <unistd.h> // required for read(), write(), close()

void process_to_measure();

int main(void) {
    struct tms tms_buffer;

    // measure CPU time
    clock_t start_time = clock();
    process_to_measure();
    clock_t end_time = clock();
    double time_spent = ((double) end_time - start_time) / CLOCKS_PER_SEC;
    printf("Total time spent: %.2lf sec\n", time_spent);

    // display process time
    times(&tms_buffer);
    printf("User Time       = %.2lf sec\n", (double)tms_buffer.tms_utime / sysconf(_SC_CLK_TCK) );
    printf("System Time     = %.2lf sec\n", (double)tms_buffer.tms_stime / sysconf(_SC_CLK_TCK) );
    return 0;
}

void process_to_measure() {
    int fd = open("/dev/null", O_RDWR);
    for (int i=0; i<10000000; i++) {
        write(fd, &i, sizeof(i));
    }
}