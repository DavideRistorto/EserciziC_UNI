#include <stdio.h>

// Implementazione delle funzioni ricorsive
void leggi_arrayR(int n, int a[]) {
    n--;
    if (n>=0) {
        scanf("%d", &a[n]);
        leggi_arrayR(n, a);
    }
}

int somma_arrayR(int a[], int n) {
    n--;
    if (n<0) {
        return 0;
    } else {
        return a[n] + somma_arrayR(a, n);
    }
}

int esiste_val_in_arrayR(int a[], int n, int val) {
    n--;
    if (n<0) {
        return 0;
    } else {
        if (a[n] == val) {
            return 1;
        } else {
            return esiste_val_in_arrayR(a, n, val);
        }
    }
}

int sottoinsiemeR(int aLen, int a[], int bLen, int b[]) {
    aLen--;
    if (aLen < 0) {
        return 1;
    } else{
        if (!esiste_val_in_arrayR(b,bLen,a[aLen])){
            return 0;
        } else{
           return sottoinsiemeR(aLen,a,bLen, b);
        }
    }
}

//Le funzione involucro servono per fare da tramite tra il main e la funzione ricorsiva
void leggi_array(int n, int a[]) {
    leggi_arrayR(n, a);
}

int somma_array(int a[], int n) {
    return somma_arrayR(a, n);
}

int esiste_val_in_array(int a[], int n, int val) {
    return esiste_val_in_arrayR(a, n, val);
}

int sottoinsieme(int aLen, int a[], int bLen, int b[]) {
    return sottoinsiemeR(aLen, a, bLen, b);
}

int main() {
    int len_a, len_b;
    scanf("%d", &len_a);
    int a[len_a];
    leggi_array(len_a, a);
    scanf("%d", &len_b);
    int b[len_b];
    leggi_array(len_b, b);

    printf("%d %d\n", somma_array(a, len_a) , somma_array(b, len_b));
    printf("%d %d\n", sottoinsieme(len_a, a, len_b, b), sottoinsieme(len_b, b, len_a, a));

    return 0;
}
