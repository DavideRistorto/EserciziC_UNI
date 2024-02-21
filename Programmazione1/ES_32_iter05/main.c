#include <stdio.h>
#include <stdbool.h>

bool isElementInArray(int val, int array[], size_t dim){              
    bool trovato = false;
    for(int i=0; i<dim && !trovato; i++){
        if(array[i] == val){
            trovato = true;         
        }
    }
    return trovato;
}

//funzione che shifta verso sinistra partendo da un certo elemento
void shiftArray(int array[], size_t dim, size_t startingIndex){
    for(size_t i = startingIndex; i < dim - 1; i++){
        array[i] = array[i + 1];
    }
}

bool e1(const size_t rows, const size_t cols,
        int mat[rows][cols], size_t rags[rows]) {

    bool unaRigaModificata = false;
    // scorro righe
    for(size_t i=1; i<rows; i++){
        //scorro colonne
        for(size_t j=0; j<rags[i]; j++){
            if(isElementInArray(mat[i][j], mat[i-1], rags[i-1])){
                unaRigaModificata = true;
                shiftArray(mat[i],rags[i], j);
                //N.B. è importante decrementare la colonna perchè avendo shiftato
                // si skipperebbe un elemento
                j-=1;
                //decremento anche la dimensione dell' array
                rags[i]--;
            }
        }
    }
    return unaRigaModificata;
}
