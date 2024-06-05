#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

/**
*@brief data una stringa in input, restituirne una nuova senza cifra e se ci sono 'a' o 'b'
*			 inserire i loro valori maiuscoli
*
*/
char* change(char* str){
	//caso stringa di input non valida
	if(str == NULL){
		return NULL;
	}
	//alloco lo spazio per la nuova stringa
	char* conversion = malloc(100*sizeof(char));
	//memorizzo l'indice della stringa di input
	int i=0;
	//memorizzo l'indice della nuova stringa, perchè può essere diverso da 'i'
	int j=0;
	//scorro tutta la stringa fino alla sua fine
	while(str[i] != '\0'){
		//se è una cifra, non metto nulla nella nuova stringa
		if(!isdigit(str[i])){
			//se e a o b ci metto il loro valore maiuscolo
			if(str[i] == 'a' || str[i] == 'b'){
				conversion[j] = toupper(str[i]);
			}else{
			conversion[j] = str[i];
			}
			j++;
		}
		i++;
	}
	conversion[j] = '\0';
	return conversion;
}

int main(){
	// la stringa iniziale non posso alloracarla con la malloc perchè è una stringa costante
	// e usare la malloc per una stringa costante è un errore e genera uno spreco di memoria
	char* string = "c2iaab3294o";
	char* conversion = change(string);
	printf("%s   -   %s",string, conversion);
	free(conversion);
	return 1;
}