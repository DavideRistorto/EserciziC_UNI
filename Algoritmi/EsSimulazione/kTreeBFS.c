// post: ritorna la lista delle etichette (chiavi) di t visitato in ampiezza
list kTreeBFS(kTree t) {

    //caso albero vuoto
    if(t == NULL) return 0;
    //inizializzo coda e lista
    list result = NULL;
    queue q = NewQueue();
    //metto la radice in coda
    EnQueue(t, q);
    
    //itero sulla cosa
    while(!isEmptyQueue(q)){
        //prendo il nodo attuale, rimuovendolo dalla coda
        kTree current = DeQueue(q);
        //lo aggiungo alla lista
        result = Add(current->key, result);
        
        //passo al figlio
        current = current->child;
        while(current){
            EnQueue(current, q);
            current = current->sibling;
        }
    }
    return result;
}