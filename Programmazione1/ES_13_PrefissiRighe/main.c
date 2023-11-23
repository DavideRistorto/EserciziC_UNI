#include <stdio.h>
#include <stdbool.h>

void leggi_matrice_irregolare(const size_t rows, const size_t cols,
                              int mat[rows][cols], size_t rags[rows])
{
    for (size_t r = 0; r < rows; r++) {
        scanf("%zu", &rags[r]);
        for (size_t c = 0; c < rags[r]; c++) {
            scanf("%d", &mat[r][c]);
        }
    }
}
//ragsA e ragsB sono le dimensioni delle singole righe
bool riga_prefisso(int ragsA, int ragsB, int rowA[], int rowB[]) {
    bool prefisso = true;
    if (ragsA > ragsB) {
        prefisso = false;
    }
    // se scorrendo c'è un carattere che non coincice non è un prefisso
    for (int i = 0; i < ragsA; i++) {
        if (rowA[i] != rowB[i]) {
            prefisso = false;
        }
    }
    return prefisso;
}

int main(void) {
    // leggi la matrice irregolare A
    size_t rowsA, colsA;
    scanf("%zu %zu", &rowsA, &colsA);
    int matA[rowsA][colsA];
    size_t ragsA[rowsA];
    leggi_matrice_irregolare(rowsA, colsA, matA, ragsA);

    // leggi la matrice irregolare B
    size_t rowsB, colsB;
    scanf("%zu %zu", &rowsB, &colsB);
    int matB[rowsB][colsB];
    size_t ragsB[rowsB];
    leggi_matrice_irregolare(rowsB, colsB, matB, ragsB);
    //per ogni riga di di matB confronto tutte le righe di matA
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < rowsA; j++) {
            if (riga_prefisso(ragsA[j], ragsB[i], matA[j], matB[i])) {
                printf("%d %d\n", j, i);
            }
        }
    }
    return 0;
}
