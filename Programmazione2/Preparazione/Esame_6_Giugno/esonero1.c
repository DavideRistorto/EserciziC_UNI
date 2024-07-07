#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
/**
*@brief data una stringa in input, restituirne una nuova senza cifra e se ci sono 'a' o 'b'
*			 inserire i loro valori maiuscoli
*
*/
char* change(char* str){
	if(str == NULL){
		return NULL;
	}
	//alloco dinamicamente la memoria 
	int len = strlen(str)+1;
	char* change = malloc(len*sizeof(char));
	// i indice di str, j indice change
	int i = 0;
	int j = 0;
	while(str[i] != '\0'){
		//aggiungo carattere alla stringa solo se non sono cifra
		if(!isdigit(str[i])){
			//caso 'a' o 'b'
			if(str[i] == 'a' || str[i] == 'b'){
				change[j] = toupper(str[i]);
			}else{
				change[j] = str[i];
			}
			j++;
		}
		i++;
	}
	//termino la stringa
	change[j] = '\0';
	return change;
}
	

int main(){
	// la stringa iniziale non posso alloracarla con la malloc perchè è una stringa costante
	// e usare la malloc per una stringa costante è un errore e genera uno spreco di memoria
	char* string = "c";
	char* conversion = change(string);
	printf("%s   -   %s",string, conversion);
	free(conversion);
	return 1;
}