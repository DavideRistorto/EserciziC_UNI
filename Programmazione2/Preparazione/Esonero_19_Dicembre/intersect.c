#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Ritorna un array che rappresenta gli elementi disgiunti tra gli insiemi
 * Esempio: arr1 : {1,2,3,4}
 *          arr2: {1,2,5,6}
 * Return : {3,4,5,6}
 */
int* difference(int* arr1, int n1, int* arr2, int n2) {
  int len = n1 + n2;
  int* newarr = malloc(len * sizeof(int));
  int lastIndex = 0;
  for (int i = 0; i < n1; i++) {
    bool find = false;
    for (int j = 0; j < n2; j++) {
      if (arr1[i] == arr2[j]) {
        find = true;
      }
    }
    if (!find) {
      newarr[lastIndex] = arr1[i];
      lastIndex++;
    }
  }
  for (int i = 0; i < n2; i++) {
    bool find = false;
    for (int j = 0; j < n1; j++) {
      if (arr2[i] == arr1[j]) {
        find = true;
      }
    }
    if (!find) {
      newarr[lastIndex] = arr2[i];
      lastIndex++;
    }
  }
  return newarr;
}

/**
 * Ritorna un array che rappresenta l' intersezione di 2 array:
 * Esempio: arr1 : {1,2,3,4}
 *          arr2: {1,2,7,8,3}
 * Return : {1,2,3}
 */
int* intersect(int* arr1, int n1, int* arr2, int n2) {
  int len = n1 >= n2 ? n1 : n2;
  int* newarr = malloc(len * sizeof(int));
  int lastindex = 0;
  for (int i = 0; i < n1; i++) {
    for (int j = 0; j < n2; j++) {
      if (arr1[i] == arr2[j]) {
        newarr[lastindex] = arr1[i];
        lastindex++;
      }
    }
  }
  return newarr;
}

int main() {
  int arr1[] = {1, 2, 3, 4, 8};
  int arr2[] = {1, 2, 7, 8, 3};
  int n1 = 5;
  int n2 = 5;

  int* result = intersect(arr1, n1, arr2, n2);
  int resultSize = 4;

  printf("Intersection of the arrays: ");
  for (int i = 0; i < resultSize; i++) {
    printf("%d ", result[i]);
  }
  printf("\n");

  int arr3[] = {1, 2, 3, 4};
  int arr4[] = {1, 2, 5, 6};
  int n3 = 4;
  int n4 = 4;
  int* result2 = difference(arr3, n3, arr4, n4);
  int resultSize2 = 4;
  printf("Difference of the arrays: ");
  for (int i = 0; i < resultSize2; i++) {
    printf("%d ", result2[i]);
  }
  free(result);
  return 0;
}