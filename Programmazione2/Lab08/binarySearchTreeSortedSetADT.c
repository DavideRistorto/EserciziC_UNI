#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "sortedSetADT.h"

typedef struct treeNode TreeNode, *TreeNodePtr;

struct treeNode {
    void* elem;
    TreeNodePtr left, right;
};

struct sortedSetADT {
    TreeNodePtr root; /* Punta alla radice dell'albero, se l'insieme e' vuoto vale NULL */
    int (*compare)(void*, void*); /* confronto tra due elementi: -1,0,1 se primo precede, uguale o segue il secondo */
    int size; /* Numero di elementi presenti nell'insieme */
};

// for debug: stampa un insieme
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

// distrugge l'insieme, recuperando la memoria
_Bool dsSSet(SortedSetADTptr* ssptr) {
  if (ssptr == NULL){
    return false;
  }
  //TODO: implementare la distruzione dell'albero
  free(*ssptr);
  *ssptr = NULL;
  return true;
}

// aggiunge un elemento all'insieme 
_Bool sset_add(SortedSetADTptr ss, void* elem) { 
  if (ss == NULL){
    return 0;
  }
  //caso in cui l' elemento è la radice
  if(ss->root == NULL){
    TreeNodePtr root = (TreeNodePtr)malloc(sizeof(struct  treeNode));
    root->elem = elem;
    root->left = NULL;
    root->right = NULL;
    ss->root = root;
    ss->size++;
    return 1;
  }
  if(sset_member(ss, elem)){
    return 0;
  }
  //inserimento nell' albero
  TreeNodePtr cur = ss->root;
  while(cur != NULL){
    //se l' elmento è maggiore dell' nodo attuale allora vado a destra
    if(ss->compare(elem, cur->elem) == 1){
      //se il nodo destro non esiste allora lo creo con l' elemento da inserire
      if(cur->right == NULL){
        TreeNodePtr new = (TreeNodePtr)malloc(sizeof(struct  treeNode));
        new->elem = elem;
        new->left = NULL;
        new->right = NULL;
        cur->right = new;
        ss->size++;
        return 1;
      // passo al nodo successivo e ripeto
      } else{
        cur = cur->right;
      }
    //caso in cui devo andare a sinistra perchè l' elemento è minore della radice
    } else {
      if(cur->left == NULL){
        TreeNodePtr new = (TreeNodePtr)malloc(sizeof(struct  treeNode));
        new->elem = elem;
        new->left = NULL;
        new->right = NULL;
        cur->left = new;
        ss->size++;
        return 1;
      } else {
          cur = cur->left;
      }
    }
  }
}  

void sset_extractMin_rec(TreeNodePtr* cur, void**ptr, int (*compare)(void*, void*)){
  if( *cur == NULL){
    return;
  }
  // se il nodo ha un figlio sinistro, allora continuo la ricorsione
  if((*cur)->left != NULL){
    sset_extractMin_rec(&((*cur)->left), ptr, compare);
  }//se non ha un figlio sinistro allora procedo con la rimozione 
  else {
    *ptr = (*cur)->elem;
    // Remove the current node from the tree
    TreeNodePtr oldNode = *cur;
    *cur = (*cur)->right;
    free(oldNode);
  }
}

void sset_extractMax_rec(TreeNodePtr* cur, void**ptr, int (*compare)(void*, void*)){
  if( *cur == NULL){
    return;
  }
  // se il nodo ha un figlio sinistro, allora continuo la ricorsione
  if((*cur)->right != NULL){
    sset_extractMax_rec(&((*cur)->right), ptr, compare);
  }//se non ha un figlio sinistro allora procedo con la rimozione 
  else {
    *ptr = (*cur)->elem;
    // Remove the current node from the tree
    TreeNodePtr oldNode = *cur;
    *cur = (*cur)->left;
    free(oldNode);
  }
}

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
  //caso albero non esistente
  if(ss == NULL){
    return -1;
  }
  //caso albero vuoto
  if(ss->root == NULL){
    return 0;
  }
  TreeNodePtr cur = ss->root;
  while (cur != NULL){
    int compareResult = ss->compare(elem, cur->elem);
    //caso elemento trovato
    if(compareResult == 0){
      return 1;
    }
    //caso elemento minore di quello attuale
    if(compareResult == -1){
      //in caso dopo non ci fosse un elemento, allora quello ricercato non appartiene all' insieme
      if(cur->left == NULL){
        return 0;
      }
      cur = cur->left;
    }
    //caso elemento maggiore di quello attuale
    else {
      //in caso dopo non ci fosse un elemento, allora quello ricercato non appartiene all' insieme
      if(cur->right == NULL){
        return 0;
      }
      cur = cur->right;
    }
  }
}
    
