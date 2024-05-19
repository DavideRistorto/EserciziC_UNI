#include <stdlib.h>
#include <stdbool.h>

#include "intSortedSetADT.h"
#include "intLinkedListSortedSetADT.h"

IntSortedSetADT mkSSet() {
  IntSortedSetADT set = malloc(sizeof(struct intSortedSet));
  if(set) {
    set->first = NULL;
    set->last = NULL;
    set->size = 0;
    return set;
  }
  return NULL;
}

_Bool dsSSet(IntSortedSetADT *ssptr) {
  if( ssptr == NULL || *ssptr == NULL){
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

_Bool sset_add(IntSortedSetADT ss, const int elem) {
  //controllo se il set esiste
  if( ss == NULL){
    return 0;
  }
  // se il set è vuoto, l'elemento nuovo è sia il primo che l'ultimo
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
  if(sset_member(ss, elem)){
    return 0;
  }
  //caso di quando l'elemento è minore del primo e quindi va messo in testa
  if(elem < ss->first->elem){
    ListNodePtr new = (ListNodePtr) malloc(sizeof(ListNode));
    new->elem = elem;
    new->next = ss->first;
    ss->first = new;
    ss->size++;
    return 1;
  }
  //caso in cui l'elemento è maggiore dell'ultimo e quindi va messo in coda
  if (elem>ss->last->elem){
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
  ListNodePtr cur = ss->first->next;
  while(cur != NULL){
    if(elem < cur->elem && elem > prev->elem){
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
  return 0;
} 

_Bool sset_remove(const IntSortedSetADT ss, const int elem) {
  //controllo validità set
  if(ss == NULL || ss->size == 0){
    return 0;
  }
  ListNodePtr cur = ss->first;
  ListNodePtr prev = NULL;
  while(cur != NULL){
    if(cur->elem == elem){
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

_Bool sset_member(const IntSortedSetADT ss, const int elem) {
  //controllo validità set
  if(ss == NULL || ss->first == NULL){
    return 0;
  } 
  ListNodePtr cur = ss->first;
  //scorro tutti gli elementi alla ricerca di quello con valore uguale a elem
  while (cur != NULL){
    if(cur->elem == elem){
      return 1;
    }
    cur = cur->next;
  }
  return 0;
}

_Bool isEmptySSet(const IntSortedSetADT ss) {
  return (ss == NULL ||ss->size != 0) ? 0 : 1;
}

int sset_size(const IntSortedSetADT ss) {
  return(ss == NULL) ? -1 : ss->size;
}

// toglie e restituisce un elemento a caso dall'insieme
_Bool sset_extract(IntSortedSetADT ss, int *ptr)  { 
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

_Bool sset_equals(const IntSortedSetADT s1, const IntSortedSetADT s2) { 
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

_Bool sset_subseteq(const IntSortedSetADT s1, const IntSortedSetADT s2) {
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

_Bool sset_subset(const IntSortedSetADT s1, const IntSortedSetADT s2) {
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

IntSortedSetADT sset_union(const IntSortedSetADT s1, const IntSortedSetADT s2) {
  if((s1 == NULL && s2 == NULL) || (s1 == NULL && s2 != NULL) || (s1 != NULL && s2 == NULL)){
    return 0;
  }
  IntSortedSetADT unionSet = mkSSet(); 
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

IntSortedSetADT sset_intersection(const IntSortedSetADT s1, const IntSortedSetADT s2) {
  if((s1 == NULL && s2 == NULL) || (s1 == NULL && s2 != NULL) || (s1 != NULL && s2 == NULL)){
    return 0;
  }
  IntSortedSetADT interSet = mkSSet(); 
  ListNodePtr node = s1->first;
  while(node != NULL){
    if(sset_member(s2, node->elem)){
      sset_add(interSet, node->elem);
    }
    node = node->next;
  }
  return interSet;
}

IntSortedSetADT sset_subtraction(const IntSortedSetADT s1, const IntSortedSetADT s2) {
  if((s1 == NULL && s2 == NULL) || (s1 == NULL && s2 != NULL) || (s1 != NULL && s2 == NULL)){
    return 0;
  }
  IntSortedSetADT subtractionSet = mkSSet(); 
  ListNodePtr node = s1->first;
  while (node != NULL){
    if(!sset_member(s2, node->elem)){
      sset_add(subtractionSet, node->elem);
    }
    node = node->next;
  }
  return subtractionSet;
} 

_Bool sset_min(const IntSortedSetADT ss, int *ptr) {
  if( ss == NULL || ss->size == 0){
    return 0;
  }
  *ptr = ss->first->elem;
  return 1;
}

_Bool sset_max(const IntSortedSetADT ss, int *ptr) {
  if( ss == NULL || ss->size == 0){
    return 0;
  }
  *ptr = ss->last->elem;
  return 1;
}

_Bool sset_extractMin(IntSortedSetADT ss, int *ptr) {
  if( ss == NULL || ss->size == 0){
    return 0;
  }    
  //tolgo il primo elemento e restituisco il valore
  //il secondo diventa il primo cioè first
  ListNodePtr temp = ss->first;
  *ptr = temp->elem;
  ss->first = ss->first->next;
  free(temp);
  ss->size--;
  return 1;
}

_Bool sset_extractMax(IntSortedSetADT ss, int *ptr) {
  if( ss == NULL || ss->first == NULL ||  ss->last == NULL || ss->size == 0){
    return 0;
  } 
  // caso in cui la lista ha un solo elemento
  if(ss->first == ss->last) {
    *ptr = ss->last->elem;
    free(ss->last);
    ss->first = NULL;
    ss->last = NULL;
    ss->size = 0;
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
