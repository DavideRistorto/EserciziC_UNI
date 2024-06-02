#include <tree_rec.h>
#include <stddef.h>


/**
 * @brief Controlla se il secondo albero è  una potatura del primo
 * 
 * 
*/
int put(IntTree *treePtr, char *path, int e){
  //sono arrivato alla fine dell' albero e inserisco qua il valore
  if(*treePtr == NULL){
    *treePtr = malloc(sizeof(IntTreeNode));
    if(*treePtr == NULL){
      return OUT_OF_MEMORY;
    }
    (*treePtr)->data = e;
    (*treePtr)->left = NULL;
    (*treePtr)->right = NULL;
    return ADDED;
  }//fine della stringa e il nodo esiste già quindi sovrascrivo il valore
  else if(*path == '\0'){
    (*treePtr)->data = e;
    return OVERWRITTEN;
  }
  //se il carattere è L vado a sinistra
  if(*path == 'L'){
    return put(&(*treePtr)->left, path + 1, e);
  }
  //se il carattere è R vado a destra
  else if(*path == 'R'){
    return put(&(*treePtr)->right, path + 1, e);
  }
  return ERROR;
}

/**
* @brief Dato un ARB con restituisce un array che contiene tutti gli elementi dell'ARB in un ordine tale che, 
* se gli elementi sono tutti distinti, allora
* inserendoli in quell'ordine nell'ARB vuoto si ricostruisce l'ARB originale.
*/
int* arbToArray(IntTree tree){
  if(tree == NULL){
    return NULL;
  }
  int *array = malloc(sizeof(int) * 100);
  if(array == NULL){
    return NULL;
  }
  int i = 0;
  array[i] = tree->data;
  i++;
  int *left = arbToArray(tree->left);
  if(left != NULL){
    for(int j = 0; left[j] != '\0'; j++){
      array[i] = left[j];
      i++;
    }
  }
  int *right = arbToArray(tree->right);
  if(right != NULL){
    for(int j = 0; right[j] != '\0'; j++){
      array[i] = right[j];
      i++;
    }
  }
  array[i] = '\0';
  return array;
}


