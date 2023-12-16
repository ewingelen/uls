#include "../inc/libmx.h"

char *mx_itoa(int number) {
    char *str = mx_strnew(12);
    int negative = 0;
    int arr[10];
    int counter = 0;

    if (number == -2147483648) {
        return "-2147483648";
    }
    else if (number == 0) {
        str[0] = '0';
        str[1] = '\0';
        return str;
    }
    else if (number < 0) {
        *str = '-';
        negative = 1;
        number = -number;
    }

    for (int i = 0; number != 0; i++) {
        arr[i] = number % 10;
        number /= 10;
        counter++;
    }

    for (int i = 0; i < counter; i++) {
        str[i + negative] = (char)(arr[counter - i - 1] + 48);
    }
    *(str + counter + negative) = '\0';
    return str;
}
