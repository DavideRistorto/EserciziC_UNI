list insert(list as, list bs, int n) {  
    list current = bs;
    // Attraversa i primi (n-1) elementi di bs
    for (int i = 1; i < n; i++) {
        current = current->next;
    }
    // Ora current punta al nodo dopo il quale inserire as
    if (current != NULL) {
        current->next = concat(as, current->next);
    }
    // Ritorna la testa originale della lista bs
    return bs;
} 