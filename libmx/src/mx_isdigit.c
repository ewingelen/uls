#include "../inc/libmx.h"

bool mx_isdigit(const char c) {
    int digit_candidate = c - '0';

    if (digit_candidate >= 0 && digit_candidate <= 9) {
        return true;
    }
    else {
        return false;
    }
}
