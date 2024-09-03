#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

/**
*@brief date 2 stringhe, controllare se la prima è contenuta nella seconda
*@param char* str1 ->possibile sottostringa
*@param char* str2 ->stringa madre
*@return 1 se str1 e contenuta in str2, altrimenti 0 
*
*/
//versione usando str str
bool subString(char* str1, char* str2){
	//restituisce un puntatore all'inizio della prima ricorrenza di string2 in string1. 
	//Se string2 non viene visualizzato in string1, la funzione strstr() restituisce NULL
	if(strstr(str2, str1) != NULL){
		return 1;
	}
	return 0;
}

bool subString2(char* str1, char* str2){
	if(strlen(str1) > strlen(str2)) return 0;
	//ciclo sull' intera stringa madre
	for(int i=0; str2[i] != '\0'; i++){
		bool corretta = true;
		for(int j=0; str1[j] != '\0' && corretta; j++){
			if(str1[j] != str2[i+j]){
				corretta = false;
			}
		}
		if(corretta) return true;
	}
	return false;
}


int main(){
  char* str1 = "dsdsa";
  char* str2 = "dsdsddds";
  printf("result: %d", subString2(str1, str2));
  return 0;
}