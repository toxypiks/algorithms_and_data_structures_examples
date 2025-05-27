#include <stdio.h>
#include <stdlib.h>

// singly-linked list queue

typedef enum Result {
    SUCCESS,
    ERR_INVAL,
    ERR_NOMEM
} Result;

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

Result queue_destroy(Queue *queue)
{
    if (queue == NULL) {
        return ERR_INVAL;
    }
    while (queue->front != NULL) {
        QueueNode *tmp = queue->front;
        queue->front = tmp->next;
        free(tmp);
    }
    free(queue);
    return SUCCESS;
}

int main(void)
{
    return 0;
}
