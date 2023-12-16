#include "../inc/libmx.h"

bool mx_list_contains(t_list *head, char *str) {
    while (head != NULL) {
        char *current_element = (char *)(head->data);
        if (mx_strcmp(current_element, str) == 0)
            return true;
        head = head->next;
    }

    return false;
}
