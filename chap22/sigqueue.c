#define _POSIX_C_SOURCE 199309

#include <signal.h>
#include "tlpi_hdr.h"

int
main(int argc, char *argv[]) {
    int j, sig, numSigs, sigData;
    union sigval sv;

    if (argc < 4 || strcmp(argv[1], "--help") == 0)
        usageErr("%s pid sig-num data [num-sigs]\n", argv[0]);

    printf("%s: PID is %ld, UID is %ld\n", argv[0], (long) getpid(), (long) getuid());

    sig = getInt(argv[2], 0, "sig-num");
    sigData = getLong(argv[3], GN_ANY_BASE, "data");
    numSigs = (argc > 4) ? getInt(argv[4], GN_GT_0, "num-sigs") : 1;

    for (j = 0; j < numSigs; ++j) {
        sv.sival_int = sigData + j;
        if (sigqueue(getLong(argv[1], 0, "pid"), sig, sv) == -1)
            errExit("sigqueue");
    }

    exit(EXIT_SUCCESS);
}
