#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


//funzione di appoggio
char* change_rec(char* str, char* dest, int i, int j){
	if(str == NULL){
		return NULL;
	}
	//caso base
	if(str[i] == '\0'){
		dest[j] = '\0';
		return dest;
	}
	if(!isdigit(str[i])){
		if(str[i] == 'a' || str[i] == 'b'){
			dest[j] = toupper(str[i]);
		}else{
			dest[j] = str[i];
		}
		//nel caso aggiungo un carattere a dest, incremento entrambi gli indici
		i++;
		j++;
		return change_rec(str, dest, i, j);
	}
	//nel caso sia una cifra, la stringa dest non vede essere incrementata
	i++;
	return change_rec(str, dest, i, j);
}
/**
*@brief data una stringa in input, restituirne una nuova senza cifra e se ci sono 'a' o 'b'
*			 inserire i loro valori maiuscoli
*
*/
char* change(char* str){
	int len = strlen(str)+1;
	char* dest = malloc(len*sizeof(char));
	return change_rec(str, dest, 0, 0);
}
	

int main(){
	// la stringa iniziale non posso alloracarla con la malloc perchè è una stringa costante
	// e usare la malloc per una stringa costante è un errore e genera uno spreco di memoria
	char* string = "a2aacb";
	char* conversion = change(string);
	printf("%s   -   %s",string, conversion);
	free(conversion);
	return 1;
}