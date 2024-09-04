#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

/**
*@brief date 2 stringhe intersecarle:
* str1: zzzzb
* str2: aaaa
* return: zazazazab
*
*/
char* incastro(char* str1, char* str2){
	int len = strlen(str1) + strlen(str2) + 1;
	char* new = malloc(len*sizeof(char));
	
	int i = 0; //indice str1/str2
	int j = 0; //indice stringa new
	bool fineStr1 = false;
	bool fineStr2 = false;
	
	while(!fineStr1 || !fineStr2){
		bool doppiaOperazione = false; // serve per fare un doppio incremento all' idice j della stringa new
		if(str1[i] == '\0') fineStr1 = true; //controllo per la singola stringa se ha ancora caratteri
		if(str2[i] == '\0') fineStr2 = true; 

		if(!fineStr1){
			//aggiungo il carattere dalla str1
			new[j] = str1[i];
			doppiaOperazione = true;
		}
		if(!fineStr2){
			if(doppiaOperazione){
				j++;
			}
			//aggiungo il carattere dalla str2
			new[j] = str2[i];
		}
		i++;
		j++;
	}
	//riporto indietro il j perchè all' ultima esecuzione è incrementato anche se non è stata inserita nessuan lettera
	new[j-1] = '\0';
	return new;
}


int main(){
  char* str1 = "zzzz"; 	
	char* str2 = "aaaabb";
  printf("result: %s", incastro(str1, str2));
  return 0;
}