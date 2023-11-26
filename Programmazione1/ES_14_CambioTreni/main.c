#include <stdio.h>
#include <stdbool.h>

void leggi_matrice_irregolare(const size_t rows, const size_t cols,int mat[rows][cols], size_t rags[rows]){
    for (size_t r = 0; r < rows; r++) {
        scanf("%zu", &rags[r]);
        for (size_t c = 0; c < rags[r]; c++) {
            scanf("%d", &mat[r][c]);
        }
    }
}

char trova_connessione(const size_t rows,const size_t cols , int mat[rows][cols], size_t rags[rows], size_t from, size_t to){
    // X come valore di default se non ci sono collegamenti tra le città
    char valore = 'X';
    // prima controllo se c'e' un l'incotro diretto
    for(int i=0; i < rags[from]; i++){
        if(mat[from][i] == to){
            valore = 'D';
        }
    }
    // se non c'e' controllo se c'è un valore in comune tra i due array
    // corrispondenti alle città
    if (valore == 'X'){
        for(int i=0; i < rags[from]; i++){
            for(int j=0; j<rags[to]; j++){
               if(mat[from][i] == mat[to][j]) {
                    valore = 'C';
               }
            }
        }
    }
    return valore;
}

int main(void) {
    size_t rows, cols;
    //numero righe e colonne
    scanf("%zu %zu", &rows, &cols);
    int mat[rows][cols];
    size_t rags[rows];
    // richiedo la matrice irregolare
    leggi_matrice_irregolare(rows, cols, mat, rags);
    //q e' il numero di interrogazioni da fare
    size_t q, from, to;
    scanf("%zu", &q);
    for (size_t i = 0; i < q; i++) {
        // richiedo le tue città in input
        scanf("%zu %zu", &from, &to);
        // calcolo la distanza
        char collegamento = trova_connessione(rows, cols, mat, rags, from, to);
        if (collegamento == 'D') {
            printf("DIRETTO\n");
        } else if (collegamento == 'C'){
            printf("UN CAMBIO\n");
        }
        else {
            printf("NO\n");
        }
    }
    return 0;
}
