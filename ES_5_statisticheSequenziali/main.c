#include <stdio.h>
#include <stdbool.h>

bool leggiSequenza(int *sommaElementi, int *sommaQuadrati, int *massimoElementi){
    int array[100];
    int i=0;
    bool continua = true;
    scanf("%d",&array[i]);
    if(array[i]!=0){
        while(i<100 && array[i]!=0){
            i++;
            scanf("%d",&array[i]);
        }
        for(int j=0;j<i;j++){
            *sommaElementi += array[j];
            *sommaQuadrati += array[j]*array[j];
            if(array[j]>*massimoElementi){
                *massimoElementi = array[j];
            }
        }
    }
    else{
        continua = false;
    }
    return continua;
}

int main() {
    int sommaEl=0;
    int sommaQr=0;
    int massimoEl=0;
    bool run = true;
    while (run){
        run = leggiSequenza(&sommaEl,&sommaQr,&massimoEl);
        if(run)
            printf("%d %d %d\n",sommaEl,sommaQr,massimoEl);
        sommaEl = 0;
        sommaQr = 0;
        massimoEl = 0;
    }
    return 0;
}
