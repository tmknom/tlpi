#include "tlpi_hdr.h"

int
main(int argc, char *argv[]) {
    int pfd[2];
    int j, dummy;

    if (argc < 2 || strcmp(argv[1], "--help") == 0)
        usageErr("%s sleep-time...\n", argv[0]);

    setbuf(stdout, NULL);
    printf("%s Parent standard\n", currTime("%T"));

    if (pipe(pfd) == -1)
        errExit("pipe");

    for (j = 1; j < argc; ++j) {
        switch (fork()) {
            case -1:
                errExit("fork %d", j);
            case 0:
                if (close(pfd[0]) == -1)
                    errExit("close");

                sleep(getInt(argv[j], GN_NONNEG, "sleep-time"));
                printf("%s Child %d (PID=%ld) closing pipe\n", currTime("%T"), j, (long) getpid());

                if (close(pfd[1]) == -1)
                    errExit("close");
                _exit(EXIT_SUCCESS);
            default:
                break;
        }
    }

    if (close(pfd[1]) == -1)
        errExit("close");

    if (read(pfd[0], &dummy, 1) != 0)
        fatal("parent didn't get EOF");

    printf("%s Parent ready to go\n", currTime("%T"));
    exit(EXIT_SUCCESS);
}
