#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *data;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->data = (int*) malloc(queue->capacity * sizeof(int));
    return queue;
}

int isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

void enqueue(Queue* queue, int item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->data[queue->rear] = item;
    queue->size = queue->size + 1;
}

int dequeue(Queue* queue) {
    if (isEmpty(queue))
        return -1;
    int item = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

char* predictPartyVictory(char* senate) {
    int n = strlen(senate);
    Queue* queueR = createQueue(n);
    Queue* queueD = createQueue(n);

    for (int i = 0; i < n; i++) {
        if (senate[i] == 'R') {
            enqueue(queueR, i);
        } else {
            enqueue(queueD, i);
        }
    }

    while (!isEmpty(queueR) && !isEmpty(queueD)) {
        int r_index = dequeue(queueR);
        int d_index = dequeue(queueD);
        
        if (r_index < d_index) {
            enqueue(queueR, r_index + n);
        } else {
            enqueue(queueD, d_index + n);
        }
    }

    char* result = (char*) malloc(8 * sizeof(char));
    if (isEmpty(queueR)) {
        strcpy(result, "Dire");
    } else {
        strcpy(result, "Radiant");
    }

    free(queueR->data);
    free(queueD->data);
    free(queueR);
    free(queueD);

    return result;
}
