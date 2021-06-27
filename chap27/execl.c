#include "tlpi_hdr.h"

int
main(int argc, char *argv[]) {
    printf("Initial value of HOME: %s\n", getenv("HOME"));
    if (putenv("HOME=/work") != 0)
        errExit("putenv");

    execl("/usr/bin/printenv", "printenv", "HOME", "PATH", (char *) NULL);
    errExit("execl");
}
