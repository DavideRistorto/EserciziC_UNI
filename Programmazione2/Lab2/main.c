#include <string.h>
#include <ctype.h>
#include <stdbool.h>

/**  Un tipo di dato per i contatti telefonici e cyberspaziali
*/
typedef struct contact {
   char* name;
   char* surname;
   char* mobile;
   char* url;
} Contact, *ContactPtr;

bool equalStrings(char *str1, char *str2){
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
    // Confronta le due stringhe carattere per carattere
    while (*str1 && *str2) {
        // Converte i caratteri in lettere minuscole prima del confronto
        char c1 = tolower(*str1);
        char c2 = tolower(*str2);

        if (c1 < c2)
            return -1; // str1 viene prima di str2
        else if (c1 > c2)
            return 1; // str1 viene dopo di str2
        str1++;
        str2++;
    }

    // Se entrambe le stringhe sono terminate, allora sono uguali
    if (!*str1 && !*str2)
        return 0; // stesse stringhe

    // Se una delle due stringhe è terminata e l'altra no,
    // la più corta viene considerata "minore"
    return (*str1) ? 1 : -1;
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
    return compareStrings(c1.surname, c2.surname);
}


/**  @brief Confronta due contatti per cognome rispetto all'ordine lessicografico e, se il cognome e' lo stesso, per nome
      @param pc1 il puntatore al primo  contatto (non può essere NULL)
      @param pc2 il puntatore al secondo  contatto (non può essere NULL)
      @return -1 se *pc1 minore di *pc2, 0 se *pc1 uguale a *pc2, 1 se *pc1 maggiore di *pc2
*/
int contactCmpEff(const Contact *pc1, const Contact *pc2) {
    return compareStrings(pc1->surname, pc2->surname);

}