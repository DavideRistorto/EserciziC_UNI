#include <stdio.h>
#include <stdlib.h>

typedef struct node IntNode, *IntList;
struct node {
  int data;
  IntList next;
};

/** @brief Restituisce la lista alternata dei nodi di *lsPtr1 e *lsPtr2, togliendoli da
*lsPtr1 e *lsPtr2,
* che alla fine conterranno entrambi NULL (non alloca nuova memoria).
* Ad es. date [1, 5, 9] e [0, 2, 4, 6, 8] restituisce [1, 0, 5, 2, 9, 4, 6, 8].
*/
IntList mixAlternate(IntList *lsPtr1, IntList *lsPtr2){
	//controllo validità stringhe
	if((lsPtr1 == NULL && lsPtr2 == NULL) || (*lsPtr1 == NULL && *lsPtr2 == NULL)){
		return NULL;
	}
  IntList result = NULL;
  IntList *nextPtr = &result;
	IntList ls1 = *lsPtr1;
	IntList ls2 = *lsPtr2;
	
	while(ls1 && ls2){
	 *nextPtr = ls1;
		nextPtr = &((*nextPtr)->next);
		ls1 = ls1->next;
		
		*nextPtr = ls2;
		nextPtr = &((*nextPtr)->next);
		ls2 = ls2->next;
	}
	if(ls1 != NULL){
		*nextPtr = ls1;
	}
	if(ls2 != NULL){
		*nextPtr = ls2;
	}
	*lsPtr1 = *lsPtr2 = NULL;
	return result;
	
}