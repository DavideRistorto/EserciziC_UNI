#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <stdio.h>

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


void print_set(const IntSetADT set) {
    if(set == NULL){
        printf("Il set è nullo.\n");
        return;
    }
    if(set->size == 0){
        printf("Il set è vuoto.\n");
        return;
    }
    ListNodePtr node = set->front;
    for(int i=0; i<set->size; i++){
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

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
        //incremento la size
        set->size += 1;
        return 1;
    }
}

_Bool set_remove(IntSetADT set, const int elem) {
    //controllo l' esistenza del set
    if(set == NULL || set->size == 0){
        return 0;
    }
    //controllo se l' elemento da togliere esiste
    bool present = false;
    ListNodePtr node = set->front;
    for (int i=0; i<set->size;i++){
        if(node->data == elem){
            present = true;
            break;
        }
        node = node->next;
    }
    // se l'elemento non è presente ritorno zero
    if(!present){
        return 0;
    }
    // se arrivato a questo punto posso procedere con la rimozione
    node = set->front;
    if(set->size == 1){
        set->size = 0;
        set->front = NULL;
        return 1;        
    }
    for(int i=0; i<set->size;i++){
        if (node->data == elem){
            set->size -= 1;
            node = node->next;
        }
    }
    return 1;
}

_Bool set_member(const IntSetADT set, const int elem) {
    // se il set è vuoto non può contenere l' elemento cercato
    if(set == NULL || set->size == 0){
        return 0;
    }
    //scorro il set e quando trovo l' elemento ritorno 1
    ListNodePtr node = set->front;
    for(int i=0; i<set->size; i++){
        if(node->data == elem){
            return 1;
        }
        node = node->next;
    }
    //in caso non ho trovato l' elemento ritorno zero
    return 0;
}

_Bool isEmptySet(const IntSetADT set) {
    // se il set è nullo o ha dimensione > 0 non è vuoto
    if (set == NULL || set->size != 0){
        return 0;
    }
    return 1;
}

int set_size(const IntSetADT set) {
    if(set == NULL){
        return -1;
    } else{
        return set->size;
    }
}

_Bool set_extract(IntSetADT set, int *datap) {
    if(set == NULL || set->size == 0){
        return 0;
    }
    // estraggo l' ultimo elemento
    ListNodePtr node = set->front;
    for(int i=0;i<set->size-1;i++){
        node = node->next;
    }
    // setto il result e diminuisco la size
    *datap = node->data;
    set->size -= 1;
    return 1;
}

_Bool set_equals(const IntSetADT set1, const IntSetADT set2) {
    //se entrambi i set sono nulli allora sono uguali
    if (set1 == NULL && set2 == NULL ){
        return 1;
    //se entrambi i set hanno size = 0 sono uguali
    }else if(set1 != NULL && set2 != NULL && set1->size == 0 && set2->size == 0){
        return 1;
    }
    //caso in cui entrambi i set sono valorizzati
    if(set1 != NULL && set2 != NULL){
        // se le size sono diverse non sono uguali
        if(set1->size != set2->size){
            return 0;
        }
        ListNodePtr node1 = set1->front;
        for(int i=0; i<set1->size; i++){
            _Bool found = 0;
            ListNodePtr node2 = set2->front;
            for(int j=0; j<set2->size; j++){
                if(node1->data == node2->data){
                    found = 1;
                    break;
                }
                node2 = node2->next;
            }
            if(!found){
                return 0;
            }
            node1 = node1->next;
        }
        return 1;
    }
    return 0;
}

_Bool subseteq(const IntSetADT set1, const IntSetADT set2) {
    // se set2  è nullo, set1 non può mai essere incluso
    if (set1 == NULL || set2 == NULL){
        return 0;
    }
    // se ilset1 è vuoto, esso è sempre incluso nel set2
    if (isEmptySet(set1)){
        return 1;
    }
    if(set1 != NULL){
        ListNodePtr node1 = set1->front;
        //controllo se ogni elemento del set1 è in set2
        for(int i=0; i<set1->size; i++){
            if(!set_member(set2, node1->data)){
                return 0;
            }
            node1 = node1->next;
        }
    }
    return 1;
}

