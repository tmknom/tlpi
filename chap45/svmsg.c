#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/stat.h>
#include "tlpi_hdr.h"

#define KEY_FILE "/work/Makefile"

int
main(int argc, char *argv[]) {
    int msgid;
    key_t key;
    const int MQ_PERMS = S_IRUSR | S_IWUSR | S_IWGRP;

    key = ftok(KEY_FILE, 1);
    if (key == -1)
        errExit("ftok");

    while ((msgid = msgget(key, IPC_CREAT | IPC_EXCL | MQ_PERMS)) == -1) {
        if (errno == EEXIST) {
            msgid = msgget(key, 0);
            if (msgid == -1)
                errExit("msgget() failed to retrieve old queue ID");
            if (msgctl(msgid, IPC_RMID, NULL) == -1)
                errExit("msgget() failed to delete old queue");
            printf("Removed old message queue (id=%d)\n", msgid);
        } else {
            errExit("msgget() failed");
        }
    }

    exit(EXIT_SUCCESS);
}
