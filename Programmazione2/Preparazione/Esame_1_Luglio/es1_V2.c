#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

/**
* @brief Dati una stringa s1 di lunghezza n1 >= 0 e una 
stringa s2 di lunghezza n2 >= 0 restituisce il valore 
* di verità dell’affermazione: la stringa ottenuta da s1 
considerando solo i caratteri in posizione pari 
* è uguale a s2.
NOTA BENE:
Si assuma s1 != NULL e s2 != NULL
ESEMPI: 
(1) date "pArEeBvUaT" (di lunghezza 10) e “provateci” (di 
lunghezza 9) restituisce 0.
(2) date "pArEoBvUaT" (di lunghezza 10) e “prova” (di 
lunghezza 5) restituisce 1.
(3) date "pArEoBvUaTeci" (di lunghezza 13) e “prova” (di 
lunghezza 5) restituisce 0.
 */
_Bool check_ric(const char *s1, int n1, const char *s2, int n2, int index1, int index2){
	//caso base della ricorsione
	if(index1 > n1 || index2 > n2){
		return 1;
	}
	//nel caso i caratteri non corrispondono esco
	if(s1[index1] != s2[index2]){
		return 0;
	}
	//incremento di 2 l' indice della prima str, mentre solo di 1 quello della seconda
	return check_ric(s1, n1, s2, n2, index1+2, index2+1);
}

_Bool check(const char *s1, int n1, const char *s2, int n2) {
 return check_ric(s1, n1, s2, n2, 0, 0);
}


int main(){
  char* str1 = "pArEoBvUaT"; 	
	char* str2 = "prova";
  printf("result: %d", check(str1, 0, str2, 0));
  return 0;
}