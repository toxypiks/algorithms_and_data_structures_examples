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
    int data;
} QueueNode;

typedef struct Queue {
    QueueNode *front;
    QueueNode *back;
} Queue;

QueueNode* create_queue_node(int data)
{
    QueueNode *new_queue_node = malloc(sizeof(QueueNode));
    if (new_queue_node == NULL) {
        return ERR_NOMEM;
    }
    new_queue_node->next = NULL;
    new_queue_node->data = data;
    return new_queue_node;
}

Queue* create_queue()
{
    Queue *new_queue = malloc(sizeof(Queue));
    if (new_queue == NULL) {
        return ERR_NOMEN;
    }
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
    if (is_empty(queue)) {
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

int queue_dequeue(Queue *queue)
{
    if (queue == NULL || queue->front == NULL) {
        return NULL;
    }
    QueueNode *tmp = queue->front;
    int data = tmp->data;
    queue->front = tmp->next;
    if (queue->front == NULL) {
        queue->back = NULL;
    }
    free(tmp);
    return data;
}

int queue_enqueue(Queue *queue, int data)
{
    if(queue == NULL) {
        return ERR_INVAL;
    }
    QueueNode *node = create_queue_node(data);
    if (queue->back == NULL) {
        queue->front = queue->back = node;
    } else {
        queue->back->next = node;
        queue->back = node;
    }
    return SUCCESS;
}

int main(void)
{
    return 0;
}
