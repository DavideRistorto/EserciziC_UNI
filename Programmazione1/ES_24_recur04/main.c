#include <stdio.h>
#include <stdbool.h>

bool esiste_elemento(int ricercato, const int b[], size_t bLen, int index) {
    if (index == bLen) {
        return false;
    } else {
        if(b[index] == ricercato){
            return true;
        } else {
            return esiste_elemento(ricercato, b, bLen, index + 1);
        }
    }
}

//uso la solita logica di shiftare gli elementi si una posizione verso sinistra
void rimuovi_elementiR(int a[], int ricercato, int source, int destination, size_t *p_aLen) {
    if (source == *p_aLen) {
        *p_aLen = destination;
        return;
    } else {
        if (a[source] == ricercato) {
            rimuovi_elementiR(a, ricercato, source + 1, destination, p_aLen);
        } else {
            a[destination] = a[source];
            rimuovi_elementiR(a, ricercato, source + 1, destination + 1, p_aLen);
        }
    }
}

int e2R(size_t *p_aLen, int a[], const size_t bLen, const int b[], int indexA) {
    if (indexA == *p_aLen) {
        return *p_aLen;
    } else {
        if (esiste_elemento(a[indexA], b, bLen, 0)) {
            rimuovi_elementiR(a, a[indexA], indexA + 1, indexA + 1, p_aLen);
        }
        return e2R(p_aLen, a, bLen, b, indexA + 1);
    }
}

int e2(size_t *p_aLen, int a[], const size_t bLen, const int b[]) {
    return e2R(p_aLen, a, bLen, b, 0);
}
