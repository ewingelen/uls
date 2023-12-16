#include "../inc/libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)) {
    bool swapped = true;
    t_list *current;
    t_list *lastSwapped = NULL;

    if (lst == NULL || lst->next == NULL) {
        return lst;
    }

    while (swapped) {
        swapped = false;
        current = lst;

        while (current->next != lastSwapped) {
            if (cmp(current->data, current->next->data)) {
                swapped = true;
                void *temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
            }
            current = current->next;
        }

        lastSwapped = current;
    }

    return lst;
}
