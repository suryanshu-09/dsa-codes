#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int front;
    int rear;
    int size;
} CircularQueue;
CircularQueue* createQueue(int size) {
    CircularQueue *queue = (CircularQueue*) malloc(sizeof(CircularQueue));
    queue->arr = (int*) malloc(size * sizeof(int));
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
    return queue;
}
int isFull(CircularQueue *queue) {
    return ((queue->rear + 1) % queue->size == queue->front);
}
int isEmpty(CircularQueue *queue) {
    return (queue->front == -1);
}
void enqueue(CircularQueue *queue, int element) {
    if (isFull(queue)) {
        printf("Queue is full. Element cannot be enqueued.\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % queue->size;
    queue->arr[queue->rear] = element;
    printf("%d enqueued to queue.\n", element);
}
int dequeue(CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Element cannot be dequeued.\n");
        return -1;
    }
    int element = queue->arr[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % queue->size;
    }
    printf("%d dequeued from queue.\n", element);
    return element;
}
void display(CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Elements in queue are: ");
    int i = queue->front;
    do {
        printf("%d ", queue->arr[i]);
        i = (i + 1) % queue->size;
    } while (i != (queue->rear + 1) % queue->size);
    printf("\n");
}

int main() {
    CircularQueue *queue = createQueue(5);
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);
    enqueue(queue, 60); 
    display(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    display(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue); 
    return 0;
}

