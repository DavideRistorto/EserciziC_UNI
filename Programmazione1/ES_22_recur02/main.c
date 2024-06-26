#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int e2R(const int a[], const int val, int left, int right) {
    int somma = 0;
    // Caso base: array vuoto
    if (left > right) {
        return somma;
    } else {
        // Calcolo dell'indice medio
        int mid = (right + left) / 2;
        if (a[mid] >= -val && a[mid] <= val) {
            somma += a[mid];
        }
        // Chiamate ricorsive sui due sottoarray
       somma += e2R(a, val, left, mid - 1);
       somma += e2R(a, val, mid + 1, right);
        // Ritorna la somma totale
        return somma;
    }
}

int e2(const size_t aLen, const int a[], const int val) {
    return e2R(a, val, 0, aLen - 1);
}
