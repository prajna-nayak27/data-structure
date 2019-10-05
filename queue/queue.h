#ifndef _INCLUDED_QUEUE_
#define _INCLUDED_QUEUE_
#include <stdint.h>
#define MAX_DEPTH 32
typedef struct _queue_ Queue;
typedef struct _queue_result_ QueueResult;
struct _queue_
{
	uint32_t size;
	uint32_t count;
	uint32_t head;
	uint32_t tail;
	float data[MAX_DEPTH];	
};

struct _queue_result_{
    int32_t data;
    uint32_t status;
};

#define QUEUE_OK 0
#define QUEUE_FULL 2
#define QUEUE_EMPTY 3

Queue queue_new(uint32_t size);
uint32_t queue_full(const Queue *q);
uint32_t queue_empty(const Queue *q);
Queue* queue_add(Queue *q, int32_t ele, QueueResult *res);
Queue* queue_delete(Queue *q,QueueResult *res);

#endif