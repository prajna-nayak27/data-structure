#ifndef _INCLUDED_STACK_
#define _INCLUDED_STACK_
#include <stdint.h>
#define MAX_DEPTH 32
typedef struct _stack_ Stack;
typedef struct _stack_result_ StackResult;
struct _stack_
{
	uint32_t size;
	int32_t top;
	float data[MAX_DEPTH];	
};

struct _stack_result_{
    float data;
    uint32_t status;
};

#define STACK_OK 0
#define STACK_FULL 1
#define STACK_EMPTY 3

Stack stack_new(uint32_t size);
uint32_t stack_full(const Stack *stk);
uint32_t stack_empty(const Stack *stk);
Stack* stack_push(Stack *stk, float ele, StackResult *res);
Stack* stack_pop(Stack *stk,StackResult *res);
Stack* stack_peek(Stack *stk,StackResult *res);
Stack* balance_paranthesis(Stack *stk, char par[], StackResult *res);
#endif