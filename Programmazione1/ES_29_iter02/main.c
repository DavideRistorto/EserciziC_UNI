#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

bool e1(const size_t rows, const size_t cols,
        const int mat[rows][cols], const size_t rags[rows],
        int *pMinSumProd) {

    int righeSelezionate = 0;
    *pMinSumProd = INT_MAX;
    //ciclo per le righe
    for (size_t i = 0; i < rows; ++i) {
        bool colonnaMultiploDi3Presente = false;
        int sum_prod = 0;
        //ciclo per le colonne
        for (size_t j = 0; j < rags[i]; ++j) {
            if (mat[i][j] % 3 == 0) {
                colonnaMultiploDi3Presente = true;
                int prod_j = 1;
                for (size_t k = 0; k < rows; ++k) {
                    if (j < rags[k]) {
                        prod_j *= mat[k][j];
                    }
                }
                sum_prod += prod_j;
            }
        }
        if (colonnaMultiploDi3Presente && sum_prod % 10 == 0) {
            righeSelezionate++;
            if (sum_prod < *pMinSumProd) {
                *pMinSumProd = sum_prod;
            }
        }
    }
    return righeSelezionate>=2;
}