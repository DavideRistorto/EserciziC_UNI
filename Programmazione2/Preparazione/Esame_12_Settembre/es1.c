/** @brief Verifica se una porzione di stringa è palindroma. Usare una soluzione RICORSIVA
*    Palindromo significa che o la stringe e' vuota oppure la meta' sinistra e' lo specchio della meta' destra.
*    Esempi: kayak, anna sono palindrome. Invece Kayak non è palindroma perche' le 'k' sono una maiuscola e l'altra minuscola.
*
*    P-IN(s,first,last): s è una stringa, first e last sono indici di caratteri in s
*    P-OUT(s,first,last,result): result è il valore di verità di “la sequenza di caratteri contenuti in s[first…last] è palindroma” 
*/

#include <stdlib.h>
#include <stdio.h>

_Bool isPalindrome(const char *s, int first, int last){
    //caso di puntatore non valido
    if(s == NULL) return 0;
    //caso base della ricorsione con ritorno 1
    if(first>last){
        return 1;
    }
    //se le lettere non sono uguali, la stringa non palindroma
    //ritorno 0
    if(s[first] != s[last]){
        return 0;
    }
    //proseguo con la ricorsione aggiornando gli indici
    return isPalindrome(s, first+1, last-1);
}