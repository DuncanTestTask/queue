#include <stdlib.h>

struct queue {
        int *data;
        int low;
        int high;
        int count;
        int max;
};

struct queue *queue_init (size_t size);
void queue_free (struct queue *q);
void queue_add (struct queue *q, int a);
int queue_get (struct queue *q);
