#define _XOPEN_SOURCE 500

#include <unistd.h>
#include <fcntl.h>
#include "tlpi_hdr.h"

int
main(int argc, char *argv[]) {
    if (fork() != 0)
        _exit(EXIT_SUCCESS);

    printf("before setsid(): PID=%ld, PGID=%ld, SID=%ld\n", (long) getpid(), (long) getpgrp(), (long) getsid(0));

    if (setsid() == -1)
        errExit("setsid");

    printf("after  setsid(): PID=%ld, PGID=%ld, SID=%ld\n", (long) getpid(), (long) getpgrp(), (long) getsid(0));

    if (open("/dev/tty", O_RDWR) == -1)
        errExit("open /dev/tty");

    exit(EXIT_SUCCESS);
}
