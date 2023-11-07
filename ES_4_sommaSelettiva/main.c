#include <stdio.h>
#include <math.h>
#define MAX_N 20

int main() {

    int dim = -1;
    while(dim==-1 || dim>MAX_N){
        scanf("%d",&dim);
    }
    if(dim!=0){
        int array[dim];
        int minimo=0;
        int somma=0;
        for(int i=0;i<dim;i++){
            scanf("%d",&array[i]);
            if(i==0){
                minimo = array[i];
            }
            if(array[i]<minimo){
                minimo = array[i];
            }
        }
        for(int i=0;i<dim;i++){
            if(array[i]>= pow(minimo,2)){
                somma += array[i];
            }
        }
        printf("%d",somma);
    }
    else{
        printf("Vuoto.");
    }
    return 0;
}
