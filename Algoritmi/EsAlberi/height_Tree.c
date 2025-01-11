#include <stdio.h>
#include <stdlib.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))

// Definizione della struttura di un nodo per un albero binario
struct TreeNode {
  int info;                // Etichetta del nodo
  struct TreeNode* left;   // Puntatore al figlio sinistro
  struct TreeNode* right;  // Puntatore al figlio destro
};

typedef struct TreeNode* Tree;

// Funzione per creare un nuovo nodo dell'albero binario
Tree createTreeNode(int x) {
  Tree newNode = (Tree)malloc(sizeof(struct TreeNode));
  newNode->info = x;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

// Funzione per calcolare l'altezza di un albero binario
int treeHeight(Tree t) {
  if (t == NULL) return -1;

  int LmaxHeight = treeHeight(t->left);
  int RmaxHeight = treeHeight(t->right);
  return max(LmaxHeight, RmaxHeight) + 1;
}

// Funzione per stampare un albero binario (visita in ordine)
void printTree(Tree t, int depth) {
  if (t == NULL) return;

  // Stampa il sottoalbero destro (per una visualizzazione più intuitiva)
  printTree(t->right, depth + 1);

  // Stampa il nodo corrente con indentazione
  for (int i = 0; i < depth; i++) printf("    ");
  printf("%d\n", t->info);

  // Stampa il sottoalbero sinistro
  printTree(t->left, depth + 1);
}

int main() {
  // Creazione di un albero binario di esempio
  Tree t1 = createTreeNode(12);
  t1->left = createTreeNode(22);
  t1->right = createTreeNode(33);
  t1->left->left = createTreeNode(1);
  t1->left->right = createTreeNode(2);
  t1->left->right->left = createTreeNode(32);
  t1->left->right->left->left = createTreeNode(3);
  t1->left->right->left->left->left = createTreeNode(4);

  // Stampa dell'albero binario
  printf("Albero binario:\n");
  printTree(t1, 0);

  // Calcolo dell'altezza
  int height = treeHeight(t1);
  printf("Altezza dell'albero binario: %d\n", height);  // Output atteso: 5

  return 0;
}