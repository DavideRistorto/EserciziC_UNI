/**@brief Trasforma un albero, agendo su ogni nodo con entrambi i rami,
*   scambiandoli se le loro radici non sono nell'ordine corretto (ovvero lo
*   scambio avviene quando sinistra > destra).
*   usare una soluzione RICORSIVA
*/

/*
        2
      /  \
    5     1
    /  \ 
  9     4
      /   \
      3    11
      \
        7

è:

        2
       /  \
      1   5
        /  \
      4     9
   /   \
 3    11
   \
    7
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct treeNode IntTreeNode, *IntTree; 
struct treeNode {  
   IntTree left;
   int data;
   IntTree right;
};

void sort(IntTree tree){
  //caso base ricorsivo con uscita dalla ricorsione
  if(tree == NULL){
    return;
  }
  //come da consegna, agisco su un nodo solo se ha entrambi i figli, ovvero non NULL
  if(tree->left && tree->right){
    //agisco sul nodo se left > right
    if(tree->left->data > tree->right->data){
      //inverto i figli
      IntTree tempNode = tree->left;
      tree->left = tree->right;
      tree->right = tempNode;
    }
  }
  //chiamo la ricorsione per i figli
  sort(tree->left);
  sort(tree->right);
}