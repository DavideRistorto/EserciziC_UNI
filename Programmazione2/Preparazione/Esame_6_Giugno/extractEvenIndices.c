#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node IntNode, *IntList;
struct node {
  int data;
  IntList next;
};

// Funzione per creare un nuovo nodo
IntList createNode(int data) {
  IntList newNode = (IntList) malloc(sizeof(IntNode));
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
  list = prepend(list, 8);
  list = prepend(list, 7);
  list = prepend(list, 6);
  list = prepend(list, 5);
  list = prepend(list, 4);
  list = prepend(list, 3);
  list = prepend(list, 2);
  list = prepend(list, 1);
  return list;
}

IntList extractEvenIndices(IntList *list) {
  if (list == NULL || *list == NULL) return NULL;

  IntList result = NULL;
  IntList *ptr = &result;
  IntList prec = NULL;
  IntList current = *list;
  int counter = 0;

  while(current){
    if(counter%2 == 0){
      //collego il nodo alla lista
      *ptr = current;
      ptr = &((*ptr)->next);
      //se prec esiste allora lo collego col next di current
      if(prec){
        prec->next = current->next;
      }else{
        //se prec non esiste, aggiorno la cima della lista
        *list = current->next;
      }
    }else{
      prec = current;
    }
    counter++;
    current = current->next;
  }
  //elimino i nodi di troppo
  *ptr = NULL;
  return result;
}


int main() {
  IntList list = createSampleList();

  printf("Lista originale:\n");
  printList(list);

  IntList evenList = extractEvenIndices(&list);

  printf("\nLista con elementi ad indice pari:\n");
  printList(evenList);

  printf("\nLista originale modificata:\n");
  printList(list);

  return 0;
}
