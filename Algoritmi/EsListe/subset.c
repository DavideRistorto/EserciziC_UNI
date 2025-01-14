#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct listEl {
  int info;
  struct listEl* next;
};
typedef struct listEl* list;

// Funzione per creare un nuovo nodo
list Cons(int info, list next) {
  list new_node = (list)malloc(sizeof(struct listEl));
  new_node->info = info;
  new_node->next = next;
  return new_node;
}

// Funzione per stampare una lista
void printList(list l) {
  while (l != NULL) {
    printf("%d ", l->info);
    l = l->next;
  }
  printf("\n");
}

bool subset(list l, list m) {
  bool isSubset = true;
  // scorro su entrambe le liste
  while (l && m && isSubset) {
    // elemento in comune, proseguo con entrambe le liste
    if (l->info == m->info) {
      l = l->next;
      m = m->next;
    } else if (l->info > m->info) {
      m = m->next;
    }  // se in m sono già arrivato ad un punto dove gli elementi sono
    // maggiori si l->info, allora l' elemento non c'è
    else {
      isSubset = false;
    }
  }
  return isSubset;
}

// Funzione di test
void test(list l, list m) {
  if (subset(l, m)) {
    printList(l);
    printf("e` sottoinsieme di ");
    printList(m);
  } else {
    printList(l);
    printf("non e` sottoinsieme di ");
    printList(m);
  }
}

int main() {
  // Test 1: {2, 5, 8} subset {0, 2, 4, 5, 7, 8}
  list l1 = Cons(2, Cons(5, Cons(8, NULL)));
  list m1 = Cons(0, Cons(2, Cons(4, Cons(5, Cons(7, Cons(8, NULL))))));
  test(l1, m1);

  // Test 2: {1, 3, 5} subset {1, 2, 3, 4, 5}
  list l2 = Cons(1, Cons(3, Cons(5, NULL)));
  list m2 = Cons(1, Cons(2, Cons(3, Cons(4, Cons(5, NULL)))));
  test(l2, m2);

  // Test 3: {1, 2, 3} subset {4, 5, 6}
  list l3 = Cons(1, Cons(2, Cons(3, NULL)));
  list m3 = Cons(4, Cons(5, Cons(6, NULL)));
  test(l3, m3);

  return 0;
}