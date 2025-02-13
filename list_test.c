#include <stdio.h>
#include <stdlib.h>
#include "list.h"

Result test_add_door() {
    struct door door1 = { .id = 1, .status = 0 };
    struct door door2 = { .id = 2, .status = 1 };
    struct door door3 = { .id = 3, .status = 0 };

    struct node* head = init(&door1);
    struct node* current = head;

    current = add_door(current, &door2);
    current = add_door(current, &door3);

    if (head->next->data->id != 2 || head->next->next->data->id != 3) {
        destroy(head);
        return FAIL;
    }

    destroy(head);
    return SUCCESS;
}

Result test_remove_door() {
    struct door door1 = { .id = 1, .status = 0 };
    struct door door2 = { .id = 2, .status = 1 };
    struct door door3 = { .id = 3, .status = 0 };

    struct node* head = init(&door1);
    struct node* current = head;

    current = add_door(current, &door2);
    current = add_door(current, &door3);

    struct node* removed = remove_door(head->next, head);

    if (removed->next->data->id != 3) {
        destroy(removed);
        return FAIL;
    }

    destroy(removed);
    return SUCCESS;
}

int main() {
    Result result = test_add_door();
    if (result == FAIL) {
        return EXIT_FAILURE;
    }

    result = test_remove_door();
    if (result == FAIL) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
