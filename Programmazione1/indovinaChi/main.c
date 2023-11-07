#include <stdio.h>
#include <stdbool.h>

//-------------------------------------------------------
// Definizione del gioco - non modificare
//-------------------------------------------------------

#define NUM_PERS  24

const char* nomi[NUM_PERS] = {
	"Claire", "Eric", "Maria", "George", "Bernard", "Sam",
	"Tom", "Paul", "Joe", "Frans", "Anne", "Max",
	"Alex", "Philip", "Bill", "Anita", "David", "Charles",
	"Herman", "Peter", "Susan", "Robert", "Richard", "Alfred"
};
const bool e_calvo[NUM_PERS] = {
	0, 0, 0, 0, 0, 1,   1, 0, 0, 0, 0, 0,   0, 0, 1, 0, 0, 0,  1, 0, 0, 0, 1, 0,
};
const bool ha_cappello[NUM_PERS] = {
	1, 1, 1, 1, 1, 0,   0, 0, 0, 0, 0, 0,   0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
};
const bool e_donna[NUM_PERS] = {
	1, 0, 1, 0, 0, 0,   0, 0, 0, 0, 1, 0,   0, 0, 0, 1, 0, 0,  0, 0, 1, 0, 0, 0,
};
const bool ha_occhiali[NUM_PERS] = {
	1, 0, 0, 0, 0, 1,   1, 1, 1, 0, 0, 0,   0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
};
const bool ha_occhi_blu[NUM_PERS] = {
	0, 0, 0, 0, 0, 0,   1, 0, 0, 0, 0, 0,   0, 0, 0, 1, 0, 0,  0, 1, 0, 1, 0, 1,
};
const bool ha_capelli_neri[NUM_PERS] = {
	0, 0, 0, 0, 0, 0,   1, 0, 0, 0, 1, 1,   0, 1, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
};


int main() {

    int eCalvo, haCappello, eDonna, haOcchiali,haOcchiBlu,haCapelliNeri;
    scanf("%d %d %d %d %d %d", &eCalvo,&haCappello, &eDonna, &haOcchiali ,&haOcchiBlu, &haCapelliNeri);
    int contaSospetti = 0;

    for(int i=0; i<NUM_PERS; i++){
        bool sospetto = true;

        if(eCalvo != e_calvo[i]){
            sospetto = false;
        }
        if(haCappello != ha_cappello[i]){
            sospetto = false;
        }
        if(eDonna != e_donna[i]){
            sospetto = false;
        }
        if(haOcchiali != ha_occhiali[i]){
            sospetto = false;
        }
        if(haOcchiBlu != ha_occhi_blu[i]){
            sospetto = false;
        }
        if(haCapelliNeri != ha_capelli_neri[i]){
            sospetto = false;
        }
        if(sospetto){
            printf("%s\n",nomi[i]);
            contaSospetti++;
        }
    }
    if(contaSospetti==0){
        printf("NO_SOSPETTI");
    }
    else if(contaSospetti==1){
        printf("TROVATO!");
    }
    else if(contaSospetti>1){
        printf("TROVATI %d",contaSospetti);
    }
}