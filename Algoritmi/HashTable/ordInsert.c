#include <stdio.h>
#include <stdlib.h>

// Definizione della struttura per gli elementi della lista
struct listEl {
  int info;
  struct listEl* pred;
  struct listEl* next;
};
typedef struct listEl* list;

// Definizione della struttura per la tabella hash
struct hashFrame {
  int dim;
  list* array;
};
typedef struct hashFrame* HashTable;

// Funzione per creare una tabella hash
HashTable meshashTable(int m) {
  HashTable T = (HashTable)malloc(sizeof(struct hashFrame));
  T->dim = m;
  T->array = (list*)calloc(m, sizeof(list));
  return T;
}

// Funzione hash preimplementata
int hashFun(int k, int m) {
  return k % m;
}

list Cons(int k, list p, list n) {
  // Alloca memoria per un nuovo nodo
  list newNode = (list)malloc(sizeof(struct listEl));
  if (newNode == NULL) {
    // Gestione dell'errore di allocazione di memoria
    fprintf(stderr, "Errore di allocazione di memoria\n");
    exit(EXIT_FAILURE);
  }
  // Inizializza il nuovo nodo
  newNode->info = k;  // Imposta la chiave
  newNode->pred = p;  // Imposta il predecessore
  newNode->next = n;  // Imposta il successore
  // Se il successore non è NULL, aggiorna il suo predecessore
  if (n != NULL) {
    n->pred = newNode;
  }
  // Se il predecessore non è NULL, aggiorna il suo successore
  if (p != NULL) {
    p->next = newNode;
  }
  // Restituisce il puntatore al nuovo nodo
  return newNode;
}

// Funzione per l'inserimento ordinato
list ordInsert(int k, list p, list l) {
  // Se la lista è vuota, inserisci il nuovo nodo come unico elemento
  if (l == NULL) {
    return Cons(k, p, l);
  }

  // Trova la posizione corretta per l'inserimento ordinato
  list current = l;
  while (current != NULL && current->info < k) {
    p = current;
    current = current->next;
  }
  // Inserisci il nuovo nodo nella posizione trovata
  return Cons(k, p, current);
}

// Funzione per l'inserimento nella tabella hash
void hashInsert(HashTable T, int k) {
  int index = hashFun(k, T->dim);
  T->array[index] = ordInsert(k, NULL, T->array[index]);
}

// Funzione di test
void test(HashTable T, int A[], int dimA) {
  for (int i = 0; i < dimA; i++) {
    hashInsert(T, A[i]);
  }
  for (int i = 0; i < T->dim; i++) {
    printf("%d : ", i);
    list current = T->array[i];
    while (current != NULL) {
      printf("%d ", current->info);
      current = current->next;
    }
    printf("\n");
  }
}

int main() {
  HashTable T1 = meshashTable(5);
  int A[] = {7, 15, 34, 12, 35, 27, 5, 12, 16};
  int dimA = sizeof(A) / sizeof(int);
  test(T1, A, dimA);
  return 0;
}