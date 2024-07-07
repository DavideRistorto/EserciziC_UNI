#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/**
* @brief Dati una stringa s1 di lunghezza n1 >= 0 e una stringa s2 di lunghezza n2 >= 0 restituisce il valore
* di verità dell’affermazione: la stringa ottenuta da s1 considerando solo i caratteri in posizione pari
* è uguale a s2. NOTA BENE: Si assuma s1 != NULL e s2 != NULL
*ESEMPI:
*(1) date "pArEeBvUaT" (di lunghezza 10) e “provateci” (di lunghezza 9) restituisce 0.
*(2) date "pArEoBvUaT" (di lunghezza 10) e “prova” (di lunghezza 5) restituisce 1.
*(3) date "pArEoBvUaTeci" (di lunghezza 13) e “prova” (di lunghezza 5) restituisce 0.
 */
 
 
bool check_rec(const char *s1, int n1, const char *s2, int n2, int count){
	if(count>n1){
		return 1;
	}
	if(*s1 != *s2){
		return 0;
	}
	return(s1+2, n1, s2+1, n2, count+2);
}

_Bool check(const char *s1, int n1, const char *s2, int n2) {
	return check_rec(s1,n1,s2,n2,0);
}




int main(){
	char* str1 = "c";
	char* str2 = "ca";
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	
	printf("%d",check(str1,len1,str2,len2));
}