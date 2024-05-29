#include <stdio.h>
#include <stdlib.h>

// Definizione delle strutture
typedef struct intNode {
    int data;
    struct intNode* next;
} IntNode, *IntList;

/**
 * @brief Riorganizza i nodi di *lsPtr invertendone l'ordine.
 * Ad esempio, data [1, 2, 3] la trasforma in [3, 2, 1]. Non alloca nuova memoria sullo heap.
 * @param lsPtr Puntatore al puntatore alla lista da invertire.
 */
void reverse(IntList* lsPtr) {
  IntList prev = NULL;
  IntList cur = *lsPtr;
  IntList next = NULL;
  while(cur != NULL){
    next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
  }

  *lsPtr = prev;
}

IntList createList() {
  IntList list = NULL;
  
  // Aggiunta di elementi alla lista
  for (int i = 1; i <= 5; i++) {
    IntNode* newNode = (IntNode*)malloc(sizeof(IntNode));
    newNode->data = i;
    newNode->next = list;
    list = newNode;
  }
  return list;
}

void printList(IntList list) {
  IntNode* current = list;
  
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  
  printf("\n");
}

int main() {
  IntList list = createList();
  
  printf("Original list: ");
  printList(list);
  
  reverse(&list);
  
  printf("Reversed list: ");
  printList(list);
  
  return 0;
}

