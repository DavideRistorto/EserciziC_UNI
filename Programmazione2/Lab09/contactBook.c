#include "contactBook.h"

#include "sortedSetADT.h"

/**
 Un tipo di dato per una rubrica di contatti
*/
struct contactBookADT {
  SortedSetADTptr contacts;  // Tutto quello che serve è già in questa struttura
};

void stampaContact(void* elem) {
  ContactPtr contact = (ContactPtr)elem;
  printf("%s %s: %s (%s)", getName(contact), getSurname(contact), getMobile(contact),
         getUrl(contact));
}

int contact_cmp(void* c1, void* c2) {
  return cmpContact((ContactPtr)c1, (ContactPtr)c2);
}

// restituisce una rubrica vuota, NULL se errore
ContactBookADTptr mkCBook() {
  ContactBookADTptr book = (ContactBookADTptr)malloc(sizeof(struct contactBookADT));
  if (book == NULL) return NULL;
  book->contacts = mkSSet(contact_cmp);

  return book;
}

// distrugge la rubrica, recuperando la memoria, false se errore
_Bool dsCBook(ContactBookADTptr* book) {
  if (book == NULL || *book == NULL) {
    return 0;
  }
  // distruggo l' albero
  dsSSet(&((*book)->contacts));
  free(*book);
  *book = NULL;
  return 1;
}

// controlla se la rubrica e' vuota, -1 se NULL
int isEmptyCBook(const ContactBookADT* book) {
  if (book == NULL) return -1;

  return isEmptySSet(book->contacts);
}

// restituisce il numero di contatti presenti nella rubrica, -1 se NULL
int cbook_size(const ContactBookADT* book) {
  if (book == NULL) return -1;

  return sset_size(book->contacts);
}

// aggiunge un contatto alla rubrica (restituisce false se l'elemento era gia' presente, true
// altrimenti)
_Bool cbook_add(ContactBookADTptr book, ContactPtr cnt) {
  if (book == NULL) {
    return 0;
  }
  return sset_add(book->contacts, cnt);
}

// toglie un elemento all'insieme (restituisce false se l'elemento non era presente, true
// altrimenti)
_Bool cbook_remove(ContactBookADTptr book, char* name, char* surname) {
  if (book == NULL) {
    return 0;
  }
  ContactPtr contact = mkContact(name, surname, "", "");
  return sset_remove(book->contacts, contact);
}

// restituisce un puntatore al contatto con dato nome e cognome (può essere usata per accedere o
// modificare il numero e url del contatto), NULL se non presente
ContactPtr cbook_search(const ContactBookADT* book, char* name, char* surname) {
  ContactPtr contact = mkContact(name, surname, "", "");
  return sset_search(book->contacts, contact);
}

// carica una rubrica da file, NULL se errore
ContactBookADTptr cbook_load(FILE* fin) {
  ContactBookADTptr book = mkCBook();
  if (fin == NULL || book == NULL) {
    return NULL;
  }
  char line[1024];
  while (fgets(line, sizeof(line), fin)) {
    char* surname = malloc(100 * sizeof(char));
    char* name = malloc(100 * sizeof(char));
    char* mobile = malloc(100 * sizeof(char));
    char* url = malloc(100 * sizeof(char));
    // controllo di allocazione dei campi del contatto
    if (name == NULL || surname == NULL || mobile == NULL || url == NULL) {
      free(name);
      free(surname);
      free(mobile);
      free(url);
      // passo all' elemento successivo
      continue;
    }
    sscanf(line, "%99[^,],%99[^,],%99[^,],%99[^\n]", name, surname, mobile, url);
    ContactPtr contact = mkContact(name, surname, mobile, url);
    if (contact != NULL) {
      cbook_add(book, contact);
    }
  }
  return book;
}

// salva una rubrica su file, false se errore
_Bool cbook_dump(const ContactBookADT* book, FILE* fout) {
  if (book == NULL || fout == NULL) {
    return 0;
  }
  int size = cbook_size(book);
  // se la rubrica è vuota, non c'e' niente da salvare
  if (size == 0) {
    return 1;
  }
  void** array = sset_toArray(book->contacts);
  if (array == NULL) {
    return 0;
  }
  // ciclo sull array di contatti e scrivo ogni elemento
  for (int i = 0; i < size; i++) {
    ContactPtr contact = array[i];
    if (contact != NULL) {
      fprintf(fout, "%s,%s,%s,%s\n", getName(contact), getSurname(contact), getMobile(contact),
              getUrl(contact));
    }
  }
  free(array);
  return 1;
}

