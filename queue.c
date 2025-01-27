#include "queue.h"

#include <stdio.h>
#if defined(DEBUG)
#define DEBUG_PRINTF(x) printf x
#else
#define DEBUG_PRINTF(x)
#endif

struct queue *queue_init(size_t size) {
	struct queue *return_value = calloc(1, sizeof(struct queue));
	return_value->data = calloc(size, sizeof(size));
	return_value->low = return_value->high = size - 1;
	return_value->max = size;
	DEBUG_PRINTF(("DEBUG: queue_init size=%ld\n", size));
	return return_value;
}
void queue_free(struct queue *queue) {
	DEBUG_PRINTF(("DEBUG: queue_free\n"));
	free(queue->data);
	free(queue);
}

void queue_add(struct queue *queue, int item) {
	DEBUG_PRINTF(("DEBUG: queue_add %d begin capacity=%d/%d range=%d/%d\n", item, queue->count, queue->max, queue->low, queue->high));
	if (queue->count == queue->max) {
		fprintf(stderr, "not enough free space\n");
		return;
	}
	queue->data[queue->low--] = item;
	queue->count++;
	if (queue->low < 0) {
		queue->low = queue->max - 1;
	}
	DEBUG_PRINTF(("DEBUG: queue_add end capacity=%d/%d rang=%d/%d\n", queue->count, queue->max, queue->low, queue->high));
}
int queue_get(struct queue *queue) {
	DEBUG_PRINTF(("DEBUG: queue_get begin capacity=%d/%d range=%d/%d\n", queue->count, queue->max, queue->low, queue->high));
	int return_value = queue->data[queue->high--];
	queue->count--;
	if (queue->high < 0) {
		queue->high = queue->max - 1;
	}
	DEBUG_PRINTF(("DEBUG: queue_get %d end capacity=%d/%d range=%d/%d\n", return_value, queue->count, queue->max, queue->low, queue->high));
	return return_value;
}
