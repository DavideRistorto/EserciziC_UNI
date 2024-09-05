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
char *extract(char *s, int i, int j){
	if(i>j){
		return ""; //ritorno la stringa vuota
	}
	//differenza degli indice j e i + 2 per avere lo spazioe per il carattere \0
	int len = j-i+2; 
	char* newStr = malloc(len*sizeof(char));
	int k = 0; //riferimento stringa newStr
	while(j>=i){
		newStr[k] = s[j];
		k++;
		j--;
	}
	newStr[k] = '\0';
	return newStr;
}

int main(){
	
	char* s = "eccocosafare";
	char* conversion = extract(s, 4, 7);
	
	printf("result:  '%s'\n", conversion);
	printf("result lenght:  %d\n", strlen(conversion));
	free(conversion);
} 
