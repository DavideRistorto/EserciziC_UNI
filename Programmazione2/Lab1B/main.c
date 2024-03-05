/**
 * @brief Converte una stringa in naturale (data la base).
 *
 * Calcola il numero intero rappresentato dalla stringa in argomento nella base
 * (la base deve essere un numero intero nel range 2..36) in argomento:
 * − saltando gli eventuali spazi bianchi iniziali,
 * − fermandosi al raggiungimento del primo carattere non cifra nella base data (le cifre per la base 36 sono: 0,..,9,A,..,Z).
 *
 * @param s: Una stringa da convertire.
 * @param b: La base.
 * @param r: L'indirizzo dell'intero dove memorizzare il risultato.
 * @return   Restituisce 0 se 'b' non è nell’intervallo ammesso, oppure se non trova nessuna cifra valida
 *           (e in tal caso il valore all'indirizzo r non è significativo).
 *           Altrimenti restituisce 1, e scrive all'indirizzo r il numero intero rappresentato nella stringa nella base data.
 *           Non si accorge dell'eventuale overflow (restituendo in questo caso un risultato tipicamente scorretto).
 */
#include <ctype.h>

int stoub(char *s, unsigned short b, int *r) {
    if(b < 2 || b > 36){
        *r = 0;
        return 0;
    }
    int result = 0;
    for(int i=0; s[i] != '\0'; i++){
        if((isspace(*s))){
            i++;
        }
        if(!isalpha(s[i]) && !isdigit(s[i])){
            return 0;
        }
        int digit;
        if (isdigit(*s))
            digit = *s - '0';
        else
            digit = toupper(*s) - 'A' + 10;

        if (digit >= b)  // Carattere non valido per la base
            return 0;

        result = result * b + digit;
        s++;
    }
    *r = result;
    return 1;
}
