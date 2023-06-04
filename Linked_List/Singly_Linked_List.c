#include <stdio.h>
#include <stdlib.h>

struct Node {
   int data;
   struct Node* next;
};

struct Node* head;

void insert(int x) {
   struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
   temp->data = x;
   temp->next = head;
   head = temp;
}

void delete(int x) {
   struct Node* prev = NULL;
   struct Node* curr = head;
   while(curr != NULL && curr->data != x) {
      prev = curr;
      curr = curr->next;
   }
   if(curr == NULL) {
      printf("%d not found in the list.\n", x);
      return;
   }
   if(prev == NULL) {
      head = curr->next;
   } else {
      prev->next = curr->next;
   }
   free(curr);
   printf("%d deleted from the list.\n", x);
}

void display() {
   struct Node* temp = head;
   if(temp == NULL) {
      printf("List is empty.\n");
      return;
   }
   printf("List is: ");
   while(temp != NULL) {
      printf("%d ", temp->data);
      temp = temp->next;
   }
   printf("\n");
}

int isEmpty() {
   return head == NULL;
}

int search(int x) {
   struct Node* temp = head;
   int pos = 1;
   while(temp != NULL) {
      if(temp->data == x) {
         return pos;
      }
      pos++;
      temp = temp->next;
   }
   return -1;
}

int main() {
   head = NULL;
   int choice, item, pos;
   while(1) {
      printf("1. Insertion\n");
      printf("2. Deletion\n");
      printf("3. Display\n");
      printf("4. Empty\n");
      printf("5. Search\n");
      printf("6. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);
      switch(choice) {
         case 1:
            printf("Enter item to be inserted: ");
            scanf("%d", &item);
            insert(item);
            break;
         case 2:
            printf("Enter item to be deleted: ");
            scanf("%d", &item);
            delete(item);
            break;
         case 3:
            display();
            break;
         case 4:
            if(isEmpty()) {
               printf("List is empty.\n");
            } else {
               printf("List is not empty.\n");
            }
            break;
         case 5:
            printf("Enter item to be searched: ");
            scanf("%d", &item);
            pos = search(item);
            if(pos == -1) {
               printf("%d not found in the list.\n", item);
            } else {
               printf("%d found at position %d in the list.\n", item, pos);
            }
            break;
         case 6:
            printf("Exiting...\n");
            exit(0);
         default:
            printf("Invalid choice. Please try again.\n");
      }
   }
   return 0;
}

