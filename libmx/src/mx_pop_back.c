#include "../inc/libmx.h"

void mx_pop_back(t_list **head) {
    if (head == NULL || *head == NULL)
        return;

    if ((*head)->next != NULL) {
        t_list *current_list = *head;
        while (current_list->next->next != NULL) {
            current_list = current_list->next;
        }
        free(current_list->next);
        current_list->next = NULL;
    }
    else {
        free(*head);
        (*head) = NULL;
    }
}
