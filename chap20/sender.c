#include <signal.h>
#include "tlpi_hdr.h"

int
main(int argc, char *argv[]) {
    int j, sig, numSigs;
    pid_t pid;

    if (argc < 4 || strcmp(argv[1], "--help") == 0)
        usageErr("%s pid num-sugs sig-num [sig-num-2]\n", argv[0]);

    pid = getLong(argv[1], 0, "PID");
    numSigs = getInt(argv[2], GN_GT_0, "num-sigs");
    sig = getInt(argv[3], 0, "sig-num");

    printf("%s: sending signal %d to process %ld %d times\n", argv[0], sig, (long) pid, numSigs);

    for (j = 0; j < numSigs; ++j)
        if (kill(pid, sig) == -1)
            errExit("kill");

    if (argc > 4)
        if (kill(pid, getInt(argv[4], 0, "sig-num")) == -1)
            errExit("kill");

    printf("%s: exiting\n", argv[0]);

    exit(EXIT_SUCCESS);
}
