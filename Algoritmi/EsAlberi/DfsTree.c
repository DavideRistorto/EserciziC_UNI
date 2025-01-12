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

// PREORDER: visito radice, sotto albero sinistro, sotto albero destro
void DFS(TreeNode* root, int* visitedNodes, int* index) {
  // creo la pila per memorizzare i nodi da esplorare
  Stack* stack = createStack();
  // inserisco la radice
  push(stack, root);
  // finchè la pila non è vuota, ci sono ancora nodi da esplorare
  while (!isStackEmpty(stack)) {
    TreeNode* current = pop(stack);
    // aggiungo il nodo tolto dalla pila, nei visitati
    visitedNodes[*index] = current->data;
    *index += 1;
    push(stack, current->right);
    push(stack, current->left);
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

  // Esegui la DFS pre-order
  DFS(root, visitedNodes, &index);

  // Stampa l'ordine dei nodi visitati
  printf("Ordine dei nodi visitati (DFS pre-order): ");
  for (int i = 0; i < index; i++) {
    printf("%d ", visitedNodes[i]);
  }
  printf("\n");
  return 0;
}