_Bool subset(const IntSetADT set1, const IntSetADT set2) {
    // controllo che size2 > size 1 in tal caso restituisco true
    if(!subseteq(set1, set2)){
        return 0;
    }else if(set1->size < set2->size){
        return 1;
    }
    return 0;
}

IntSetADT set_reverse(IntSetADT set) {
    if (set == NULL || set->size <= 1) {
        // Se il set è vuoto o ha un solo elemento, non c'è bisogno di invertirlo
        return set;
    }

    // Creazione di un nuovo set vuoto
    IntSetADT reversedSet = mkSet();
    if (reversedSet == NULL) {
        // Se non è stato possibile allocare memoria per il nuovo set, restituisci NULL
        return NULL;
    }

    // Iterazione attraverso il set originale e aggiunta degli elementi al nuovo set in testa
    ListNodePtr node = set->front;
    while (node != NULL) {
        // Creazione di un nuovo nodo per il nuovo set
        ListNodePtr newNode = (ListNodePtr)malloc(sizeof(struct listNode));
        if (newNode == NULL) {
            // Se non è stato possibile allocare memoria per il nuovo nodo, dealloca il nuovo set e restituisci NULL
            dsSet(&reversedSet);
            return NULL;
        }
        // Assegnazione del valore del nodo corrente al nuovo nodo
        newNode->data = node->data;
        // Collegamento del nuovo nodo alla lista invertita
        newNode->next = reversedSet->front;
        reversedSet->front = newNode;
        // Passaggio al nodo successivo nel set originale
        node = node->next;
    }

    return set_reverse(reversedSet);
}

IntSetADT set_union(const IntSetADT set1, const IntSetADT set2) {
    //se gli insiemi sono entrami vuoti o nulli l' inserzione non si può fare
    if((set1 == NULL && isEmptySet(set2)) || (set2 == NULL && isEmptySet(set1))){
        return NULL;
    }
    IntSetADT unionSet = mkSet();
    ListNodePtr node = set1->front;
    //aggiungo tutti gli elem di set1
    for(int i=0; i<set1->size; i++){
        set_add(unionSet, node->data);
        node = node->next;
    }
    //aggiungo tutti gli elem di set2
    node = set2->front;
    for(int i=0; i<set2->size; i++){
        set_add(unionSet, node->data);
        node = node->next;
    }
    return unionSet;
}

IntSetADT set_intersection(const IntSetADT set1, const IntSetADT set2) {
    //se gli insiemi sono entrami vuoti o nulli l' inserzione non si può fare
    if((set1 == NULL && isEmptySet(set2)) || (set2 == NULL && isEmptySet(set1))){
        return NULL;
    }
    IntSetADT intersectionSet = mkSet();
    //se uno degli insiemi è vuoto, l' inserzione è vuota
    if(isEmptySet(set1) || isEmptySet(set2)){
        return intersectionSet;
    }
    ListNodePtr node = set1->front;
    for(int i=0; i<set1->size; i++){
        if(set_member(set2, node->data)){
            set_add(intersectionSet, node->data);
        }
        node = node->next;
    }
    return intersectionSet;
}

IntSetADT set_subtraction(const IntSetADT set1, const IntSetADT set2) {
    if((set1 == NULL && isEmptySet(set2)) || (set2 == NULL && isEmptySet(set1))){
        return NULL;
    }
    IntSetADT subtrSet = mkSet();
    printf("subtrSet->size: %d\n", subtrSet->size);
    ListNodePtr node = set1->front;
    //se il secondo set è vuoto, l' insieme di sottrazione è uguale al primo
    if(isEmptySet(set2)){
        for(int i=0; i<(set1->size); i++){
            set_add(subtrSet, node->data);
            node = node->next;
        }
    }else{
        // se un elemento del primo set, non appartiene al secondo allora lo aggiungo a quello di sub.
        for(int i=0; i<set1->size; i++){
            if(!set_member(set2, node->data)){
                set_add(subtrSet, node->data);
                node = node->next;
            }
        }
    }
    return subtrSet;
}