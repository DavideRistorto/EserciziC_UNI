list reverse_aux(list l, list acc) {
    if (l == NULL)
        return acc;
    //aggiungo il nodo in testa lista [1,2,3] -> [1] -> [2,3] -> [3,2,1]
    acc = Cons(l->info, acc);
    //itero sul nodo successivo
    return reverse_aux(l->next, acc);
}

// post: inverte non distruttivamente l in tempo 
//       lineare, ritornando la lista invertita
list fast_reverse(list l) {
    return reverse_aux(l, NULL);
}
