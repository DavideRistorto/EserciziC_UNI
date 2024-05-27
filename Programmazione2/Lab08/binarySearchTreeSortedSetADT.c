#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "sortedSetADT.h"
#include "binarySearchTreeSortedSetADT.h"

void stampaSet_rec(TreeNodePtr cur, void (*stampaelem)(void*)) {
    #ifdef DEBUG
    printf("( ");
    #endif
    if (cur) {
        stampaSet_rec(cur->left, stampaelem);
        (*stampaelem)(cur->elem);
        stampaSet_rec(cur->right, stampaelem);
    }
    #ifdef DEBUG
    printf(") ");
    #endif
}

// stampa i contenuti dell'insieme, data la funzione di stampa di un elemento
void stampaSet(SortedSetADTptr ss, void (*stampaelem)(void*)) {
    if(!ss) printf("Insieme non esiste\n");
    else if(sset_size(ss) == 0) printf("Insieme vuoto\n");
    else {
        printf("Insieme: (size %d) ",ss->size);
        stampaSet_rec(ss->root, stampaelem);
        printf("\n");
    }
}

// restituisce un insieme vuoto impostando funzione di confronto, NULL se errore
SortedSetADTptr mkSSet(int (*compare)(void*, void*)) {
  SortedSetADTptr set = (SortedSetADTptr)malloc(sizeof(struct sortedSetADT));
  if(set == NULL){
      return NULL;
  }
  set->compare = compare;
  set->size = 0;
  set->root = NULL;
  return set;
}

//funzione ricorsiva che elimina ogni nodo
void dsTree(TreeNodePtr cur){
    if(cur == NULL){
        return;
    }
    dsTree(cur->left);
    dsTree(cur->right);
    free(cur);
}

// distrugge l'insieme, recuperando la memoria
_Bool dsSSet(SortedSetADTptr* ssptr) {
  if (ssptr == NULL){
    return false;
  }
  dsTree((*ssptr)->root);
  free(*ssptr);
  *ssptr = NULL;
  return true;
}

void sset_add_rec(TreeNodePtr* cur, void* elem, SortedSetADTptr ss) {
    if (*cur == NULL) {
        *cur = (TreeNodePtr)malloc(sizeof(TreeNode));
        (*cur)->elem = elem;
        (*cur)->right = (*cur)->left = NULL;
    } else {
        if (ss->compare(elem, (*cur)->elem) < 0) {
            sset_add_rec(&(*cur)->left, elem, ss);
        } else {
            sset_add_rec(&(*cur)->right, elem, ss);
        }
    }
}

// Aggiunge un elemento all'insieme 
_Bool sset_add(SortedSetADTptr ss, void* elem) { 
    // Set nullo o elemento già presente
    if (ss == NULL || sset_member(ss, elem) == 1) {
        return 0;
    }
    sset_add_rec(&ss->root, elem, ss);
    ss->size++;
    return 1;
} 

void sset_extractMin_rec(TreeNodePtr* cur, void**ptr, int (*compare)(void*, void*));
void sset_extractMax_rec(TreeNodePtr* cur, void**ptr, int (*compare)(void*, void*));

// funzione ausiliaria che toglie un elemento da un sottoalbero
_Bool sset_remove_rec(TreeNodePtr* cur, void* elem, int (*compare)(void*, void*)) {
    if (*cur == NULL) return false;
    int r = compare(elem, (*cur)->elem);
    if (r < 0) return sset_remove_rec(&((*cur)->left), elem, compare);
    if (r > 0) return sset_remove_rec(&((*cur)->right), elem, compare);
    void* ptr;
    if ((*cur)->left == NULL) {
        sset_extractMin_rec(cur, &ptr, compare);
    } else if ((*cur)->right == NULL) {
        sset_extractMax_rec(cur, &ptr, compare);
    } else {
        sset_extractMax_rec(&((*cur)->left), &ptr, compare);
        (*cur)->elem = ptr;
    }
    return true;
}

// toglie un elemento all'insieme
_Bool sset_remove(SortedSetADTptr ss, void* elem) {
    if (ss && sset_remove_rec(&(ss->root), elem, ss->compare)) {
        ss->size--;
        return true;
    }
    return false;
}

