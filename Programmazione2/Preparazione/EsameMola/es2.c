#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode IntTreeNode, *IntTree;
struct treeNode {  
	IntTree left;
	int data;
	IntTree right;
};

void mirror(IntTree tree){
  //controllo validità albero
  if(tree == NULL){
    return;
  }
  //caso base: se sia il ramo destro che sinistro sono nulli, non ho nulla da scambiare
	if(tree->left == NULL && tree->right == NULL){
		return;
	}
  //scambio i due rami
	IntTree temp = tree->left;
	tree->left = tree->right;
	tree->right = temp;
	mirror(tree->left);
	mirror(tree->right);
}