#include <stdio.h>
#include <stdlib.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))

struct TreeNode {
  int info;                  // Etichetta del nodo
  struct TreeNode* child;    // Puntatore al primo figlio
  struct TreeNode* sibling;  // Puntatore al prossimo fratello
};

typedef struct TreeNode* Tree;

// Funzione per creare un nuovo nodo dell'albero
Tree createTreeNode(int x) {
  Tree newNode = (Tree)malloc(sizeof(struct TreeNode));
  newNode->info = x;
  newNode->child = NULL;
  newNode->sibling = NULL;
  return newNode;
}

// Funzione per creare un nodo foglia
Tree leaf(int x, Tree sibling) {
  Tree newNode = createTreeNode(x);
  newNode->sibling = sibling;
  return newNode;
}

// Funzione per creare un nodo radice con un figlio
Tree root(int x, Tree child) {
  Tree newNode = createTreeNode(x);
  newNode->child = child;
  return newNode;
}

// Funzione per costruire un albero con un nodo radice e una lista di figli
Tree consTree(int x, Tree child, Tree sibling) {
  Tree newNode = createTreeNode(x);
  newNode->child = child;
  newNode->sibling = sibling;
  return newNode;
}

// Funzione di utilità per stampare un albero (visita in profondità)
void printTree(Tree t, int depth) {
  if (t == NULL) return;
  for (int i = 0; i < depth; i++) printf("  ");  // Indentazione per rappresentare la profondità
  printf("%d\n", t->info);
  printTree(t->child, depth + 1);  // Visita il primo figlio
  printTree(t->sibling, depth);    // Visita il prossimo fratello
}

// Pre: t è un albero k-ario
// Post: ritorna la somma di tutti i nodi non foglie
int sumNodes(Tree t) {
  // caso in cui sono una foglia
  if (t == NULL || t->child == NULL) return 0;
  // aggiungo alla somma il valore corrente
  int sum = t->info;
  Tree current = t->child;
  while (current) {
    sum += sumNodes(current);
    current = current->sibling;
  }
  return sum;
}

int main() {
  // Creazione di un albero di esempio
  Tree t1 = root(12, consTree(22, leaf(1, NULL), leaf(2, root(32, leaf(3, leaf(4, NULL))))));

  // Stampa dell'albero
  printf("Albero:\n");
  printTree(t1, 0);

  // Calcolo dell'altezza
  int sum = sumNodes(t1);
  printf("Somma dei valore delle non foglie: %d\n", sum);

  return 0;
}