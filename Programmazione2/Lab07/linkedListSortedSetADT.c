#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "sortedSetADT.h"

typedef struct listNode ListNode, *ListNodePtr;

struct listNode {
  void* elem;
  ListNodePtr next;
};

struct sortedSetADT {
  ListNodePtr first; /* Punta al primo nodo dell'insieme, se l'insieme e' vuoto vale NULL */
  ListNodePtr last; /* Punta all'ultimo nodo dell'insieme, se l'insieme e' vuoto vale NULL */
  int (*compare)(void*, void*); /* confronto tra due elementi: -1,0,1 se primo precede, uguale o segue il secondo */
  int size; /* Numero di elementi presenti nell'insieme */
};

// for debug: stampa un insieme
void stampaSet(SortedSetADTptr ss, void (*stampaelem)(void*)) {
  ListNodePtr cur;
  if(!ss) printf("Insieme non esiste\n");
  else if(sset_size(ss) == 0) printf("Insieme vuoto\n");
  else {
    printf("Insieme: (size %d) ",ss->size);
    for(cur = ss->first; cur; cur=cur->next) (*stampaelem)(cur->elem);
      printf("\n");
  }
} 

_Bool areSetsInvalid2(const SortedSetADT* s1, const SortedSetADT* s2){
  if((s1 == NULL && s2 == NULL) || (s1 == NULL && s2 != NULL) || (s1 != NULL && s2 == NULL)){
    return 1;
  }
  return 0;
}

// restituisce un insieme vuoto impostando funzione di confronto, NULL se errore
SortedSetADTptr mkSSet(int (*compare)(void*, void*)) {
  SortedSetADTptr set = (SortedSetADTptr) malloc(sizeof(SortedSetADT));
  if(set) {
    set->first = set->last = NULL;
    set->compare = compare;
    set->size = 0;
    return set;
  }
  return NULL;
}

// distrugge l'insieme, recuperando la memoria
_Bool dsSSet(SortedSetADTptr* ssptr) {
  if(ssptr == NULL){
    return 0;
  }
  ListNodePtr current = (*ssptr)->first;
  ListNodePtr nextNode;
  while (current != NULL){
    nextNode = current->next;
    free(current);
    current = nextNode;
  }
  free(*ssptr);
  *ssptr = NULL;
  return 1;
}

// aggiunge un elemento all'insieme 
_Bool sset_add(SortedSetADTptr ss, void* elem) { 
//controllo se il set esiste
  if(ss == NULL){
    return 0;
  }
  //caso in cui il set è vuoto
  if(ss->size == 0){
    ListNodePtr new = (ListNodePtr) malloc(sizeof(ListNode));
    new->elem = elem;
    new->next = NULL;
    // sia first che last puntano al nuovo nodo essendo l'unico presente
    ss->first = ss->last = new;
    ss->size++;
    return 1;
  }
  //controllo se l'elemento è già presente, se si restituisco 0 e non lo inserisco
  ListNodePtr cur = ss->first;
  while(cur != NULL){
    if(ss->compare(elem, cur->elem) == 0){
      return 0;
    }
    cur = cur->next;
  }
  //caso di quando l'elemento è minore del primo e quindi va messo in testa
  if(ss->compare(elem, ss->first->elem) == -1){
    ListNodePtr new = (ListNodePtr) malloc(sizeof(ListNode));
    new->elem = elem;
    new->next = ss->first;
    ss->first = new;
    ss->size++;
    return 1;
  }
  //caso in cui l'elemento è maggiore dell'ultimo e quindi va messo in coda
  if (ss->compare(elem, ss->last->elem) == 1){
    ListNodePtr new = (ListNodePtr) malloc(sizeof(ListNode));
    new->elem = elem;
    new->next = NULL;
    ss->last->next = new;
    ss->last = new;
    ss->size++;
    return 1;
  }
  //caso in cui l'elemento va messo in mezzo a due nodi
  ListNodePtr prev = ss->first;
  cur = ss->first->next;
  while(cur != NULL){
    if(ss->compare(elem, cur->elem) == -1 && ss->compare(elem, prev->elem) == 1){
      ListNodePtr new = (ListNodePtr) malloc(sizeof(ListNode));
      new->elem = elem;
      new->next = cur;
      prev->next = new;
      ss->size++;
      return 1;
    }
    prev = cur;
    cur = cur->next;
  }
}  

