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

// Funzione per l'intersezione di due liste ordinate
list intersect(list l, list m) {
  list result = NULL;
  list tail = NULL;

  while (l && m) {
    // aggiungo l' elemento alla lista
    // avanzo con entrame le liste
    if (l->info == m->info) {
      if (result == NULL) {
        result = Cons(l->info, NULL);
        tail = result;
      } else {
        tail->next = Cons(l->info, NULL);
        tail = tail->next;
      }
      l = l->next;
      m = m->next;
    }
    // avanzo con la lista l
    else if (l->info < m->info) {
      l = l->next;
    }
    // avanzo con m
    else {
      m = m->next;
    }
  }
  return result;
}

// Funzione di utilità per stampare una lista
void printList(list l) {
  while (l != NULL) {
    printf("%d ", l->info);
    l = l->next;
  }
  printf("\n");
}

// Funzione principale per testare l'implementazione
int main() {
  // Creazione delle liste di esempio
  list l0 = Cons(2, Cons(3, Cons(8, NULL)));
  list m0 = Cons(0, Cons(2, Cons(4, Cons(5, Cons(7, Cons(8, NULL))))));

  // Calcolo dell'intersezione
  list intersection = intersect(l0, m0);

  // Stampa del risultato
  printList(intersection);

  return 0;
}