// controlla se l'insieme e' vuoto    
int isEmptySSet(const SortedSetADT* ss) {
  //insieme invalido
  if(ss == NULL){
    return -1;
  }
  //insieme vuoto -> true
  if(ss->size == 0){
    return 1;
  }
  //insieme non vuoto -> false
  return 0;
} 

// restituisce il numero di elementi presenti nell'insieme
int sset_size(const SortedSetADT* ss) {
  //insieme invalido
  if(ss == NULL){
    return -1;
  }
  return ss->size;
} 

_Bool sset_extract(SortedSetADTptr ss, void**ptr) { // toglie e restituisce un elemento a caso dall'insieme
  return sset_extractMax(ss, ptr);
} 

// controlla se due insiemi sono uguali
int sset_equals(const SortedSetADT* s1, const SortedSetADT* s2) { 
  if (s1 == NULL || s2 == NULL){
    return -1;
  }
  // se hanno due dimensioni diverse, allora non sono uguali
  if (s1->size != s2->size) {
    return 0;
  }
  // controllo se ogni elemento di s1 è presente in s2
  TreeNodePtr cur = s1->root;
  TreeNodePtr stack[s1->size];
  int top = -1;
  // in ordine simmetrico
  while (cur != NULL || top != -1) {
    while (cur != NULL) {
      stack[++top] = cur;
      cur = cur->left;
    }
    cur = stack[top--];
    // se l'elemento corrente non è presente in s2, allora i due insiemi non sono uguali
    if (!sset_member(s2, cur->elem)) {
      return 0;
    }
    cur = cur->right;
  }
  // se tutti gli elementi di s1 sono presenti in s2, allora i due insiemi sono uguali
  return 1;
}

// controlla se il primo insieme e' incluso nel secondo
int sset_subseteq(const SortedSetADT* s1, const SortedSetADT* s2) {
  if (s1 == NULL || s2 == NULL){
    return -1;
  }
  if(sset_equals(s1, s2)){
    return 1;
  }
  // controllo se ogni elemento di s1 è presente in s2
  TreeNodePtr cur = s1->root;
  TreeNodePtr stack[s1->size];
  int top = -1;
  // in ordine simmetrico
  while (cur != NULL || top != -1) {
    while (cur != NULL) {
      stack[++top] = cur;
      cur = cur->left;
    }
    cur = stack[top--];
    // se l'elemento corrente non è presente in s2, allora i due insiemi non sono uguali
    if (!sset_member(s2, cur->elem)) {
      return 0;
    }
    cur = cur->right;
  }
}

// controlla se il primo insieme e' incluso strettamente nel secondo
int sset_subset(const SortedSetADT* s1, const SortedSetADT* s2) {
  if(sset_subseteq(s1, s2) && !sset_equals(s1, s2)){
    return 1;
  }
  return 0;
} 

// restituisce la sottrazione primo insieme meno il secondo, NULL se errore
SortedSetADTptr sset_subtraction(const SortedSetADT* s1, const SortedSetADT* s2) {
  if (s1 == NULL || s2 == NULL){
    return NULL;
  }   
  // se il seconodo insieme è vuoto, la sottrazione è uguale a s1
  if(s2->size == 0){
    return s1;
  }
  SortedSetADTptr subtractionSet = mkSSet(s1->compare);
  // controllo se ogni elemento di s1 è presente in s2
  TreeNodePtr cur = s1->root;
  TreeNodePtr stack[s1->size];
  int top = -1;
  // in ordine simmetrico
  while (cur != NULL || top != -1) {
    while (cur != NULL) {
      stack[++top] = cur;
      cur = cur->left;
    }
    cur = stack[top--];
    // se l'elemento corrente non è presente in s2, allora i due insiemi non sono uguali
    if (!sset_member(s2, cur->elem)) {
      sset_add(subtractionSet, cur->elem);
    }
    cur = cur->right;
  }
  return subtractionSet;
} 

// restituisce l'unione di due insiemi, NULL se errore
SortedSetADTptr sset_union(const SortedSetADT* s1, const SortedSetADT* s2) {
  if (s1 == NULL || s2 == NULL){
    return NULL;
  }   
  SortedSetADTptr unionSet = mkSSet(s1->compare);
  TreeNodePtr cur = s1->root;
  TreeNodePtr stack[s1->size];
  int top = -1;
  // in ordine simmetrico
  while (cur != NULL || top != -1) {
    while (cur != NULL) {
      stack[++top] = cur;
      cur = cur->left;
    }
    cur = stack[top--];
    // aggiungo ogni elemento di s1 in unionSet
    sset_add(unionSet, cur->elem);
    cur = cur->right;
  }
  cur = s2->root;
  TreeNodePtr stack2[s2->size];
  top = -1;
    while (cur != NULL || top != -1) {
    while (cur != NULL) {
      stack[++top] = cur;
      cur = cur->left;
    }
    cur = stack[top--];
    // aggiungo ogni elemento di s2 in unionSet
    sset_add(unionSet, cur->elem);
    cur = cur->right;
  }
  return unionSet;
} 

