#include <stdio.h>
#include <stddef.h>
#include <assert.h>
#include "queue.h"

Queue queue_new(uint32_t size)
{
	size=(size>0 && size<32)? size:MAX_DEPTH;
	Queue q={size,0,0,0,{0}};
	return q;
}
uint32_t queue_full(const Queue *q)
{
	assert(q!=NULL);
	return (q->count==q->size);
}

uint32_t queue_empty(const Queue *q)
{
	assert(q!=NULL);
	return (q->count==0);
}

Queue* queue_add(Queue *q, int32_t ele, QueueResult *res)
{
	assert(q!=NULL);
	if (q->count < q->size)
	{
		q->data[q->head]=ele;
		q->head=(q->head+1)%q->size;
		++q->count;
		res->status=QUEUE_OK;
	}
	else
	{
		res->status=QUEUE_FULL;
	}
	assert(res->status==QUEUE_OK || q->count== q->size);
	return q;
}

Queue* queue_delete(Queue *q,QueueResult *res)
{
	assert(q!=NULL);
	if (q->count >0)
	{
		res->data=q->data[q->tail];
		q->tail=(q->tail+1)%q->size;
		--q->count;
		res->status=QUEUE_OK;
	}
	else
	{
		res->status=QUEUE_EMPTY;
	}
	assert(res->status==QUEUE_OK || q->count== 0);
	return q;
}

