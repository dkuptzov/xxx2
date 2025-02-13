#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

typedef enum {
    SUCCESS,
    FAIL
} Result;

struct door {
    int id;
    int status;
};

struct node {
    struct door* data;
    struct node* next;
};

struct node* init(struct door* door);
struct node* add_door(struct node* elem, struct door* door);
struct node* find_door(int door_id, struct node* root);
struct node* remove_door(struct node* elem, struct node* root);
void destroy(struct node* root);

#endif // LIST_H
