#include <stdio.h>
#include <stdbool.h>

bool e1(const size_t rows, const size_t cols,
        int mat[rows][cols], size_t rags[rows]) {

    bool tutteModificate = true;
    bool colonnaModificata;
    //controllo righe
    for(int i=0; i<rows; i++){
        colonnaModificata = false;
        //indice che parte dalla fine della riga della matrice irregolare
        int indexSecondario = rags[i];
        //controllo ogni colonna
        for(int j=0; j<rags[i]; j++){
            //controllo se l' elemento è multiplo di 3, maggiore di zero, e se c'è ancora spazio per aggiungere
            //un elemento a fine colonna
            if(mat[i][j]%3==0 && mat[i][j]>0 && indexSecondario<cols){
                colonnaModificata = true;
                mat[i][indexSecondario] = mat[i][j] / 3;
                indexSecondario++;
                // aggiorno la dimensione della matrice
                rags[i] = indexSecondario;
            }
        }
        if(!colonnaModificata){
            tutteModificate = false;
        }
    }
    return tutteModificate;
}