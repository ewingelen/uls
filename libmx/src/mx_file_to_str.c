#include "../inc/libmx.h"

char *mx_file_to_str(const char *file) {
    if (file == NULL)
        return NULL;

    int fd = open(file, O_RDONLY);

    if (fd < 0)
        return NULL;

    ssize_t file_length = mx_file_len(file);

    if (file_length <= 0) {
        close(fd);
        return NULL;
    }

    char *str = mx_strnew((int)file_length);

    if (str == NULL) {
        close(fd);
        return NULL;
    }

    ssize_t read_size = read(fd, str, file_length);

    if (read_size == file_length) {
        str[file_length] = '\0';
        close(fd);
        return str;
    }
    else {
        mx_strdel(&str);
        close(fd);
        return NULL;
    }
}
