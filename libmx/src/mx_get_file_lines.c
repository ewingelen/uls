#include "../inc/libmx.h"

char **mx_get_file_lines(const char *file_name) {
    char *file_content = mx_file_to_str(file_name);
    char **lines = mx_strsplit(file_content, '\n');

    mx_strdel(&file_content);
    return lines;
}
