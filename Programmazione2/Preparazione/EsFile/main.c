#include <stdio.h>
#include <stdlib.h>

/**
 * @brief dati due file, legge il primo se trova delle cifre, le scrive sotto forma di parole nel secondo file
 * @param f1 file da dove leggere le cifre
 * @param f2 file dove si andranno a inserire le parole
 * 
*/
void compare(FILE *f1, FILE *f2) {
  if(f1 == NULL || f2 == NULL) {
    printf("Error: File not found\n");
    if(f1) fclose(f1);
    if(f2) fclose(f2);
    return;
  }
  char* strings[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
  char valRead;
  while(!feof(f1)){
    valRead = fgetc(f1);
    if(valRead >= '0' && valRead <= '9'){
      printf("value found: %c\n",valRead);
      fprintf(f2,"%s\n",strings[valRead-'0']);
    }
  }
  fclose(f1);
  fclose(f2);
  return;
}

int main(){
  printf("Converting number to text...\n");
  FILE* f1 = fopen("f1.txt","r");
  FILE* f2 = fopen("f2.txt","w");  
  compare(f1, f2);

  return 0;
}