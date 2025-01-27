#include <stdlib.h>

struct queue {
        int *data;
        int low;
        int high;
        int count;
        int max;
};

struct queue *queue_init (size_t size);
void queue_free (struct queue *queue);
void queue_add (struct queue *queue, int item);
int queue_get (struct queue *queue);
