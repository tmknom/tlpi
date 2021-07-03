#include <sched.h>
#include "tlpi_hdr.h"

int
main(int argc, char *argv[]) {
    int j, pol;
    struct sched_param sp;

    if (argc < 3 || strcmp(argv[1], "--help") == 0)
        usageErr("%s {r|f|o} priority [pid...]\n", argv[0]);

    pol = (argv[1][0] == 'r') ? SCHED_RR : (argv[1][0] == 'f') ? SCHED_FIFO : SCHED_OTHER;

    sp.sched_priority = getInt(argv[2], 0, "priority");
    for (j = 3; j < argc; ++j) {
        if (sched_setscheduler(getLong(argv[j], 0, "pid"), pol, &sp) == -1) {
            errExit("sched_setscheduler");
        }
    }

    exit(EXIT_SUCCESS);
}
