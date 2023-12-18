#include <stdio.h>
#include <stdbool.h>

bool esiste_val_in_arrayR(int array[], int dim, int ricercato, int index) {
    if (index == dim) {
        return false;
    } else {
        if (array[index] == ricercato) {
            return true;
        } else {
            return esiste_val_in_arrayR(array, dim, ricercato, index + 1);
        }
    }
}

int e2R(const size_t rows, const size_t cols,
        int mat[rows][cols], size_t rags[rows],
        const int val, int currentRows) {
    int somma = 0;
    if (currentRows == rows) {
        return somma;
    } else {
        if (esiste_val_in_arrayR(mat[currentRows], rags[currentRows], val, 0)) {
            somma += rags[currentRows];
        }
        return somma + e2R(rows,cols, mat,rags,val,currentRows+1);
    }
}

int e2(const size_t rows, const size_t cols,
       int mat[rows][cols], size_t rags[rows],
       const int val) {
    return e2R(rows, cols, mat, rags, val, 0);
}