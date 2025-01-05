#include <stdio.h>
#include <stdlib.h>

// Definizione della struttura per un nodo dell'albero k-ario
struct TreeNode {
  int info;                  // Etichetta del nodo
  struct TreeNode* child;    // Puntatore al primo figlio
  struct TreeNode* sibling;  // Puntatore al prossimo fratello
};

typedef struct TreeNode* Tree;

struct listE1 {
  int info;
  struct listE1* next;
};

typedef struct listE1* list;

// Funzione per creare un nuovo elemento della lista
list Cons(int x, list xs) {
  list newElement = (list)malloc(sizeof(struct listE1));
  newElement->info = x;
  newElement->next = xs;
  return newElement;
}

// Funzione di utilità per stampare una lista
void printList(list l) {
  while (l != NULL) {
    printf("%d ", l->info);
    l = l->next;
  }
  printf("\n");
}

list concat(list xs, list ys) {
  if (xs == NULL) return ys;
  list current = xs;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = ys;
  return xs;
}

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

list fringe(Tree t) {
  list result = NULL;
  if (t == NULL) return NULL;

  // caso base:foglia
  if (t->child == NULL) {
    return Cons(t->info, result);
  }

  // itero su tutti i figli e fratelli
  Tree current = t->child;
  while (current) {
    result = concat(result, fringe(current));
    current = current->sibling;
  }
  return result;
}

// Funzione di utilità per stampare un albero (visita in profondità)
void printTree(Tree t, int depth) {
  if (t == NULL) return;
  for (int i = 0; i < depth; i++) printf("  ");  // Indentazione per rappresentare la profondità
  printf("%d\n", t->info);
  printTree(t->child, depth + 1);  // Visita il primo figlio
  printTree(t->sibling, depth);    // Visita il prossimo fratello
}

// Funzione principale per testare le strutture
int main() {
  // Creazione di un albero di esempio come nell'immagine
  Tree t1 = root(12, consTree(22, leaf(1, NULL), leaf(2, root(32, leaf(3, leaf(4, NULL))))));

  // Stampa dell'albero
  printf("Albero:\n");
  printTree(t1, 0);

  printList(fringe(t1));
  return 0;
}