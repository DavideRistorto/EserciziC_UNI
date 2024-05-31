#include "list_rec.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>


//fucntion that make a list
ListNodePtr mkList(){
  ListNodePtr list = (ListNodePtr)malloc(sizeof(ListNode));
  list->next = NULL;
  return list;
}

//print list
void printList(ListNodePtr list){
  ListNodePtr current = list;
  while(current != NULL){
    printf("%d ", current->data);
    current = current->next;
  }
}

ListNodePtr fromTo_rec(int m, int n){
  if(m > n){
    return NULL;
  }
  ListNodePtr newNode = (ListNodePtr)malloc(sizeof(ListNode));
  newNode->data = m;
  newNode->next = fromTo_rec(m+1, n);
  return newNode;
}

ListNodePtr fromTo(int m, int n){
  return fromTo_rec(m, n);
}

_Bool included_rec(ListNodePtr ls1, ListNodePtr ls2){
  if(ls1 == NULL && ls2 == NULL){
    return 1;
  }
  if(ls1 == NULL || ls2 == NULL || ls1->data != ls2->data){
    return 0;
  }
  returnincluded_rec(ls1->next, ls2->next);
}

int occurrences_rec(ListNodePtr ls, int x){
  if(ls == NULL){
    return 0;
  }
  if(ls->data == x){
    return 1+occurrences_rec(ls->next,x);
  }
  return occurrences_rec(ls->next,x);
}

int occurrences(ListNodePtr ls, int x){
  return occurrences_rec(ls, x);
}

void remove_all_rec(ListNodePtr *p_ls, int x){
  if(*p_ls == NULL){
    return;
  }
  if((*p_ls)->data == x){
    p_ls = (*p_ls)->next;
  }
  return remove_all_rec(&(*p_ls)->next,x);
}

void duplicate_even_rec(ListNodePtr ls){
  if(ls == NULL){
    return;
  }
  if(ls->data % 2 == 0){
    ListNodePtr duplicate = (ListNodePtr)malloc(sizeof(ListNode));
    duplicate->data = ls->data;
    duplicate->next = ls->next;
    ls->next = duplicate;
    duplicate_even_rec(duplicate->next);
  }else{
    duplicate_even_rec(ls->next);
  }
}

void zipSum_rec2(ListNodePtr ls1, ListNodePtr ls2, ListNodePtr newList) {
  if (ls1 == NULL || ls2 == NULL) {
    return;
  }
  ListNodePtr newNode = (ListNodePtr)malloc(sizeof(ListNode));
  newNode->data = ls1->data + ls2->data;
  newList->next = newNode;
  zipSum_rec2(ls1->next, ls2->next, newList->next);  
}


ListNodePtr zipSum_rec(ListNodePtr ls1, ListNodePtr ls2) {
  if (ls1 == NULL || ls2 == NULL) {
    return NULL;
  }
  ListNodePtr newNode = (ListNodePtr)malloc(sizeof(ListNode));
  newNode->data = ls1->data + ls2->data;
  newNode->next = zipSum_rec(ls1->next,ls2->next);
  
  return newNode;
}

ListNodePtr zipSum(ListNodePtr ls1, ListNodePtr ls2){
  return zipSum_rec(ls1, ls2);
}




int main() {
  ListNodePtr list = mkList();
  list = fromTo(1, 5);
  printList(list);

  
  return 0;
}