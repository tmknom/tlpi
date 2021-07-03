#include <sys/time.h>
#include <sys/resource.h>
#include "tlpi_hdr.h"

int
main(int argc, char *argv[]) {
    int which, prio;
    id_t who;

    if (argc != 4 || strcmp(argv[1], "--help") == 0)
        usageErr("%s {p|g|u} who priority\n", argv[0]);

    which = (argv[1][0] == 'p') ? PRIO_PROCESS : (argv[1][0] == 'g') ? PRIO_PGRP : PRIO_USER;
    who = getLong(argv[2], 0, "who");
    prio = getInt(argv[3], 0, "prio");

    if (setpriority(which, who, prio) == -1)
        errExit("setpriority");

    errno = 0;
    prio = getpriority(which, who);
    if (prio == -1 && errno != 0)
        errExit("getpriority");

    printf("Nice value = %d\n", prio);
    exit(EXIT_SUCCESS);
}
