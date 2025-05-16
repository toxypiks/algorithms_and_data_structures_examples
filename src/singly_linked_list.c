#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct List {
    Node *nodes;
} List;

Node* create_node()
{
    Node *node = malloc(sizeof(Node));
    node->data = 0;
    node->next = NULL;
    return node;
}

List* create_list()
{
    List *new_list = malloc(sizeof(List));
    Node *new_node = create_node();
    new_list->nodes = new_node;
    return new_list;
}

bool is_empty(List *list)
{
    if (list->nodes->next == NULL) {
        return true;
    }
    return false;
}

int list_len(List *list)
{
    int length = 0;
    Node *current = list->nodes->next;

    while (current != NULL) {
        ++length;
        current = current->next;
    }

    return length;
}

int main (void)
{
    List *my_list = create_list();
    printf("Is my List empty? %d\n", is_empty(my_list));
    printf("Length of my list is: %d\n", list_len(my_list));
    return 0;
}
