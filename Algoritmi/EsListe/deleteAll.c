// post: ritorna la lista as da cui sono state rimosse 
//       tutte le occorrenze di n
list deleteAll(int n, list as) {
    
    list prev = NULL;
    list current = as;
    
    while (current){
        //caso di cancellazione
        if(current->info == n){
            //se elimino il pirmo nodo della lista, devo aggiornare il riferimento alla testa
            if(prev == NULL){
                as = current->next;
            }
            //se elimino un nodo, il tuo predecessore devo puntare al suo successore
            else{
                prev->next = current->next;
            }
            //deallocazione
            list tmp = current;
            current = current->next;
            free(tmp);
        }//caso in cui non cancello. itero su prev e current
        else{
            prev = current;
            current = current->next;
        }
    }
    return as;
}
