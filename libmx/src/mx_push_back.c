#include "../inc/libmx.h"

void mx_push_back(t_list **list, void *data) {
    t_list *node = mx_create_node(data);
    t_list *current = *list;

    if (*list == NULL) {
        *list = node;
        return;
    }

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = node;
}
