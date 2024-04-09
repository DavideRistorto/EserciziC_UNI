#include <stdlib.h>
#include <stdbool.h>
#include "intSetADT.h"

typedef struct listNode ListNode, *ListNodePtr;

struct listNode {
    int data;
    ListNodePtr next;
};

struct intSet {
    ListNodePtr front; /* Punta al primo nodo dell'insieme, se l'insieme e' vuoto vale NULL */
    int size; /* Numero di elementi presenti nell'insieme */
};

IntSetADT mkSet() {
    IntSetADT set = (IntSetADT)malloc(sizeof(struct intSet));
    if (set){
        set->front = NULL;
        set->size = 0;
    }
    return set;
}

_Bool dsSet(IntSetADT *sp) {
    if(sp != NULL){
        free(*sp);
        *sp = NULL;
        return 1;
    }
    return 0;
}

_Bool set_add(IntSetADT set, const int elem) {
    //controllo se il set esiste
    if(set == NULL){
        return 0;
        //controllo se il set è vuoto
    } else if(set->size == 0){
        //creo un nuovo nodo è lo metto come front
        ListNodePtr node = (ListNodePtr)malloc(sizeof(struct listNode));
        node->data = elem;
        node->next = NULL;
        set->front = node;
        set->size += 1;
        return 1;
    } else {
        //controllo se l' elemento è gia presente
        ListNodePtr node = set->front;
        for(int i=0; i<(set->size)-1; i++){
            // se presente return 0
            if(node->data == elem){
                return 0;
            }
        }
        // arrivo fino all' ultimo nodo
        node = set->front;
        for(int i=0; i<(set->size)-1; i++){
            node = node->next;
        }
        // creo un nuovo nodo e lo metto in foto alla lista
        ListNodePtr newNode = (ListNodePtr)malloc(sizeof(struct listNode));
        newNode->data = elem;
        newNode->next = NULL;
        node->next = newNode;
        set->size += 1;
        return 1;
    }
}

_Bool set_remove(IntSetADT set, const int elem) {
    return false;
}

_Bool set_member(const IntSetADT set, const int elem) {
    return false;
}

_Bool isEmptySet(const IntSetADT set) {
    if (set == NULL || set->size == 0){
        return 0;
    }
    return set->size;
}

int set_size(const IntSetADT set) {
    return -1;
}

_Bool set_extract(IntSetADT set, int *datap) {
    return false;
}

_Bool set_equals(const IntSetADT set1, const IntSetADT set2) {
    return false;
}

_Bool subseteq(const IntSetADT set1, const IntSetADT set2) {
    return false;
}

_Bool subset(const IntSetADT set1, const IntSetADT set2) {
    return false;
}

IntSetADT set_union(const IntSetADT set1, const IntSetADT set2) {
    return NULL;
}

IntSetADT set_intersection(const IntSetADT set1, const IntSetADT set2) {
    return NULL;
}

IntSetADT set_subtraction(const IntSetADT set1, const IntSetADT set2) {
    return NULL;
}