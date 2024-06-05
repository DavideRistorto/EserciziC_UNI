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
	if(str == NULL){
		return NULL;
	}
	//alloco il nuovo array e assegno j che mi terra traccia del carattere attuale
	char* newArray = malloc(n*sizeof(char));
	int j=0;
	for(int i=0; i<n && str[i] != '\0'; i++){
		//aggiungo carattere al nuovo array solo se non si tratta di una cifra
		if(!isdigit(str[i])){
			//maiuscolo K/H
			if(str[i] == 'k' || str[i] == 'h'){
				newArray[j] = toupper(str[i]);
			}else{
				newArray[j] = str[i];
			}
			j++;
		}
	}
	for(int i=j;i<n;i++){
		newArray[i] = '#';
	}
	newArray[n-1] = '\0';
	return newArray;
}

int main(){
	char size = 10;
	char* string = malloc(size*sizeof(char));
	string = "ciao999cc";
	char* conversion = change(string,size);
	printf("%s   -   %s",string, conversion);
	free(string);
	free(conversion);
	return 1;
}
