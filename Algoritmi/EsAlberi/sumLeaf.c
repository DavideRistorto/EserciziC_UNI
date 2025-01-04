// post: ritorna la somma delle etichette delle foglie di t
int sumLeaf (kTree t) {
    if(t == NULL) return 0;
    //se è una foglia, ritorno il suo valore
    if(t->child == NULL) return t->key;
    
    kTree figlio = t->child;
    int sum = 0;
    while(figlio){
        sum += sumLeaf(figlio);
        figlio = figlio->sibling;
    }
    return sum;
}