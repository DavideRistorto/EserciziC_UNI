#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "contactBook.h"
#include "sortedSetADT.h"

/**
 Un tipo di dato per una rubrica di contatti
*/
struct contactBookADT {
  SortedSetADTptr contacts; // Tutto quello che serve è già in questa struttura
};

void stampaContact(void* elem) {
  ContactPtr contact = (ContactPtr)elem;
  printf("%s %s: %s (%s)", getName(contact), getSurname(contact), getMobile(contact), getUrl(contact));
}

int contact_cmp(void* c1, void* c2) {
  return cmpContact((ContactPtr)c1, (ContactPtr)c2);
}

// restituisce una rubrica vuota, NULL se errore
ContactBookADTptr mkCBook() {
  ContactBookADTptr book = (ContactBookADTptr)malloc(sizeof(struct contactBookADT));
  if(book == NULL) return NULL;
  book->contacts = mkSSet(contact_cmp);

  return book;
}

// distrugge la rubrica, recuperando la memoria, false se errore
_Bool dsCBook(ContactBookADTptr* book) {
  if( *book == NULL || book == NULL)  return false;

  dsSSet(&((*book)->contacts));
  free(*book);
  *book = NULL;
  return 1;
}

// controlla se la rubrica e' vuota, -1 se NULL
int isEmptyCBook(const ContactBookADT* book) {
  if(book == NULL) return -1;

  return isEmptySSet(book->contacts);
}

// restituisce il numero di contatti presenti nella rubrica, -1 se NULL
int cbook_size(const ContactBookADT* book) {
  if(book == NULL) return -1;

  return sset_size(book->contacts);
}

// aggiunge un contatto alla rubrica (restituisce false se l'elemento era gia' presente, true altrimenti)
_Bool cbook_add(ContactBookADTptr book, ContactPtr cnt) {
  return sset_add(book->contacts, cnt);
}

// toglie un elemento all'insieme (restituisce false se l'elemento non era presente, true altrimenti)
_Bool cbook_remove(ContactBookADTptr book, char* name, char* surname) {
  ContactPtr contact = mkContact(name, surname, "", "");
  return sset_remove(book->contacts, contact);
}

// restituisce un puntatore al contatto con dato nome e cognome (può essere usata per accedere o modificare il numero e url del contatto), NULL se non presente
ContactPtr cbook_search(const ContactBookADT* book, char* name, char* surname) {
  ContactPtr contact = mkContact(name, surname, "", "");
  return sset_search(book->contacts, contact);
}

// carica una rubrica da file, NULL se errore
ContactBookADTptr cbook_load(FILE* fin) {
  //nuova rubirca
  ContactBookADTptr book = mkCBook();
  // apro file in lettura
  fin = fopen("temp.csv","r");
  //file errore o rubrica con allocata
  if(fin == NULL || book == NULL){
    return NULL;
  }
  //read the file and for each line create a contact and add it to the book
  char line[1024];
  char name[100], surname[100], mobile[100], url[100];
  while(fgets(line,sizeof(line),fin)){
    sscanf(line, "%[^,],%[^,],%[^,],%[^\n]", name, surname, mobile, url);
    ContactPtr contact = mkContact(name, surname, mobile, url);
    cbook_add(book, contact);
  }
  return book;
}

// salva una rubrica su file, false se errore
_Bool cbook_dump(const ContactBookADT* book, FILE* fout) {
  // apro file in scrittura
  fout = fopen("temp.csv","w");
  //file errore
  if(fout == NULL){
    return false;
  }
  //se la rubrica è vuota pulisco il file
  if(book == NULL || sset_size(book->contacts) > 0){
    fclose(fout);
    return 1;
  }
  void** array = sset_toArray(book->contacts);
  for(int i=0; i<sset_size(book->contacts); i++){
    ContactPtr contact = array[i];
    fprintf(fout, "%s,%s,%s,%s\n", getName(contact), getSurname(contact), getMobile(contact), getUrl(contact));
  }
  fclose(fout);
  return 1;
}