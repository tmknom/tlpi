#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include "tlpi_hdr.h"

int
main(int argc, char *argv[]) {
    size_t len;
    off_t offset;
    int fd, ap, j;
    int openFlags;
    mode_t filePerms;
    char *buf;
    ssize_t numRead, numWritten;

    if (argc < 3 || strcmp(argv[1], "--help") == 0)
        usageErr("%s file {r<length>|R<length>|w<string>|s<offset>}...\n", argv[0]);

    openFlags = O_CREAT | O_RDWR;
    filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;
    fd = open(argv[1], openFlags, filePerms);
    if (fd == -1)
        errExit("opening file %s", argv[2]);

    for (ap = 2; ap < argc; ++ap) {
        switch (argv[ap][0]) {
            case 'r':
            case 'R':
                len = getLong(&argv[ap][1], GN_ANY_BASE, argv[ap]);
                buf = malloc(len);
                if (buf == NULL)
                    errExit("malloc");

                numRead = read(fd, buf, len);
                if (numRead == -1)
                    errExit("read");

                if (numRead == 0) {
                    printf("%s: end-of-file\n", argv[ap]);
                } else {
                    printf("%s: ", argv[ap]);
                    for (j = 0; j < numRead; ++j) {
                        if (argv[ap][0] == 'r') {
                            printf("%c", isprint((unsigned char) buf[j]) ? buf[j] : '?');
                        } else {
                            printf("%02x ", (unsigned char) buf[j]);
                        }
                    }
                    printf("\n");
                }
                free(buf);
                break;
            case 'w':
                numWritten = write(fd, &argv[ap][1], strlen(&argv[ap][1]));
                if (numWritten == -1)
                    errExit("write");
                printf("%s: wrote %ld bytes\n", argv[ap], (long) numWritten);
                break;
            case 's':
                offset = getLong(&argv[ap][1], GN_ANY_BASE, argv[ap]);
                if (lseek(fd, offset, SEEK_SET) == -1)
                    errExit("lseek");
                printf("%s: seek succeeded\n", argv[ap]);
                break;
            default:
                cmdLineErr("Argument must start wit [rRws]: %s\n", argv[ap]);
        }
    }

    if (close(fd) == -1)
        errExit("close");

    exit(EXIT_SUCCESS);
}
