#include <stdio.h>
#include <stdlib.h>

// singly-linked list queue

typedef struct QueueNode {
    struct QueueNode *next;
    void *data;
} QueueNode;

typedef struct Queue {
    QueueNode *front;
    QueueNode *back;
} Queue;

QueueNode* create_queue_node(void *data)
{
    QueueNode *new_queue_node = malloc(sizeof(QueueNode));
    new_queue_node->next = NULL;
    new_queue_node->data = data;
    return new_queue_node;
}

Queue* create_queue()
{
    Queue *new_queue = malloc(sizeof(Queue));
    new_queue->front = NULL;
    new_queue->back = NULL;
    return new_queue;
}

bool is_empty(Queue *queue)
{
    return queue->front == NULL|| queue->back == NULL ? true : false;
}

int main(void)
{
    return 0;
}
