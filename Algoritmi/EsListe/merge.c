#include <stdio.h>
#include <stdlib.h>

// Definizione della struttura per la lista
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

// Funzione da implementare: fusione di due liste ordinate
list merge(list l, list m) {
  // Creiamo una lista vuota per il risultato
  list result = NULL;
  list tail = NULL;

  while (l && m) {
    // aggiungo l a result
    if (l->info < m->info) {
      if (result == NULL) {
        result = Cons(l->info, NULL);
        tail = result;
      } else {
        tail->next = Cons(l->info, NULL);
        tail = tail->next;
      }
      // avanzo con l
      l = l->next;
    }  // aggiungo m a result
    else {
      if (result == NULL) {
        result = Cons(m->info, NULL);
        tail = result;
      } else {
        tail->next = Cons(m->info, NULL);
        tail = tail->next;
      }
      // avanzo con m
      m = m->next;
    }
  }
  // Se una delle due liste ha ancora elementi, li aggiungiamo alla fine
  while (l != NULL) {
    if (result == NULL) {
      result = Cons(l->info, NULL);
      tail = result;
    } else {
      tail->next = Cons(l->info, NULL);
      tail = tail->next;
    }
    l = l->next;
  }

  while (m != NULL) {
    if (result == NULL) {
      result = Cons(m->info, NULL);
      tail = result;
    } else {
      tail->next = Cons(m->info, NULL);
      tail = tail->next;
    }
    m = m->next;
  }
  return result;
}

// Funzione principale per testare l'implementazione
int main() {
  // Creazione delle liste di esempio
  list l0 = Cons(1, Cons(3, Cons(5, NULL)));
  list m0 = Cons(2, Cons(4, Cons(6, NULL)));

  // Stampa delle liste originali
  printf("Lista l0: ");
  printList(l0);  // Output: 1 3 5

  printf("Lista m0: ");
  printList(m0);  // Output: 2 4 6

  // Calcolo della fusione
  list mergedList = merge(l0, m0);

  // Stampa del risultato
  printf("Lista fusa: ");
  printList(mergedList);  // Output atteso: 1 2 3 4 5 6

  return 0;
}