#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool prefixR( char *str,  char *prefix) {
    // se scorrendo tutto il prefisso non si è usciti prima dalla ricorsione
    // quando il prefisso termina vuol dire che è valido
    if(*prefix == '\0'){
        return true;
    }
    //se il carattere tra prefisso e stringa non corrispondo allora non è un prefisso
    if(*str != *prefix){
        return false;
    }
    return prefixR(str+1,prefix+1);
}

// Funzione ricorsiva che stampa la stringa seq filtrando le occorrenze di del_seq
void stampa_filtro_substrR(char *seq,  char *del_seq) {
    if (*seq == '\0'){
        return;
    }
    if(prefixR(seq,del_seq)){
        printf("-");
        stampa_filtro_substrR(seq + strlen(del_seq), del_seq);
    } else{
        printf("%c",*seq);
        stampa_filtro_substrR(seq + 1, del_seq);
    }
}

int main() {
    char seq[101];
    char del_seq[101];
    scanf("%s", seq);
    scanf("%s", del_seq);

    stampa_filtro_substrR(seq, del_seq);

    return 0;
}
