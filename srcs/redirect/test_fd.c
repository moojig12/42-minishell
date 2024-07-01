#include <minishell.h>
// #include <fcntl-linux.h>

# define FD_MAX 15

char *fcntl_flags(int flags)
{
    static char output[128];
    *output = 0;

    if (flags & O_RDONLY)
        strcat(output, "O_RDONLY ");
    if (flags & O_WRONLY)
        strcat(output, "O_WRONLY ");
    if (flags & O_RDWR)
        strcat(output, "O_RDWR ");
    if (flags & O_CREAT)
        strcat(output, "O_CREAT ");
    if (flags & O_EXCL)
        strcat(output, "O_EXCL ");
    if (flags & O_NOCTTY)
        strcat(output, "O_NOCTTY ");
    if (flags & O_TRUNC)
        strcat(output, "O_TRUNC ");
    if (flags & O_APPEND)
        strcat(output, "O_APPEND ");
    if (flags & O_NONBLOCK)
        strcat(output, "O_NONBLOCK ");
    if (flags & O_SYNC)
        strcat(output, "O_SYNC ");
    if (flags & O_ASYNC)
        strcat(output, "O_ASYNC ");

    return output;
}

char *fd_info(int fd)
{
    if (fd < 0 || fd >= FD_MAX)
        return FALSE;
    // if (fcntl(fd, F_GETFL) == -1 && errno == EBADF)
    int rv = fcntl(fd, F_GETFL);
    return (rv == -1) ? strerror(errno) : fcntl_flags(rv);
}

int pth_util_fd_valid(int fd)
{
    if (fd < 3 || fd >= FD_MAX)
        return FALSE;
    if (fcntl(fd, F_GETFL) == -1 && errno == EBADF)
        return FALSE;
    return TRUE;
}

/* check first 1024 (usual size of FD_SESIZE) file handles */
int test_fds()
{
    int i;
    int fd_dup;
    char errst[64];

    i = 0;
    while (i < FD_MAX)
    {
        *errst = 0;
        fd_dup = dup(i);
        if (fd_dup == -1) {
                strcpy(errst, strerror(errno));
                // EBADF  oldfd isnâ€™t an open file descriptor, or newfd is out of the allowed range for file descriptors.
                // EBUSY  (Linux only) This may be returned by dup2() during a race condition with open(2) and dup().
                // EINTR  The dup2() call was interrupted by a signal; see signal(7).
                // EMFILE The process already has the maximum number of file descriptors open and tried to open a new one.
        } else {
                close(fd_dup);
                strcpy(errst, "dup() ok");
        }
        fprintf(stderr, "%4i: %5i %24s %s\n", i, fcntl(i, 9), fd_info(i), errst);
    i++;
    }
    fprintf(stderr, "--------\n");
    return (EXIT_SUCCESS);
}
