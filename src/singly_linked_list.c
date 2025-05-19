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
    new_list->last = NULL;
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
    Node *current = list->last;
    list->last = new_node;

    if (current == NULL) {
        list->first = new_node;
        list->length++;
        return;
    }
    current->next = new_node;
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
    if (list->length == 0 && position == 0 || list->length > 0 && position == 0) {
        list_push_first(list, data);
        return;
    }
    if (list->length == 0 && position > 0 || list->length > 0 && position > list->length) {
        printf("ERROR: Position out of range\n");
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
        printf("ERROR: List already empty\n");
        return;
    } else if (list->length == 1) {
        free(list->last);
        list->last = NULL;
        list->first = NULL;
        list->length--;
        return;
    }
    Node *second = list->first->next;
    list->first = second;
    free(first);
    list->length--;
}

void list_delete_last(List *list)
{
    Node *current = list->first;

    if (current == NULL) {
        printf("ERROR: List already empty\n");
        return;
    } else if (list->length == 1) {
        free(list->last);
        list->last = NULL;
        list->first = NULL;
        list->length--;
        return;
    }
    while (current->next->next != NULL) {
        current = current->next;
    }
    list->last = current;
    free(current->next);
    current->next = NULL;
    list->length--;
}

void list_delete_at_position(List *list, int position)
{
    Node *current = list->first;
    Node *tmp_current = list->first;

    if (current == NULL) {
        printf("ERROR: List already empty\n");
        return;
    }
    if (position == list->length) {
        list_delete_last(list);
        return;
    }
    if (list->length == 0 && position > 0 || list->length > 0 && position > list->length) {
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
        tmp_current = current->next->next;
        free(current->next);
        current->next = tmp_current;
        list->length--;
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

void list_swap_positions(List *list, int position_a, int position_b)
{
    Node *current_a = list->first;
    Node *current_b = list->first;

    if (position_a > position_b) {
        printf("ERROR: First position must be smaller than second\n");
    }
    if (list->length < 2) {
        printf("ERROR: Too few elements in list\n");
    }
    if (position_a == position_b) {
        return;
    }
    for (size_t i = 0; i < position_a; ++i) {
        current_a = current_a->next;
    }
    for (size_t j = 0; j < position_b; ++j) {
        current_b = current_b->next;
    }

    int data_a = current_a->data;
    int data_b = current_b->data;

    list_delete_at_position(list, position_a);
    list_delete_at_position(list, position_b);

    list_push_to_position(list, data_b, position_a);
    list_push_to_position(list, data_a, position_b);
}

int main (void)
{
    List *my_list = create_list();
    printf("Is my List empty? %d\n", is_empty(my_list));
    printf("Length of my list is: %d\n", list_len(my_list));

    list_push_to_position(my_list, 4, 1);
    print_list(my_list);

    list_push_to_position(my_list, 4, 0);
    print_list(my_list);

    list_push_to_position(my_list, 6, 1);
    print_list(my_list);

    list_push_to_position(my_list, 9, 0);
    print_list(my_list);

    list_push_to_position(my_list, 7, 2);
    print_list(my_list);

    list_push_to_position(my_list, 7, 5);
    print_list(my_list);

    list_swap_positions(my_list, 1, 3);
    print_list(my_list);

    //list_delete_at_position(my_list, 3);

    printf("Length of my list is: %d\n", list_len(my_list));
    printf("Is my List empty? %d\n", is_empty(my_list));

    return 0;
}
