#include <stdio.h>

#include "minunit.h"
#include "queue.h"

#define QUEUE_ERROR_CHECK(error) \
	switch (error) { \
		case 0: \
			mu_assert("no error", error == 0); \
			break; \
		case 1: \
			mu_assert("init case error", error == 0); \
			break; \
		case 2: \
			mu_assert("add case error", error == 0); \
			break; \
		case 3: \
			mu_assert("get case error", error == 0); \
			break; \
		default: \
			mu_assert("no error", error == 0); \
			break; \
	}

#define QUEUE_ERROR_CHECK_ONLY(error) \
	if (error > 0) { \
		mu_assert("check error", error == 0); \
	}

int tests_run = 0;	// must be specified for minunit.h

static char *test_queue_init_basic1() {
	const int queue_size = 100;
	struct queue *test_queue = queue_init(queue_size);
  QUEUE_ERROR_CHECK_ONLY(test_queue->error);
	mu_assert("error state", test_queue->error == 0);
	mu_assert("max size", test_queue->max == queue_size);
	mu_assert("count", test_queue->count == 0);
	mu_assert("hight mark", test_queue->high == queue_size - 1);
	mu_assert("low mark", test_queue->low == queue_size - 1);
	queue_free(test_queue);
	// mu_assert("free", test_queue ==  NULL);
	return 0;
}

static char *test_queue_add1() {
	const int queue_size = 5;
	struct queue *test_queue = queue_init(queue_size);
  QUEUE_ERROR_CHECK_ONLY(test_queue->error);
	queue_add(test_queue, 1);
  QUEUE_ERROR_CHECK_ONLY(test_queue->error);
	mu_assert("error state", test_queue->error == 0);
	mu_assert("max size", test_queue->max == queue_size);
	mu_assert("count", test_queue->count == 1);
	mu_assert("hight mark", test_queue->high == queue_size - 1);
	mu_assert("low mark", test_queue->low == queue_size - 1 - 1);
	queue_free(test_queue);
	return 0;
}

static char *test_queue_add2() {
	const int queue_size = 5;
	struct queue *test_queue = queue_init(queue_size);
  QUEUE_ERROR_CHECK_ONLY(test_queue->error);
	queue_add(test_queue, 1);
  QUEUE_ERROR_CHECK_ONLY(test_queue->error);
	queue_add(test_queue, 1);
  QUEUE_ERROR_CHECK_ONLY(test_queue->error);
	mu_assert("error state", test_queue->error == 0);
	mu_assert("max size", test_queue->max == queue_size);
	mu_assert("count", test_queue->count == 2);
	mu_assert("hight mark", test_queue->high == queue_size - 1);
	mu_assert("low mark", test_queue->low == queue_size - 1 - 2);
	queue_free(test_queue);
	return 0;
}

static char *test_queue_get1() {
	const int queue_size = 5;
	const int a = 99;  // test value
	struct queue *test_queue = queue_init(queue_size);
  QUEUE_ERROR_CHECK_ONLY(test_queue->error);
	queue_add(test_queue, a);
  QUEUE_ERROR_CHECK_ONLY(test_queue->error);
	int b = queue_get(test_queue);
  QUEUE_ERROR_CHECK_ONLY(test_queue->error);
	mu_assert("check value", a == b);
	mu_assert("error state", test_queue->error == 0);
	mu_assert("max size", test_queue->max == queue_size);
	mu_assert("count", test_queue->count == 0);
	mu_assert("hight mark", test_queue->high == queue_size - 1 - 1);
	mu_assert("low mark", test_queue->low == queue_size - 1 - 1);
	queue_free(test_queue);
	return 0;
}

static char *test_queue_get2() {
	const int queue_size = 5;
	const int a = 99;	// test value
	const int a2 = 88;	// test value
	struct queue *test_queue = queue_init(queue_size);
  QUEUE_ERROR_CHECK_ONLY(test_queue->error);
	queue_add(test_queue, a);
  QUEUE_ERROR_CHECK_ONLY(test_queue->error);
	queue_add(test_queue, a2);
  QUEUE_ERROR_CHECK_ONLY(test_queue->error);
	int b = queue_get(test_queue);
  QUEUE_ERROR_CHECK_ONLY(test_queue->error);
	mu_assert("check value", a == b);
	mu_assert("error state", test_queue->error == 0);
	mu_assert("max size", test_queue->max == queue_size);
	mu_assert("count", test_queue->count == 1);
	mu_assert("hight mark", test_queue->high == queue_size - 1 - 1);
	mu_assert("low mark", test_queue->low == queue_size - 1 - 2);
	int b2 = queue_get(test_queue);
  QUEUE_ERROR_CHECK_ONLY(test_queue->error);
	mu_assert("check value", a2 == b2);
	mu_assert("error state", test_queue->error == 0);
	mu_assert("max size", test_queue->max == queue_size);
	mu_assert("count", test_queue->count == 0);
	mu_assert("hight mark", test_queue->high == queue_size - 1 - 2);
	mu_assert("low mark", test_queue->low == queue_size - 1 - 2);
	queue_free(test_queue);
	return 0;
}

static char *test_queue_overflow() {
	const int queue_size = 3;
	struct queue *test_queue = queue_init(queue_size);
	QUEUE_ERROR_CHECK_ONLY(test_queue->error);
	for (int i = 0; i < queue_size; i++) {
		queue_add(test_queue, i);
		QUEUE_ERROR_CHECK_ONLY(test_queue->error);
	}
	queue_add(test_queue, 1);
	mu_assert("expected error state", test_queue->error == 2);
	queue_free(test_queue);
	return 0;
}

static char *test_queue_get_from_empty() {
	const int queue_size = 3;
	struct queue *test_queue = queue_init(queue_size);
	QUEUE_ERROR_CHECK_ONLY(test_queue->error);
	int value = queue_get(test_queue);
	mu_assert("expected error state", test_queue->error == 3);
	mu_assert("max size", test_queue->max == queue_size);
	mu_assert("count", test_queue->count == 0);
	mu_assert("hight mark", test_queue->high == queue_size - 1);
	mu_assert("low mark", test_queue->low == queue_size - 1);
	queue_free(test_queue);
	return 0;
}

static char *tests() {
	mu_run_test(test_queue_init_basic1);
	mu_run_test(test_queue_add1);
	mu_run_test(test_queue_add2);
	mu_run_test(test_queue_get1);
	mu_run_test(test_queue_get2);
	mu_run_test(test_queue_overflow);
	mu_run_test(test_queue_get_from_empty);
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