// restituisce l'intersezione di due insiemi, NULL se errore
SortedSetADTptr sset_intersection(const SortedSetADT* s1, const SortedSetADT* s2) {
  if (s1 == NULL || s2 == NULL){
    return NULL;
  }   
  SortedSetADTptr intersectionSet = mkSSet(s1->compare);
  // se il seconodo insieme è vuoto, l' intersezione è nulla
  if(s1->size == 0 ||s2->size == 0){
    return intersectionSet;
  }
  // controllo se ogni elemento di s1 è presente in s2
  TreeNodePtr cur = s1->root;
  TreeNodePtr stack[s1->size];
  int top = -1;
  // in ordine simmetrico
  while (cur != NULL || top != -1) {
    while (cur != NULL) {
      stack[++top] = cur;
      cur = cur->left;
    }
    cur = stack[top--];
    // se l'elemento corrente non è presente in s2, allora i due insiemi non sono uguali
    if (sset_member(s2, cur->elem)) {
      sset_add(intersectionSet, cur->elem);
    }
    cur = cur->right;
  }
  return intersectionSet;
}

// restituisce il primo elemento 
_Bool sset_min(const SortedSetADT* ss, void**ptr) {
  if(ss == NULL){
    return 0;
  }
  //per trovare l' elemento minore devo andare nel ramo più a sinistra di tutti
  TreeNodePtr cur = ss->root;
  while(cur!=NULL){
    //se il nodo attuale, non ha uno sinistro, allora sono nel più piccolo
    if(cur->left == NULL){
      *ptr = cur->elem;
      return 1;
    }
    //vado ulteriormente a sinistra
    cur = cur->left;
  }
  return 0;
}

// restituisce l'ultimo elemento 
_Bool sset_max(const SortedSetADT* ss, void**ptr) {
  if(ss == NULL){
    return 0;
  }
  //per trovare l' elemento maggiore devo andare nel ramo più a destra di tutti
  TreeNodePtr cur = ss->root;
  while(cur!=NULL){
    //se il nodo attuale, non ha uno destro, allora sono nel più maggiore
    if(cur->right == NULL){
      *ptr = cur->elem;
      return 1;
    }
    //vado ulteriormente a destra
    cur = cur->right;
  }
  return 0;
}

// toglie e restituisce il primo elemento ovvero quello più a sinistra 
_Bool sset_extractMin(SortedSetADTptr ss, void**ptr) {
  if(ss == NULL || ss->size==0){
    return 0;
  }
  //per togliere l' elemento minore devo andare nel ramo più a sinistra di tutti
  TreeNodePtr cur = ss->root;
  TreeNodePtr prev = NULL;
  while(cur!=NULL){
    //se il nodo attuale, non ha uno sinistro, allora sono nel più piccolo
    if(cur->left == NULL){
      *ptr = cur->elem;
      //caso in cui il nodo da eliminare è la radice
      if(prev == NULL){
        // il nodo a destra della radice diventa la nuova radice
        ss->root = cur->right;
      } else {
        prev->left = cur->right;
      }
      free(cur);
      ss->size--;
      return 1;
    }
    //vado ulteriormente a sinistra
    prev = cur;
    cur = cur->left;
  }
}

// toglie e restituisce l'ultimo elemento (0 se lista vuota, -1 se errore, 1 se restituisce elemento)
_Bool sset_extractMax(SortedSetADTptr ss, void**ptr) {
  if(ss == NULL || ss->size==0){
    return 0;
  }       
  //per togliere l' elemento maggiore devo andare nel ramo più a destra di tutti
  TreeNodePtr cur = ss->root;
  TreeNodePtr prev = NULL;
  while(cur != NULL){
    if(cur->right == NULL){
      *ptr = cur->elem;
      //caso in cui siamo nella radice
      if(prev == NULL){
        //il ramo a sinistra della radice, diventa la nuova radice
        ss->root = cur->left;
      } else {
        prev->right = cur->left;
      }
      free(cur);
      ss->size--;
      return 1;
    }
    prev = cur;
    cur = cur->right;
  }
}