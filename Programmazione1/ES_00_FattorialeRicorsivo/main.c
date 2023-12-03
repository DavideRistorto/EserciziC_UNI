#include <stdio.h>
#include <stdlib.h>

int calcolaFattoriale(int numero){
    int ret=0;
    if(numero==0){
        ret =  1;
    }else{
        ret = numero*calcolaFattoriale(numero-1);
    }
    return ret;
}

int main()
{
    int numero;
    printf("inserisci il numero da calcolare il fattoriale: ");
    scanf("%d",&numero);
    int fattoriale = calcolaFattoriale(numero);
    printf("Fattoriale %d",fattoriale);

    return 0;
}
