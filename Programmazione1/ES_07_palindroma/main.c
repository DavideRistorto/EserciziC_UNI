#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define WORD_MAX 51


void capovolgi(char string[],char capovolta[]){
    for(int j=0;j<strlen(string);j++){
        int i = strlen(string)-1-j;
        capovolta[j] = string[i];
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
    char stringa[WORD_MAX] = {0};
    char capovolta[WORD_MAX] = {0};
    scanf("%s",stringa);
    capovolgi(stringa,capovolta);
    if(isPalindroma(stringa,capovolta)){
        printf("PALINDROMA");
    }else{
        printf("%s %s",stringa,capovolta);
    }
    return 0;
}
