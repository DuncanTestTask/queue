#include "minunit.h"
#include "queue.h"
#include <stdio.h>

int tests_run = 0; // must be specified for minunit.h 


static char *test_queue_init_basic1() {
  const int queue_size = 100;
  struct queue *test_queue = queue_init(queue_size);
  mu_assert("max size", test_queue->max ==  queue_size);
  mu_assert("count", test_queue->count ==  0);
  mu_assert("hight mark", test_queue->high ==  queue_size -1);
  mu_assert("low mark", test_queue->low ==  queue_size -1);
  queue_free(test_queue);
  // mu_assert("free", test_queue ==  NULL);
  return 0;
}

static char *test_queue_add1() {
  const int queue_size = 5;
  struct queue *test_queue = queue_init(queue_size);
  queue_add(test_queue, 1);
  mu_assert("max size", test_queue->max ==  queue_size);
  mu_assert("count", test_queue->count ==  1);
  mu_assert("hight mark", test_queue->high ==  queue_size -1);
  mu_assert("low mark", test_queue->low ==  queue_size -1-1);
  queue_free(test_queue);
  return 0;
}

static char *test_queue_add2() {
  const int queue_size = 5;
  struct queue *test_queue = queue_init(queue_size);
  queue_add(test_queue, 1);
  queue_add(test_queue, 1);
  mu_assert("max size", test_queue->max ==  queue_size);
  mu_assert("count", test_queue->count ==  2);
  mu_assert("hight mark", test_queue->high ==  queue_size -1);
  mu_assert("low mark", test_queue->low ==  queue_size -1-2);
  queue_free(test_queue);
  return 0;
}


static char *test_queue_get1() {
  const int queue_size = 5;
  const int a = 99; //test value
  struct queue *test_queue = queue_init(queue_size);
  queue_add(test_queue, a);
  int b = queue_get(test_queue);
  mu_assert("check value", a ==  b);
  mu_assert("max size", test_queue->max ==  queue_size);
  mu_assert("count", test_queue->count ==  0);
  mu_assert("hight mark", test_queue->high ==  queue_size -1-1);
  mu_assert("low mark", test_queue->low ==  queue_size -1-1);
  queue_free(test_queue);
  return 0;
}

static char *test_queue_get2() {
  const int queue_size = 5;
  const int a = 99; //test value
  const int a2 = 88; //test value
  struct queue *test_queue = queue_init(queue_size);
  queue_add(test_queue, a);
  queue_add(test_queue, a2);
  int b = queue_get(test_queue);
  mu_assert("check value", a ==  b);
  mu_assert("max size", test_queue->max ==  queue_size);
  mu_assert("count", test_queue->count ==  1);
  mu_assert("hight mark", test_queue->high ==  queue_size -1-1);
  mu_assert("low mark", test_queue->low ==  queue_size -1-2);
  int b2 = queue_get(test_queue);
  mu_assert("check value", a2 ==  b2);
  mu_assert("max size", test_queue->max ==  queue_size);
  mu_assert("count", test_queue->count ==  0);
  mu_assert("hight mark", test_queue->high ==  queue_size -1-2);
  mu_assert("low mark", test_queue->low ==  queue_size -1-2);
  queue_free(test_queue);
  return 0;
}


static char *tests() {
  mu_run_test(test_queue_init_basic1);
  mu_run_test(test_queue_add1);
  mu_run_test(test_queue_add2);
  mu_run_test(test_queue_get1);
  mu_run_test(test_queue_get2);
  return 0;
}

int main(int argc, char **argv) {
  char *result = tests();
  if (result != 0) {
    printf("%s\n", result);
  } else {
    printf("ALL PASSED\n");
  }
  printf("Tests: %d\n", tests_run);

  return result != 0;
}

