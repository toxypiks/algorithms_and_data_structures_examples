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

}


int main(void)
{
    printf("Hello World\n");
    return 0;
}
