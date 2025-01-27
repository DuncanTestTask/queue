#include "minunit.h"
#include "queue.h"
#include <stdio.h>

int tests_run = 0; // must be specified for minunit.h 


static char *test_queue_init_basic1() {
    const int queue_size = 100;
  struct queue *q = queue_init(queue_size);
  mu_assert("size", q->high ==  queue_size);
  //queue_free(q);
  return 0;
}

static char *tests() {
  mu_run_test(test_queue_init_basic1);
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

