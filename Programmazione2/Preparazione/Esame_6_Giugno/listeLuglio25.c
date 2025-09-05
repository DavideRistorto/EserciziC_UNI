#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct node CharNode, * CharList;
struct node {
  char data;
  CharList next;
};

// Funzione per creare un nuovo nodo
CharList createNode(char data) {
  CharList newNode = (CharList)malloc(sizeof(CharNode));
  if (newNode) {
    newNode->data = data;
    newNode->next = NULL;
  }
  return newNode;
}

// Funzione per aggiungere un elemento in testa
CharList prepend(CharList list, char data) {
  CharList newNode = createNode(data);
  if (newNode) {
    newNode->next = list;
  }
  return newNode;
}

// Funzione per aggiungere un elemento in coda
void append(CharList* list, char data) {
  CharList newNode = createNode(data);
  if (!newNode) return;

  if (*list == NULL) {
    *list = newNode;
    return;
  }

  CharList current = *list;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = newNode;
}

// Funzione per stampare una lista
void printList(CharList list) {
  while (list) {
    printf("%c -> ", list->data);
    list = list->next;
  }
  printf("NULL\n");
}

// Funzione per creare una lista di esempio
CharList createSampleList() {
  CharList list = NULL;
  list = prepend(list, 'C');
  list = prepend(list, 'B');
  list = prepend(list, 'A');
  return list;
}

// Funzione per inserire stringa dopo 'Z' o in fondo
/**
 * Abbiamo una lista e una stringa.
 * Se la lista contiene 'Z', inseriamo la stringa dopo 'Z'.
 * Altrimenti, inseriamo la stringa in fondo alla lista.
 *
 * Invidiuiamo i 2 casi principali:
 * 1. La lista contiene 'Z' quindi inseriamo la stringa dopo 'Z'
 * 2. La lista non contiene 'Z' quindi inseriamo la stringa in fondo alla lista
 *
 */
int modifica(CharList* list, char* str) {
  // Caso lista vuota -> ritorno 0
  if (list == NULL || *list == NULL) {
    return 0;
  }
  // Caso in cui la stringa è vuota/nulla -> non modifico la lista e ritorno 1
  if (str == NULL || strlen(str) == 0) {
    return 1;
  }
  // Cerca la lettera 'Z' nella lista
  CharList current = *list; //per scorrere la lista
  CharList zNode = NULL;    //per memorizzare il nodo con 'Z' se trovato
  while (current != NULL) {
    if (current->data == 'Z') {
      zNode = current; // Nodo con 'Z' trovato ed esco dal ciclo
      break;
    }
    current = current->next; // Continua a scorrere la lista se non trovato il nodo
  }
  //Caso in cui ho trovato un nodo con 'Z', quindi inserisco la stringa dopo dopo zNode
  if (zNode != NULL) {
    CharList temp = zNode->next; // questo è il nodo successivo a zNode originalmente. Ci servirà da collegamento da la fine della stringa e il resto della lista dopo la Z
    // Per ogni carattere della stringa creo un nuovo nodo e lo inserisco dopo zNode
    for (int i = 0; str[i] != '\0'; i++) {
      CharList newNode = createNode(str[i]);
      if (newNode) {
        zNode->next = newNode;
        zNode = newNode;
      }
    }
    zNode->next = temp; // Collego l'ultimo nodo della stringa al resto della lista
    return 1; // Esco e ritorno 1
  }
  // Caso in cui non ho trovato un nodo con 'Z' e quindi devo inserire la stringa in fondo alla lista
  else {
    // Trovo l'ultimo nodo, ovvero quello che punta a NULL
    current = *list;
    while (current->next != NULL) {
      current = current->next;
    }
    // Per ogni carattere della stringa creo un nuovo nodo e lo inserisco in coda
    for (int i = 0; str[i] != '\0'; i++) {
      current->next = createNode(str[i]);
      current = current->next;
    }
    return 1; // Esco e ritorno 1
  }
}


int main() {
  // Test caso 1: Lista senza 'Z'
  CharList list1 = createSampleList();
  printf("Lista originale (senza Z):\n");
  printList(list1);

  int result1 = modifica(&list1, "XYZ");
  printf("\nLista dopo inserimento stringa 'XYZ' (in fondo):\n");
  printList(list1);
  printf("Risultato: %d\n", result1);

  // Test caso 2: Lista con 'Z'
  CharList list2 = NULL;
  list2 = prepend(list2, 'D');
  list2 = prepend(list2, 'Z');
  list2 = prepend(list2, 'A');

  printf("\nLista originale (con Z):\n");
  printList(list2);

  int result2 = modifica(&list2, "123");
  printf("\nLista dopo inserimento stringa '123' (dopo Z):\n");
  printList(list2);
  printf("Risultato: %d\n", result2);

  // Test caso 3: Lista nulla (passaggio di puntatore nullo)
  int result3 = modifica(NULL, "TEST");
  printf("\nTest con lista nulla:\n");
  printf("Risultato: %d\n", result3);

  // Test caso 4: Stringa vuota
  CharList list4 = createSampleList();
  printf("\nLista originale per test stringa vuota:\n");
  printList(list4);

  int result4 = modifica(&list4, "");
  printf("\nLista dopo inserimento stringa vuota:\n");
  printList(list4);
  printf("Risultato: %d\n", result4);

  return 0;
}