#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Date una stringa s, la sua lunghezza n >= 0, e un numero m tale che m >= 0,
 * restituisce la stringa che, nella posizione 0, contiene s[n-1]; nella posizione 1,
 * contiene  s[n-2]; eccetera, terminando con i caratteri trovati nelle posizioni
 * s[n-min(n,m)+1], s[n-min(n,m)] (se m == 0, restituisce la stringa vuota).
 * Si noti che nella stringa risultato i caratteri sono riportati in ordine inverso
 * rispetto alla stringa originaria.
 *
 * ESEMPI: 
 * (1) dati "eccocosafare", 12, 5 restituisce "erafa".
 * (2) dati "eccocosafare", 12,0 restituisce "".
 */
 
char *tailextract(char *s, int n, int m)  {
	//se m è maggiore di n lo riduciamo a n perchè non 
	//possiamo prendere m caratteri se c'è ne sono solo n
	if(m > n){
		m = n;
	}
	//lo spazio sono m caratteri +1 per lo spazio di '\0'
	char* result = (char*)malloc((m+1)*sizeof(char));
	int k = 0; //indice stringa result
	while(k<m){
		result[k] = s[n-1-k];
		k++;
	}
	result[k] = '\0';
	return result;
}
	
int main() {
	char *str = "eccocosafare";
	int len  = 12;
	int val  = 5;
	char *result = tailextract(str,len,val);
	printf ("result - '%s'", result);
	free(result);
	return 0;	
} 
