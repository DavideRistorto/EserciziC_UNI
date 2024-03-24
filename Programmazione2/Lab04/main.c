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


void printQueue(CharQueueADT q) {
    ListNodePtr temp = q->front;
    while(temp != NULL){
        printf("Element: '%c'\n", temp->data);
        temp = temp->next;
    }
}


/* @brief Restituisce una coda vuota, se non trova memoria restituisce NULL */
CharQueueADT mkQueue() {
    printf("MALLOC\n");
    CharQueueADT queue = (CharQueueADT)malloc(sizeof(struct charQueue));
    if(queue != NULL){
        queue->front = NULL;
        queue->rear = NULL;
    }
    return queue;
}

/* @brief Distrugge la coda, recuperando la memoria */
void dsQueue(CharQueueADT *pq) {
    printf("FREE\n");
    free(*pq);
    *pq = NULL;
}

/* @brief Aggiunge un elemento in fondo alla coda */
_Bool enqueue(CharQueueADT q, const char e) {
    printf("ENQUEUE\n");
    ListNodePtr newNode = (ListNodePtr)malloc(sizeof(struct listNode));
    if(newNode == NULL){
        return 0;
    }
    newNode->data = e;
    newNode->next = NULL;
    if(q->rear != NULL){
        q->rear->next = newNode;
    }else{
        q->front = newNode;
    }
    q->rear = newNode;
    printQueue(q);
    return 1;
}


/* @brief Toglie e restituisce l'elemento in testa alla coda */
_Bool dequeue(CharQueueADT q, char* res) {
    printf("DEQUEUE\n");
    if(q->front == NULL){
        printf("NULL\n");
        res = NULL;
        return 0;
    }else{
        printf("NON NULL\n");
        res = &(q->front->data);
        return q->front->data;
    }
}



/* @brief Controlla se la coda è vuota */
_Bool isEmpty(CharQueueADT q) {
   return 1;
}

/* @brief Restituisce il numero degli elementi presenti nella coda */
int size(CharQueueADT q) {
    return 1;
}

/* @brief Restituisce l'elemento nella posizione data (senza toglierlo) */
_Bool peek(CharQueueADT q, int position, char *res) {
    return 1;
}


