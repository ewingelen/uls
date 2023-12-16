unsigned long mx_hex_to_nbr(const char *hex) {
    unsigned long nbr = 0;

    for (int i = 0; hex[i] != '\0'; i++) {
        char current_char = hex[i];

        if (current_char >= '0'
            && current_char <= '9')
            nbr = nbr * 16 + (current_char - '0');
        else if (current_char >= 'A'
                 && current_char <= 'F')
            nbr = nbr * 16 + (current_char - 'A' + 10);
        else if (current_char >= 'a'
                 && current_char <= 'f')
            nbr = nbr * 16 + (current_char - 'a' + 10);
        else
            return 0;
    }

    return nbr;
}
