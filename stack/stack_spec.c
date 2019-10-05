#include <assert.h>
#include "stack.h"

void test_empty_stack()
{
	Stack s= stack_new(5);
	Stack *stk=&s;
	assert(stack_full(stk)==0);
	assert(stack_empty(stk)==1);
}

void test_element_stack()
{
	Stack s=stack_new(2);
	Stack *stk=&s;
	StackResult res;
	stk=stack_push(stk,10,&res);
	stk=stack_peek(stk,&res);
	assert(res.status==STACK_OK && res.data==10);
	stk= stack_push(stk,20,&res);
	assert(stack_full(stk)==1);
	stk= stack_push(stk,30,&res);
	stk=stack_pop(stk,&res);
	assert(stack_empty(stk)==-1);
	stk=stack_pop(stk,&res);
}

int main()
{
	test_empty_stack();
	test_element_stack();
	return 0;
}