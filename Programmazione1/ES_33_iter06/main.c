#include <stdio.h>
#include <stdbool.h>

//funzione per capire se un elemento è il massimo della sua riga
bool isMaxInRow(int val, int dim ,const int array[]){
    bool isMax = true;
    for(int i=0; i<dim; i++){
        if(array[i]>val){
            isMax = false;
        }
    }
    return isMax;
}

//funzione per capire se un elemento è il minimo della sua colonna
bool isMinInCol(int val, const size_t rows, const size_t cols, const int mat[rows][cols], int currentCol){
    bool isMin = true;
    for(int i=0; i<rows; i++){
        if(mat[i][currentCol]<val){
            isMin = false;
        }
    }
    return isMin;
}


bool e1(const size_t rows, const size_t cols, const int mat[rows][cols]){

    bool tuttePuntoSella = true;

    for(int i=0; i<rows; i++){
        bool puntoSella = false;
        for(int j=0; j<cols; j++){
            //controllo se l'elemento mat[i][j] rispetta i requisiti
            if(isMaxInRow(mat[i][j], cols, mat[i]) && isMinInCol(mat[i][j], rows, cols, mat, j)){
                printf("%d %d \n",i,j);
                puntoSella = true;
            }
        }
        if(!puntoSella){
            tuttePuntoSella = false;
        }
    }
    return tuttePuntoSella;
}