#include <stdio.h>
#include <stdlib.h>
#define DIM 5

void scriviArray(int *array, int index){
    if(index<DIM){
        printf("inserisci elemento di indice %d: ",index);
        scanf("%d",&array[index]);
        index++;
        scriviArray(array,index);
    }
}

void leggiArray(int *array, int index){
    if(index<DIM){
        printf("%d ",array[index]);
        index++;
        leggiArray(array,index);
    }
}

int main()
{
    int array[DIM];
    scriviArray(array,0);
    leggiArray(array,0);
    return 0;
}
