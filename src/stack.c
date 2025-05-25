#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct StackElement {
    int value;
    struct StackElement *last;
} StackElement;

typedef struct Stack {
    StackElement *top;
} Stack;

StackElement* create_stack_element(int value)
{
    StackElement *new_stack_element = malloc(sizeof(StackElement));
    new_stack_element->value = value;
    new_stack_element->last = NULL;
    return new_stack_element;
}

Stack* create_stack()
{
    Stack *new_stack = malloc(sizeof(Stack));
    new_stack->top = NULL;
    return new_stack;
}

bool is_empty(Stack *stack)
{
    return stack->top == NULL ? 1 : 0;
}

void stack_push(Stack *stack, int value)
{
    StackElement *new_element = create_stack_element(value);
    new_element->last = stack->top;
    stack->top = new_element;
}

int stack_pop(Stack *stack)
{
    if (is_empty(stack)) {
        return 1;
    }
    StackElement *remove = stack->top;
    stack->top = remove->last;
    int value = remove->value;
    free(remove);
    remove = NULL;
    return value;
}

void stack_print_elements(Stack *stack, StackElement *top)
{
    if (top) {
        stack_print_elements(stack, top->last);
        printf("%d ", top->value);
    }
}

void stack_print(Stack *stack)
{
    stack_print_elements(stack, stack->top);
}

int main(void)
{
    Stack *my_stack = create_stack();
    stack_push(my_stack, 2);
    stack_push(my_stack, 6);
    stack_push(my_stack, 4);
    stack_push(my_stack, 8);
    stack_push(my_stack, 9);
    stack_print(my_stack);

    printf("--------------\n");
    stack_pop(my_stack);
    stack_print(my_stack);
    return 0;
}
