//funzione che raccoglio il valore della somma
// e nodo dopo nodo genera i coranghi
list corank_rec(list l, int sum){
    if (l == NULL){
        return 0;
    }
    sum += l->info;
    l->info = sum;
    return corank_rec(l->next, sum);
}


// post: ogni nodo di l contiene il suo rango
list corank(list l) {
    return corank_rec(l, 0);
}