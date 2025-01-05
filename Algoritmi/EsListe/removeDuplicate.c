#include <stdio.h>
#include <stdlib.h>

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

// Pre: l è una lista ordinata in modo crescente
// Post: ritorna una nuova lista ordinata senza duplicati
list removeDuplicates(list l) {
  list result = NULL;
  list tail = NULL;
  while (l != NULL) {
    // Aggiungo l'elemento corrente se è diverso dal successivo
    if (l->next == NULL || l->info != l->next->info) {
      if (result == NULL) {
        result = Cons(l->info, NULL);
        tail = result;
      } else {
        tail->next = Cons(l->info, NULL);
        tail = tail->next;
      }
    }
    // Avanzo al prossimo elemento
    l = l->next;
  }
  return result;
}

int main() {
  // Creazione di una lista ordinata con duplicati
  list l0 = Cons(1, Cons(1, Cons(2, Cons(3, Cons(3, Cons(3, Cons(4, NULL)))))));

  // Stampa della lista originale
  printf("Lista originale: ");
  printList(l0);  // Output: 1 1 2 3 3 3 4

  // Rimozione dei duplicati
  list uniqueList = removeDuplicates(l0);

  // Stampa della lista senza duplicati
  printf("Lista senza duplicati: ");
  printList(uniqueList);  // Output atteso: 1 2 3 4

  return 0;
}