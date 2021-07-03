#include <sched.h>
#include "tlpi_hdr.h"

int
main(int argc, char *argv[]) {
    int j, pol;
    struct sched_param sp;

    for (j = 3; j < argc; ++j) {
        pol = sched_getscheduler(getLong(argv[j], 0, "pid"));
        if (pol == -1)
            errExit("sched_getscheduler");

        if (sched_getparam(getLong(argv[j], 0, "pid"), &sp) == -1)
            errExit("sched_getparam");

        printf("%s: %-5s %2d\n", argv[j],
               (pol == SCHED_OTHER) ? "OTHER" : (pol == SCHED_RR) ? "RR" : (pol == SCHED_FIFO) ? "FIFO" : "?",
               sp.sched_priority);
    }

    exit(EXIT_SUCCESS);
}
