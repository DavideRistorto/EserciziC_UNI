#include "contactOpq.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct contact {
    char* name;
    char* surname;
    char* mobile;
    char* url;
} Contact, *ContactPtr;

/**
* @brief Crea un nuovo contatto
*
* @param name La stringa che contiene il nome
* @param surname La stringa che contiene il cognome
* @param mobile La stringa che contiene il numero di cellulare
* @param url La stringa che contiene la home page
* @return Il puntatore alla struttura che rappresenta il contatto, NULL se ((name == NULL) || (surname == NULL))
*/
ContactPtr mkContact(char* name, char* surname, char* mobile, char* url) {
    if (name == NULL || surname == NULL) {
        return NULL;
    }
    ContactPtr newContact = (ContactPtr)malloc(sizeof(Contact));
    if (newContact == NULL) {
        return NULL;
    }
    newContact->name = (char*)malloc(strlen(name) + 1);
    if (newContact->name == NULL) {
        free(newContact);
        return NULL;
    }
    strcpy(newContact->name, name);

    newContact->surname = (char*)malloc(strlen(surname) + 1);
    if (newContact->surname == NULL) {
        free(newContact->name);
        free(newContact);
        return NULL;
    }
    strcpy(newContact->surname, surname);

    newContact->mobile = (char*)malloc(strlen(mobile) + 1);
    if (newContact->mobile == NULL) {
        free(newContact->surname);
        free(newContact->name);
        free(newContact);
        return NULL;
    }
    strcpy(newContact->mobile, mobile);

    newContact->url = (char*)malloc(strlen(url) + 1);
    if (newContact->url == NULL) {
        free(newContact->mobile);
        free(newContact->surname);
        free(newContact->name);
        free(newContact);
        return NULL;
    }
    strcpy(newContact->url, url);

    return newContact;
}

/**
* @brief Dealloca una struttura Contact e mette il relativo puntatore (che dunque deve essere passato per riferimento) a NULL
*
* @param cntptr il puntatore al contatto (non può essere NULL). Nota: cntptr è un puntatore a puntatore a Contact
*/
void dsContact(ContactPtr* cntptr) {
    if(cntptr != NULL && *cntptr != NULL && ) {
        free((cntptr)->name);
        free((cntptr)->surname);
        free((cntptr)->mobile);
        free((cntptr)->url);
        free(cntptr);
        *cntptr = NULL;
    }
}

/**
* @brief Aggiorna il telefono di un contatto
*
* @param cnt Il contatto
* @param mobile La stringa che contiene il nuovo numero di cellulare  (può essere NULL)
*/
void updateMobile(ContactPtr cnt, char* newMobile){
    if( newMobile != NULL){
        strcpy(cnt->mobile, newMobile);
    }
}

/**
* @brief Aggiorna la home page di un contatto
*
* @param cnt Il contatto
* @param url La stringa che contiene la nuova home page  (può essere NULL)
*/
void updateUrl(ContactPtr cnt, char* newUrl){
    if( newUrl != NULL){
        strcpy(cnt->url, newUrl);
    }
}


/**
* @brief Restituisce il nome di un contatto
*
* @param cnt Il contatto
* @return url La stringa che contiene il nome del contatto
*/
char* getName(const ContactPtr cnt){
    return cnt->name;
}

/**
* @brief Restituisce il cognome di un contatto
*
* @param cnt Il contatto
* @return url La stringa che contiene il cognome del contatto
*/
char* getSurname(const ContactPtr cnt){
    return cnt->surname;
}

/**
* @brief Restituisce il numero di cellulare di un contatto
*
* @param cnt Il contatto
* @return url La stringa che contiene il numero di cellulare  (può essere NULL)
*/
char* getMobile(const ContactPtr cnt){
    return cnt->mobile;
}

/**
* @brief Restituisce la home page di un contatto
*
* @param cnt Il contatto
* @return url La stringa che contiene la nuova home page  (può essere NULL)
*/
char* getUrl(const ContactPtr cnt){
    return cnt->url;
}

/**
* @brief Controlla se due contatti sono uguali rispetto al cognome e al nome
*
* @param cnt1 Il primo contatto
* @param cnt2 Il secondo contatto
* @return 1 se i due contatti hanno lo stesso cognome e lo stesso nome, 0 altrimenti
*/
_Bool equalsContact(const ContactPtr cnt1, const ContactPtr cnt2) {
    if (cnt1 == NULL || cnt2 == NULL) {
        return 0; // Se uno dei contatti è NULL, non sono uguali
    }
    return strcmp(cnt1->name, cnt2->name) == 0 && strcmp(cnt1->surname, cnt2->surname) == 0;
}

/**
* @brief Confronta due contatti in ordine lessicografico in base al cognome e al nome
*
* @param cnt1 Il primo contatto
* @param cnt2 Il secondo contatto
* @return -1 se cnt1 minore cnt2, 0 se cnt1 uguale cnt2, 1 se cnt1 maggiore cnt2
*/
int cmpContact(const ContactPtr cnt1, const ContactPtr cnt2) {
    if (cnt1 == NULL || cnt2 == NULL) {
        return 0; // Se uno dei contatti è NULL, non possono essere confrontati
    }
    int surnameComparison = strcmp(cnt1->surname, cnt2->surname);
    if (surnameComparison != 0) {
        return surnameComparison; // Se i cognomi sono diversi, restituisci il risultato della comparazione dei cognomi
    }

    return strcmp(cnt1->name, cnt2->name); // Se i cognomi sono uguali, confronta i nomi
}