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

void insert(struct Node **root, int data) {
  struct Node *newNode = newNode(data);
  struct Node *currentNode = *root;
  struct Node *parentNode = NULL;

  while (currentNode != NULL) {
    parentNode = currentNode;
    if (data < currentNode->data) {
      currentNode = currentNode->left;
    } else {
      currentNode = currentNode->right;
    }
  }

  if (parentNode == NULL) {
    *root = newNode;
  } else if (data < parentNode->data) {
    parentNode->left = newNode;
  } else {
    parentNode->right = newNode;
  }
}

void delete(struct Node **root, int data) {
  struct Node *currentNode = *root;
  struct Node *parentNode = NULL;

  while (currentNode != NULL && currentNode->data != data) {
    parentNode = currentNode;
    if (data < currentNode->data) {
      currentNode = currentNode->left;
    } else {
      currentNode = currentNode->right;
    }
  }

  if (currentNode == NULL) {
    return;
  }

  if (currentNode->left == NULL && currentNode->right == NULL) {
    if (parentNode == NULL) {
      *root = NULL;
    } else if (data < parentNode->data) {
      parentNode->left = NULL;
    } else {
      parentNode->right = NULL;
    }
  } else if (currentNode->left != NULL && currentNode->right != NULL) {
    struct Node *successor = currentNode->right;
    while (successor->left != NULL) {
      successor = successor->left;
    }

    int temp = currentNode->data;
    currentNode->data = successor->data;
    successor->data = temp;
    delete(root, successor->data);
  } else {
    struct Node *childNode;
    if (currentNode->left != NULL) {
      childNode = currentNode->left;
    } else {
      childNode = currentNode->right;
    }

    if (parentNode == NULL) {
      *root = childNode;
    } else if (data < parentNode->data) {
      parentNode->left = childNode;
    } else {
      parentNode->right = childNode;
    }
  }
}

struct Node *findMinimum(struct Node *root) {
  struct Node *currentNode = root;
  while (currentNode->left != NULL) {
    currentNode = currentNode->left;
  }
  return currentNode;
}

struct Node *findMaximum(struct Node *root) {
  struct Node *currentNode = root;
  while (currentNode->right != NULL) {
    currentNode = currentNode->right;
  }
  return currentNode;
}

struct Node *findKthElement(struct Node *root, int k) {
  if (root == NULL || k <= 0) {
    return NULL;
  }

  int leftSubtreeSize = countNodes(root->left);
  if (k <= leftSubtreeSize) {
    return findKthElement(root->left, k);
  } else if (k > leftSubtreeSize + 1) {
    return findKthElement(root->right, k - leftSubtreeSize - 1);
  } else {
    return root;
  }
}

void inorder(struct Node *node) {
  if (node == NULL) {
    return;
  }

