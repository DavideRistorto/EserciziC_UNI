// post: ritorna la somma delle etichette delle foglie di t
int sumLeaf (kTree t) {
    //caso base: albero nullo
    if(t == NULL) return 0;
    //caso base: foglia
    if(t->child == NULL) return t->key;
    
    int sum = 0;
    //caso ricorsivo
    kTree current = t->child;
    while(current){
        //calcolo la somma per tale nodo
        sum += sumLeaf(current);
        //passo a suo fratello
        current = current->sibling;
    }
    return sum;
}