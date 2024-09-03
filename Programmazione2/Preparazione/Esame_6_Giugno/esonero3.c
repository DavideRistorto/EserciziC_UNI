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

  int len = (strlen(str)*2)+1;
  //nel caso la stringa fosse solo numeri mi serve il doppio dello spazio, quindi dim * 2
  //riservo lo spazio per il carattere '\0', quindi + 1
  char* conversion = malloc(len*sizeof(char));
  int i = 0; //indice str
  int j = 0; // indice conversion
  while(str[i] != '\0'){
    if(isdigit(str[i])){
      //ricopio per 2 volte la cifra
      conversion[j] = str[i];
      j++;
      conversion[j] = str[i];
    }else{
      conversion[j] = str[i];
    }
    i++;
    j++;
  }
  conversion[j] = '\0';
  return conversion;
}

int main(){
  char* string = "1aa99aa1";
  char* conversion = change(string);
  printf("%s   -    %s", string, conversion);

  free(conversion); //dealloco solo la memorio allocata con la maccol
  return 0;
}
