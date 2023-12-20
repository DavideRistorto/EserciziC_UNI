#include <stdio.h>
#include <stdbool.h>

bool e1(const size_t rows, const size_t cols,
	    const int mat[rows][cols], const size_t rags[rows],
	    const size_t aLen, const int a[aLen],
	    int *pSum) {

    int sommaTuttiProdotti = 0, sommaRiga = 0;
    bool sommaRigaMultiplo5 = false;
    for(int i=0; i<rows; i++){
        sommaRiga = 0;
        for(int j=0; j<rags[i] && j<aLen; j++){
            sommaRiga += a[j]*mat[i][j];
        }
        if(sommaRiga>0 && sommaRiga%5==0){
            sommaRigaMultiplo5 = true;
            sommaTuttiProdotti += sommaRiga;
        }
    }
    *pSum = sommaTuttiProdotti;
    return  sommaRigaMultiplo5;
}