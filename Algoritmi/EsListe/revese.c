list reverse_aux(list l, list acc) {
    if (l == NULL)
        return acc;
    return reverse_aux(l->next, Cons(l->info, acc));
}

// post: inverte non distruttivamente l in tempo 
//       lineare, ritornando la lista invertita
list fast_reverse(list l) {
    return reverse_aux(l, NULL);
}