void menu() {
  printf("\nMenu:\n");
  printf("0) Uscita dal programma\n");
  printf("1) Crea una nuova rubrica\n");
  printf("2) Crea un nuovo contatto e inserisci nella rubrica\n");
  printf("3) Ricerca di un contatto nella rubrica\n");
  printf("4) Cancella un contatto dalla rubrica\n");
  printf("5) Salva la rubrica su un file\n");
  printf("6) Carica una rubrica da file\n");
  printf("Scelta: ");
}

int main() {
  ContactBookADTptr rubrica = NULL;
  int scelta;
  char nome[100], cognome[100], mobile[100], url[100];
  char filename[100];
  FILE* file;
  while (1) {
    menu();
    scanf("%d", &scelta);
    switch (scelta) {
      case 0:
        if (rubrica != NULL) {
          dsCBook(&rubrica);
        }
        printf("Uscita dal programma...\n");
        return 0;
      case 1:
        if (rubrica != NULL) {
          dsCBook(&rubrica);
        }
        rubrica = mkCBook();
        if (rubrica == NULL) {
          printf("Errore nella creazione della rubrica.\n");
        } else {
          printf("Rubrica creata.\n");
        }
        break;
      case 2:
        if (rubrica == NULL) {
          printf("Rubrica non valida. Crea una rubrica prima di aggiungere contatti!\n");
        } else {
          printf("Nome: ");
          scanf("%99s", nome);
          printf("Cognome: ");
          scanf("%99s", cognome);
          printf("Mobile: ");
          scanf("%99s", mobile);
          printf("Url: ");
          scanf("%99s", url);
          ContactPtr contatto = mkContact(nome, cognome, mobile, url);
          if (cbook_add(rubrica, contatto)) {
            printf("Contatto aggiunto correttamente.\n");
          } else {
            printf("Contatto già presente nella rubrica, quindi non aggiunto.\n");
            free(contatto);
          }
        }
        break;
      case 3:
        if (rubrica == NULL) {
          printf("Rubrica non esistente. Creare una rubrica prima di cercare contatti.\n");
        } else {
          printf("Nome del contatto da cercare: ");
          scanf("%99s", nome);
          printf("Cognome del contatto da cercare: ");
          scanf("%99s", cognome);
          ContactPtr contatto = cbook_search(rubrica, nome, cognome);
          if (contatto == NULL) {
            printf("Contatto non trovato.\n");
          } else {
            printf("Contatto trovato: %s %s, %s, %s\n", getName(contatto), getSurname(contatto),
                   getMobile(contatto), getUrl(contatto));
          }
        }
        break;
      case 4:
        if (rubrica == NULL) {
          printf("Rubrica non esistente. Creare una rubrica prima di cancellare contatti.\n");
        } else {
          printf("Nome del contatto da cancellare: ");
          scanf("%99s", nome);
          printf("Cognome del contatto da cancellare: ");
          scanf("%99s", cognome);
          if (cbook_remove(rubrica, nome, cognome)) {
            printf("Contatto cancellato con successo.\n");
          } else {
            printf("Contatto non cancellato, perchè non trovato.\n");
          }
        }
        break;
      case 5:
        if (rubrica == NULL) {
          printf("Rubrica non esistente. Crea una rubrica prima di salvarla su file.\n");
        } else {
          printf("Nome del file su cui salvare la rubrica: ");
          scanf("%99s", filename);
          file = fopen(filename, "w");
          if (file == NULL) {
            printf("File non aperto correttamente.\n");
          } else {
            if (cbook_dump(rubrica, file)) {
              printf("Rubrica salvata con successo.\n");
            } else {
              printf("Errore nel salvataggio della rubrica.\n");
            }
            fclose(file);
          }
        }
        break;
      case 6:
        if (rubrica != NULL) {
          dsCBook(&rubrica);
        }
        printf("Nome del file da cui caricare la rubrica: ");
        scanf("%99s", filename);
        file = fopen(filename, "r");
        if (file == NULL) {
          printf("File non aperto correttamente.\n");
        } else {
          rubrica = cbook_load(file);
          if (rubrica == NULL) {
            printf("Errore nel caricamento della rubrica.\n");
          } else {
            printf("Rubrica caricata con successo.\n");
          }
          fclose(file);
        }
        break;
      default:
        printf("Scelta non valida, riprova.\n");
        break;
    }
  }
}
