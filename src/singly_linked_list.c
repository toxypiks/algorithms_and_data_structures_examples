#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct List {
    Node *first;
    Node *last;
    size_t length;
} List;

Node* create_node(int data)
{
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

List* create_list()
{
    List *new_list = malloc(sizeof(List));
    new_list->first = NULL;
    new_list->length = 0;
    return new_list;
}

bool is_empty(List *list)
{
    if (list->first == NULL) {
        return true;
    }
    return false;
}

bool is_empty_alt(List *list)
{
    if (list->length == 0) {
        return true;
    }
    return false;
}

int list_len_slow(List *list)
{
    int length = 0;
    Node *current = list->first;

    while (current != NULL) {
        ++length;
        current = current->next;
    }

    return length;
}

int list_len(List *list)
{
    return list->length;
}

void list_push_first(List *list, int data)
{
    Node *new_node = create_node(data);
    Node *tmp = list->first;

    if (list->first == NULL) {
        list->last = new_node;
    }
    list->first = new_node;
    new_node->next = tmp;
    list->length++;
}

void list_push_last(List *list, int data)
{
    Node *new_node = create_node(data);
    Node *current = list->first;
    if (current == NULL) {
        list->first = new_node;
        list->last = new_node;
        list->length++;
        return;
    }
    list->last->next = new_node;
    list->last = new_node;
    list->length++;
}

void list_push_to_position(List *list, int data, int position)
{
    Node *new_node = create_node(data);
    Node *current = list->first;
    Node *tmp_current = list->first;

    if (current != NULL && position > list->length) {
        printf("ERROR: Position out of range\n");
        free(new_node);
        return;
    }
    if (current == NULL && position > 0 || position == 1) {
        list_push_first(list, data);
        return;
    }
    if (position == 0) {
        printf("ERROR: Position must be greater than 0\n");
        free(new_node);
        return;
    }
    else {
        for (int i = 0; i < position - 2; ++i) {
            current = current->next;
        }
        tmp_current = current;
        current = current->next;
        tmp_current->next = new_node;
        new_node->next = current;
        list->length++;
    }
}

void list_delete_first(List *list)
{
    Node *first = list->first;
    if (list->first == NULL) {
        printf("List already empty\n");
        return;
    }
    Node *second = list->first->next;
    list->first = second;
    free(first);
}

void list_delete_last(List *list)
{
    Node *current = list->first;

    if (current == NULL) {
        printf("List already empty\n");
        return;
    }
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
}

void list_delete_at_position(List *list, int position)
{
    Node *current = list->first;
    Node *tmp_current = list->first;

    if (current == NULL) {
        printf("List already empty\n");
        return;
    }
    if (position == 0) {
        printf("Position must be greater than 0\n");
        return;
    }
    if (position > list->length && current != NULL) {
        printf("Position out of range\n");
        return;
    }
    if (position == 1) {
        list_delete_first(list);
    }
    else {
        for (int i = 0; i < position - 2; ++i) {
            current = current->next;
        }
        tmp_current = current->next->next;
        free(current->next);
        current->next = NULL;
        current->next = tmp_current;
    }

}

void print_list(List *list)
{
    Node *current = list->first;
    while (current != NULL) {
        printf("%d,", current->data);
        current = current->next;
    }
    printf("\n");
}


int main (void)
{
    List *my_list = create_list();
    printf("Is my List empty? %d\n", is_empty(my_list));
    printf("Length of my list is: %d\n", list_len(my_list));

    //list_push_first(my_list, 4);
    //list_push_first(my_list, 10);
    //list_push_first(my_list, 30);
    //list_push_last(my_list, 20);
    //list_push_last(my_list, 100);

    list_push_to_position(my_list, 4, 1);
    list_push_to_position(my_list, 6, 1);
    list_push_to_position(my_list, 7, 2);

    list_delete_at_position(my_list, 3);

    //list_push_to_position(my_list, 8, 2);
    //list_push_to_position(my_list, 9, 4);
    //list_push_to_position(my_list, 4, 0);

    //list_push_to_position(my_list, 9, 2); //TODO empty list

    printf("Length of my list is: %d\n", list_len(my_list));
    printf("Is my List empty? %d\n", is_empty(my_list));

    print_list(my_list);

    return 0;
}
