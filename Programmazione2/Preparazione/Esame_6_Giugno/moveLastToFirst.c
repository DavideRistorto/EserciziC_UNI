#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node IntNode, * IntList;
struct node {
  int data;
  IntList next;
};

// Funzione per creare un nuovo nodo
IntList createNode(int data) {
  IntList newNode = (IntList)malloc(sizeof(IntNode));
  if (newNode) {
    newNode->data = data;
    newNode->next = NULL;
  }
  return newNode;
}

// Funzione per aggiungere un elemento in testa
IntList prepend(IntList list, int data) {
  IntList newNode = createNode(data);
  if (newNode) {
    newNode->next = list;
  }
  return newNode;
}

// Funzione per stampare una lista
void printList(IntList list) {
  while (list) {
    printf("%d -> ", list->data);
    list = list->next;
  }
  printf("NULL\n");
}

// Funzione per creare una lista di esempio
IntList createSampleList() {
  IntList list = NULL;
  list = prepend(list, 5);
  list = prepend(list, 9);
  list = prepend(list, 2);
  list = prepend(list, 3);
  return list;
}

// Funzione per spostare l'ultimo nodo in testa
void moveLastToFront(IntList* list) {
  //caso lista vuota
  if (list == NULL || *list == NULL) return;

  IntList ls = *list;
  IntList prec = NULL;
  //caso lista un solo elemento
  //non faccio nulla
  if (ls != NULL && ls->next == NULL) return;
  //salvo il primo elemento
  IntList firstElem = ls;
  //scorro la lista per arrivare all' ultimo nodo
  while (ls->next) {
    prec = ls;
    ls = ls->next;
  }
  //in penultimo elemento ora è l'ultimo quindi punta a null
  prec->next = NULL;
  //l' ultimo elemento lo faccio puntare al primo
  ls->next = firstElem;
  //aggiorno la testa della lista
  *list = ls;
  return;
}

int main() {
  IntList list = createSampleList();

  printf("Lista originale:\n");
  printList(list);

  moveLastToFront(&list);

  printf("\nLista dopo aver spostato l'ultimo nodo in testa:\n");
  printList(list);

  return 0;
}
