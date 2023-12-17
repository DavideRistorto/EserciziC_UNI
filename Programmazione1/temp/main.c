#include <stdio.h>
#include <stdbool.h>
#define NMAX 50

int main() {
    int subseq[NMAX];
    int max_err;
    int len;
    int errors = 0;

    // Leggi subseq
    scanf("%d", &len);
    for (int i = 0; i < len; i++) {
        scanf("%d", &subseq[i]);
    }
    scanf("%d", &max_err);
    while (true) {
        int seq[NMAX];
        int seq_len;
        // Leggi la sequenza corrente
        scanf("%d", &seq_len);
        if (seq_len == 0) {
            break;
        }
        // Leggi seq
        for (int i = 0; i < seq_len; i++) {
            scanf("%d", &seq[i]);
        }
        // Cerca il match con massimo max_err errori
        for (int i = 0; i <= seq_len - len; i++) {
            errors = 0;
            // Confronta gli elementi della sequenza corrente con quelli della subseq
            for (int j = 0; j < len; j++) {
                if (subseq[j] != seq[j+i]) {
                    errors++;
                }
            }
            // Se il numero di errori è inferiore o uguale a max_err, stampa l'intervallo e il numero di errori
            if (errors <= max_err) {
                printf("[%d, %d) errori=%d\n", i, i + len, errors);
                break; // Esci dal loop interno, abbiamo trovato un match
            }
        }
        // Se non è stato trovato alcun match con massimo max_err errori, stampa "NO"
        if (errors > max_err) {
            printf("NO\n");
        }
    }

    return 0;
}
