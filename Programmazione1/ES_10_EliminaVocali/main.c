#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_SIZE 50

// ritorna true se il carattere ch è una vocale
bool is_vowel(char ch) {
#   define NUM_VOWELS 10
    const char vowels[NUM_VOWELS] = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
    bool is_v = false;
    for (size_t i=0; i<NUM_VOWELS && !is_v; i++) {
        if (ch == vowels[i])
            is_v = true;
    }
    return is_v;
}

void eliminaVocali(char string[], char stringNoVocali[]){
    int stringNoVocaliIndex = 0;
    for(int j=0;j< strlen(string);j++){
        if(!is_vowel(string[j])){
            stringNoVocali[stringNoVocaliIndex] = string[j];
            stringNoVocaliIndex++;
        }
    }
}

int main(void) {
    char stringa[MAX_SIZE];
    //NB: inizializzare la stringa seguente a "" evita errori di byte non identificati
    char stringaNoVocali[MAX_SIZE] = "";
    scanf("%s",stringa);
    eliminaVocali(stringa,stringaNoVocali);
    for(int j=0;j<strlen(stringaNoVocali);j++){
        printf("%c",stringaNoVocali[j]);
    }
}
