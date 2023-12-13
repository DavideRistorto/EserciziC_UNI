#include <stdio.h>
#include <stdbool.h>

bool ricerca_binaria(const int a[], const int val, size_t *pIndice,
                     const size_t left, const size_t right) {
    //caso base, il numero non viene trovato
    if (left >= right) {
        return false;
    } else {
        // trvovo l' indice a metà degli estremi sx e dx
        size_t mid = (right + left) / 2;
        *pIndice = mid;
        if (a[mid] == val) {
            return true;
        } else {
            //se il valore è maggiore di mid, allora bisogna aumentare l' estremo sx
            if (val > a[mid]) {
                return ricerca_binaria(a, val, pIndice, mid + 1, right);
            } else {
                //se il valore è minore di mid, allora bisogna decrementare l' estremo dx
                return ricerca_binaria(a, val, pIndice, left, mid);
            }
        }
    }
}

bool trova_coppia(const int a[], const int somma_target,
             const size_t left, const size_t right,
             size_t *pIndice1, size_t *pIndice2) {
    // uso left come indice dell' array, che parte da 0
    //quando l' indice supera right, allora si è arrivati alla fine
    if(left>=right){
        return false;
    } else {
        *pIndice1 = left;
        int target = somma_target - a[*pIndice1];
        //facciò la ricerca sul valore che mi serve, se lo trovo aggiorno il suo indice e fermo la ricorsione
        if (ricerca_binaria(a,target, pIndice2, left, right)){
            return true;
        } else {
            // se non trovo l' elemento, incremento left e ricomincio tutto
            return trova_coppia(a, somma_target, left+1, right, pIndice1, pIndice2);
        }
    }
}