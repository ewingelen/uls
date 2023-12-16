int mx_str_contains(const char *s, char c) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == c) {
            return 1;
        }
    }

    return 0;
}
