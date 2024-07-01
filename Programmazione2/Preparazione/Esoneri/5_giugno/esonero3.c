#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/**
*@brief data una stringa in input, restituirne una nuova avendo sdoppiate tutte le cifre
* es: aa1b -> aa11b
*
*/
char* change(char* str){
	if(str == NULL) return NULL;
	
	int len = strlen(str)*2+1;
	char* conv = malloc(len*sizeof(char));
	//indice prima stringa
	int i=0;
	//indice seconda striga
	int j=0;
	while(str[i] != '\0'){
		//caso in cui è un numero
		if(isdigit(str[i])){
			//sdoppio il carattere
			conv[j] = str[i];
			j++;
			conv[j] = str[i];
		}else{ //caso di non cifra, copio il carattere una volta
			conv[j] = str[i];
		}
		//incremento entrambi gli indici
		i++;
		j++;
	}
	conv[j] = '\0';
	return conv;
}




int main(){
	// la stringa iniziale non posso alloracarla con la malloc perchè è una stringa costante
	// e usare la malloc per una stringa costante è un errore e genera uno spreco di memoria
	char* string = "1a2bb3";
	char* conversion = change(string);
	printf("%s   -   %s",string, conversion);
	free(conversion);
	return 1;
}