#include <stdio.h>
#include <stdlib.h>

#include "ordered_array.h"

/*
Realizzare la struttura dati Array Ordinato che mantiene un array ordinato di elementi.
Gli elementi di ogni array hanno tutti lo stesso tipo, ma la struttura dati deve essere generica (il
tipo e il numero massimo di elementi non possono essere assunti come noti a priori).
L’implementazione deve permettere di specificare il criterio secondo cui ordinare gli elementi.
La struttura dati deve offrire metodi/funzioni per:
_ Creare un array ordinato inizialmente vuoto
_ Testare se l’array è vuoto
_ Recuperare la dimensione dell’array
_ Aggiungere un elemento all’array
_ Recuperare l’elemento dell’array in posizione i
*/

typedef struct _OrderedArray{
  void **array;
  unsigned long capacity;
  unsigned long nElemts;
  int (*precedes)(void *, void *);  // restituisce true se primo arg. < secondo arg.
};

OrderedArray *ordered_array_create(int (*precedes)(void *, void *)){
  if(precedes == NULL){
    printf("The parameter \"preceses\" is NULL");
    exit(EXIT_FAILURE);
  }
  OrderedArray *orderedArray = (OrderedArray*)malloc(sizeof(OrderedArray));
  if(precedes == NULL){
    printf("Error during the definition of \"orderedArray\"");
    exit(EXIT_FAILURE);
  }
  orderedArray->array = (void**)malloc(2*sizeof(void*));
  orderedArray->nElemts = 0;
  orderedArray->capacity = 2;  // definisco la capacità iniziale dell'array
  return orderedArray;
}

int ordered_array_is_empty(OrderedArray *ordered_array){
  if(ordered_array == NULL){
    exit(EXIT_FAILURE);
  }
  return ordered_array->nElemts == 0;
}

unsigned long ordered_array_size(OrderedArray *ordered_array){
  if(ordered_array == NULL){
    fprintf(stderr,"ordered_array_size: ordered_array parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }
  return ordered_array->nElemts;
}

void ordered_array_add(OrderedArray *ordered_array, void* data){
  if(ordered_array == NULL){
    fprintf(stderr,"ordered_array_add: ordered_array parameter is NULL");
    exit(EXIT_FAILURE);
  }
  if(data == NULL){
    fprintf(stderr,"ordered_array_add: data parameter is NULL");
    exit(EXIT_FAILURE);
  }
  unsigned long index = get_index_to_insert(ordered_array, data);
  insert_element(ordered_array, data, index);
  ordered_array->nElemts++;
}

//get the specified element at index i in the ordered array
void* ordered_array_get(OrderedArray *ordered_array, unsigned long i){
  if(ordered_array == NULL){
    fprintf(stderr,"ordered_array_get: ordered_array parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }
  //if the requested index is over the number of elemtents, i cannot access to that index
  if(i >= ordered_array->nElemts){
    printf("Cannot accesso to index %d because there are only %d elements",i, ordered_array->nElemts);
  }
  //return the specified element
  return ordered_array->array[i];
}

void ordered_array_free_memory(OrderedArray *ordered_array){
  if(ordered_array == NULL){
    fprintf(stderr,"ordered_array_free_memory: ordered_array parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }
  free(ordered_array->array);
  free(ordered_array);
}

static unsigned long get_index_to_insert(OrderedArray *ordered_array, void* element){
  int index = 0;
  while(index < ordered_array->nElemts){
    if(ordered_array->precedes(element, (ordered_array->array)[index])){
      return index;
    }
    index++;
  }
}

//inserts the specified element in the specified ordered array at the specified
//index position
static void insert_element(OrderedArray *ordered_array, void* data, unsigned long index) {
  // Shift elements to the right to make space for the new element
  for (unsigned long i = ordered_array->nElemts; i > index; i--) {
    (ordered_array->array)[i] = (ordered_array->array)[i-1];
  }
  // Insert the new element at the specified index
  (ordered_array->array)[index] = data;
}
