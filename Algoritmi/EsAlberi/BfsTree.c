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

// Struttura per un nodo dell'albero binario
typedef struct TreeNode {
  int data;  // Dato memorizzato nel nodo
  struct TreeNode* left;
  struct TreeNode* right;
} TreeNode;

// Crea un nuovo nodo dell'albero
TreeNode* createTreeNode(int data) {
  TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
  newNode->data = data;
  newNode->left = newNode->right = NULL;
  return newNode;
}

// Inserisce un nodo nell'albero (esempio di inserimento semplice)
TreeNode* insertTreeNode(TreeNode* root, int data) {
  if (root == NULL) {
    return createTreeNode(data);
  }

  if (data < root->data) {
    root->left = insertTreeNode(root->left, data);
  } else {
    root->right = insertTreeNode(root->right, data);
  }

  return root;
}

void BFS(TreeNode* root, int* visitedNodes, int* index) {
  // coda per salvare i nodi ancora da visitare
  Queue* q = createQueue();
  // come prima cosa inserisco la radice
  enqueue(q, root);
  // finchè la coda non è vuota, ci sono altri nodi da esplorare
  while (!isQueueEmpty(q)) {
    TreeNode* current = dequeue(q);
    // aggiungo il nodo corrente ai nodi visitati
    visitedNodes[*index] = current->data;
    *index += 1;
    // metto in coda i figli
    enqueue(q, current->left);
    enqueue(q, current->right);
  }
}

int main() {
  // Creazione di un albero binario di esempio
  TreeNode* root = NULL;
  root = insertTreeNode(root, 10);
  root = insertTreeNode(root, 5);
  root = insertTreeNode(root, 15);
  root = insertTreeNode(root, 3);
  root = insertTreeNode(root, 7);
  root = insertTreeNode(root, 12);
  root = insertTreeNode(root, 18);

  // Array per salvare l'ordine dei nodi visitati
  int visitedNodes[100];
  int index = 0;

  // Esegui la BFS
  BFS(root, visitedNodes, &index);

  // Stampa l'ordine dei nodi visitati
  printf("Ordine dei nodi visitati (BFS): ");
  for (int i = 0; i < index; i++) {
    printf("%d ", visitedNodes[i]);
  }
  printf("\n");
  return 0;
}