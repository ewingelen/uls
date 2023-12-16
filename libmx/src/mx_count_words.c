#include "../inc/libmx.h"

int mx_count_words(const char *str, char c) {
    if (str == NULL) {
        return -1;
    }

    int word_count = 0;
    bool inside_word = false;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) {
            inside_word = false;
        }
        else {
            if (!inside_word) {
                word_count++;
            }
            inside_word = true;
        }
    }

    return word_count;
}
