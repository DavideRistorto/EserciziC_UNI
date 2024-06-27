#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
*	@brief dato un array di dimensione n, restituire una array della stessa dimensione che:
* se trova i caratteri 'k' o 'h' li metta maiuscole
* elimini tutte le cifre
* riempire le rimanenti posizione libere col carattere '#'
*/
char* change(char* str, int n){
}

int main(){
	char size = 10;
	char* string = "ciao999cc";
	char* conversion = change(string,size);
	printf("%s   -   %s",string, conversion);
	free(string);
	free(conversion);
	return 1;
}
