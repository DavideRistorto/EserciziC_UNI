#include "charQueueADT.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct listNode ListNode, *ListNodePtr;
struct listNode {
    char data;
    ListNodePtr next;
};

struct charQueue {
    ListNodePtr front;
    ListNodePtr rear;
    // Come indicato da consegna, aggiungo come campo la dimensione della coda per non doverla calcolare ogni volta
    int size;
};

CharQueueADT mkQueue() {
    // Alloco la memoria per la coda e setto i valori iniziali
    CharQueueADT queue = (CharQueueADT)malloc(sizeof(struct charQueue));
    if(queue != NULL){
        queue->front = NULL;
        queue->rear = NULL;
        queue->size = 0;
    }
    return queue;
}

void dsQueue(CharQueueADT *pq) {
    free(*pq);
    *pq = NULL;
}

_Bool enqueue(CharQueueADT q, const char e) {
    //creo un nuovo nodo temporaneo
    ListNodePtr newNode = (ListNodePtr)malloc(sizeof(struct listNode));
    // setto i valori all' interno del nodo
    newNode->data = e;
    newNode->next = NULL;
    // aggiorno la coda (la fine)
    if(q->rear != NULL){
        q->rear->next = newNode;
    }else{
        // nel caso la coda sia vuota, il nuovo nodo è messo in testa
        q->front = newNode;
    }
    // aggiorno la coda che è l'ultimo nodo appena inserito
    q->rear = newNode;
    q->size++;
    return 1;
}

_Bool dequeue(CharQueueADT q, char* res) {
    // se la coda è vuoto non posso fare la dequeue
    if(q->front == NULL){
        return 0;
    }else{
        // nodo temporaneo che punta al primo nodo della coda
        ListNodePtr newNode = q->front;
        // estraggo il risultato
        *res = q->front->data;
        // aggiorno la coda che partirà dal secondo nodo
        q->front = q->front->next;
        // nel caso la coda fosse formata da un solo nodo,
        // la coda sarà vuota e il reaa/front saranno nulli
        if(q->front == NULL){
            q->rear = NULL;
        }
        free(newNode);
        q->size--;
        return 1;
    }
}

_Bool isEmpty(CharQueueADT q) {
    if(q == NULL || q->front == NULL){
        return 1;
    } return 0;
}

int size(CharQueueADT q) {
    if(q != NULL){
        return q->size;
    }
    return 0;
}

_Bool peek(CharQueueADT q, int position, char *res) {
    // controllo se position > 0 e se la coda è vuota
    if(q->front == NULL || position < 0){
        return 0;
    }
    int counter = 0;
    ListNodePtr node = q->front;
    // ciclo tutta la lista fino ad arrivare al nodo desiderato
    while(node != NULL && counter < position){
        counter++;
        node = node->next;
    }
    // controllo se il nodo cercato esiste effettivamente nella lista
    if(node != NULL){
        *res = node->data;
        return 1;
    }
    return 0;
}