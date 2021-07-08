#define _GNU_SOURCE

#include <time.h>
#include <utmpx.h>
#include <paths.h>
#include "tlpi_hdr.h"

int
main(int argc, char *argv[]) {
    struct utmpx ut;
    char *devName;

    if (argc < 2 || strcmp(argv[1], "--help") == 0)
        usageErr("%s username [sleep-time]\n", argv[0]);

    memset(&ut, 0, sizeof(struct utmpx));
    ut.ut_type = USER_PROCESS;
    strncpy(ut.ut_user, argv[1], sizeof(ut.ut_user));
    if (time(&ut.ut_tv.tv_sec) == -1)
        errExit("time");
    ut.ut_pid = getpid();

    devName = ttyname(STDIN_FILENO);
    if (devName == NULL)
        errExit("ttyname");
    if (strlen(devName) <= 8)
        fatal("Terminal name is too short: %s", devName);

    strncpy(ut.ut_line, devName + 5, sizeof(ut.ut_line));
    strncpy(ut.ut_id, devName + 8, sizeof(ut.ut_id));

    printf("Creating login entries\n");
    printf("     using pid %ld, line %.*s, id %.*s\n",
           (long) ut.ut_pid, (int) sizeof(ut.ut_line), ut.ut_line, (int) sizeof(ut.ut_id), ut.ut_id);

    setutxent();
    if (pututxline(&ut) == NULL)
        errExit("pututxline");
    updwtmpx(_PATH_WTMP, &ut);

    sleep((argc > 2) ? getInt(argv[2], GN_NONNEG, "sleep-time") : 15);

    ut.ut_type = DEAD_PROCESS;
    time(&ut.ut_tv.tv_sec);
    memset(&ut.ut_user, 0, sizeof(ut.ut_user));

    printf("Creating logout entries\n");
    setutxent();
    if (pututxline(&ut) == NULL)
        errExit("pututxline");
    updwtmpx(_PATH_WTMP, &ut);

    endutxent();
    exit(EXIT_SUCCESS);
}
