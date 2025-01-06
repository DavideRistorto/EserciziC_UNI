#include <stdio.h>
#include <stdlib.h>

// Funzione per scambiare due elementi
void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Funzione per ripristinare la proprietà di heap
void heapify(int arr[], int n, int i) {
  int largest = i;        // Inizializza il più grande come radice
  int left = 2 * i + 1;   // Figlio sinistro
  int right = 2 * i + 2;  // Figlio destro

  // Se il figlio sinistro è più grande della radice
  if (left < n && arr[left] > arr[largest]) largest = left;

  // Se il figlio destro è più grande del più grande finora
  if (right < n && arr[right] > arr[largest]) largest = right;

  // Se il più grande non è la radice
  if (largest != i) {
    swap(&arr[i], &arr[largest]);
    // Ripristina ricorsivamente la proprietà di heap
    heapify(arr, n, largest);
  }
}

// Funzione per costruire un heap
void buildHeap(int arr[], int n) {
  // Parti dall'ultimo nodo non foglia e heapify tutti i nodi
  for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
}

// Funzione per estrarre il massimo da un heap
int extractMax(int arr[], int* n) {
  if (*n <= 0) return -1;  // Heap vuoto

  // La radice è il massimo
  int max = arr[0];

  // Sostituisci la radice con l'ultimo elemento
  arr[0] = arr[*n - 1];
  (*n)--;

  // Ripristina la proprietà di heap
  heapify(arr, *n, 0);

  return max;
}

// Funzione principale per testare l'implementazione
int main() {
  int arr[] = {10, 20, 15, 30, 40};
  int n = sizeof(arr) / sizeof(arr[0]);

  // Costruisci il heap
  buildHeap(arr, n);

  printf("Max-Heap: ");
  for (int i = 0; i < n; i++) printf("%d ", arr[i]);
  printf("\n");

  // Estrai il massimo
  printf("Elemento massimo estratto: %d\n", extractMax(arr, &n));

  printf("Heap dopo l'estrazione: ");
  for (int i = 0; i < n; i++) printf("%d ", arr[i]);
  printf("\n");

  return 0;
}