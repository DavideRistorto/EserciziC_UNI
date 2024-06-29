#include <stdio.h>
#include <stdlib.h>

int func(int a, int* b) {
  int c = a + *b;
  printf("c = %d\n", c);
  return c;
}


int main() {
  int x = 5;
  int* y = &x;
  //NULL NON DA ERRORE PERCHE' NULL E' UN PUNTATORE
  func(x,NULL);
  return 0;
}