// controlla se un elemento appartiene all'insieme
int sset_member(const SortedSetADT* ss, void* elem) {
	//set vuoto allora return errore
	if(ss == NULL){
		return -1;
	}
	TreeNodePtr node = ss->root;
	while(node != NULL){
		//compare il ricercato vs l' elemento attuale
		int compareResult = ss->compare(elem, node->elem);
		//caso di uguaglianza
		if(compareResult == 0){
			return 1;
		}
		//caso in cui il ricercato è minore di quello attuale
		else if( compareResult == -1){
			node = node->left;
		}
		//caso in cui il ricercato è maggiore di quello attuale
		else {
			node = node->right;
		}
	}
	return 0;
}

void* sset_search_rec(const SortedSetADT* ss, void* elem, TreeNodePtr cur){
    //caso di uscita
    if(cur == NULL){
        return NULL;
    }
    int compareResult = ss->compare(elem, cur->elem);
    //caso di elemento trovato
    if(compareResult == 0){
        return cur->elem;
    }//scorro a sinistra perchè minore
    else if(compareResult == -1){
        return sset_search_rec(ss, elem, cur->left);
    }//scorro a destra perchè maggiore
    else{
        return sset_search_rec(ss, elem, cur->right);
    }
}

// cerca un elemento nell'insieme che si compara uguale a quello dato, NULL se non trovato
void* sset_search(const SortedSetADT* ss, void* elem) {
    if(isEmptySSet(ss) != 0){
        return NULL;
    }
    //chiamata funzione ricorsiva
    return sset_search_rec(ss, elem, ss->root);
}

// controlla se l'insieme e' vuoto
int isEmptySSet(const SortedSetADT* ss) {
  if(ss == NULL){
		return -1;
    }
	return (ss->size == 0) ? 1 : 0;
}  

// restituisce il numero di elementi presenti nell'insieme
int sset_size(const SortedSetADT* ss) {
  return (ss == NULL) ? -1 : ss->size;
} 

// toglie e restituisce un elemento a caso dall'insieme
_Bool sset_extract(SortedSetADTptr ss, void**ptr) { 
    if(ss == NULL || ss->root == NULL){
        return false;
    }
    // Genera un indice casuale nell'intervallo [0, size - 1]
    srand(time(NULL)); // Inizializza il generatore di numeri casuali
    int random_index = rand() % ss->size;
    void ** array = sset_toArray(ss);
    void* elem = array[random_index];
    if(sset_remove(ss, elem) == 1){
    *ptr = elem;
    free(array);
    return 1;
    }
    else{
        return 0;
    }
}

// controlla se due insiemi sono uguali
int sset_equals(const SortedSetADT* s1, const SortedSetADT* s2) { 
    if ((s1 == NULL) || (s2 == NULL) || (s1->size == 0 && s2->size == 0)){
        return -1;
    }
    if(s1->size != s2->size){
        return 0;
    }
    bool allPresent = 1;
    void** array = sset_toArray(s1);
    for (size_t i = 0; i < s1->size; i++) {
        if(sset_member(s2, array[i]) != 1){
            allPresent = 0;
        }
    }
    return allPresent;
}

// controlla se il primo insieme e' incluso nel secondo
int sset_subseteq(const SortedSetADT* s1, const SortedSetADT* s2) {
    if ((s1 == NULL) || (s2 == NULL) || (s1->size == 0 && s2->size == 0)){
        return -1;
    }
    if(s1->size > s2->size){
        return 0;
    }
    bool allPresent = 1;
    void** array = sset_toArray(s1);
    for (size_t i = 0; i < s1->size; i++) {
        if(sset_member(s2, array[i]) != 1){
            allPresent = 0;
        }
    }
    return allPresent;
}

// controlla se il primo insieme e' incluso strettamente nel secondo
int sset_subset(const SortedSetADT* s1, const SortedSetADT* s2) {
    if ((s1 == NULL) || (s2 == NULL) || (s1->size == 0 && s2->size == 0)){
        return -1;
    }
    if(sset_equals(s1, s2) == 1){
        return 0;
    }
    return sset_subseteq(s1, s2);
} 

// restituisce l'unione di due insiemi, NULL se errore
SortedSetADTptr sset_union(const SortedSetADT* s1, const SortedSetADT* s2) {
    if (s1 == NULL || s2 == NULL) {
        return NULL;
    }
    SortedSetADTptr unionSet = mkSSet(s1->compare);
    if (unionSet == NULL) {
        return NULL;
    }
    void** array1 = sset_toArray(s1);
    void** array2 = sset_toArray(s2);
    // Inserisci gli elementi di s1 nell'insieme unione
    for (size_t i = 0; i < s1->size; i++) {
        if (sset_member(unionSet, array1[i]) == 0) {
            sset_add(unionSet, array1[i]);
        }
    }
    // Inserisci gli elementi di s2 nell'insieme unione
    for (size_t i = 0; i < s2->size; i++) {
        if (sset_member(unionSet, array2[i]) == 0) {
            sset_add(unionSet, array2[i]);
        }
    }
    free(array1);
    free(array2);
    return unionSet;
}

