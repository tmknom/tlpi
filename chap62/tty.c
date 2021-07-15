#include <termios.h>
#include <signal.h>
#include <ctype.h>
#include "tlpi_hdr.h"

static struct termios userTemios;

static void
handler(int sig) {
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &userTemios) == -1)
        errExit("tcsetattr");
    _exit(EXIT_SUCCESS);
}

static void
tstpHandler(int sig) {
    struct termios ourTemios;
    sigset_t tstpMask, prevMask;
    struct sigaction sa;
    int savedErrno;

    savedErrno = errno;

    if (tcgetattr(STDIN_FILENO, &ourTemios) == -1)
        errExit("tcgetattr");
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &userTemios) == -1)
        errExit("tcsetattr");

    if (signal(SIGTSTP, SIG_DFL) == SIG_ERR)
        errExit("signal");
    raise(SIGTSTP);

    sigemptyset(&tstpMask);
    sigaddset(&tstpMask, SIGTSTP);
    if (sigprocmask(SIG_UNBLOCK, &tstpMask, &prevMask) == -1)
        errExit("sigprocmask");

    if (sigprocmask(SIG_SETMASK, &prevMask, NULL) == -1)
        errExit("sigprocmask");

    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;
    sa.sa_handler = tstpHandler;
    if (sigaction(SIGTSTP, &sa, NULL) == -1)
        errExit("sigaction");

    if (tcgetattr(STDIN_FILENO, &userTemios) == -1)
        errExit("tcgetattr");
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &ourTemios) == -1)
        errExit("tcsetattr");

    errno = savedErrno;
}

int
main(int argc, char *argv[]) {
    char ch;
    struct sigaction sa, prev;
    ssize_t n;

    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;

    if (argc > 1) {
        if (ttySetCbreak(STDIN_FILENO, &userTemios) == -1)
            errExit("ttySetCbreak");

        sa.sa_handler = handler;
        if (sigaction(SIGQUIT, NULL, &prev) == -1)
            errExit("sigaction");
        if (prev.sa_handler != SIG_IGN)
            if (sigaction(SIGQUIT, &sa, NULL) == -1)
                errExit("sigaction");

        if (sigaction(SIGINT, NULL, &prev) == -1)
            errExit("sigaction");
        if (prev.sa_handler != SIG_IGN)
            if (sigaction(SIGINT, &sa, NULL) == -1)
                errExit("sigaction");

        sa.sa_handler = tstpHandler;
        if (sigaction(SIGTSTP, NULL, &prev) == -1)
            errExit("sigaction");
        if (prev.sa_handler != SIG_IGN)
            if (sigaction(SIGTSTP, &sa, NULL) == -1)
                errExit("sigaction");
    } else {
        if (ttySetRaw(STDIN_FILENO, &userTemios) == -1)
            errExit("ttySetRaw");
    }

    sa.sa_handler = handler;
    if (sigaction(SIGTERM, &sa, NULL) == -1)
        errExit("sigaction");

    setbuf(stdout, NULL);

    for (;;) {
        n = read(STDIN_FILENO, &ch, 1);
        if (n == -1) {
            errMsg("read");
            break;
        }

        if (n == 0)
            break;

        if (isalpha((unsigned char) ch))
            putchar(tolower((unsigned char) ch));
        else if (ch == '\n' || ch == '\r')
            putchar(ch);
        else if (iscntrl((unsigned char) ch))
            printf("^%c", ch ^ 64);
        else
            putchar('*');

        if (ch == 'q')
            break;
    }

    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &userTemios) == -1)
        errExit("tcsetattr");
    exit(EXIT_SUCCESS);
}
