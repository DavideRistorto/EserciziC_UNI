// post: ogni nodo di l contiene il suo rango
int corank(list l) {
    if(l == NULL || l->next == NULL) return 0;
    
    l->next->info += l->info;
    return (corank(l->next));
}
