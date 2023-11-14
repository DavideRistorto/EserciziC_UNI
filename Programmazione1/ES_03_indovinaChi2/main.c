#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include "string.h"

#define NUM_PERS 24

// I nomi dei soggetti fermati
const char* nomi[NUM_PERS] = {
        "Claire","Eric",   "Maria", "George","Bernard","Sam",    "Tom",    "Paul",
        "Joe",   "Frans",  "Anne",  "Max",   "Alex",   "Philip", "Bill",   "Anita",
        "David", "Charles","Herman","Peter", "Susan",  "Robert", "Richard","Alfred",
};

// Gli attributi dei soggetti fermati, codificati come stringa
const char* attributi[NUM_PERS] = {
        "drco", "bc",   "dtc", "wc",   "tcg",  "wpo",  "npzo", "wo",
        "bo",   "r",    "dn",  "nfsg", "nfs",  "nal",  "rpal", "dblz",
        "ba",   "bfs",  "rpg", "wszg", "dwls", "tlzg", "tpfa", "rfz",
};

int main(void) {
    bool sospetto;
    int contaSospetti = 0;
    char indizio[15];
    scanf("%s",indizio);

    for(int i=0;i<NUM_PERS;i++){
        sospetto = true;
        for(int j=0; j<strlen(indizio);j++){
           if(islower(indizio[j])){
                if(!strchr(attributi[i],indizio[j])){
                    sospetto = false;
                }
            }
            else if(isupper(indizio[j])){
                if(strchr(attributi[i], tolower(indizio[j]))){
                    sospetto = false;
                }
            }
        }
        if(sospetto){
            printf("%s\n",nomi[i]);
            contaSospetti++;
        }
    }
    printf("%d",contaSospetti);
    return 0;
}