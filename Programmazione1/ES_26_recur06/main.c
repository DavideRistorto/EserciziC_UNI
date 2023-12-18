#include <stdio.h>

void shiftArray(int array[], size_t* dim, int index) {
    if (index == *dim - 1) {
        *dim -= 1;
        return;
    } else {
        array[index] = array[index + 1];
        shiftArray(array, dim, index + 1);
    }
}

void e2R(size_t *p_aVal, int a[], const int min, const int max, int index) {
    if (index == *p_aVal) {
        return;
    } else {
        if (a[index] > max || a[index] < min) {
            shiftArray(a, p_aVal, index);
            e2R(p_aVal, a, min, max, index);
        } else {
            e2R(p_aVal, a, min, max, index + 1);
        }
    }
}

void e2(size_t *p_aVal, int a[], const int min, const int max) {
    e2R(p_aVal, a, min, max, 0);
}


