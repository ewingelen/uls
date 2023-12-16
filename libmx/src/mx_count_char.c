int mx_count_char(const char *s, char c) {
    int char_count = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == c) {
            char_count++;
        }
    }

    return char_count;
}
