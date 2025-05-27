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
        return NULL;
    }
    new_queue_node->next = NULL;
    new_queue_node->data = data;
    return new_queue_node;
}

Queue* create_queue()
{
    Queue *new_queue = malloc(sizeof(Queue));
    if (new_queue == NULL) {
        return NULL;
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

QueueNode* queue_dequeue(Queue *queue)
{
    if (queue == NULL || queue->front == NULL) {
        return NULL;
    }
    QueueNode *tmp = queue->front;
    queue->front = tmp->next;
    if (queue->front == NULL) {
        queue->back = NULL;
    }
    return tmp;
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

void print_queue(Queue *queue)
{
    if (queue == NULL) {
        return;
    }
    QueueNode *tmp = queue->front;
    while (tmp != NULL) {
        printf("%d\n", tmp->data);
        tmp = tmp->next;
    }
}

int main(void)
{
    Queue *my_queue = create_queue();
    printf("is empty? %d\n", is_empty(my_queue));

    queue_enqueue(my_queue, 5);
    queue_enqueue(my_queue, 8);
    queue_enqueue(my_queue, 10);
    queue_enqueue(my_queue, 9);

    print_queue(my_queue);
    return 0;
}
