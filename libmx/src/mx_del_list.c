#include "../inc/libmx.h"

void mx_del_list(t_list *head) {
    while (head != NULL) {
        t_list *temp = head;
        head = head->next;
        free(temp);
    }
}
