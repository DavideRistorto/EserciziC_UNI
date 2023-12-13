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
