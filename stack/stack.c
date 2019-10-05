#include <stdio.h>
#include <stddef.h>
#include <assert.h>
#include "stack.h"

Stack stack_new(uint32_t size)
{
	size=(size>0 && size<32)? size:MAX_DEPTH;
	Stack s={size,-1,{0}};
	return s;
}
uint32_t stack_full(const Stack *stk)
{
	assert(stk!=NULL);
	return (stk->top+1==stk->size);
}

uint32_t stack_empty(const Stack *stk)
{
	assert(stk!=NULL);
	return (stk->top==-1);
}

Stack* stack_push(Stack *stk, float ele, StackResult *res)
{
	assert(stk!=NULL);
	if (stk->top+1 < stk->size)
	{
		stk->data[stk->top+1]=ele;
		res->data=ele;
		res->status=STACK_OK;
	}
	else
	{
		res->status=STACK_FULL;
	}
	assert(res->status==STACK_OK || (stk->top+1)== stk->size);
	return stk;
}

Stack* stack_pop(Stack *stk,StackResult *res)
{
	assert(stk!=NULL);
	if(stk->top>-1)
	{
		res->data=stk->data[stk->top];
		res->status=STACK_OK;
		--stk->top;
	}
	else
	{
		res->status=STACK_EMPTY;
	}
	assert(res->status==STACK_OK || stk->top==-1);
	return stk;
}

Stack* stack_peek(Stack *stk,StackResult *res)
{
	assert(stk!=NULL);
	if(stk->top>-1)
	{
		res->data=stk->data[stk->top];
		res->status=STACK_OK;
	}
	else
	{
		res->status=STACK_EMPTY;
	}
	assert(res->status==STACK_OK || stk->top==-1);
	return stk;
}

