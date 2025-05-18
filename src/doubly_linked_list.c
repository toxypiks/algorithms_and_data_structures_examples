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
    list->last->next = new_node;
    new_node->prev = last_node;
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

    printf("Is my list empty? %d\n", is_empty(my_list));

    return 0;
}
