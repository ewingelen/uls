#include "../inc/libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    int digits = 1;
    char *hex = mx_strnew(digits);

    if (nbr == 0) {
        return "0";
    }

    for (unsigned long i = nbr; i > 0; i /= 16) {
        digits++;
    }

    for (int i = digits - 2; i >= 0; i--) {
        unsigned long digit = nbr % 16;
        hex[i] = (char)(digit < 10 ? '0' + digit : 'a' + digit - 10);
        nbr /= 16;
    }

    return hex;
}
