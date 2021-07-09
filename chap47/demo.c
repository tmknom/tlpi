#include <sys/types.h>
#include <sys/sem.h>
#include <sys/stat.h>
#include "tlpi_hdr.h"

int
main(int argc, char *argv[]) {
    int semid;

    if (argc < 2 || argc > 3 || strcmp(argv[1], "--help") == 0)
        usageErr("%s init-value || %s semid operation\n", argv[0], argv[0]);

    if (argc == 2) {
        union semun arg;

        semid = semget(IPC_PRIVATE, 1, S_IRUSR | S_IWUSR);
        if (semid == -1)
            errExit("semget");

        arg.val = getInt(argv[1], 0, "init-value");
        if (semctl(semid, 0, SETVAL, arg) == -1)
            errExit("semctl");

        printf("Semaphore ID = %d\n", semid);
    } else {
        struct sembuf sop;

        semid = getInt(argv[1], 0, "semid");

        sop.sem_num = 0;
        sop.sem_op = getInt(argv[2], 0, "operation");
        sop.sem_flg = 0;

        printf("%ld: about to semop at %s\n", (long) getpid(), currTime("%T"));

        if (semop(semid, &sop, 1) == -1)
            errExit("semop");

        printf("%ld: completed at %s\n", (long) getpid(), currTime("%T"));
    }
    exit(EXIT_SUCCESS);
}
