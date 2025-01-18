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

// post: ritorna l'avo destro più prossimo a nd se esiste; NULL altrimenti
btree* rightAncestor(btree* nd) {
  if (nd->parent == NULL) return NULL;

  if (nd == nd->parent->left) return nd->parent;

  return rightAncestor(nd->parent);
}

// post: ritorna il puntatore al predecessore di nd se esiste
//       NULL altrimenti
btree* successor(btree* nd) {
  if (nd->right) return minInBtree(nd->right);

  return rightAncestor(nd);
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
  printf("min value: %d\n", min->key);

  btree* RXAncestor = rightAncestor(bt1->right->left);
  printf("RXAncestor of %d is %d\n", bt1->right->left->key, RXAncestor->key);

  btree* success = successor(bt1->left->left);
  printf("successor of %d is %d\n", bt1->left->left->key, success->key);

  return 0;
}