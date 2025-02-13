#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// Функция для создания нового узла
struct node* create_node(struct door* door) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        perror("Ошибка выделения памяти.");
        exit(EXIT_FAILURE);
    }
    newNode->data = door;
    newNode->next = NULL;
    return newNode;
}

// Инициализация структуры односвязного списка на базе переданной struct door
struct node* init(struct door* door) {
    return create_node(door);
}

// Вставка нового элемента struct door в односвязный список после переданного узла elem
struct node* add_door(struct node* elem, struct door* door) {
    if (elem == NULL) {
        return create_node(door);  // Если elem равен NULL, создаем новый узел
    }

    struct node* newNode = create_node(door);
    newNode->next = elem->next;
    elem->next = newNode;
    return newNode;
}

// Поиск двери в списке по её id
struct node* find_door(int door_id, struct node* root) {
    struct node* current = root;
    while (current != NULL && current->data->id != door_id) {
        current = current->next;
    }
    return current;
}

// Удаление элемента списка
struct node* remove_door(struct node* elem, struct node* root) {
    if (root == NULL || elem == NULL) {
        return root;
    }

    if (root == elem) {
        struct node* temp = root;
        root = root->next;
        free(temp);
        return root;
    }

    struct node* current = root;
    while (current != NULL && current->next != elem) {
        current = current->next;
    }

    if (current != NULL) {
        struct node* temp = current->next;
        current->next = current->next->next;
        free(temp);
    }

    return root;
}

// Освобождение памяти, занимаемой структурой списка
void destroy(struct node* root) {
    struct node* current = root;
    while (current != NULL) {
        struct node* temp = current;
        current = current->next;
        free(temp->data);
        free(temp);
    }
}
