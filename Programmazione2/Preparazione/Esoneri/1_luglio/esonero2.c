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
	if(s == NULL) return NULL;
	
	int dim = 0;
	if(n<m){
		// se n<m dimensione della stringa pari a n poichè tiene già conto del carattere '\0'
		dim = n;
	}else{
		//altrimenti m caratteri piu lo spazio per '\0'
		dim = m+1;
	}
	char* str = (char*)malloc((dim+1)*sizeof(char));
	int k = 0;
	while(k<dim-1){
		str[k] = s[n-1-k];
		k++;
	}
	str[k] = '\0';
	return str;
}

int main() {
	char *str = "eccocosafare";
	int len  = 12;
	int val  = 5;
	char *str2 = tailextract(str,len,val);
	printf ("%s - %s",str,str2);
	free(str2);
	return 0;
}
