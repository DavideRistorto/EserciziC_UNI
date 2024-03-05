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
#include <stdbool.h>
#include <string.h>
#include <math.h>

int stoub(char *s, unsigned short b, int *r) {
    //se la base non appartiene al range o la stringa da convertire è nulla, uscita dal programma
    if (b < 2 || b > 36 || strlen(s)==0) {
        *r = 0;
        return 0;
    }
    int result = 0;
    int exponent = 0;
    bool negative = false;
    //scorriamo la stringa dalla fine verso l' inizio
    for (int i = strlen(s)-1; i>=0 ; i--) {
        if(s[i] == '-'){
            negative = true;
        }
        //controlliamo che il carattere attuale sia un numero/lettera
        if(isalpha(s[i]) || isdigit(s[i])){
           //fase di coversione nella rispettiva base
           // se il carattere è una cifra prendiamo il suo val codice ASCII e lo sottraiamo col valore ASCII del carattere '0'
           // se il carattere è una lettera, sottraiamo il suo valore a quello della lettera A, aggiunto di 10, perche A=10
            result += (isdigit(s[i]) ? s[i] - '0' : toupper(s[i]) - 'A' + 10) * pow(b, exponent);
            exponent++;
        }
    }
    //short if per controllo del segno
    //Esempio: variable = (condition) ? expressionTrue : expressionFalse;
    result = negative ? -result : result;
    *r = result;
    return 1;
}

/*per testare il programma a mano
int main() {
    int ciao;
    int* result = &ciao;
    int res = stoub("z",16,result);
    printf("%d %d", res, *result);
}
*/