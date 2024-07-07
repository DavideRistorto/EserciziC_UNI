#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*  INSERIRE QUI EVENTUALI FUNZIONI AUSILIARIE (CON UN COMMENTO SIGNIFICATIVO IN TESTA) */

/**
 * @brief Date una stringa s e due indici i, j validi per s (cioè tali da fare riferimento
 * a caratteri della stringa), restituisce una nuova stringa che nella posizione 0 contiene s[j],
 * nella posizione 1 contiene  s[j-1], eccetera terminando con i caratteri trovati nelle
 * posizioni s[i+1], s[i] (se i > j, restituisce la stringa vuota). Si noti che nella stringa
 * risultato i caratteri sono riportati in ordine inverso rispetto alla stringa originaria.
 *
 * ESEMPI: 
 * (1) dati "eccocosafare", 4, 7 restituisce “asoc”.
 * (2) dati "eccocosafare”, 8,3 restituisce “”.
 */
char *extract(char *s, int i, int j)  {
	if(s == NULL) return NULL;
	
	//caso stringa vuota
	if(i>j){
		char* str = "\0";
		return str;
	}
	//+2 perchè 7-4 fa 3, ma devo prenere 4 caratteri più lo spazio per '\0'
	int dim = j-i+2;
	char *str = (char*)malloc(dim*sizeof(char));
	int k = 0;
	while(j>=i){
		str[k] = s[j];
		k++;
		j--;
	}
	str[k] = '\0';
	return str;

}

/**
 * @brief Inizializza una stringa str e due indici first, last validi per str,
 * e scrive sullo schermo la stringa restituita da extract(str,first,last).
 */
int main() {

    char* str = "eccocosafare";
    int first  = 4;
    int last  = 7;

    char* newStr = extract(str, first, last);
    
    printf("Test\n");
    printf("extract(%s, %d, %d)\n", str, first, last);
    printf("result: %s\n", newStr);
}