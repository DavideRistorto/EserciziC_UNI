#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "stdio.h"

/**  Un tipo di dato per i contatti telefonici e cyberspaziali
*/
typedef struct contact {
   char* name;
   char* surname;
   char* mobile;
   char* url;
} Contact, *ContactPtr;

bool equalStrings(char *str1, char *str2){
    //date due stringhe confronto carattere per carattere che sianno uguali
    if(strlen(str1) != strlen(str2)){
        return 0;
    }
    for(int i=0; i< strlen(str1);i++){
        if(tolower(str1[i]) != tolower(str2[i])){
            return 0;
        }
    }
    return 1;
}

int compareStrings(char *str1, char *str2) {
    // Confronto le due stringhe carattere per carattere
    int i=0;
    while (i< strlen(str1) && i< strlen(str2)) {
        // Convertoi caratteri in lettere minuscole prima del confronto
        char c1 = tolower(str1[i]);
        char c2 = tolower(str2[i]);
        if (c1 < c2)
            return -1; // str1 viene prima di str2
        else if (c1 > c2)
            return 1; // str1 viene dopo di str2
        i++;
    }
    // Se entrambe le stringhe sono terminate, allora sono uguali
    if (i==strlen(str1) && i==strlen(str2)){
        return 0;
    } else if (strlen(str1)> strlen(str2)){
        return 1;
    }
    return -1;
}

/**  @brief Controlla se due contatti hanno lo stesso nome e cognome
      @param c1 il primo  contatto
      @param c2 il secondo contatto
      @return 1 se i due contatti sono uguali, 0 altrimenti
*/
_Bool contactEq(Contact c1, Contact c2) {
    return equalStrings(c1.name, c2.name) && equalStrings(c1.surname, c2.surname);
}


/**  @brief Controlla se due contatti hanno lo stesso nome e cognome∗
      @param pc1 il puntatore al primo  contatto (non può essere NULL)
      @param pc2 il puntatore al secondo  contatto (non può essere NULL)
      @return 1 se i due contatti sono uguali, 0 altrimenti
*/
_Bool contactEqEff(const Contact *pc1, const Contact *pc2) {
    return equalStrings(pc1->name, pc2->name) && equalStrings(pc1->surname, pc2->surname);
}


/**  @brief Confronta due contatti per cognome rispetto all'ordine lessicografico e, se il cognome e' lo stesso, per nome
      @param c1 il primo  contatto
      @param c2 il secondo contatto
      @return -1 se c1 minore di c2, 0 se c1 uguale a c2, 1 se c1 maggiore di c2
*/
int contactCmp(Contact c1, Contact c2) {
    int value = compareStrings(c1.surname, c2.surname);
    if(value != 0){
        return value;
    }
    return compareStrings(c1.name, c2.name);
}


/**  @brief Confronta due contatti per cognome rispetto all'ordine lessicografico e, se il cognome e' lo stesso, per nome
      @param pc1 il puntatore al primo  contatto (non può essere NULL)
      @param pc2 il puntatore al secondo  contatto (non può essere NULL)
      @return -1 se *pc1 minore di *pc2, 0 se *pc1 uguale a *pc2, 1 se *pc1 maggiore di *pc2
*/
int contactCmpEff(const Contact *pc1, const Contact *pc2) {
    int value = compareStrings(pc1->surname, pc2->surname);
    if(value != 0){
        return value;
    }
    return compareStrings(pc1->name, pc2->name);
}