#include <stdlib.h>
#include <stdbool.h>

#include "intSortedSetADT.h"
#include "intLinkedListSortedSetADT.h"

_Bool areSetsInvalid(const IntSortedSetADT* s1, const IntSortedSetADT* s2){
  if((s1 == NULL && s2 == NULL) || (s1 == NULL && s2 != NULL) || (s1 != NULL && s2 == NULL)){
    return 1;
  }
  return 0;
}


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
  if( ssptr!= NULL){
    free(*ssptr);
    *ssptr = NULL;
    return 1;
  }
  return 0;
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
  ListNodePtr cur = ss->first;
  while(cur != NULL){
    if(cur->elem == elem){
      return 0;
    }
    cur = cur->next;
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
  cur = ss->first->next;
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
}  

_Bool sset_remove(const IntSortedSetADT ss, const int elem) {
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
  return (ss->size == 0) ? 1 : 0;
}

int sset_size(const IntSortedSetADT ss) {
  return(ss == NULL) ? -1 : ss->size;
}

_Bool sset_extract(IntSortedSetADT ss, int *ptr) {
    return false;
}

_Bool sset_equals(const IntSortedSetADT s1, const IntSortedSetADT s2) {
    return false;
}

_Bool sset_subseteq(const IntSortedSetADT s1, const IntSortedSetADT s2) {
    return false;
}

_Bool sset_subset(const IntSortedSetADT s1, const IntSortedSetADT s2) {
    return false;
}

IntSortedSetADT sset_union(const IntSortedSetADT s1, const IntSortedSetADT s2) {
    return NULL; 
}

IntSortedSetADT sset_intersection(const IntSortedSetADT s1, const IntSortedSetADT s2) {
    return NULL;
}

IntSortedSetADT sset_subtraction(const IntSortedSetADT s1, const IntSortedSetADT s2) {
    return NULL;   
}

_Bool sset_min(const IntSortedSetADT ss, int *ptr) {
    return false;
}

_Bool sset_max(const IntSortedSetADT ss, int *ptr) {
    return false;
}

_Bool sset_extractMin(IntSortedSetADT ss, int *ptr) {
    return false;    
}

_Bool sset_extractMax(IntSortedSetADT ss, int *ptr) {
    return false;       
}