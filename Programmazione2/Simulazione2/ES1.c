/**
* @brief Dato un albero binario restituisce:
* il numero di foglie (se l’albero è vuoto restituisce 0).
* 
* @param tree nodo dell' albero
* @return numero di foglie
*/
//P-IN(tree): tree è un nodo dell' albero
//P-OUT(tree,n): P-OUT-0(tree,n) XOR P-OUT-1(tree,n)
//P-OUT-0(tree,n): tree == NULL
//P-OUT-1(tree,n): tree->left == NULL && tree->right == NUL

int nfoglie(CharTree tree){
    if(tree == NULL){
        return 0;
    }
    if(tree->left == NULL && tree->right == NULL){
        return 1;
    }
    return nfoglie(tree->left) + nfoglie(tree->right);
}