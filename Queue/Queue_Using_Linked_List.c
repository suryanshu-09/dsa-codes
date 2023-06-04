#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;
typedef struct {
    Node *front;
    Node *rear;
} Deque;
Deque* createDeque() {
    Deque *deque = (Deque*) malloc(sizeof(Deque));
    deque->front = NULL;
    deque->rear = NULL;
    return deque;
}
int isEmpty(Deque *deque) {
    return (deque->front == NULL);
}
void addFront(Deque *deque, int element) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = element;
    newNode->prev = NULL;
    newNode->next = deque->front;
    if (isEmpty(deque)) {
        deque->rear = newNode;
    } else {
        deque->front->prev = newNode;
    }
    deque->front = newNode;
    printf("%d added to front of deque.\n", element);
}
void addRear(Deque *deque, int element) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = element;
    newNode->prev = deque->rear;
    newNode->next = NULL;
    if (isEmpty(deque)) {
        deque->front = newNode;
    } else {
        deque->rear->next = newNode;
    }
    deque->rear = newNode;
    printf("%d added to rear of deque.\n", element);
}
int removeFront(Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Element cannot be removed from front.\n");
        return -1;
    }
    Node *temp = deque->front;
    int element = temp->data;
    deque->front = temp->next;
    if (deque->front == NULL) {
        deque->rear = NULL;
    } else {
        deque->front->prev = NULL;
    }
    free(temp);
    printf("%d removed from front of deque.\n", element);
    return element;
}
int removeRear(Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Element cannot be removed from rear.\n");
        return -1;
    }
    Node *temp = deque->rear;
    int element = temp->data;
    deque->rear = temp->prev;
    if (deque->rear == NULL) {
        deque->front = NULL;
    } else {
        deque->rear->next = NULL;
    }
    free(temp);
    printf("%d removed from rear of deque.\n", element);
    return element;
}
void display(Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
        return;
    }
    printf("Elements in deque are: ");
    Node *temp = deque->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    Deque *deque = createDeque();
    addFront(deque, 10);
    addRear(deque, 20);    
    addFront(deque, 30);   
    addRear(deque, 40);    
    display(deque);         
    removeFront(deque);     
    removeRear(deque);      
    display(deque);         
    addFront(deque, 50);    
    addRear(deque, 60);     

    display(deque); 

    return 0;
}
