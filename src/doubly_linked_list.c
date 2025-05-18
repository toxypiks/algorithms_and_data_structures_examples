#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct List {
    Node *node;
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
    new_list->node = NULL;
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

int main(void)
{
    List *my_list = create_list();
    printf("Is my list empty? %d\n", is_empty(my_list));

    return 0;
}
