#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

bool e1(const size_t rows, const size_t cols,
        const int mat[rows][cols], const size_t rags[rows],
        const int k, int *pMaxSum){

    bool rigaSommaMultiplo7 = false;
    int sommaMax = 0;
    int sommaRiga;

    // controll se la matrice irregola è vuota
    bool matriceVuota = true;
    for(int i=0;i<rows;i++){
        if(rags[i]!=0){
            matriceVuota = false;
        }
    }
    //la matrice non è vuota proseguo col programma
    if(!matriceVuota){
        rigaSommaMultiplo7 = true;
        for(int i=0; i<rows; i++){
            sommaRiga = 0;
            if(rags[i]>0){
                for(int j=0; j<rags[i]; j++){
                    sommaRiga += mat[i][j];
                }
                // controllo se esiste una riga cui la somma non è multiplo di 7
                if(sommaRiga % k!=0) {
                    rigaSommaMultiplo7 = false;
                } else {
                    if (sommaRiga > sommaMax) {
                        sommaMax = sommaRiga;
                    }
                }
            }
        }
    }
    if(rigaSommaMultiplo7){
        *pMaxSum = sommaMax;
    }
    return  rigaSommaMultiplo7;
}