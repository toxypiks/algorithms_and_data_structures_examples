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
        list->last = new_node;
    } else {
        first_node->prev = new_node;
    }
    list->first = new_node;
    list->first->next = first_node;
    list->length++;
}

void list_push_last(List *list, int data)
{
    Node *new_node = create_node(data);
    Node *first_node = list->first;
    Node *current = list->last;
    list->last = new_node;

    if(first_node == NULL) {
        list->first = new_node;
        list->length++;
        return;
    }
    current->next = new_node;
    list->last->prev = current;
    list->length++;
}

void list_push_to_position(List *list, int data, int position)
{
    Node *new_node = create_node(data);
    Node *current = list->first;
    Node *tmp_current = list->first;

    if (position == list->length) {
        list_push_last(list, data);
        return;
    }
    if (list->length == 0 && position > 0 || list->length > 0 && position > list->length)  {
        printf("ERROR: position out of range\n");
        return;
    }
    if (list->length == 0 && position == 0 || list->length > 0 && position == 0) {
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
    current->prev = new_node;
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
    else if (list->length == 1) {
        free(list->last);
        list->last = NULL;
        list->first = NULL;
        list->length--;
        return;
    }
    Node *second = list->first->next;
    list->first = second;
    list->first->prev = NULL;
    free(first);
    list->length--;
}

void list_delete_last(List *list)
{
    Node *last = list->last;
    if (list->length == 0) {
        printf("ERROR: List already empty\n");
        return;
    }
    else if (list->length == 1) {
        free(list->last);
        list->last = NULL;
        list->first = NULL;
        list->length--;
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

    if (current == NULL) {
        printf("ERROR: List already empty\n");
        return;
    }
    if (position == list->length) {
        list_delete_last(list);
        return;
    }
    if (list->length == 0 && position > 0 || list->length > 0 && position > list->length)  {
        printf("ERROR: Position out of range\n");
        return;
    }
    if (list->length == 0 && position == 0 || list->length > 0 && position == 0) {
        list_delete_first(list);
        return;
    }
    else {
        for (int i = 0; i < position - 2; ++i) {
            current = current->next;
        }
    }

    Node *current_next_next = current->next->next;
    free(current->next);
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

    list_push_to_position(my_list, 10, 1);
    print_list(my_list);

    list_delete_at_position(my_list, 3);
    print_list(my_list);

    list_delete_at_position(my_list, 1);
    print_list(my_list);

    list_delete_at_position(my_list, 3);
    print_list(my_list);

    printf("Is my list empty? %d\n", is_empty(my_list));

    return 0;
}
