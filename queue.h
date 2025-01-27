#include <stdlib.h>
struct queue {
	int *data;	// stored data
	int low;	// low mark, extends on left on add
	int high;	// hight mark, reduces on left on pop
	int count;	// curent amount elements (count <= max)
	int max;	// max number elements of the queue
	int error;	// error state
				// 0 - OK
				// 1 - init fail, no mem was allocated
				// 2 - add fail, not enough free space
				// 3 - get fail, queue is empty
};

struct queue *queue_init(size_t size);
void queue_free(struct queue *queue);
void queue_add(struct queue *queue, int item);
int queue_get(struct queue *queue);
