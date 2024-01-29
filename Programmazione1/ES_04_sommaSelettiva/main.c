#include <stdio.h>
#include "math.h"
#define MAX_N 20 
int main() {
    int sequenza=-1;
    scanf("%d",&sequenza);
    if(sequenza<0 || sequenza > MAX_N){
        printf("Errore: numero di elementi non valido.");
    }
    else{
        int elementi[sequenza];
        if(sequenza!=0){
            for(int i=0; i<sequenza; i++){
                scanf("%d", &elementi[i]);
            } 
            int minimo=elementi[0];
            for(int i=1; i<sequenza; i++){
                if(elementi[i]<minimo){
                minimo=elementi[i];
                }
            }
            int somma=0;
            for(int i=0; i<sequenza; i++){
                if(elementi[i] >= pow(minimo,2)){
                somma+=elementi[i];
                }
            }
            printf("%d", somma);
        } 
        else {
            printf("Vuoto.");
        }   
    }
    return 0;
}
