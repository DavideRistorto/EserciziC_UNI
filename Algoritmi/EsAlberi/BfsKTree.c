#include <stdio.h>
#include <stdlib.h>

// Struttura per un nodo della coda
typedef struct QueueNode {
  void* data;  // Puntatore generico per memorizzare qualsiasi tipo di dato
  struct QueueNode* next;
} QueueNode;

// Struttura per la coda
typedef struct {
  QueueNode* front;
  QueueNode* rear;
} Queue;

// Crea una coda vuota
Queue* createQueue() {
  Queue* q = (Queue*)malloc(sizeof(Queue));
  q->front = q->rear = NULL;
  return q;
}
// Verifica se la coda è vuota
int isQueueEmpty(Queue* q) {
  return q->front == NULL;
}

// Aggiunge un elemento alla coda
void enqueue(Queue* q, void* data) {
  if (data == NULL) return;
  QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
  newNode->data = data;
  newNode->next = NULL;
  if (isQueueEmpty(q)) {
    q->front = q->rear = newNode;
  } else {
    q->rear->next = newNode;
    q->rear = newNode;
  }
}

// Rimuove un elemento dalla coda
void* dequeue(Queue* q) {
  if (isQueueEmpty(q)) {
    printf("Errore: coda vuota!\n");
    return NULL;
  }
  QueueNode* temp = q->front;
  void* data = temp->data;
  q->front = q->front->next;

  if (q->front == NULL) {
    q->rear = NULL;
  }
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

void BFS(Tree root, int* visitedNodes, int* index) {
  Queue* q = createQueue();
  enqueue(q, root);

  while (!isQueueEmpty(q)) {
    Tree current = dequeue(q);
    visitedNodes[*index] = current->info;
    *index += 1;

    current = current->child;
    while (current) {
      enqueue(q, current);
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
  BFS(t1, visitedNodes, &index);

  // Stampa l'ordine dei nodi visitati
  printf("Ordine dei nodi visitati (BFS): ");
  for (int i = 0; i < index; i++) {
    printf("%d ", visitedNodes[i]);
  }
  printf("\n");

  // Libera la memoria dell'albero (non implementato in questo esempio)
  return 0;
}