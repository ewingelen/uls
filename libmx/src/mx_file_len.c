#include "../inc/libmx.h"

ssize_t mx_file_len(const char *file) {
    int fd = open(file, O_RDONLY);
    ssize_t num_bytes = 0;
    char buffer[2048];
    ssize_t result;

    if (fd < 0) {
        return -1;
    }

    while ((result = read(fd, buffer, sizeof(buffer))) > 0) {
        num_bytes += result;
    }

    if (result < 0) {
        close(fd);
        return -1;
    }

    close(fd);
    return num_bytes;
}
