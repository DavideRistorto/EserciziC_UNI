#include <stdio.h>

// Funzione swap per scambiare due elementi in un array
void swap(int A[], int i, int j) {
  int temp = A[i];
  A[i] = A[j];
  A[j] = temp;
}

// Ordina l'array in modo che tutti i numeri pari siano prima di tutti i numeri dispari
// in complessità O(n)
void OddEven(int A[], int n) {
  int currentOdd = 0;
  for (int i = 0; i < n; i++) {
    if (A[i] % 2 == 0) {
      // metto l' elemento pari in testa
      swap(A, i, currentOdd);
      currentOdd++;
    }
  }
}

// Funzione main per testare
int main() {
  int A[] = {3, 1, 2, 4, 6, 5};
  int n = sizeof(A) / sizeof(A[0]);

  printf("Array prima di OddEven: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", A[i]);
  }
  printf("\n");

  OddEven(A, n);

  printf("Array dopo OddEven: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", A[i]);
  }
  printf("\n");

  return 0;
}