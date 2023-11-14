#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define WORD_MAX 50


void capovolgi(char string[],char capovolta[]){
    for(int j=0;j<strlen(string);j++){
        capovolta[j] = string[strlen(string)-1-j];
    }
}

bool isPalindroma(char string[],char capovolta[]){
    bool palindroma=true;
    for(int i=0;i< strlen(string);i++){
        if(string[i]!=capovolta[i]){
            palindroma = false;
        }
    }
    return palindroma;
}

int main() {

    char stringa[WORD_MAX];
    char capovolta[WORD_MAX];
    scanf("%s",stringa);
    capovolgi(stringa,capovolta);
    if(isPalindroma(stringa,capovolta)){
        printf("PALINDROMA");
    }else{
        //da errori su caratteri speciali
        //printf("%s %s ",stringa,capovolta);
        //stampo carattere per carattere

        for(int i=0;i<strlen(stringa);i++){
            printf("%c",stringa[i]);
        }
        printf(" ");
        for(int i=0;i<strlen(capovolta);i++){
            printf("%c",capovolta[i]);
        }

    }
    return 0;
}
