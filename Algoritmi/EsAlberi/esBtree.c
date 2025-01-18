#include <stdio.h>
#include <stdlib.h>

typedef struct btree {
  int key;
  struct btree* left;
  struct btree* right;
  struct btree* parent;
} btree;

btree* insert(int key, btree* root, btree* parent) {
  if (root == NULL) {
    btree* newNode = (btree*)malloc(sizeof(btree));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = parent;
    return newNode;
  }

  if (key < root->key) {
    root->left = insert(key, root->left, root);
  } else if (key > root->key) {
    root->right = insert(key, root->right, root);
  }

  return root;
}

btree* minInBtree(btree* bt) {
  if (bt->left == NULL) return bt;

  return minInBtree(bt->left);
}

int main() {
  // Test 1
  btree* bt1 = insert(45, NULL, NULL);
  bt1 = insert(23, bt1, NULL);
  bt1 = insert(52, bt1, NULL);
  bt1 = insert(12, bt1, NULL);
  bt1 = insert(48, bt1, NULL);
  bt1 = insert(1, bt1, NULL);
  bt1 = insert(7, bt1, NULL);

  btree* min = minInBtree(bt1);
  printf("min value: %d", min->key);

  return 0;
}