// toglie un elemento all'insieme 
_Bool sset_remove(SortedSetADTptr ss, void* elem) {
  if(ss == NULL || ss->size == 0){
    return 0;
  }
  ListNodePtr cur = ss->first;
  ListNodePtr prev = NULL;
  while(cur != NULL){
    if(ss->compare(elem, cur->elem) == 0){
      // elemento trovato
      if(prev == NULL){
        ss->first = cur->next;
        if(ss->first == NULL){
          ss->last = NULL;
        }
      } else {
        // L'elemento da rimuovere non è il primo elemento
        prev->next = cur->next;
        if(cur->next == NULL){
          // L'elemento da rimuovere è l'ultimo elemento
          ss->last = prev;
        }
      }
      free(cur);
      ss->size--;
      return 1;
    }
    prev = cur;
    cur = cur->next;
  }
  // L'elemento non è stato trovato
  return 0;
}
// controlla se un elemento appartiene all'insieme
int sset_member(const SortedSetADT* ss, void* elem) {
  //controllo validità set
  if(ss == NULL || ss->first == NULL){
    return 0;
  } 
  ListNodePtr cur = ss->first;
  //scorro tutti gli elementi alla ricerca di quello con valore uguale a elem
  while (cur != NULL){
    if(ss->compare(elem, cur->elem) == 0){
      return 1;
    }
    cur = cur->next;
  }
  return 0;
}
    
// controlla se l'insieme e' vuoto    
int isEmptySSet(const SortedSetADT* ss) {
  return (ss == NULL ||ss->size != 0) ? 0 : 1;
} 

// restituisce il numero di elementi presenti nell'insieme
int sset_size(const SortedSetADT* ss) {
  return(ss == NULL) ? -1 : ss->size;
} 

_Bool sset_extract(SortedSetADTptr ss, void**ptr) { // toglie e restituisce un elemento a caso dall'insieme
  if(ss == NULL || ss->size == 0){
    return false;
  }
  int randomIndex = rand() % ss->size; 
  ListNodePtr cur = ss->first;
  ListNodePtr prev = NULL;
  int count = 0;
  while(cur != NULL){
    if(count == randomIndex){
      *ptr = cur->elem;
      if(prev == NULL){
        ss->first = cur->next;
        if(ss->first == NULL){
          ss->last = NULL;
        }
      } else {
        prev->next = cur->next;
        if(cur->next == NULL){
          ss->last = prev;
        }
      }
      free(cur);
      ss->size--;
      return true;
    }
    prev = cur;
    cur = cur->next;
    count++;
  }
  return false;
}
// controlla se due insiemi sono uguali
int sset_equals(const SortedSetADT* s1, const SortedSetADT* s2) { 
  //controllo la validità di entrambi gli insiemi
  if((s1 == NULL && s2 == NULL) || (s1 == NULL && s2 != NULL) || (s1 != NULL && s2 == NULL)){
    return 0;
  }
  //se gli insiemi hanno dim diverse allora non possono essere uguali
  if(s1->size != s2->size){
    return 0;
  }
  //prendo ogni elem del primo e controllo se è dentro al secondo
  ListNodePtr node1 = s1->first;
  while(node1 != NULL){
    //se un elemento di s1, non è presente in s2, allora non sono uguali
    if(!sset_member(s2, node1->elem)){
      return 0;
    }
    node1 = node1->next;
  }
  //se sono arrivato qua allora sono uguali e posso dare 1
  return 1;
}

// controlla se il primo insieme e' incluso nel secondo
int sset_subseteq(const SortedSetADT* s1, const SortedSetADT* s2) {
  //controllo la validità di entrambi gli insiemi
  if((s1 == NULL && s2 == NULL) || (s1 == NULL && s2 != NULL) || (s1 != NULL && s2 == NULL)){
    return 0;
  }
  //se il primo insieme è vuoto allora è sottoinsieme del secondo per definizione
  if(isEmptySSet(s1)){
    return 1;
  }
  //controllo se ogni elem del primo e anche nel secondo
  ListNodePtr node1 = s1->first;
  while(node1 != NULL){
    //se un elemento di s1, non è presente in s2, allora s1 non è sottoinsieme
    if(!sset_member(s2, node1->elem)){
      return 0;
    }
    node1 = node1->next;
  }
  //se arrivo qua, s1 è sottoinsieme di s2
  return 1;
}

