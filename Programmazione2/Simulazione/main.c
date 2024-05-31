#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
  //errore apertura file
  if(f1 == NULL || f2 == NULL){
    if(f1) fclose(f1);
    if(f2) fclose(f2);
    return -1;
  }
  *line = 1;
  *charpos = 0;
  char c1, c2;
  bool exit = false;
  while((!feof(f1) && !feof(f2)) && !exit){
    *charpos += 1;
    c1 = fgetc(f1);
    c2 = fgetc(f2);
    if(c1 != c2){
      exit = true;
    }
    else if(c1 == '\n'){
      *line += 1;
      *charpos = 0;
    }
  }
  //se non sono uscito dal ciclo per una disuguaglianza, controllo se i file hanno stessa lunghezza
  if(!exit){
    if(feof(f1) != feof(f2)){
      exit = true;
    }
  }
  fclose(f1);
  fclose(f2);
  return exit;
}


int main(){

  char* file1Name = "file1.txt";
  char* file2Name = "file2.txt";
  long line, charpos; 
  int result = compare(file1Name, file2Name, &line, &charpos);
  printf("Risultato confronto: %d\n", result);
  if(result == -1){
    printf("Errore nella apertura di un file\n");
  }
  else if(result == 0){
    printf("I file sono uguali\n");
  }
  else{
    printf("I file sono diversi alla riga %ld e alla posizione %ld\n", line, charpos);
  }
  return 0;
}