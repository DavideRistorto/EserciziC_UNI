#include <stdio.h>
#include <stdbool.h>

void leggi_matrice(const size_t rows, const size_t cols, int mat[rows][cols]) {
    for (size_t r = 0; r < rows; r++) {
        for (size_t c = 0; c < cols; c++) {
            scanf("%d", &mat[r][c]);
        }
    }
}

int main(void) {
    // leggi le dimensioni della matrice rettangolare
    size_t rows, cols;
    scanf("%zu %zu", &rows, &cols);

    // riserva la memoria per la matrice di dimensione rows * cols
    int mat[rows][cols];

    // leggi i dati
    leggi_matrice(rows, cols, mat);

    // trova e stampa le coppie di indici
    for (size_t r = 0; r < rows; r++) {
        for (size_t c = 0; c < cols; c++) {
            bool rigaNonNegativaEPari = true;
            bool colonnaNonNegativaEPari = true;

            //controllo se la riga è pari è positiva
            for(size_t i=0;i<cols;i++){
                if(mat[r][i]<0 || mat[r][i]%2!=0){
                    rigaNonNegativaEPari = false;
                }
            }
            //controllo se la colonna è pari è positiva
            for(size_t i=0;i<rows;i++){
                if(mat[i][c]<0 || mat[i][c]%2!=0){
                    colonnaNonNegativaEPari = false;
                }
            }
            if(colonnaNonNegativaEPari && rigaNonNegativaEPari){
                printf("%zu %zu\n",r,c);
            }
        }
    }

    return 0;
}
