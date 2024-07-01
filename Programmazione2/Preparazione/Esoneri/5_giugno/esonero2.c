#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


/**
*	@brief dato un array di dimensione n, restituire una array della stessa dimensione che:
* se trova i caratteri 'k' o 'h' li metta maiuscole
* elimini tutte le cifre
* riempire le rimanenti posizione libere col carattere '#'
*/
char* change(char* str, int n){
	if(str == NULL){
		return NULL;
	}
	char* dest = malloc(n*sizeof(char));
	int i = 0;
	int j = 0;
	while (i<n){
		if(!isdigit(str[i])){
			if(str[i] == 'k' || str[i] == 'h'){
				dest[j] = toupper(str[i]);
			}else{
				dest[j] = str[i];
			}
			j++;
		}
		i++;
	}
	//aggiungere eventuali spazi vuoti con '#'
	while(j<n){
		dest[j] = '#';
		j++;
	}
	dest[j] = '\0';
	return dest;
}

int main(){
	char* string = "c1h1";
	char* conversion = change(string,strlen(string));
	printf("%s   -   %s\n",string, conversion);
	printf("dim string: %d       dim conversion: %d\n", strlen(string), strlen(conversion));
	free(string);
	free(conversion);
	return 1;
}
