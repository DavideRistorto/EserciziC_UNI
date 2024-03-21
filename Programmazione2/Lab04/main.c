#include "charQueueADT.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct listNode ListNode, *ListNodePtr;
struct listNode {
   char data;
   ListNodePtr next;
};

struct charQueue {
    ListNodePtr front; /* Punta al primo nodo della lista, che contiene l'elemento in testa alla coda, se la coda è vuota vale NULL */
    ListNodePtr rear; /* Punta all'ultimo nodo della lista, che contiene l'elemento in fondo alla coda, se la coda è vuota vale NULL */
    
    /* aggiungere eventuali altre variabili per ottenere una implementazione più efficiente */
};

/* @brief Restituisce una coda vuota, se non trova memoria restituisce NULL */
CharQueueADT mkQueue() {
    CharQueueADT queue = (CharQueueADT)malloc(sizeof(struct charQueue));
    return queue;
}

/* @brief Distrugge la coda, recuperando la memoria */
void dsQueue(CharQueueADT *pq) {
   free(*pq);
   *pq = NULL;
}

/* @brief Aggiunge un elemento in fondo alla coda */
_Bool enqueue(CharQueueADT q, const char e) {
    ListNodePtr newNode = (ListNodePtr)malloc(sizeof(struct listNode));
    newNode->data = e;
    if(q->rear != NULL){
        newNode->next = q->rear;
        q->rear = newNode;
    }else{
        q->rear = newNode;
        q->front = newNode;
    }
    //printf("%c", q->rear->data);
    return 1;
}


/* @brief Toglie e restituisce l'elemento in testa alla coda */
_Bool dequeue(CharQueueADT q, char* res) {
    
    if(q != NULL && q->front != NULL && q->rear != NULL){
        if(&(q->front->data) != NULL){
        }
    }
    
    return 1;
}


/* @brief Controlla se la coda è vuota */
_Bool isEmpty(CharQueueADT q) {
    return q->front == NULL;
}

/* @brief Restituisce il numero degli elementi presenti nella coda */
int size(CharQueueADT q) {
    return 1;
}

/* @brief Restituisce l'elemento nella posizione data (senza toglierlo) */
_Bool peek(CharQueueADT q, int position, char *res) {
    return 1;
}


