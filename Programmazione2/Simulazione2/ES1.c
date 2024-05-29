/**
* @brief Dato un albero binario restituisce:
* il numero di foglie (se l’albero è vuoto restituisce 0).
*/
int nfoglie(CharTree tree){
    //albero vuoto
    if(tree == NULL){
        return 0;
    }
    //tree è una foglia
    if(tree->right == NULL && tree->left == NULL){
        return 1;
    }
    //ricorsione
    return nfoglie(tree->right) + nfoglie(tree->left);
}



