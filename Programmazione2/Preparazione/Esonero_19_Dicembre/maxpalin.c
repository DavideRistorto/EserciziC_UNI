#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*  INSERIRE QUI EVENTUALI FUNZIONI AUSILIARIE (CON UN COMMENTO SIGNIFICATIVO IN TESTA) */

/**
 * @brief Dati: un array di caratteri A, la sua lunghezza N, e un indice valido i (contenuto in [0, N-1]);
 * Supponendo: N>0;
 * Restituire la massima stringa palindroma in i, se ne esiste una di lunghezza >1, NULL altrimenti.
 * Nel primo caso è necessario eseguire malloc per allocare lo spazio necessario alla stringa restituita.
 *
 * SPIEGAZIONI:
 * Palindroma significa che l’ultimo carattere è uguale al primo, il penultimo al secondo, ecc. (es. kayak).
 * Invece “Palindromo in i” significa considerare il carattere in i come centrale. Ad esempio DEGRADARE ha 9
 * caratteri, se i==5 (cioè identifica la seconda ‘D’), la massima palindroma in i è RADAR. Se i==2 invece
 * non vi è palindroma perché G è preceduta da E e seguita da R che sono diverse. Notare che secondo questa
 * definizione, non vengono considerati palindromi di lunghezza pari (che non hanno un carattere centrale).
 *
 * ESEMPI:
 * (1) dati [‘T’,’A’,’F’,’A’,’N’,’O’], 6, 2   restituisce “AFA”
 * (2) dati [‘T’,’A’,’F’,’A’,’N’,’O’], 6, 4   restituisce NULL
 * (3) dati [‘P’,’O’,’S’,’S’,’E’,’S’,’S’,’O’] 8, 4 restituisce “OSSESSO”
 *
 * AVVERTENZA: attenzione alla differenza tra array di caratteri e stringa.
 */
char *maxpalin(char *A, int N, int i)
{
  int left = i - 1;
  int right = i + 1;
  if (A[left] != A[right])
  {
    return NULL;
  }

  int palLeft = left;
  int palRight = right;
  left--;
  right++;
  while (left >= 0 && right < N)
  {
    if (A[left] != A[right])
    {
      break;
    }
    palLeft = left;
    palRight = right;
    left--;
    right++;
  }
  int len = (palRight - palLeft) + 1;
  char *palinmax = malloc(len * sizeof(char));
  int j = 0;
  while (j < len)
  {
    palinmax[j] = A[j + palLeft];
    j++;
  }
  palinmax[j] = '\0';
  return palinmax;
}

int main()
{
  char *S = "POSSESSO";
  int len = 8;
  int index = 4;
  char *newstring = maxpalin(S, len, index);
  printf("  %s", newstring);
  free(newstring);
  return 0;
}