// controlla se il primo insieme e' incluso strettamente nel secondo
int sset_subset(const SortedSetADT* s1, const SortedSetADT* s2) {
  //controllo la validità di entrambi gli insiemi
  if((s1 == NULL && s2 == NULL) || (s1 == NULL && s2 != NULL) || (s1 != NULL && s2 == NULL)){
    return 0;
  }
  //se il primo insieme è vuoto allora è sottoinsieme del secondo per definizione
  if(isEmptySSet(s1)){
    return 1;
  }
  //controllo se ogni elem del primo e anche nel secondo
  ListNodePtr node1 = s1->first;
  while(node1 != NULL){
    //se un elemento di s1, non è presente in s2, allora s1 non è sottoinsieme
    if(!sset_member(s2, node1->elem)){
      return 0;
    }
    node1 = node1->next;
  }
  //se la loro dimensione è uguale, sono due insimi uguali e quindi non s1 strettamente incluso in s2
  if(s1->size == s2->size){
    return 0;
  }
  return 1;
} 

// restituisce la sottrazione primo insieme meno il secondo, NULL se errore
SortedSetADTptr sset_subtraction(const SortedSetADT* s1, const SortedSetADT* s2) {
  if((s1 == NULL && s2 == NULL) || (s1 == NULL && s2 != NULL) || (s1 != NULL && s2 == NULL)){
    return 0;
  }
  SortedSetADTptr subtractionSet = mkSSet(s1->compare); 
  ListNodePtr node = s1->first;
  while (node != NULL){
    if(!sset_member(s2, node->elem)){
      sset_add(subtractionSet, node->elem);
    }
    node = node->next;
  }
  return subtractionSet;
} 

// restituisce l'unione di due insiemi, NULL se errore
SortedSetADTptr sset_union(const SortedSetADT* s1, const SortedSetADT* s2) {
  if((s1 == NULL && s2 == NULL) || (s1 == NULL && s2 != NULL) || (s1 != NULL && s2 == NULL)){
    return 0;
  }
  SortedSetADTptr unionSet = mkSSet(s1->compare); 
  ListNodePtr node = s1->first;
  //inserisco tutti gli elem del primo insieme
  while (node != NULL){
    sset_add(unionSet, node->elem);
    node = node->next;
  }
  //inserisco gli elem del secondo insieme
  node = s2->first;
  while (node != NULL){
    sset_add(unionSet, node->elem);
    node = node->next;
  }
  return unionSet;
} 

// restituisce l'intersezione di due insiemi, NULL se errore
SortedSetADTptr sset_intersection(const SortedSetADT* s1, const SortedSetADT* s2) {
  if((s1 == NULL && s2 == NULL) || (s1 == NULL && s2 != NULL) || (s1 != NULL && s2 == NULL)){
    return 0;
  }
  SortedSetADTptr interSet = mkSSet(s1->compare); 
  ListNodePtr node = s1->first;
  while(node != NULL){
    if(sset_member(s2, node->elem)){
      sset_add(interSet, node->elem);
    }
    node = node->next;
  }
  return interSet;
}

// restituisce il primo elemento 
_Bool sset_min(const SortedSetADT* ss, void**ptr) {
  if( ss == NULL || ss->size == 0){
    return 0;
  }
  *ptr = ss->first->elem;
  return 1;
}

// restituisce l'ultimo elemento 
_Bool sset_max(const SortedSetADT* ss, void**ptr) {
  if( ss == NULL || ss->size == 0){
    return 0;
  }
  *ptr = ss->last->elem;
  return 1;
}

// toglie e restituisce il primo elemento 
_Bool sset_extractMin(SortedSetADTptr ss, void**ptr) {
  if( ss == NULL || ss->size == 0){
    return 0;
  }    
  ListNodePtr temp = ss->first;
  *ptr = temp->elem;
  ss->first = ss->first->next;
  free(temp);
  ss->size--;
  return 1;
}

// toglie e restituisce l'ultimo elemento (0 se lista vuota, -1 se errore, 1 se restituisce elemento)
_Bool sset_extractMax(SortedSetADTptr ss, void**ptr) {
  if( ss == NULL || ss->size == 0){
    return 0;
  }
  if(ss->size == 1){
    *ptr = ss->last->elem;
    free(ss->last);
    ss->first = NULL;
    ss->last = NULL;
    ss->size--;
    return 1;
  }
  ListNodePtr temp = ss->first;
  //scorro per arrivare al penultimo elemento
  while(temp->next != ss->last){
    temp = temp->next;
  }
  //temp è il penultimo, quindi dopo aver tolto l'ultimo diventerà lui l'ultimo
  *ptr = temp->next->elem;
  ss->last = temp;
  free(temp->next);
  ss->last->next = NULL;
  ss->size--;
  return 1;   
}
