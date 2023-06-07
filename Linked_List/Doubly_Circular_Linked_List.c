#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;
void insert(int item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = item;
    newNode->prev = NULL;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        head->next = head;
        head->prev = head;
    } else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = head;
        head->prev = newNode;
    }
    printf("Node with data %d inserted successfully.\n", item);
}
void delete(int item) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    struct Node* temp = head;
    struct Node* prevNode = NULL;
    int found = 0;
    while (temp->next != head) {
        if (temp->data == item) {
            found = 1;
            break;
        }
        prevNode = temp;
        temp = temp->next;
    }
    if (!found && temp->data == item) {
        found = 1;
    }
    if (!found) {
        printf("Node with data %d not found in the list. Cannot delete.\n", item);
        return;
    }
    // Delete the node
    if (prevNode != NULL) {
        prevNode->next = temp->next;
        temp->next->prev = prevNode;
    } else {
        head = temp->next;
        head->prev = NULL;
    }
    free(temp);
    printf("Node with data %d deleted successfully.\n", item);
}
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("List: ");
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}
int isEmpty() {
    return head == NULL;
}
int search(int item) {
    if (head == NULL) {
        printf("List is empty. Cannot search.\n");
        return -1;
    }
    struct Node* temp = head;
    int pos = 0;
    // Search for the node
    do {
        if (temp->data == item) {
            return pos;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);
    return -1;
}
int main() {
    int choice, item, pos;
    while (1) {
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Display\n");
        printf("4. Empty\n");
        printf("5. Search\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to be inserted: ");
                scanf("%d", &item);
                insert(item);
                break;
            case 2:
                printf("Enter the data to be deleted: ");
                scanf("%d", &item);
                delete(item);
                break;
            case 3:
                display();
                break;
            case 4:
                if (isEmpty()) {
                    printf("List is empty.\n");
                } else {
                    printf("List is not empty.\n");
                }
                break;
            case 5:
                printf("Enter the data to be searched: ");
                scanf("%d", &item);
                pos = search(item);
                if (pos == -1) {
                    printf("Node with data %d not found in the list.\n", item);
                } else {
                    printf("Node with data %d found at position %d.\n", item, pos);
                }
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }

    return 0;
}
