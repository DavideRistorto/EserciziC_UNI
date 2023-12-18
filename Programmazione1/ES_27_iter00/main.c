#include <stdio.h>
#include <stdbool.h>

int e1(const size_t rows, const size_t cols,
	   const int mat[rows][cols], const size_t rags[rows]) {

    int somma = 0;
    bool tutteLunghe = true;
    bool tutteCon7 = true;
    for (int i = 0; i < rows && tutteLunghe; i++) {
        if (rags[i] < rows) {
            tutteLunghe = false;
        }
    }
    for (int i = 0; i < rows && tutteCon7; i++) {
        bool isOneSevenMultiplePresent = false;
        for (int j = 0; j < rags[i]; j++) {
            if (mat[i][j] % 7 == 0) {
                isOneSevenMultiplePresent = true;
            }
        }
        if (!isOneSevenMultiplePresent) {
            tutteCon7 = false;
        }
    }
    if (tutteLunghe && tutteCon7) {
        for (int i = 0; i < rows; i++) {
            bool trovato = false;
            for (int j = 0; j < rags[i] && j<cols; j++) {
                if (mat[i][j] % 7 == 0 && !trovato) {
                    somma += mat[i][j];
                    trovato = true;
                }
            }
        }
    }
    return somma;
}