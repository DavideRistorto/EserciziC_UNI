#include <stdio.h>
#include <stdbool.h>
#define DIM_MAX 20

int leggiArray(int array[]){ 
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&array[i]);
    }
    return n;
}

int contaUnivoci(int array[], int dim){
    int contaUnivoci = 0;
    for(int j=0;j<dim;j++){
        bool unico = true;
        for(int k=0;k<dim;k++){
            if((array[j] == array[k]) && (k!=j)){
                unico = false;
            }
        }
        if(unico){
            contaUnivoci++;
        }
    }
    return contaUnivoci;
}

void stampaElementiRipetuti(int array1[], int dim1, int array2[],int dim2){
    for(int j=0;j<dim1;j++){
        bool trovato = false;
        for(int k=0;k<dim2;k++){
            if(!trovato){
                if(array1[j] == array2[k]){
                    printf("%d ",array1[j]);
                    trovato = true;
                }
            }
        }
    }
}

int main() {
    int array1[DIM_MAX];
    int array2[DIM_MAX];
    int dim1 = leggiArray(array1);
    int dim2 = leggiArray(array2);
    int unic1 = contaUnivoci(array1,dim1);
    int unic2 = contaUnivoci(array2,dim2);

    printf("%d %d\n",unic1,unic2);
    stampaElementiRipetuti(array1,dim1,array2,dim2);
    return 0;
}
