#include "queue.h"
#if defined(DEBUG)
#include <stdio.h>
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
    DEBUG_PRINTF(("DEBUG: queue_add begin capacity=%d/%d rang=%d/%d\n", queue->count, queue->max, queue->low, queue->high));

}
int queue_get(struct queue *queue) {
    DEBUG_PRINTF(("DEBUG: queue_get begin capacity=%d/%d rang=%d/%d\n", queue->count, queue->max, queue->low, queue->high));
	int return_value=0;
	return return_value;
}
