#include <stdio.h>
#include "ctype.h"
#include "stdbool.h"
#include "string.h"

int main() {


    char password[20];
    scanf("%s",password);

    //almeno una cifra
    bool cifra = false;
    for(int i=0;i< strlen(password) && !cifra; i++){
        if(isdigit(password[i])){
            cifra = true;
        }
    }
    //tutti i caratteri lettere
    bool tutteLettere = true;
    for(int i=0;i< strlen(password); i++){
        if(!isalpha(password[i])){
            tutteLettere = false;
        }
    }
    //ci sono due lettere maiuscole
    int maiuscole = 0;
    bool almenoDueMaiuscole = false;
    for(int i=0;i< strlen(password); i++){
        if(isupper(password[i])){
            maiuscole++;
        }
    }
    if(maiuscole>=2){
        almenoDueMaiuscole = true;
    }
    // ci sono almeno due cifre consecutive
    bool dueCifreConsecutive = false;
    for(int i=0;i< strlen(password)-1 && !dueCifreConsecutive; i++){
        if(isdigit(password[i]) && isdigit(password[i+1])){
            dueCifreConsecutive = true;
        }
    }
    //gli ultimi due caratteri sono segni di punteggiatura
    int len = strlen(password);
    bool ultimeDuePunti = false;
    if(ispunct(password[len-1]) && ispunct(password[len-2])){
        ultimeDuePunti = true;
    }

    printf("%s ",password);
    if(cifra){
        printf("1 ");
    }else{
        printf("0 ");
    }
    if(tutteLettere){
        printf("1 ");
    }else{
        printf("0 ");
    }
    if(almenoDueMaiuscole){
        printf("1 ");
    }else{
        printf("0 ");
    }
    if(dueCifreConsecutive){
        printf("1 ");
    }else{
        printf("0 ");
    }
    if(ultimeDuePunti){
        printf("1 ");
    }else{
        printf("0 ");
    }

    return 0;
}
