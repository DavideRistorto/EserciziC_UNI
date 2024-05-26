//avvio: cls && gcc -o compare main.c && ./compare

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief la funzione controlla se due file sono uguali o no
 * 
 * @param fname1 puntatore ad un primo file
 * @param fname2 puntatore ad un secondo file
 * @param line puntatore a long che serve per salvare in quale linea c'è una differenza tra i file
 * @param charpos puntatore a long che serve per salvare in quale posizione c'è una differenza tra i file
 * 
 * @return -1 se errore nei file, 0 se i file sono uguali, 1 se i file sono diversi
*/
int compare(char* fname1, char* fname2, long* line, long* charpos){
  FILE* f1 = fopen(fname1, "r");
  FILE* f2 = fopen(fname2, "r");
  //caso di errore nella apertura di file
  if(f1 == NULL || f2 == NULL){
    if(f1) fclose(f1);
    if(f2) fclose(f2);
    return -1;
  }
  //caratteri
  int c1, c2;
  *line = 1;
  *charpos = 0;
  printf("%d %d", *line, *charpos);
  while((c1 = fgetc(f1) != EOF) || (c2 = fgetc(f2) != EOF)){
    *charpos += 1;
    if(c1 != c2){
      fclose(f1);
      fclose(f2);
      return 1;
    }
    //passo alla riga successiva
    if (c1 == '\n'){
      *line += 1;
      *charpos = 0;
    }
  }
  if(c1 != c2){
    fclose(f1);
    fclose(f2);
    return 1;
  }

  fclose(f1);
  fclose(f2);
  return 0;
}


int main(){

  char* file1Name = "file1.txt";
  char* file2Name = "file2.txt";
  long *line, *charpos; 
  int result = compare(file1Name, file2Name, line, charpos);
  if(result == -1){
    printf("Errore nella apertura di un file");
  }
  else if(result == 0){
    printf("I file sono uguali");
  }
  else{
    ("I file sono diversi alla fine %d e alla posizione %d", *line, *charpos);
  }
  return 0;
}