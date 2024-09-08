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
	if((lsPtr1 == NULL && lsPtr2 == NULL) || (*lsPtr1 == NULL && *lsPtr2 == NULL)){
		return NULL;
	}
	IntList result = NULL;
	IntList* resultNext = &result;
	IntList ls1 = *lsPtr1;
	IntList ls2 = *lsPtr2;

	while(ls1 && ls2){
		*resultNext = ls1;
		resultNext = &((*resultNext)->next);
		ls1 = ls1->next;

		*resultNext = ls2;
		resultNext = &((*resultNext)->next);
		ls2 = ls2->next;
	}
	if(ls1){
		*resultNext = ls1;
	}
	if(ls2 != NULL){
		*resultNext = ls2;
	}
	*lsPtr1 = NULL;
	*lsPtr2 = NULL;
	return result;
}

// Funzione per creare un nuovo nodo
IntList create_node(int data) {
	IntList new_node = (IntList)malloc(sizeof(IntNode));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

// Funzione per aggiungere un nodo alla fine della lista
void append(IntList *head_ref, int new_data) {
	IntList new_node = create_node(new_data);
	IntList last = *head_ref;
	if (*head_ref == NULL) {
		*head_ref = new_node;
		return;
	}
	while (last->next != NULL) {
		last = last->next;
	}
	last->next = new_node;
}

// Funzione per stampare la lista
void print_list(IntList node) {
	while (node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}

int main() {
	IntList list1 = NULL;
	IntList list2 = NULL;

	// Creazione della prima lista [1, 5, 9]
	append(&list1, 1);
	append(&list1, 5);
	append(&list1, 9);

	// Creazione della seconda lista [0, 2, 4, 6, 8]
	append(&list2, 0);
	append(&list2, 2);
	append(&list2, 4);
	append(&list2, 6);
	append(&list2, 8);

	printf("List 1: ");
	print_list(list1);
	printf("List 2: ");
	print_list(list2);

	// Unione delle liste in modo alternato
	IntList merged_list = mixAlternate(&list1, &list2);

	printf("Merged List: ");
	print_list(merged_list);

	// Verifica che le liste originali siano vuote
	printf("List 1 after merge: ");
	print_list(list1);
	printf("List 2 after merge: ");
	print_list(list2);

	return 0;
}
