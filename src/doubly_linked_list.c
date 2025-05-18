#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *prev;
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
    node->prev = NULL;
    node->next = NULL;
    return node;
}

List* create_list()
{
    List *new_list = malloc(sizeof(List));
    new_list->first = NULL;
    new_list->last = NULL;
    new_list->length = 0;
    return new_list;
}

bool is_empty(List *list)
{
    if (!list->length) {
        return true;
    }
    return false;
}

int list_len(List *list)
{
    return list->length;
}

void list_push_first(List *list, int data)
{
    Node *new_node = create_node(data);
    Node *first_node = list->first;

    if (first_node == NULL) {
        list->first = new_node;
        list->last = new_node;
        list->length++;
        return;
    }
    list->first = new_node;
    list->first->next = first_node;
    first_node->prev = list->first;
    list->length++;
}

void list_push_last(List *list, int data)
{
    Node *new_node = create_node(data);
    Node *first_node = list->first;
    Node *last_node = list->last;

    if(first_node == NULL) {
        list->first = new_node;
        list->last = new_node;
        list->length++;
        return;
    }
    list->last = new_node;
    last_node->next = new_node;
    list->last->prev = last_node;
    list->length++;
}

void list_push_to_position(List *list, int data, int position)
{
    Node *new_node = create_node(data);
    Node *current = list->first;
    Node *tmp_current = list->first;

    if (position == 0) {
        printf("ERROR: position must be greater than 0\n");
        return;
    }
    if (list->length > 0 && position > list->length || list->length == 0 && position > 0)  {
        printf("ERROR: position out of range\n");
        return;
    }
    if (list->length == 0 || position == 1) {
        list_push_first(list, data);
        return;
    }
    else {
        for (int i = 0; i < position - 2; ++i) {
            current = current->next;
        }
    }
    tmp_current = current;
    current = current->next;
    tmp_current->next = new_node;
    new_node->next = current;
    new_node->prev = tmp_current;
    list->length++;
}

void list_delete_first(List *list)
{
    Node *first = list->first;
    if (list->length == 0) {
        printf("ERROR: List already empty\n");
        return;
    }
    Node *second = list->first->next;
    list->first = second;
    list->first->prev = NULL;
    free(first);
    first = NULL;
    list->length--;
}

void list_delete_last(List *list)
{
    Node *last = list->last;
    if (list->length == 0) {
        printf("ERROR: List already empty\n");
        return;
    }
    Node *penultimate = last->prev;
    penultimate->next = NULL;
    free(last);
    last = NULL;
    list->length--;
}

void list_delete_at_position(List *list, int position)
{
    Node *current = list->first;

    if (position == 0) {
        printf("ERROR: position must be greater than 0\n");
        return;
    }
    if (list->length > 0 && position > list->length || list->length == 0 && position > 0)  {
        printf("ERROR: position out of range\n");
        return;
    }
    if (list->length == 0 || position == 1) {
        list_delete_first(list);
        return;
    }
    else {
        for (int i = 0; i < position - 1; ++i) {
            current = current->next;
        }
    }

    Node *current_next_next = current->next->next;
    free(current->next);
    current->next = NULL;
    current->next = current_next_next;
    current_next_next->prev = current;
    list->length--;
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

int main(void)
{
    List *my_list = create_list();
    printf("Is my list empty? %d\n", is_empty(my_list));

    list_push_first(my_list, 5);
    print_list(my_list);

    list_push_first(my_list, 8);
    print_list(my_list);

    list_push_first(my_list, 2);
    print_list(my_list);

    list_push_last(my_list, 1);
    print_list(my_list);

    printf("my_list last: %d\n", my_list->last->data);

    list_push_to_position(my_list, 10, 3);
    print_list(my_list);

    list_delete_at_position(my_list, 3);
    print_list(my_list);

    printf("Is my list empty? %d\n", is_empty(my_list));

    return 0;
}
