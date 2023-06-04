#include <stdio.h>

struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};

struct Node *newNode(int data) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

void inorder(struct Node *node) {
  if (node == NULL) {
    return;
  }
  inorder(node->left);
  printf("%d ", node->data);
  inorder(node->right);
}

void preorder(struct Node *node) {
  if (node == NULL) {
    return;
  }
  printf("%d ", node->data);
  preorder(node->left);
  preorder(node->right);
}

void postorder(struct Node *node) {
  if (node == NULL) {
    return;
  }
  postorder(node->left);
  postorder(node->right);
  printf("%d ", node->data);
}

int main() {
  struct Node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(6);
  root->right->right = newNode(7);

  printf("Inorder traversal: ");
  inorder(root);
  printf("\n");

  printf("Preorder traversal: ");
  preorder(root);
  printf("\n");

  printf("Postorder traversal: ");
  postorder(root);
  printf("\n");

  return 0;
}

