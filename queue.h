#include <stdlib.h>
struct queue {
	int *data;	// stored data
	int low;	// low mark, extends on left on add
	int high;	// hight mark, reduces on left on pop
	int count;	// current amount elements (count <= max)
	int max;	// max number elements of the queue
	int error;	// error state
				// 0 - OK
				// 1 - init fail, no mem was allocated
				// 2 - add fail, not enough free space
				// 3 - get fail, queue is empty
};

/**
 * @brief Initialize a queue structure with a specified size.
 *
 * @param size The maximum number of elements the queue can hold.
 * @return A pointer to the initialized queue structure.
 *         If memory allocation fails, the error field is set to 1.
 */
struct queue *queue_init(size_t size);

/**
 * @brief Frees the memory allocated for the queue structure.
 *
 * @param queue A pointer to the queue structure to be freed.
 */
void queue_free(struct queue *queue);

/**
 * @brief Adds an item to the queue.
 *
 * @param queue A pointer to the queue structure.
 * @param item The item to be added to the queue.
 *         If not enough free space, the error field is set to 2.
 */
void queue_add(struct queue *queue, int item);

/**
 * @brief Retrieves and removes an item from the queue.
 *
 * @param queue A pointer to the queue structure.
 * @return The item retrieved from the queue.
 *         If the queue is empty, the error field is set to 3.
 */
int queue_get(struct queue *queue);
