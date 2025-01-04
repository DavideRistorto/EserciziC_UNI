// pre:  l è una lista di interi, eventualmente vuota
// post: l è stata trasformata nella lista dei ranghi dei suoi
//       elementi; il valore ritornato è il rango del primo elemento
//       rispetto alla lista originaria (ovvero il valore del primo elemento
//       della lista così come trasformata da rank()), se questa non è vuota,
//       0 altrimenti
int rank(list l) {
    if (l == NULL) return 0;
    int sum = 0;
    list current = l;
    //calcolo la somma totale del rango
    while(current){
        sum += current->info;
        current = current->next;
    }
    current = l;
    int tmp = 0;
    while(current){
        //salvo il valore originale del nodo
        tmp = current->info;
        //metto nel nodo il valore del rango
        current->info = sum;
        //aggiorno il valore del rango
        sum -= tmp;
        //itero sulla lista
        current = current->next;
    }
    return l->info;
}