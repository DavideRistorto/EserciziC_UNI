#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define WORD_MAX 50


void capovolgi(char string[],char capovolta[]){
    for(int j=0;string[j]!='\0';j++){
        capovolta[j] = string[strlen(string)-1-j];
    }
}

bool isPalindroma(char string[],char capovolta[]){
    bool palindroma=true;
    for(int i=0;string[i]!='\0';i++){
        if(string[i]!=capovolta[i]){
            palindroma = false;
        }
    }
    return palindroma;
}

int main() {

    char stringa[WORD_MAX] = {0};
    char capovolta[WORD_MAX] = {0};
    scanf("%s",stringa);
    capovolgi(stringa,capovolta);
    if(isPalindroma(stringa,capovolta)){
        printf("PALINDROMA");
    }else{
        //da errori su caratteri speciali
        printf("%zu %zu\n",strlen(stringa),strlen(capovolta));
        printf("%s %s",stringa,capovolta);
        //stampo carattere per carattere
        /*
        for(int i=0;stringa[j]!='\0';i++){
            printf("%c",stringa[i]);
        }
        printf(" ");
        for(int i=0;capovolta[i]!='\0';i++){
            printf("%c",capovolta[i]);
        }
         */

    }
    return 0;
}
