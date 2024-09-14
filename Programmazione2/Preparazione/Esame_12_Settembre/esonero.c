#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*  INSERIRE QUI EVENTUALI FUNZIONI AUSILIARIE (CON UN COMMENTO SIGNIFICATIVO IN TESTA) */

/**
 * @brief Dati due array di interi a e b e la loro lunghezza n, restituire il puntatore ad un
 * blocco di 2*n interi (ovvero al primo elemento di un array di interi) allocato sullo heap
 * che contiene nell’ordine gli interi a[0], b[n-1], a[1], b[n-2],... a[n-2], b[1], a[n-1], b[0].
 *
 * Si assuma: a !=NULL, b != NULL, n > 0.
 *
 * ESEMPI:
 * (1) dati a=[1, 2, 3, 4], b=[6, 7, 8, 9], n=4 restituisce [1, 9, 2, 8, 3, 7, 4, 6]
 * (2) dati a=[5], b=[3], n=1 restituisce [5, 3]
 */
int *combine(int *a, int *b, int n)  {

    //dimensione da allocare
    int len = n*2; 
    //creo l' array
    int* array = malloc(len*sizeof(int));
    //indice per tenere riferimento dell' array appena creato
    int k = 0; 
    
    for(int i=0; i<n; i++){
        //riempio in array con l' elemento di a (crescente)
        array[k] = a[i];
        k++;
        //riempio in array con l' elemento di b (decrescente)
        array[k] = b[n-1-i];
        k++;
    }
    //ritorno l' array creato
    return array;
}

#define DIM 4

/**
 * @brief Inizializza due array di interi arr1 e arr2 della stessa lunghezza e scrive
 * sullo schermo gli elementi dell’array restituito da combine(arr1, arr2, DIM).
 * Aggiungi le definizioni di altre variabili, se ritenute necessarie.
 */
int main() {
    
    //replico esempio della consegna
    int arr1[DIM] = {1, 2, 3, 4};
    int arr2[DIM] = {6, 7, 8, 9};
    
    int* array = combine(arr1, arr2, DIM);
    
    for(int i=0; i<DIM*2; i++){
        printf("%d - ", array[i]);
    }
    free(array);
    return 0;
}
