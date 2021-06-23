#include <signal.h>
#include "tlpi_hdr.h"

#define XATTR_SIZE 10000

static void
sigHandler(int sig) {
    printf("Ouch!\n");
}

int
main(int argc, char *argv[]) {
    int j;

    if (signal(SIGINT, sigHandler) == SIG_ERR)
        errExit("signal");


    for (j = 0;; ++j) {
        printf("%d\n", j);
        sleep(3);
    }

    exit(EXIT_SUCCESS);
}
