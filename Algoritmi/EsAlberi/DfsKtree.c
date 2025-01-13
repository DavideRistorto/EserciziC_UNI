#include <stdio.h>
#include <stdlib.h>

// Struttura per un nodo della pila
typedef struct StackNode {
  void* data;  // Puntatore generico per memorizzare qualsiasi tipo di dato
  struct StackNode* next;
} StackNode;

// Struttura per la pila
typedef struct {
  StackNode* top;
} Stack;

// Crea una pila vuota
Stack* createStack() {
  Stack* s = (Stack*)malloc(sizeof(Stack));
  s->top = NULL;
  return s;
}

// Verifica se la pila è vuota
int isStackEmpty(Stack* s) {
  return s->top == NULL;
}

// Aggiunge un elemento alla pila
void push(Stack* s, void* data) {
  if (data == NULL) return;
  StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
  newNode->data = data;
  newNode->next = s->top;
  s->top = newNode;
}

// Rimuove un elemento dalla pila
void* pop(Stack* s) {
  if (isStackEmpty(s)) {
    printf("Errore: pila vuota!\n");
    return NULL;
  }
  StackNode* temp = s->top;
  void* data = temp->data;
  s->top = s->top->next;
  free(temp);
  return data;
}

// Struttura per un nodo dell'albero k-ario
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

void DFS(Tree root, int* visitedNodes, int* index) {
  Stack* s = createStack();
  push(s, root);

  while (!isStackEmpty(s)) {
    Tree current = pop(s);
    visitedNodes[*index] = current->info;
    *index += 1;
    current = current->child;
    while (current) {
      push(s, current);
      current = current->sibling;
    }
  }
}

int main() {
  // Creazione di un albero k-ario di esempio
  Tree t1 = root(1, consTree(2, leaf(5, leaf(6, NULL)), consTree(3, leaf(7, NULL), leaf(4, NULL))));

  // Array per salvare l'ordine dei nodi visitati
  int visitedNodes[100];
  int index = 0;

  // Esegui la BFS
  DFS2(t1, visitedNodes, &index);

  // Stampa l'ordine dei nodi visitati
  printf("Ordine dei nodi visitati (BFS): ");
  for (int i = 0; i < index; i++) {
    printf("%d ", visitedNodes[i]);
  }
  printf("\n");

  return 0;
}