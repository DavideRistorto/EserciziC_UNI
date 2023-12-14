#include <stdio.h>
#include <stdbool.h>

bool esiste_carattere(char *string, char carattere, int index) {
    if (string[index] == '\0') {
        return false;
    } else {
        if (string[index] == carattere) {
            return true;
        } else {
            return esiste_carattere(string, carattere, index + 1);
        }
    }
}
//funzione per shiftare tutti i caratteri indietro di uno
void copia_caratteri_ricorsiva(char *dest, char *src) {
    if (*src == '\0') {
        *dest = '\0';
        return;
    }
    *dest = *src;
    copia_caratteri_ricorsiva(dest + 1, src + 1);
}

void e2R(char *string, int index) {
    if (string[index] == '\0') {
        return;
    } else {
        if (esiste_carattere(string, string[index], index + 1)) {
            copia_caratteri_ricorsiva(string + index, string + index + 1);
        } else {
            ++index;
        }
        e2R(string, index);
    }
}

void e2(char *pStr) {
    e2R(pStr, 0);
}
