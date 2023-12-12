#include <stdio.h>
#include <stdbool.h>

bool ricerca_binaria(const int a[], const int val, size_t *pIndice,
                const size_t left, const size_t right){
    if(left>=right){
        return false;
    }
    else{
        size_t mid = (left + right) / 2;
        if (a[mid] == val){
            *pIndice = mid;
            return true;
        } else {
          if(val>a[mid]){
              return ricerca_binaria(a, val, pIndice, mid+1, right);
          }else{
              return ricerca_binaria(a, val, pIndice, left, right);
          }
        }
    }
}