#include <stdio.h>
#include <stdbool.h>

void e2R(const size_t aLen, const int a[], size_t* p_bLen, int b[],
         const int val, int indexA, int indexB) {
    //quando si raggiunge la fine di uno dei due array si esce dall ricorsione
    if(indexA==aLen || indexB == *p_bLen){
        // la dimensione effettiva di b[] viene aggiornata
        *p_bLen = indexB;
        return;
    } else {
        if (a[indexA] > val) {
            //inserimento della differenza nell' array b
            b[indexB] = a[indexA]-val;
            //incremento dell' indice
            indexB += 1;
        }
        return e2R(aLen, a, p_bLen, b, val, indexA + 1, indexB);
    }
}

//funzione involucro per richiamare la funzione ricorsiva
void e2(const size_t aLen, const int a[], size_t* p_bLen, int b[], const int val) {
    //aggiungo come variabili d' appoggio gli indici correnti di a[] e b[]
    e2R(aLen, a, p_bLen, b, val, 0,0);
}