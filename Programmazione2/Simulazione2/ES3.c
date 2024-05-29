IntList reverseRecursiveHelper(IntList curr, IntList prev) {
    //sono in fondo
    if(curr == NULL){
        return prev;
    }
    //salvo il prossimo nodo
    IntList next = curr->next;
    //inverto il collegamento da curr e prev
    curr->next = prev;
    //aggiorno per la ricorsione
    prev = curr;
    return reverseRecursiveHelper(next, curr);
}

/**
 * @brief Riorganizza i nodi di *lsPtr invertendone l'ordine.
 * Ad esempio, data [1, 2, 3] la trasforma in [3, 2, 1]. Non alloca nuova memoria sullo heap.
 * @param lsPtr Puntatore al puntatore alla lista da invertire.
 */
void reverse(IntList* lsPtr) {
    if (lsPtr == NULL || *lsPtr == NULL) {
        return;  // Controlla se lsPtr è NULL o se la lista è vuota
    }
    *lsPtr = reverseRecursiveHelper(*lsPtr, NULL);
}