SortedSetADTptr sset_subtraction(const SortedSetADT* s1, const SortedSetADT* s2) {
    if (s1 == NULL || s2 == NULL) {
        return NULL;
    }
    SortedSetADTptr resultSet = mkSSet(s1->compare);
    void** array1 = sset_toArray(s1);
    for (size_t i = 0; i < s1->size; i++) {
        if (sset_member(s2, array1[i]) == 0) {
            sset_add(resultSet, array1[i]);
        }
    }
    return resultSet;
}

// restituisce l'intersezione di due insiemi, NULL se errore
SortedSetADTptr sset_intersection(const SortedSetADT* s1, const SortedSetADT* s2) {
    if (s1 == NULL || s2 == NULL) {
        return NULL;
    }
    SortedSetADTptr resultSet = mkSSet(s1->compare);
    void** array1 = sset_toArray(s1);
    for (size_t i = 0; i < s1->size; i++) {
        if (sset_member(s2, array1[i]) == 1) {
            sset_add(resultSet, array1[i]);
        }
    }
    return resultSet;
}

// restituisce il primo elemento 
_Bool sset_min(const SortedSetADT* ss, void**ptr) {
  if (ss == NULL || ss->root == NULL){
		return 0;
	}
	//l' elemento minore sarà quello più a sinistra
	TreeNodePtr node = ss->root;
	while (node->left != NULL){
		node = node->left;
	}
	*ptr = node->elem;
	return 1;
}

// restituisce l'ultimo elemento 
_Bool sset_max(const SortedSetADT* ss, void**ptr) {
	if (ss == NULL || ss->root == NULL){
		return 0;
	}
	//l' elemento minore sarà quello più a sinistra
	TreeNodePtr node = ss->root;
	while (node->right != NULL){
		node = node->right;
	}
	*ptr = node->elem;
	return 1;
}


void sset_extractMin_rec(TreeNodePtr* cur, void**ptr, int (*compare)(void*, void*)) {
    if ((*cur)->left) sset_extractMin_rec(&((*cur)->left), ptr, compare);
    else {
        (*ptr) = (*cur)->elem;
        if ((*cur)->right) {
            TreeNodePtr tmp = *cur;
            (*cur) = (*cur)->right;
            free(tmp);
        } else {
            free(*cur);
            *cur = NULL;
        }
    }
}

// toglie e restituisce il primo elemento 
_Bool sset_extractMin(SortedSetADTptr ss, void**ptr) {
    if(isEmptySSet(ss) != 0){
        return 0;
    }    
    sset_extractMin_rec(&(ss->root), ptr, ss->compare);
    return 1;
}

void sset_extractMax_rec(TreeNodePtr* cur, void**ptr, int (*compare)(void*, void*)) {
    if ((*cur)->right) sset_extractMax_rec(&((*cur)->right), ptr, compare);
    else {
        (*ptr) = (*cur)->elem;
        if ((*cur)->left) {
            TreeNodePtr tmp = *cur;
            (*cur) = (*cur)->left;
            free(tmp);
        } else {
            free(*cur);
            *cur = NULL;
        }
    }
}

// toglie e restituisce l'ultimo elemento (0 se lista vuota, -1 se errore, 1 se restituisce elemento)
_Bool sset_extractMax(SortedSetADTptr ss, void**ptr) {
    if(isEmptySSet(ss) != 0){
        return 0;
    }    
    sset_extractMax_rec(&(ss->root), ptr, ss->compare);  
    return 1;
}

void sset_toArray_rec(TreeNodePtr cur, void** array, int* index) {
    if (cur == NULL) {
        return;
    }
    array[*index] = cur->elem;
    (*index)++;
    sset_toArray_rec(cur->left, array, index);
    sset_toArray_rec(cur->right, array, index);
}

void** sset_toArray(const SortedSetADT* ss) {
    if (ss == NULL || ss->root == NULL || ss->size == 0) {
        return NULL;
    }
    void** array = (void**)malloc(ss->size * sizeof(void*));
    if (array == NULL) {
        return NULL;
    }
    int index = 0;
    sset_toArray_rec(ss->root, array, &index);
    return array;
}
