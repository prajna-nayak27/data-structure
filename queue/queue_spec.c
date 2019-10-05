#include <assert.h>
#include "queue.h"

void test_empty_queue()
{
	Queue queue= queue_new(5);
	Queue *q=&queue;
	assert(queue_full(q)==0);
	assert(queue_empty(q)==1);
}

void test_element_queue()
{
	Queue queue=queue_new(2);
	Queue *q= &queue;
	QueueResult res;
	q=queue_add(q,10,&res);
	assert(res.status==QUEUE_OK && res.data==10);
	q= queue_add(q,20,&res);
	assert(queue_full(q)==1);
	q= queue_add(q,30,&res);
	q=queue_delete(q,&res);
	assert(queue_empty(q)==-1);
	q=queue_delete(q,&res);
}

int main()
{
	test_empty_queue();
	test_element_queue();
	return 0;
}
