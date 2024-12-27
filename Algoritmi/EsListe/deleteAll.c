// post: ritorna la lista as da cui sono state rimosse 
//       tutte le occorrenze di n
list deleteAll(int n, list as) {
    list prev = NULL;
    list current = as;
    
    while (current){
        //caso di cancellazione
        if(current->info == n){
            if(prev == NULL){
                //aggiorno la testa della cosa
                as = current->next;
            }else{
                //salto l' elemento
                prev->next = current->next;
            }
            list tmp = current;
            current = current->next;
            free(tmp);
        }
        else{
            //aggiorno i riferimenti di prev e current
            prev = current;
            current = current->next;
        }

    }
    return as;
}