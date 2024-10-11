#include <stdio.h>
#include <stdlib.h>
#include "unity.h"
#include "ordered_array.c"

/*
 * Test suite for ordered array data structure and algorithms
 */

//precedence relation used in tests
static int precedes_int(void* elem1,void* elem2){
  //cast the values from void to int
  int* intElem1 = (int*)elem1;
  int* intElem2 = (int*)elem2;
  return *intElem1 < *intElem2;
}

//Data elements that are initialized before each test
static int i1,i2,i3;
static OrderedArray *ordered_array_int;

//Data elements that are initialized before each test
void setUp(){
  i1 = -12;
  i2 = 0;
  i3 = 4;
  ordered_array_int = ordered_array_create(precedes_int);
}

static void test_empty_array_true(){
  TEST_ASSERT_TRUE(ordered_array_is_empty(ordered_array_int));
}

static void test_empty_array_false(){
 ordered_array_add(ordered_array_int,&i1);
 TEST_ASSERT_FALSE(ordered_array_is_empty(ordered_array_int));
}

static void test_size_empty(){
  TEST_ASSERT_EQUAL_INT(0, ordered_array_size(ordered_array_add));
}

static void test_size_not_empty(){
 ordered_array_add(ordered_array_int,&i1);
 TEST_ASSERT_EQUAL_INT(1, ordered_array_size(ordered_array_int));
}

static void test_ordered_array_size_two_el(void){
  ordered_array_add(ordered_array_int,&i1);
  ordered_array_add(ordered_array_int,&i2);
  TEST_ASSERT_EQUAL_INT(2,ordered_array_size(ordered_array_int));
}

int main(void) {

  //test session
  UNITY_BEGIN();
  
  RUN_TEST(test_empty_array_true);
  RUN_TEST(test_empty_array_false);
  RUN_TEST(test_size_empty);
  RUN_TEST(test_size_not_empty);
  RUN_TEST(test_ordered_array_size_two_el);

  return UNITY_END();
}







