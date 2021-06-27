#define _GNU_SOURCE

#include <signal.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sched.h>
#include "tlpi_hdr.h"

#ifndef CHILD_STG
#define CHILD_STG SIGUSR1
#endif

static int
childFunc(void *arg) {
    if (close(*((int *) arg)) == -1)
        errExit("close");
    return 0;
}

int
main(int argc, char *argv[]) {
    const int STACK_SIZE = 65536;
    char *stack;
    char *stackTop;
    int s, fd, flags;

    fd = open("/dev/null", O_RDWR);
    if (fd == -1)
        errExit("open");

    flags = (argc > 1) ? CLONE_FILES : 0;

    stack = malloc(STACK_SIZE);
    if (stack == NULL)
        errExit("malloc");
    stackTop = stack + STACK_SIZE;

    if (CHILD_STG != 0 && CHILD_STG != SIGCHLD)
        if (signal(CHILD_STG, SIG_IGN) == SIG_ERR)
            errExit("signal");

    if (clone(childFunc, stackTop, flags | CHILD_STG, (void *) &fd) == -1)
        errExit("clone");

    if (waitpid(-1, NULL, (CHILD_STG != SIGCHLD) ? __WCLONE : 0) == -1)
        errExit("waitpid");
    printf("child has terminated\n");

    s = write(fd, "x", 1);
    if (s == -1 && errno == EBADF)
        printf("file descriptor %d has been close\n", fd);
    else if (s == -1)
        printf("write() on file descriptor %d failed unexpectedly (%s)\n", fd, strerror(errno));
    else
        printf("write() on file descriptor %d succeeded\n", fd);

    exit(EXIT_SUCCESS);
}
