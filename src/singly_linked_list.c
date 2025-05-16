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

    if(list->last == NULL) {
        list->last = new_node;
    }
    list->first = new_node;
    new_node->next = tmp;
    list->length++;
}

void list_push_last_slow(List *list, int data)
{
    Node *new_node = create_node(data);
    Node *current = list->first;
    if (current == NULL) {
        list->first = new_node;
        list->last = new_node;
        return;
    }
    do {
        current = current->next;
    }
    while (current->next != NULL);
    current->next = new_node;
    list->last = new_node;
    list->length++;
}

void list_push_last(List *list, int data)
{
    Node *new_node = create_node(data);
    Node *current = list->first;
    if (current == NULL) {
        list->first = new_node;
        list->last = new_node;
        return;
    }
    list->last->next = new_node;
    list->last = new_node;
    list->length++;
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

    list_push_first(my_list, 4);
    list_push_first(my_list, 10);
    list_push_first(my_list, 30);
    list_push_last(my_list, 20);
    list_push_last(my_list, 100);

    printf("Length of my list is: %d\n", list_len(my_list));
    printf("Is my List empty? %d\n", is_empty(my_list));

    print_list(my_list);

    return 0;
}
