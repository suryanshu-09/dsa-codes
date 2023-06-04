#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int *arr;
    int front;
    int rear;
    int size;
} Queue;
Queue* createQueue(int size) {
    Queue *queue = (Queue*) malloc(sizeof(Queue));
    queue->arr = (int*) malloc(size * sizeof(int));
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
    return queue;
}
int isFull(Queue *queue) {
    return (queue->rear == queue->size - 1);
}
int isEmpty(Queue *queue) {
    return (queue->front == -1 || queue->front > queue->rear);
}
void enqueue(Queue *queue, int element) {
    if (isFull(queue)) {
        printf("Queue is full. Element cannot be enqueued.\n");
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->rear++;
    queue->arr[queue->rear] = element;
    printf("%d enqueued to queue.\n", element);
}
int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Element cannot be dequeued.\n");
        return -1;
    }
    int element = queue->arr[queue->front];
    queue->front++;
    printf("%d dequeued from queue.\n", element);
    return element;
}
void display(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Elements in queue are: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}
int main() {
    Queue *queue = createQueue(5);
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

