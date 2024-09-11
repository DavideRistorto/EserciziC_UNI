#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node IntNode, *IntList;
struct node {
	int data;
	IntList next;
};

/**
 *@brief Funzione ausiliaria per controllare se 
 * un elemento è all' interno di una lista
 */
bool checkInList(int data, IntList list) {
	while(list){
		if(data == list->data){
			return 1;
		}
		list = list->next;
	}
	return 0;
}

/** @brief Modifica *lsPtr1 togliendo da *lsPtr1 tutti i nodi che 
 * occorrono in *lsPtr2, li resituisce in una nuova lista nello stesso ordine in cui 
 * occorrono in *lsPtr1 (NON ALLOCARE NUOVA MEMORIA)
 * ESEMPIO: [1,2,5,3,4,5,9,8] e [7,5,2,4] modifica la prima lista in [1,3,9,8] e 
 * resituisce [2,5,4,5]
*/
IntList transfer(IntList *lsPtr1, IntList *lsPtr2) {
	if(lsPtr1 == NULL || lsPtr2 == NULL) return NULL;

	IntList result = NULL;
	IntList *resultPtr = &result; 
	IntList currentLs1 = *lsPtr1;
	IntList prevLs1 = NULL;
	
	while(currentLs1){
		if(checkInList(currentLs1->data, *lsPtr2)){
			//caso in cui devo scollegare l'elemento e metterlo in result
			*resultPtr = currentLs1;
			resultPtr = &((*resultPtr)->next);
			
			//se prev è inizializzato faccio prev->(current)->next
			if(prevLs1){
				prevLs1->next = currentLs1->next;
				currentLs1 = currentLs1->next;
			}else{
				//se prev non è inizializzato devo aggiornare la testa della lista
				*lsPtr1 = currentLs1->next;
				currentLs1 = currentLs1->next;

			}
		}else{
			//se l'elemento non è presente in ls2 aggiorno solamente
			//i riferimenti a prev e current per mandarli in avanti
			prevLs1 = currentLs1;
			currentLs1 = currentLs1->next;
		}
	}
	//scollego gli elementi ti troppo in result
	*resultPtr = NULL;
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

	// Creazione della prima lista [1,2,5,3,4,5,9,8]
	append(&list1, 1);
	append(&list1, 2);
	append(&list1, 5);
	append(&list1, 3);
	append(&list1, 4);
	append(&list1, 5);
	append(&list1, 9);
	append(&list1, 8);

	// Creazione della seconda lista [7,5,2,4]
	append(&list2, 7);
	append(&list2, 5);
	append(&list2, 2);
	append(&list2, 4);

	printf("List 1: ");
	print_list(list1);
	printf("List 2: ");
	print_list(list2);

	// Unione delle liste in modo alternato
	IntList merged_list = transfer(&list1, &list2);

	printf("Transferred List: ");
	print_list(merged_list);

	// Verifica che le liste originali siano vuote
	printf("List 1 after transfer: ");
	print_list(list1);
	printf("List 2 after transfer: ");
	print_list(list2);

	return 0;
}
