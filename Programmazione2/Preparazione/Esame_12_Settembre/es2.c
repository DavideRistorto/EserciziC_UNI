/** @brief Date due liste ordinate *lsPtr1 e *lsPtr2, restituisce una lista ordinata contenente tutti i nodi di *lsPtr1 e *lsPtr2.
*    I nodi vanno posizionati nella lista risultato a seconda del loro valore, in modo tale da renderla ordinata.
*    Non bisogna usare la malloc bensì bisogna togliere i nodi dalle liste di input *lsPtr1 e *lsPtr2, che alla fine conterranno
*    entrambi NULL  (in altri termini non si alloca nuova memoria).
*    Ad es. date [1, 5, 9] e [0, 2, 4, 6, 8] restituisce [0, 1, 2, 4, 5, 6, 8, 9].
*    Realizzare una soluzione ITERATIVA
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct node IntNode, *IntList;
struct node {
  int data;
  IntList next;
};


IntList merge(IntList *lsPtr1, IntList *lsPtr2){
  //caso base in cui non posso generare una lista
  if(*lsPtr1 == NULL && *lsPtr2){
    return NULL;
  }
    
  IntList curr1 = *lsPtr1; //copia lista 1
  IntList curr2 = *lsPtr2; //copia lista 2
  IntList mergeList = NULL; // lista risultato che viene restituita alla fine 
  IntList *risPtr = &mergeList; //puntatore alla lista per mantenere traccia di dove sono
  
  //scorro finche entrambe le liste hanno valori
  while(curr1 && curr2){
    //se curr1 < curr2 lo aggiungo per primo alla lista
    if(curr1->data < curr2->data){
      *risPtr = curr1;      //collego il nodo alla lista risultato
      curr1 = curr1->next; //passo al nodo successivo della lista 1
    //se curr1 > curr2 aggiungo prima curr2
    }else{
      *risPtr = curr2;  //collego il nodo alla lista risultato
      curr2 = curr2->next; //passo al nodo successivo della lista 2
    }
    //aggiorno il puntatore della lista risultato
    risPtr = &((*risPtr)->next); 
  }
  // collego la parte restante della lista 1 se ha ancora elementi dopo il ciclo while
  if(curr1){
    *risPtr = curr1;
  }
  //altrimenti collego la parte restante della lista 2
  if(curr2){
    *risPtr = curr2;
  }
  //setto le due liste di partenza a NULL come da consegna
  *lsPtr1 = NULL;
  *lsPtr2 = NULL;
  return mergeList;
}