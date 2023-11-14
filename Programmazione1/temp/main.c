#include <stdio.h>

int main() {

    int contaPari=0,contaDispari=0;
    int numero=0;
    while (numero<100){
        scanf("%d",&numero);
        if(numero%2==0){
            contaPari++;
        }
        else{
            contaDispari++;
        }
    }
    printf("ci sono %d numeri pari e %d numeri dispari", contaPari, contaDispari);
    return 0;
}