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
  //func(x,NULL);

  int a[5] = {1, 2, 3, 4, 5};
  int b[5] = a;
 if(a!=b){
    printf("a e b sono diversi\n");
  }else{
    printf("a e b sono uguali\n");
 }
  
  return 0;
}