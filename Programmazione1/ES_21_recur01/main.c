#include <stdio.h>
#include <stdbool.h>

int e2R(const size_t aLen, const int a[], const size_t bLen, const int b[], int indexA, int indexB) {
    int somma = 0;
    if((indexA == aLen && indexB == bLen)){
        return somma;
    }
    if(indexA<aLen && indexB<bLen){
        somma += a[indexA]*b[indexB] + e2R(aLen, a, bLen, b, indexA+1, indexB+1);
        return somma;
    } else {
        if(indexA<aLen) {
            somma += a[indexA] * a[indexA] + e2R(aLen, a, bLen, b, indexA + 1, indexB);
        } else {
            somma += b[indexB] * b[indexB] + e2R(aLen, a, bLen, b, indexA, indexB+1);
        }
        return somma;
    }
}

int e2(const size_t aLen, const int a[], const size_t bLen, const int b[]) {
   return e2R(aLen, a, bLen, b, 0, 0);
}