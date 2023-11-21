#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ROWS 3
#define COLS 3

int main()
{
    bool vincitore = false;
    char campo[3][3];

    //input della matrice con le mosse
    for(int i=0; i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            scanf(" %c",&campo[i][j]);
        }
    }
    //controllo righe
    for(int i=0;i<ROWS;i++){
        if(campo[i][0] == campo[i][1] && campo[i][0] == campo[i][2]){
            printf("%c",campo[i][0]);
            vincitore = true;
        }
    }
    //controllo colonne
    for(int i=0;i<COLS;i++){
        if(campo[0][i] == campo[1][i] && campo[0][i] == campo[2][i]){
            printf("%c",campo[0][i]);
            vincitore = true;
        }
    }
    //controllo diagonali
    if((campo[0][0] == campo[1][1] && campo[0][0] == campo[2][2]) || (campo[0][2] == campo[1][1] && campo[0][2] == campo[2][0])){
        printf("%c",campo[1][1]);
        vincitore = true;
    }
    //simbolo di pareggio se non è stato troavato un vincitore;
    if(!vincitore){
        printf("-");
    }

    return 0;
}
