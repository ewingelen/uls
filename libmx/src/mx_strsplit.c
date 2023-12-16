#include "../inc/libmx.h"

char **mx_strsplit(const char *s, char c) {
    if (s == NULL)
        return NULL;

    int words_count = mx_count_words(s, c);
    char **arr = malloc(sizeof(char *) * (words_count + 1));
    int arr_add_index = 0;
    int word_start;

    if (arr == NULL)
        return NULL;
    else if (mx_str_contains(s, c) == 0) {
        arr[0] = mx_strdup(s);
        if (arr[0] == NULL) {
            free(arr);
            return NULL;
        }

        arr[1] = NULL;
        return arr;
    }

    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] != c) {
            word_start = i;
            while (s[i] && s[i] != c)
                i++;
            arr[arr_add_index] = mx_strndup(&s[word_start], i - word_start);
            if (arr[arr_add_index] == NULL) {
                for (int j = 0; j < arr_add_index; j++)
                    mx_strdel(&arr[j]);
                free(arr);
                return NULL;
            }
            arr_add_index++;
            if (s[i] == '\0')
                break;
        }

    arr[arr_add_index] = NULL;
    return arr;
}
