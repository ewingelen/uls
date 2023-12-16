#include "../inc/libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    ssize_t bytes_read;
    size_t total_bytes = 0;
    char *buffer = malloc(buf_size);

    if (fd < 0 || lineptr == NULL || buffer == NULL) {
        if (buffer != NULL)
            free(buffer);
        return -2;
    }

    while ((bytes_read = read(fd, buffer + total_bytes, 1)) > 0) {
        if (buffer[total_bytes] == delim)
            break;

        total_bytes += bytes_read;

        if (total_bytes >= buf_size - 1) {
            buf_size *= 2;
            char *new_buffer = mx_realloc(buffer, buf_size);
            if (new_buffer == NULL) {
                free(buffer);
                return -2;
            }
            buffer = new_buffer;
        }
    }

    if (bytes_read == 0 && total_bytes == 0) {
        free(buffer);
        return -1;
    }

    *lineptr = malloc(total_bytes + 1);
    if (*lineptr == NULL) {
        free(buffer);
        return -2;
    }

    mx_memcpy(*lineptr, buffer, total_bytes);
    (*lineptr)[total_bytes] = '\0';

    free(buffer);
    return total_bytes;
}
