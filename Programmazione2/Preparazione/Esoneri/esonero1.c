#include <stdlib.h>
#include <stdio.h>

/**
*@brief data una stringa in input, restituirne una nuova senza cifra e se ci sono 'a' o 'b'
*			 inserire i loro valori maiuscoli
*
*/
char* change(char* str){
	
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