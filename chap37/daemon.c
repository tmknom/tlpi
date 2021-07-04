#include <sys/stat.h>
#include <fcntl.h>
#include "tlpi_hdr.h"

int
main(int argc, char *argv[]) {
    becomeDaemon(0);
    sleep((argc > 1) ? getInt(argv[1], GN_GT_0, "sleep-time") : 120);
    exit(EXIT_SUCCESS);
}
