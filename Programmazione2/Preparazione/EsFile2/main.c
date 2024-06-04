#include <stdio.h>
#include <stdlib.h>

int main(){
  FILE *fp = fopen("dati.txt","r");
  FILE* fp2 = fopen("report.txt","w");
  //read the file
  char cognome[50], nome[50], eta[50];
  //mettere == 3 permette di non leggere righe incomplete
  while(fscanf(fp,"%49[^,],%49[^,],%49[^\n]",cognome,nome,eta) == 3){
    printf("%s %s %s",cognome,nome,eta);
    fprintf(fp2,"%s,%s,%s",cognome,nome,eta);
  }
  fclose(fp);
  fclose(fp2);
  return 0;
}