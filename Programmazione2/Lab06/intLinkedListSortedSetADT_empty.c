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
    if( ss->size == 0){
        ListNodePtr node = malloc(sizeof(struct listNode));
        node->elem = elem;
        node->next = NULL;
        ss->first = node;
        ss->last = node;
        ss->size++;
        return 1;
    }
    //controllo se l'elemento è già presente
    ListNodePtr current = ss->first;
    while(current != NULL){
        if(current->elem == elem){
            return 0;
        }
        current = current->next;
    }
    //aggiungo l'elemento in coda in maniera ordinata
    ListNodePtr node = malloc(sizeof(struct listNode));
    node->elem = elem;
    node->next = NULL;
    // se l'emento è minore del primo, diventa il primo
    if(elem < ss->first->elem){
        node->next = ss->first;
        ss->first = node;
        ss->size++;
        return 1;
    }
    // se l'elemento è maggiore dell'ultimo, diventa l'ultimo
    if(elem > ss->last->elem){
        ss->last->next = node;
        ss->last = node;
        ss->size++;
        return 1;
    }
    // se l'elemento è compreso tra il primo e l'ultimo, lo inserisco in mezzo
    ListNodePtr prev = ss->first;
    ListNodePtr succ = ss->first->next;
    while(succ != NULL){
        if(prev->elem < elem && succ->elem > elem){
            prev->next = node;
            node->next = succ;
            ss->size++;
            return 1;
        }
        prev = succ;
        succ = succ->next;
    }
    return 0;
}

_Bool sset_remove(const IntSortedSetADT ss, const int elem) {
    //controllo l' esistenza del set
    if(ss == NULL || ss->size == 0){
        return 0;
    }
    //caso in cui il set ha un solo elemento
    if(ss->size == 1){
        if(ss->first->elem == elem){
            free(ss->first);
            ss->first = NULL;
            ss->last = NULL;
            ss->size--;
            return 1;
        }
    }
    //caso in cui l'elemento da eliminare è il primo
    if(ss->first->elem == elem){
        ListNodePtr temp = ss->first;
        ss->first = ss->first->next;
        free(temp);
        ss->size--;
        return 1;
    }
    //caso in cui l'elemento da eliminare è l' ultimo
    ListNodePtr secondLastNode = ss->first;
    while(secondLastNode->next != NULL){
        if(secondLastNode->next->elem == elem){
            free(secondLastNode->next);
            secondLastNode->next = NULL;
            //l 'ultimo nodo diventa il penultimo
            ss->last = secondLastNode;
            ss->size--;
            return 1;
        }
        secondLastNode = secondLastNode->next;
    }
    // caso in cui l'elemento da eliminare è in mezzo a due nodi
}

_Bool sset_member(const IntSortedSetADT ss, const int elem) {
    return false;
}

_Bool isEmptySSet(const IntSortedSetADT ss) {
    return false;
}

int sset_size(const IntSortedSetADT ss) {
    return -1;
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