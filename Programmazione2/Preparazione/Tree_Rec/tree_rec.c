#include <tree_rec.h>
#include <stddef.h>

Response put(IntTree *treePtr, char *path, int e){
  if(*treePtr == NULL){
    *treePtr = (IntTree)malloc(sizeof(IntTreeNode));
  }
}



